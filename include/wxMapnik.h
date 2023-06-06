#ifndef WXMAPNIK_H
#define WXMAPNIK_H

#include <protozero/pbf_reader.hpp>
#include <iostream>
#include <fstream>
#include <curl/curl.h>
#include <string>
#include <algorithm>
#include <mapnik/map.hpp>
#include <mapnik/load_map.hpp>
#include <mapnik/layer.hpp>
#include <mapnik/rule.hpp>
#include <mapnik/util/variant.hpp>
#include <mapnik/feature_type_style.hpp>
#include <mapnik/symbolizer.hpp>
#include <mapnik/text/placements/dummy.hpp>
#include <mapnik/text/text_properties.hpp>
#include <mapnik/text/formatting/text.hpp>
#include <mapnik/datasource.hpp>
#include <mapnik/datasource_cache.hpp>
#include <mapnik/font_engine_freetype.hpp>
#include <mapnik/agg_renderer.hpp>
#include <mapnik/expression.hpp>
#include <mapnik/color_factory.hpp>
#include <mapnik/image_util.hpp>
#include <mapnik/unicode.hpp>
#include <mapnik/save_map.hpp>
#include <mapnik/cairo_io.hpp>
#include <protozero/pbf_reader.hpp>
#include <boost/algorithm/algorithm.hpp>
#include <boost/algorithm/string.hpp>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/rawbmp.h>
#include <wx/msgdlg.h>
#include <wx/colour.h>
#include <tinyxml.h>
#include "../vector_tile_decode/vector_tile_datasource_pbf.hpp"
#include "../vector_tile_decode/vector_tile_compression.hpp"
#include "../vector_tile_decode/vector_tile_config.hpp"
#include "../vector_tile_decode/vector_tile_projection.hpp"

namespace wxMapnik{
using ds_ptr = std::shared_ptr<mapnik::vector_tile_impl::tile_datasource_pbf>;

class tile_number
{
public:
    tile_number(){}
    tile_number(int x, int y, int z):X(x),Y(y),Z(z){}
    int getX(){return X;}
    int getY(){return Y;}
    int getZ(){return Z;}
    void setX(int x){X = x;}
    void setY(int y){Y = y;}
    void setZ(int z){Z = z;}
    void setXYZ(int x, int y, int z)
    {
        X = x;
        Y = y;
        Z = z;
    }
private:
    int X = 0;
    int Y = 0;
    int Z = 0;
};

class style_information{
public:
    style_information() = default;
    style_information(std::string name, std::string exp, std::string tar):
        style_name(name),
        expression(exp),
        target(tar){}
    std::string get_name(){return style_name;}
    std::string get_expression(){return expression;}
    std::string get_target(){return target;}
    virtual wxColor get_fill_color() {return wxColor(0,0,0);};
    virtual double get_fill_opacity() {return -1;};
    virtual wxColor get_stroke_color() {return wxColor(0,0,0);};
    virtual double get_stroke_width() {return -1;};
    virtual double get_stroke_opacity(){return -1;}
    virtual int get_stroke_linecap(){return -1;}
    virtual double get_dot_opacity(){return -1;}
    virtual bool get_dot_overlap(){return false;}
    virtual std::string get_dot_file(){return "";}
    virtual std::string get_label_field(){return "";}
    virtual int get_label_placement(){return -1;}
    virtual double get_label_size(){return -1;}
    virtual wxColor get_label_fillColor(){return wxColor(0,0,0);}
    virtual wxColor get_label_haloColor(){return wxColor(0,0,0);}
    virtual double get_label_haloRadius(){return -1;}

    virtual void set_fill_color(wxColor cf){}
    virtual void set_fill_opacity(double of){}
    virtual void set_stroke_color(wxColor cs){}
    virtual void set_stroke_width(double ws){}
    virtual void set_stroke_opacity(double os){}
    virtual void set_stroke_linecap(int i){}
    virtual void set_dot_opacity(double od){}
    virtual void set_dot_overlap(bool od){}
    virtual void set_dot_file(std::string fd){}
    virtual void set_label_field(std::string fl){}
    virtual void set_label_placement(int pl){}
    virtual void set_label_size(double sl){}
    virtual void set_label_fillColor(wxColor fl){}
    virtual void set_label_haloColor(wxColor hl){}
    virtual void set_label_haloRadius(double hl){}
    virtual ~style_information() = default;
protected:
    std::string style_name;
    std::string expression;
    std::string target;
};

class style_information_polygon : public style_information{
public:
    style_information_polygon() = default;
    style_information_polygon(std::string name, std::string exp, std::string tar, wxColor cfill, double ofill=1.0):
        style_information(name, exp, tar),
        colour_fill(cfill),
        opacity_fill(ofill){}

    wxColor get_fill_color(){return colour_fill;}
    double get_fill_opacity(){return opacity_fill;}

    void set_fill_color(wxColor cf){colour_fill = cf;}
    void set_fill_opacity(double of){opacity_fill = of;}
private:
    wxColor colour_fill;
    double opacity_fill;
};

class style_information_line : public style_information{
public:
    style_information_line() = default;
    style_information_line(std::string name, std::string exp, std::string tar, wxColor cstroke, double wstroke=1.0, double ostroke=1.0, int cindex=0):
        style_information(name, exp, tar),
        colour_stroke(cstroke),
        width_stroke(wstroke),
        opacity_stroke(ostroke),
        linecap_index(cindex){}

