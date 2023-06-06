#include "../include/wxMapnik.h"

namespace wxMapnik{

size_t write_data(void* buffer, size_t size_, size_t nmemb, void* userp)
{
    std::string data((char*) buffer, size_ * nmemb);
    *((std::stringstream*) userp) << data;
    return  size_ * nmemb;
}

void get_layers_datasource(const char * data, std::size_t size, std::vector<ds_ptr>& ds_vec, std::vector<std::string>& layer_names, tile_number t)
{
    ds_vec.clear();
    layer_names.clear();
    protozero::pbf_reader tile_msg(data,size);
    while (tile_msg.next())
    {
        switch(tile_msg.tag())
        {
            case mapnik::vector_tile_impl::Tile_Encoding::LAYERS:
            {
                const auto layer_view = tile_msg.get_view();
                protozero::pbf_reader layer_props_msg(layer_view);
                std::string layer_name;
                std::uint32_t layer_version = 1;
                while(layer_props_msg.next())
                {
                    switch(layer_props_msg.tag())
                    {
                        case mapnik::vector_tile_impl::Layer_Encoding::NAME:
                             layer_name = layer_props_msg.get_string();
                             break;
                        case mapnik::vector_tile_impl::Layer_Encoding::VERSION:
                             layer_version = layer_props_msg.get_uint32();
                             break;
                        default:
                             layer_props_msg.skip();
                             break;
                    }
                }
                if(layer_names.size()==0 || layer_names.end() != std::find(layer_names.begin(),layer_names.end(),layer_name))
                {
                    layer_names.push_back(layer_name);
                    protozero::pbf_reader layer_msg(layer_view);
                    ds_vec.push_back(std::make_shared<mapnik::vector_tile_impl::tile_datasource_pbf>(
                        layer_msg,t.getX(),t.getY(),t.getZ()
                    ));
                }
            }
        }
    }
}
/*
    //瓦片数据读取
    ifstream stream("osm_places_2023_04_24_10_00.mvt",ios_base::in|ios_base::binary);
    std::string buffer(std::istreambuf_iterator<char>(stream.rdbuf()),(std::istreambuf_iterator<char>()));
    //瓦片数据转化成数据源对象
    protozero::pbf_reader tile_msg(buffer.data(),buffer.size());
    while (tile_msg.next())
    {
        switch(tile_msg.tag())
        {
            case mapnik::vector_tile_impl::Tile_Encoding::LAYERS:
            {
                const auto layer_view = tile_msg.get_view();
                protozero::pbf_reader layer_msg(layer_view);
                ds_vec.push_back(std::make_shared<mapnik::vector_tile_impl::tile_datasource_pbf>(
                        layer_msg,0,0,0
                    ));
            }
        }
    }
*/
bool get_layer_datasource_url(std::string layer_name, std::vector<std::string>& layer_names, std::vector<ds_ptr>& ds_vec, std::vector<std::string>& buffer_url, tile_number t)
{
    std::string buffer = get_url_string(layer_name, t);
    if(buffer == "")
    {
        wxMessageBox(_("Can not connect to server"),_("error"));
        return false;
    }
    if(boost::algorithm::starts_with(buffer, "<!doctype html>"))
    {
        std::stringstream ss;
        ss<<"Layer'"<<layer_name<<"' has no feature in the extent and will not add to the map";
        wxMessageBox(_(ss.str()), _("warning"));
        return true;
    }

    buffer_url.push_back(buffer);
    protozero::pbf_reader tile_msg(buffer_url[buffer_url.size()-1].data(), buffer_url[buffer_url.size()-1].size());
    while (tile_msg.next())
    {
        switch(tile_msg.tag())
        {
            case mapnik::vector_tile_impl::Tile_Encoding::LAYERS:
            {
                const auto layer_view = tile_msg.get_view();
                protozero::pbf_reader layer_msg(layer_view);
                //tile_datasource_ptr = std::make_shared<mapnik::vector_tile_impl::tile_datasource_pbf>(layer_msg,0,0,0);
                ds_vec.push_back(std::make_shared<mapnik::vector_tile_impl::tile_datasource_pbf>(layer_msg,t.getX(),t.getY(),t.getZ()));
                break;
            }
        }
    }
    layer_names.push_back(layer_name);
    return true;

}

std::string get_url_string(std::string layer_name, tile_number t)
{
    mapnik::box2d<double> tile_extent = mapnik::vector_tile_impl::tile_mercator_bbox(t.getX(), t.getY(), t.getZ());
    std::stringstream ss;
    ss.setf(std::ios::fixed);
    ss.precision(6);
    ss<<"http://192.168.1.107:8080/MVTSelectService/query?xmin="<<tile_extent.minx()<<"&ymin="<<tile_extent.miny()<<"&xmax="<<tile_extent.maxx()<<"&ymax="<<tile_extent.maxy()<<"&srid=3857&tbName="<<layer_name;
    std::string url_i;

    ss>>url_i;

    CURL* curl;
    std::stringstream out;
    curl = curl_easy_init();
    if(curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url_i.data());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &wxMapnik::write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &out);

        curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        std::string buffer = std::string(std::istreambuf_iterator<char>(out.rdbuf()),(std::istreambuf_iterator<char>()));
        return buffer;
    }
    return "";
}

void get_layers_datasource(std::string filename, std::vector<ds_ptr>& ds_vec, std::vector<std::string>& layer_names, tile_number t)
{
    std::ifstream stream(filename, std::ios_base::in|std::ios_base::binary);
    std::string buffer_compress(std::istreambuf_iterator<char>(stream.rdbuf()),(std::istreambuf_iterator<char>()));
    get_layers_datasource(buffer_compress.data(), buffer_compress.size(), ds_vec, layer_names, t);
}

void get_fields(ds_ptr ds,std::vector<std::string>& field_names)
{
    field_names.clear();
    mapnik::layer_descriptor layer_desc = ds -> get_descriptor();
    std::vector<mapnik::attribute_descriptor> att_desc = layer_desc.get_descriptors();
    for(int i=0; i<att_desc.size();i++)
    {
        field_names.push_back(att_desc[i].get_name());
    }
}

void get_field_values(ds_ptr ds, std::vector<std::string> field_names, std::vector<std::vector<std::string>>& values)
{
    for(int i=0; i<values.size();i++)
    {
        values[i].clear();
    }
    values.clear();

    mapnik::query q(ds->envelope());
    for(auto i=field_names.begin();i!=field_names.end();i++)
    {
        q.add_property_name(*i);
    }
    mapnik::featureset_ptr features = ds ->features(q);

    values.resize(field_names.size());

    if(features)
    {
        mapnik::feature_ptr feature;
        while((feature = features->next()))
        {
            for(int i=0;i<field_names.size();i++)
            {
                std::string s = feature->get(field_names[i]).to_string();
                if(s == ""){continue;}
                bool is_have = false;
                for(auto j=values[i].begin();j!=values[i].end();j++)
                {
                   if(*j==s){is_have = true;break;}
                }
                if(!is_have)
                {
                   values[i].push_back(s);
                }
            }
        }
    }
}

void init_styles_num(std::vector<std::vector<int>>& styles_num , int n )
{
    for(int i=0; i<styles_num.size();i++)
    {
        styles_num[i].clear();
    }
    styles_num.clear();

    for(int i=0; i<n; i++)
    {
        std::vector<int> v(4, 0);
        styles_num.push_back(v);
    }
}

int get_geometry_type(std::shared_ptr<mapnik::datasource> ds)
{
    mapnik::query q(ds->envelope());
    mapnik::featureset_ptr features = ds ->features(q);
    mapnik::feature_ptr feature = features -> next();
    int n = features->get_geometry_type();
    return n;
}

int get_geometry_type(ds_ptr ds)
{
    mapnik::query q(ds->envelope());
    mapnik::featureset_ptr features = ds ->features(q);
    mapnik::feature_ptr feature = features -> next();
    int n = features->get_geometry_type();
    return n;
}

bool have_Chinese(char* str)
{
    char c;
	while(1)
	{
		c=*str++;
		if (c==0) break; //如果到字符串尾则说明该字符串没有中文字符
		if ((c & 0x80)&&(*str & 0x80)) return true;//如果字符高位为1且下一字符高位也是1则有中文字符
	}
	return false;
}

void image_to_wxBitmap(mapnik::image_rgba8 img, wxBitmap& bmp)
{
    unsigned char* img_data = img.bytes();
    wxAlphaPixelData bmp_data(bmp);

    wxAlphaPixelData::Iterator p(bmp_data);
    for (int y = 0; y < img.height(); y++) {
        for (int x = 0; x < img.width(); x++) {
            p.Red() = img_data[4 * (y * img.width() + x) + 0];
            p.Green() = img_data[4 * (y * img.width() + x) + 1];
            p.Blue() = img_data[4 * (y * img.width() + x) + 2];
            p.Alpha() = img_data[4 * (y * img.width() + x) + 3];
            ++p;
        }
    }
}

void get_expressions(std::map<std::string, std::string>& expressions, TiXmlDocument doc)
{
    if(!doc.LoadFile())
    {
        wxMessageBox(_("XML load failed"),_("warning"));
        return;
    }
    TiXmlElement* root = doc.RootElement();
    if(root)
    {
        TiXmlElement* style_e = root->FirstChildElement("Style");
        while(style_e)
        {
            std::string style_name = std::string(style_e->Attribute("name"));
            std::string expression = "ALL";
            TiXmlElement* rule_e = style_e->FirstChildElement("Rule");
            TiXmlElement* file_e = rule_e->FirstChildElement("Filter");
            if(file_e)
            {
                expression = std::string(file_e->GetText());
                int l = expression.find("(");
                int r = expression.find(")");
                expression = expression.substr(l+1, r-1);
            }
            expressions.insert(std::make_pair(style_name, expression));
            style_e = style_e->NextSiblingElement("Style");
        }
    }
}

std::string get_keys_file(std::string style_name, TiXmlDocument doc)
{
    if(!doc.LoadFile())
    {
        wxMessageBox(_("XML load failed"),_("warning"));
        return "";
    }
    TiXmlElement* root = doc.RootElement();
    if(root)
    {
        TiXmlElement* style_e = root->FirstChildElement("Style");
        while(style_e)
        {
            std::string sn = std::string(style_e->Attribute("name"));
            if(sn == style_name)
            {
                TiXmlElement* rule_e = style_e->FirstChildElement("Rule");
                TiXmlElement* sym_e = rule_e->FirstChildElement("PointSymbolizer");
                std::string file_ = std::string(sym_e->Attribute("file"));
                return file_;
            }
            style_e = style_e->NextSiblingElement("Style");
        }
    }
    return "";
}

std::shared_ptr<style_information_polygon> get_style_information_polygon(std::string name, std::string expression, int type, mapnik::feature_type_style style)
{
    using namespace mapnik;
    using const_iterator = mapnik::symbolizer_base::cont_type::const_iterator;

    rules rules_ = style.get_rules();
    rule rule_ = rules_[0];
    expression_ptr exp_ptr = rule_.get_filter();
    rule::symbolizers::iterator sym_it = rule_.begin();

    polygon_symbolizer polygon_sym = sym_it->get<polygon_symbolizer>();

    const_iterator itr_1 = polygon_sym.properties.find(keys::fill);
    color fill_ = util::apply_visitor(extract_raw_value<color>(), itr_1->second);

    const_iterator itr_2 = polygon_sym.properties.find(keys::fill_opacity);
    double opacity_ = util::apply_visitor(extract_raw_value<double>(), itr_2->second);

    std::string target = "Unknown";
    if(type == 3)
    {
        target = "polygon fill";
    }
    auto polygon_style = std::make_shared<style_information_polygon>(name, expression, target, wxColor(fill_.red(),fill_.green(),fill_.blue()), opacity_);
    return polygon_style;
}

std::shared_ptr<style_information_line> get_style_information_line(std::string name, std::string expression, int type, mapnik::feature_type_style style)
{
    using namespace mapnik;
    using const_iterator = mapnik::symbolizer_base::cont_type::const_iterator;

    rules rules_ = style.get_rules();
    rule rule_ = rules_[0];
    expression_ptr exp_ptr = rule_.get_filter();
    rule::symbolizers::iterator sym_it = rule_.begin();

    line_symbolizer line_sym =sym_it->get<line_symbolizer>();

    const_iterator itr_1 = line_sym.properties.find(keys::stroke);
    color fill_ = util::apply_visitor(extract_raw_value<color>(), itr_1->second);

    const_iterator itr_2 = line_sym.properties.find(keys::stroke_width);
    double width_ = util::apply_visitor(extract_raw_value<double>(), itr_2->second);

    const_iterator itr_3 = line_sym.properties.find(keys::stroke_opacity);
    double opacity_ = util::apply_visitor(extract_raw_value<double>(), itr_3->second);

    const_iterator itr_4 = line_sym.properties.find(keys::stroke_linecap);
    line_cap_enum lineCap = util::apply_visitor(extract_raw_value<line_cap_enum>(), itr_4->second);
    int lineCap_index = -1;
    switch(lineCap)
    {
    case line_cap_enum::BUTT_CAP:
        lineCap_index = 0;
        break;
    case line_cap_enum::SQUARE_CAP:
        lineCap_index = 1;
        break;
    case line_cap_enum::ROUND_CAP:
        lineCap_index = 2;
        break;
    }

    std::string target = "Unknown";
    if(type == 2)
    {
        target = "line";
    }
    if(type == 3)
    {
        target = "polygon edge";
    }

    auto style_line = std::make_shared<wxMapnik::style_information_line>(name, expression, target, wxColor(fill_.red(),fill_.green(),fill_.blue()), width_, opacity_, lineCap_index);
    return style_line;
}