    wxColor get_stroke_color(){return colour_stroke;}
    double get_stroke_width(){return width_stroke;}
    double get_stroke_opacity(){return opacity_stroke;}
    int get_stroke_linecap(){return linecap_index;}

    void set_stroke_color(wxColor cs){colour_stroke = cs;}
    void set_stroke_width(double ws){width_stroke = ws;}
    void set_stroke_opacity(double os){opacity_stroke = os;}
    void set_stroke_linecap(int i){linecap_index = i;}
private:
    wxColor colour_stroke;
    double width_stroke;
    double opacity_stroke;
    int linecap_index;
};

class style_information_point : public style_information{
public:
    style_information_point() = default;
    style_information_point(std::string name, std::string exp, std::string tar, std::string fdot, double odot=1.0, bool oldot=false):
        style_information(name, exp, tar),
        opacity_dot(odot),
        overlap_dot(oldot),
        file_dot(fdot){}

    double get_dot_opacity(){return opacity_dot;}
    bool get_dot_overlap(){return overlap_dot;}
    std::string get_dot_file(){return file_dot;}

    void set_dot_opacity(double od){opacity_dot = od;}
    void set_dot_overlap(bool old){overlap_dot = old;}
    void set_dot_file(std::string fd){file_dot = fd;}
private:
    double opacity_dot;
    bool overlap_dot;
    std::string file_dot;
};

class style_information_text : public style_information{
public:
    style_information_text() = default;
    style_information_text(std::string name, std::string exp, std::string tar, std::string flabel, int plabel, double slabel, wxColor fclabel, wxColor hclabel, double hrlabel):
        style_information(name, exp, tar),
        field_label(flabel),
        placement_label(plabel),
        size_label(slabel),
        fillColor_label(fclabel),
        haloColor_label(hclabel),
        haloRadius_label(hrlabel){}
    std::string get_label_field(){return field_label;}
    int get_label_placement(){return placement_label;}
    double get_label_size(){return size_label;}
    wxColor get_label_fillColor(){return fillColor_label;}
    wxColor get_label_haloColor(){return haloColor_label;}
    double get_label_haloRadius(){return haloRadius_label;}

    void set_label_field(std::string fl){field_label = fl;}
    void set_label_placement(int pl){placement_label = pl;}
    void set_label_size(double sl){size_label = sl;}
    void set_label_fillColor(wxColor fl){fillColor_label = fl;}
    void set_label_haloColor(wxColor hl){haloColor_label = hl;}
    void set_label_haloRadius(double hl){haloRadius_label = hl;}
private:
    std::string field_label;
    int placement_label;
    double size_label;
    wxColor fillColor_label;
    wxColor haloColor_label;
    double haloRadius_label;

};

size_t write_data(void* buffer, size_t size, size_t nmemb, void* userp);

void get_layers_datasource(const char * data, std::size_t size, std::vector<ds_ptr>& ds_vec, std::vector<std::string>& layer_names, tile_number t);
void get_layers_datasource(std::string filename, std::vector<ds_ptr>& ds_vec, std::vector<std::string>& layer_names, tile_number t);
bool get_layer_datasource_url(std::string layer_name, std::vector<std::string>& layer_names, std::vector<ds_ptr>& ds_vec, std::vector<std::string>& buffer_url, tile_number t);

std::string get_url_string(std::string layer_name, tile_number t);

void get_fields(ds_ptr ds,std::vector<std::string>& field_names);
void get_field_values(ds_ptr ds, std::vector<std::string> field_names, std::vector<std::vector<std::string>>& values);

int get_geometry_type(ds_ptr ds);
int get_geometry_type(std::shared_ptr<mapnik::datasource> ds);

void init_styles_num(std::vector<std::vector<int>>& styles_num , int n );

bool have_Chinese(char* str);

void image_to_wxBitmap(mapnik::image_rgba8 img, wxBitmap& bmp);

void get_expressions(std::map<std::string, std::string>& expressions, TiXmlDocument doc);

std::string get_keys_file(std::string style_name, TiXmlDocument doc);

std::shared_ptr<style_information_polygon> get_style_information_polygon(std::string name, std::string expression, int type, mapnik::feature_type_style style);
std::shared_ptr<style_information_line> get_style_information_line(std::string name, std::string expression, int type, mapnik::feature_type_style style);
std::shared_ptr<style_information_point> get_style_information_point(std::string name, std::string expression, int type, mapnik::feature_type_style style, TiXmlDocument doc);
std::shared_ptr<style_information_text> get_style_information_text(std::string name, std::string expression, int type, TiXmlDocument doc);

void updata_styles_information(std::map<std::string, std::shared_ptr<wxMapnik::style_information>>& styles_information, mapnik::Map m, std::string file_name);

tile_number get_tile_number(double x_, double y_, std::uint64_t level);
};

#endif // WXMAPNIK_H