std::shared_ptr<style_information_point> get_style_information_point(std::string name, std::string expression, int type, mapnik::feature_type_style style, TiXmlDocument doc)
{
    using namespace mapnik;
    using const_iterator = mapnik::symbolizer_base::cont_type::const_iterator;

    rules rules_ = style.get_rules();
    rule rule_ = rules_[0];
    expression_ptr exp_ptr = rule_.get_filter();
    rule::symbolizers::iterator sym_it = rule_.begin();

    point_symbolizer point_sym = sym_it->get<point_symbolizer>();

    //const_iterator itr_1 = point_sym.properties.find(keys::file);
    std::string file_ = get_keys_file(name, doc);

    const_iterator itr_2 = point_sym.properties.find(keys::opacity);
    double opacity_ = util::apply_visitor(extract_raw_value<double>(), itr_2->second);

    const_iterator itr_3 = point_sym.properties.find(keys::allow_overlap);
    bool is_overlap = util::apply_visitor(extract_raw_value<bool>(), itr_3->second);

    std::string target = "Unknown";
    if(type == 1)
    {
        target = "point";
    }
    if(type == 2)
    {
        target = "point in line";
    }
    if(type == 3)
    {
        target = "point in polygon";
    }

    auto style_point = std::make_shared<wxMapnik::style_information_point>(name, expression, target, file_, opacity_, is_overlap);
    return style_point;
}

std::shared_ptr<style_information_text> get_style_information_text(std::string name, std::string expression, int type, TiXmlDocument doc)
{
    using namespace mapnik;
    if(!doc.LoadFile())
    {
        wxMessageBox(_("XML load failed"),_("warning"));
        auto style_text = std::make_shared<style_information_text>();
        return style_text;
    }
    TiXmlElement* root = doc.RootElement();

    std::string field_ = "";
    int placement_ = 2;
    double size_ = 10;
    wxColor fillColor_ = wxColor(0,0,0);
    wxColor haloColor_ = wxColor(0,0,0);
    double haloRadius_ = 1;

    std::string target = "Unknown";
    if(type == 1)
    {
        target = "point label";
    }
    if(type == 2)
    {
        target = "line label";
    }
    if(type == 3)
    {
        target = "polygon label";
    }

    if(root)
    {
        TiXmlElement* style_e = root->FirstChildElement("Style");
        while(style_e)
        {
            std::string sn = std::string(style_e->Attribute("name"));
            if(sn == name)
            {
                TiXmlElement* rule_e = style_e->FirstChildElement("Rule");
                TiXmlElement* sym_e = rule_e->FirstChildElement("TextSymbolizer");

                std::string field_1 = std::string(sym_e->GetText());
                if(field_1 != "")
                {
                    int l = field_1.find("[");
                    int r = field_1.find("]");
                    field_ = field_1.substr(l+1, r-1);
                }

                const char* placement_0 = sym_e->Attribute("placement");
                if(placement_0)
                {
                    std::string placement_1 = std::string(placement_0);
                    if(placement_1 == "polylabel")
                        {placement_ = 0;}
                    else if(placement_1 == "interior")
                        {placement_ = 1;}
                    else if(placement_1 == "vertex")
                        {placement_ = 3;}
                    else if(placement_1 == "line")
                        {placement_ = 4;}
                }

                const char* size_0 = sym_e->Attribute("size");
                if(size_0)
                {
                    std::string size_1 = std::string(size_0);

                    std::stringstream ss;
                    ss<<size_1;
                    ss>>size_;
                }

                const char* haloRadius_0 = sym_e->Attribute("halo-radius");
                if(haloRadius_0)
                {
                    std::string haloRadius_1 = std::string(haloRadius_0);

                    std::stringstream ss;
                    ss<<haloRadius_1;
                    ss>>haloRadius_;
                }

                const char* fillColor_0 = sym_e->Attribute("fill");
                if(fillColor_0)
                {
                    std::string fillColor_1 = std::string(fillColor_0);

                    int l = fillColor_1.find("(");
                    int r = fillColor_1.find(")");
                    fillColor_1 = fillColor_1.substr(l+1, r-1);

                    std::vector<int> rgb(3, 0);
                    std::string each;
                    int i = 0;
                    std::stringstream ss(fillColor_1);
                    while(std::getline(ss, each, ','))
                    {
                        std::stringstream ss_(each);
                        ss_>>rgb[i++];
                    }

                    fillColor_ = wxColor(rgb[0], rgb[1], rgb[2]);
                }


                const char* haloColor_0 = sym_e->Attribute("halo-fill");
                if(haloColor_0)
                {
                    std::string haloColor_1 = std::string(sym_e->Attribute("halo-fill"));

                    int l = haloColor_1.find("(");
                    int r = haloColor_1.find(")");
                    haloColor_1 = haloColor_1.substr(l+1, r-1);

                    std::vector<int> rgb(3, 0);
                    std::string each;
                    int i = 0;
                    std::stringstream ss(haloColor_1);
                    while(std::getline(ss, each, ','))
                    {
                        std::stringstream ss_(each);
                        ss_>>rgb[i++];
                    }

                    haloColor_ = wxColor(rgb[0], rgb[1], rgb[2]);
                }

                auto style_text = std::make_shared<style_information_text>(name, expression, target, field_, placement_, size_, fillColor_, haloColor_, haloRadius_);
                return style_text;

            }
            style_e = style_e->NextSiblingElement("Style");
        }
    }
    auto style_text = std::make_shared<style_information_text>();
    return style_text;

}

void updata_styles_information(std::map<std::string, std::shared_ptr<wxMapnik::style_information>>& styles_information, mapnik::Map m, std::string file_name)
{
    using namespace mapnik;
    styles_information.clear();
    std::map<std::string, feature_type_style> styles = m.styles();

    std::map<std::string, std::string> expressions;
    TiXmlDocument doc(file_name);
    get_expressions(expressions, doc);

    std::vector<mapnik::layer> layers = m.layers();
    for(auto i = layers.begin(); i != layers.end(); i++)
    {
        std::vector<std::string> layer_styles = i->styles();
        int type = get_geometry_type(i->datasource());
        for(auto j = layer_styles.begin(); j != layer_styles.end(); j++)
        {
            std::string expression = expressions[*j];
            mapnik::feature_type_style style_ = styles[*j];
            if(boost::algorithm::starts_with(*j, "polygon"))
            {
                std::shared_ptr<style_information_polygon> sp = get_style_information_polygon(*j, expression, type, style_);
                styles_information.insert(std::make_pair(*j, sp));
            }
            if(boost::algorithm::starts_with(*j, "line"))
            {
                std::shared_ptr<style_information_line> sl = get_style_information_line(*j, expression, type, style_);
                styles_information.insert(std::make_pair(*j, sl));
            }
            if(boost::algorithm::starts_with(*j, "point"))
            {
                std::shared_ptr<style_information_point> sp = get_style_information_point(*j, expression, type, style_, doc);
                styles_information.insert(std::make_pair(*j, sp));
            }
            if(boost::algorithm::starts_with(*j, "text"))
            {
                std::shared_ptr<style_information_text> st = get_style_information_text(*j ,expression, type, doc);
                styles_information.insert(std::make_pair(*j, st));
            }
        }

    }
}

tile_number get_tile_number(double x_, double y_, std::uint64_t level)
{
    double half_of_equator = M_PI * mapnik::EARTH_RADIUS;
    double tile_size = 2.0 * half_of_equator / (1ull << level);

    int row = (x_ + half_of_equator)/tile_size;
    int col = (half_of_equator - y_)/tile_size;

    tile_number t(row, col, level);
    return t;
}

}
