/***************************************************************
 * Name:      mapnik_test_imageMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    hbs ()
 * Created:   2023-02-15
 * Copyright: hbs ()
 * License:
 **************************************************************/

#include "../include/mapnik_test_imageMain.h"
#include "../include/StyleDesignPolygon.h"
#include "../include/StyleDesignLine.h"
#include "../include/StyleDesignPoint.h"
#include "../include/StyleInfoPolygon.h"
#include "../include/StyleInfoLine.h"
#include "../include/StyleInfoPoint.h"
#include "../include/StyleInfoText.h"
#include "../include/SelectUrl.h"
#include "../include/SaveToImg.h"
#include "../include/SaveToXML.h"
#include <wx/msgdlg.h>
#include <wx/event.h>
#include <wx/bitmap.h>
#include <wx/filename.h>
#include <wx/dcmemory.h>
#include <wx/clipbrd.h>
#include <wx/dcclient.h>
#include <wx/chartype.h>
#include <wx/image.h>
#include <wx/log.h>
#include <wx/rawbmp.h>
#include <boost/algorithm/algorithm.hpp>
#include "wx/wfstream.h"

//(*InternalHeaders(mapnik_test_imageFrame)
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(mapnik_test_imageFrame)
const long mapnik_test_imageFrame::ID_SCROLLEDWINDOW2 = wxNewId();
const long mapnik_test_imageFrame::ID_CHOICE1 = wxNewId();
const long mapnik_test_imageFrame::ID_STATICTEXT1 = wxNewId();
const long mapnik_test_imageFrame::ID_BUTTON1 = wxNewId();
const long mapnik_test_imageFrame::ID_LISTBOX1 = wxNewId();
const long mapnik_test_imageFrame::ID_BUTTON2 = wxNewId();
const long mapnik_test_imageFrame::ID_BUTTON3 = wxNewId();
const long mapnik_test_imageFrame::ID_BUTTON4 = wxNewId();
const long mapnik_test_imageFrame::ID_PANEL1 = wxNewId();
const long mapnik_test_imageFrame::ID_BUTTON5 = wxNewId();
const long mapnik_test_imageFrame::ID_BUTTON6 = wxNewId();
const long mapnik_test_imageFrame::ID_BUTTON7 = wxNewId();
const long mapnik_test_imageFrame::ID_SCROLLEDWINDOW1 = wxNewId();
const long mapnik_test_imageFrame::idMenuLoad = wxNewId();
const long mapnik_test_imageFrame::idMenuLoadUrl = wxNewId();
const long mapnik_test_imageFrame::idMenuLoadStyle = wxNewId();
const long mapnik_test_imageFrame::idMenuSaveXML = wxNewId();
const long mapnik_test_imageFrame::idMenuSaveImg = wxNewId();
const long mapnik_test_imageFrame::idMenuQuit = wxNewId();
const long mapnik_test_imageFrame::idMenuAbout = wxNewId();
const long mapnik_test_imageFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(mapnik_test_imageFrame,wxFrame)
    //(*EventTable(mapnik_test_imageFrame)
    //*)
    EVT_PAINT(mapnik_test_imageFrame::OnPaint)
    //EVT_MOUSE_EVENTS(mapnik_test_imageFrame::OnMouseWheelInMap)
END_EVENT_TABLE()

mapnik_test_imageFrame::mapnik_test_imageFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(mapnik_test_imageFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(980,630));
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    ScrolledWindow1 = new wxScrolledWindow(this, ID_SCROLLEDWINDOW1, wxPoint(200,32), wxSize(980,630), wxVSCROLL|wxHSCROLL, _T("ID_SCROLLEDWINDOW1"));
    Panel1 = new wxScrolledWindow(ScrolledWindow1, ID_SCROLLEDWINDOW2, wxPoint(20,20), wxSize(512,512), wxBORDER_SIMPLE|wxVSCROLL|wxHSCROLL, _T("ID_SCROLLEDWINDOW2"));
    Choice1 = new wxChoice(ScrolledWindow1, ID_CHOICE1, wxPoint(597,48), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    StaticText1 = new wxStaticText(ScrolledWindow1, wxID_ANY, _("Layer:"), wxPoint(546,55), wxDefaultSize, 0, _T("wxID_ANY"));
    StaticText2 = new wxStaticText(ScrolledWindow1, ID_STATICTEXT1, _("Type:"), wxPoint(548,106), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    StaticText3 = new wxStaticText(ScrolledWindow1, wxID_ANY, _("Unknown"), wxPoint(595,108), wxDefaultSize, 0, _T("wxID_ANY"));
    Button1 = new wxButton(ScrolledWindow1, ID_BUTTON1, _("style..."), wxPoint(591,156), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Panel2 = new wxPanel(ScrolledWindow1, ID_PANEL1, wxPoint(736,20), wxSize(201,400), wxBORDER_SIMPLE|wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    ListBox1 = new wxListBox(Panel2, ID_LISTBOX1, wxPoint(17,40), wxSize(167,272), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX1"));
    Button2 = new wxButton(Panel2, ID_BUTTON2, _("delete"), wxPoint(112,328), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    StaticText4 = new wxStaticText(Panel2, wxID_ANY, _("current layer\'s styles:"), wxPoint(24,16), wxDefaultSize, 0, _T("wxID_ANY"));
    Button3 = new wxButton(Panel2, ID_BUTTON3, _("+"), wxPoint(16,328), wxSize(35,35), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    Button4 = new wxButton(Panel2, ID_BUTTON4, _("-"), wxPoint(64,328), wxSize(35,35), 0, wxDefaultValidator, _T("ID_BUTTON4"));
    Button5 = new wxButton(ScrolledWindow1, ID_BUTTON5, _("zoom in"), wxPoint(551,384), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
    Button6 = new wxButton(ScrolledWindow1, ID_BUTTON6, _("zoom out"), wxPoint(551,437), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
    Button7 = new wxButton(ScrolledWindow1, ID_BUTTON7, _("reset"), wxPoint(551,489), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON7"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu1, idMenuLoad, _("Load from file"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem3);
    MenuItem7 = new wxMenuItem(Menu1, idMenuLoadUrl, _("Load from server"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem7);
    MenuItem6 = new wxMenuItem(Menu1, idMenuLoadStyle, _("Load styles"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem6);
    MenuItem5 = new wxMenuItem(Menu1, idMenuSaveXML, _("Save styles"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem5);
    MenuItem4 = new wxMenuItem(Menu1, idMenuSaveImg, _("Save to image file"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem4);
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    FileDialog1 = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, _("XML files|*.xml"), wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    FileDialog2 = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, _("MVT files|*.mvt"), wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    Center();

    Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&mapnik_test_imageFrame::OnChoice1Select);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mapnik_test_imageFrame::OnButton1Click2);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mapnik_test_imageFrame::OnButton2Click1);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mapnik_test_imageFrame::OnButton3Click);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mapnik_test_imageFrame::OnButton4Click);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mapnik_test_imageFrame::OnButton5Click3);
    Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mapnik_test_imageFrame::OnButton6Click1);
    Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mapnik_test_imageFrame::OnButton7Click);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&mapnik_test_imageFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&mapnik_test_imageFrame::OnAbout);
    //*)

    Connect(idMenuLoad, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&mapnik_test_imageFrame::OnLoad);
    Connect(idMenuLoadUrl, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&mapnik_test_imageFrame::OnLoadUrl);
    Connect(idMenuLoadStyle, wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&mapnik_test_imageFrame::OnLoadStyle);
    Connect(idMenuSaveImg, wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&mapnik_test_imageFrame::OnSaveImg);
    Connect(idMenuSaveXML, wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&mapnik_test_imageFrame::OnSaveXML);
    //Connect(wxEVT_LEFT_DOWN, wxMouseEventHandler(mapnik_test_imageFrame::OnMouseWheelInMap));
    Bind(wxEVT_LISTBOX_DCLICK, &mapnik_test_imageFrame::OnListBoxDclick, this, ID_LISTBOX1);
    //Bind(wxEVT_PAINT, &mapnik_test_imageFrame::OnPaint, this);

    mapnik::datasource_cache::instance().register_datasources("/usr/local/lib/mapnik/input");
    mapnik::freetype_engine::register_font("/usr/local/lib/mapnik/fonts/DejaVuSans.ttf");
}

mapnik_test_imageFrame::~mapnik_test_imageFrame()
{
    //(*Destroy(mapnik_test_imageFrame)
    //*)
}

void mapnik_test_imageFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void mapnik_test_imageFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void mapnik_test_imageFrame::OnLoadUrl(wxCommandEvent& event)
{
    using namespace mapnik;

    //wxMapnik::tile_number tn = wxMapnik::get_tile_number(12742033.87, 3544656.366, 10);
    SelectUrl url_select(this);
    int dlg = url_select.ShowModal();
    if(dlg == wxID_OK)
    {
        if(url_select.RadioButton1->GetValue())
        {
            int x_ = url_select.SpinCtrl1->GetValue();
            int y_ = url_select.SpinCtrl2->GetValue();
            int z_ = url_select.SpinCtrl3->GetValue();
            tn.setXYZ(x_, y_, z_);
        }
        else
        {
            double x = url_select.SpinCtrlDouble1->GetValue();
            double y = url_select.SpinCtrlDouble2->GetValue();
            int z = url_select.SpinCtrl4->GetValue();
            tn = wxMapnik::get_tile_number(x, y, z);
        }

        layer_names.clear();
        ds_vec.clear();
        buffer_url.clear();
        if(url_select.admin_cb->GetValue())
        {
            if(!wxMapnik::get_layer_datasource_url("osm_admin", layer_names, ds_vec, buffer_url, tn))
            {
                return;
            }
        }
        if(url_select.waterarea_cb->GetValue())
        {
            if(!wxMapnik::get_layer_datasource_url("osm_waterareas", layer_names, ds_vec, buffer_url, tn))
            {
                return;
            }
        }
        if(url_select.building_cb->GetValue())
        {
            if(!wxMapnik::get_layer_datasource_url("osm_buildings", layer_names, ds_vec, buffer_url, tn))
            {
                return;
            }
        }
        if(url_select.road_cb->GetValue())
        {
            if(!wxMapnik::get_layer_datasource_url("osm_roads", layer_names, ds_vec, buffer_url, tn))
            {
                return;
            }
        }
        if(url_select.place_cb->GetValue())
        {
            if(!wxMapnik::get_layer_datasource_url("osm_places", layer_names, ds_vec, buffer_url, tn))
            {
                return;
            }
        }

        if(layer_names.size() == 0)
        {
            return;
        }
    }

    wxMapnik::init_styles_num(styles_num, layer_names.size());
    styles_information.clear();

    h = Panel1->GetSize().GetHeight();
    w = Panel1->GetSize().GetWidth();

    m = std::make_shared<mapnik::Map>(w, h);
    m->set_background(mapnik::parse_color("white"));
    current_layer = 0;

    //定义样式
    feature_type_style line_style;
    {
        rule r;
        {
            line_symbolizer line_sym;
            put(line_sym, keys::clip, true);
            put(line_sym, keys::stroke, color(125, 125, 125));
            put(line_sym, keys::stroke_width, 1.0);
            put(line_sym, keys::stroke_opacity, 1.0);
            put(line_sym, keys::stroke_linecap, line_cap_enum::BUTT_CAP);
            r.append(std::move(line_sym));
        }
        line_style.add_rule(std::move(r));
    }
    m->insert_style("line_1", std::move(line_style));
    ++style_line_num;

    wxColor color_stroke(125,125,125);
    auto style_line = std::make_shared<wxMapnik::style_information_line>("line_1", "ALL", "polygon edge", color_stroke, 1);
    styles_information.insert(std::make_pair("line_1", style_line));

    //创建图层
    for(int i=0; i<layer_names.size(); i++)
    {
        layer lyr(layer_names[i]);
        lyr.set_datasource(ds_vec[i]);
        lyr.add_style("line_1");
        ++styles_num[i][1];
        m->add_layer(lyr);
    }

    wxMapnik::get_fields(ds_vec[0], field_names);
    wxMapnik::get_field_values(ds_vec[0], field_names, values);
    type = wxMapnik::get_geometry_type(ds_vec[0]);
    if(type == 1)
    {
        StaticText3->SetLabel(_("Point"));
    }
    else if(type == 2)
    {
        StaticText3->SetLabel(_("LineString"));
    }
    else if(type == 3)
    {
        StaticText3->SetLabel(_("Polygon"));
    }



    m->zoom_all();

    //渲染
    mapnik::image_rgba8 im(w, h);
    mapnik::agg_renderer<mapnik::image_rgba8> ren(*m, im);
    ren.apply();
    //mapnik::save_to_file(im, "the_image_1.png");

    bmp.Create(w,h,32);
    wxMapnik::image_to_wxBitmap(im, bmp);

    ShowBitmap();
    SaveXML("the_map_1.xml");
    UpdataLayerlist();
    UpdataStylelist(0);
    is_load = true;

}

void mapnik_test_imageFrame::OnLoad(wxCommandEvent& event)
{
    using namespace mapnik;
    //my_wxclientdc->Clear();


    int dlg = FileDialog2->ShowModal();
    if(dlg == wxID_OK)
    {
    std::string mvt_path = std::string(FileDialog2->GetPath().ToUTF8().data());
    //mvt_path = "http://192.168.1.107:8080/MVTSelectService/query?xmin=12589659.4809&ymin=4153740.12159&xmax=12636596.2855&ymax=4206211.84735&srid=3857&tbName=osm_waterareas_gen1";

    std::ifstream stream(mvt_path, std::ios_base::in|std::ios_base::binary);        //读取文件

    buffer_compress = std::string(std::istreambuf_iterator<char>(stream.rdbuf()),(std::istreambuf_iterator<char>()));
    //buffer_compress = wxMapnik::get_url_string("osm_waterareas");
    //int bs = buffer_compress.size();

    //std::ofstream file("t1.txt");
    //file << buffer_compress;
    //将mvt中各个图层转换成datasoure对象保存到ds_vec中，各图层名称保存到layer_names中
    tn.setXYZ(837, 421, 10);
    wxMapnik::get_layers_datasource(buffer_compress.data(), buffer_compress.size(), ds_vec, layer_names, tn);

/*
    layer_names.push_back("s");
    protozero::pbf_reader tile_msg(buffer_compress.data(), buffer_compress.size());
    while (tile_msg.next())
    {
        switch(tile_msg.tag())
        {
            case mapnik::vector_tile_impl::Tile_Encoding::LAYERS:
            {
                const auto layer_view = tile_msg.get_view();
                protozero::pbf_reader layer_msg(layer_view);
                ds_vec.push_back(std::make_shared<mapnik::vector_tile_impl::tile_datasource_pbf>(layer_msg,0,0,0));
            }
        }
    }
*/

    wxMapnik::init_styles_num(styles_num, layer_names.size());
    styles_information.clear();

    type = wxMapnik::get_geometry_type(ds_vec[0]);
    if(type == 1)
    {
        StaticText3->SetLabel(_("Point"));
    }
    else if(type == 2)
    {
        StaticText3->SetLabel(_("LineString"));
    }
    else if(type == 3)
    {
        StaticText3->SetLabel(_("Polygon"));
    }


    wxMapnik::get_fields(ds_vec[current_layer], field_names);
    wxMapnik::get_field_values(ds_vec[current_layer], field_names, values);

    h = Panel1->GetSize().GetHeight();
    w = Panel1->GetSize().GetWidth();

    m = std::make_shared<mapnik::Map>(w, h);

    m->set_background(mapnik::parse_color("white"));
    //定义样式
    feature_type_style line_style;
    {
        rule r;
        {
            line_symbolizer line_sym;
            put(line_sym, keys::clip, true);
            put(line_sym, keys::stroke, color(125, 125, 125));
            put(line_sym, keys::stroke_width, 1.0);
            put(line_sym, keys::stroke_opacity, 1.0);
            put(line_sym, keys::stroke_linecap, line_cap_enum::BUTT_CAP);
            r.append(std::move(line_sym));
        }
        line_style.add_rule(std::move(r));
    }
    m->insert_style("line_1", std::move(line_style));
    ++style_line_num;

    wxColor color_stroke(125,125,125);
    auto style_line = std::make_shared<wxMapnik::style_information_line>("line_1", "ALL", "polygon edge", color_stroke, 1);
    styles_information.insert(std::make_pair("line_1", style_line));

    feature_type_style polygon_style;
    {
        rule r;
        {
            polygon_symbolizer polygon_sym;
            put(polygon_sym, keys::fill, color(150,150,200));
            put(polygon_sym, keys::fill_opacity, 1.0);
            put(polygon_sym, keys::clip, true);
            r.append(std::move(polygon_sym));
        }
        polygon_style.add_rule(std::move(r));
    }
    //m->insert_style("polygon_1",std::move(polygon_style));
    //++style_polygon_num;

    //wxColor color_fill(150,150,200);
    //auto style_polygon = std::make_shared<wxMapnik::style_information_polygon>("polygon_1", "ALL", "polygon fill", color_fill, 1);
    //styles_information.insert(std::make_pair("polygon_1", style_polygon));

    feature_type_style point_style;
    {
        rule r;
        {
            point_symbolizer point_sym;
            put(point_sym, keys::opacity, 1.0);
            r.append(std::move(point_sym));
        }
        point_style.add_rule(std::move(r));
    }
    //m->insert_style("point_1", std::move(point_style));
   // ++style_point_num;

    //auto style_point = std::make_shared<wxMapnik::style_information_point>("point_1","ALL","polygon center", "",1,true);
    //styles_information.insert(std::make_pair("point_1", style_point));

    /*
    feature_type_style text_style;
    {
        rule r;
        {
            text_symbolizer text_sym;
            text_placements_ptr placement_finder = std::make_shared<text_placements_dummy>();
            placement_finder->defaults.expressions.label_placement = enumeration_wrapper(label_placement_enum::INTERIOR_PLACEMENT);
            placement_finder->defaults.format_defaults.face_name = "DejaVu Sans Book";
            placement_finder->defaults.format_defaults.text_size = 10.0;
            placement_finder->defaults.format_defaults.fill = color(0, 0, 0);
            placement_finder->defaults.format_defaults.halo_fill = color(255, 255, 200);
            placement_finder->defaults.format_defaults.halo_radius = 1.0;
            placement_finder->defaults.set_format_tree(std::make_shared<mapnik::formatting::text_node>(parse_expression("[admin_level]")));
            put<text_placements_ptr>(text_sym, keys::text_placements_, placement_finder);
            put(text_sym, keys::allow_overlap, true);
            r.append(std::move(text_sym));
        }
        {
            text_symbolizer text_sym;
            text_placements_ptr placement_finder = std::make_shared<text_placements_dummy>();
            placement_finder->defaults.expressions.label_placement = enumeration_wrapper(label_placement_enum::VERTEX_PLACEMENT);
            placement_finder->defaults.format_defaults.face_name = "DejaVu Sans Book";
            placement_finder->defaults.format_defaults.text_size = 10.0;
            placement_finder->defaults.format_defaults.fill = color(200, 0, 0);
            placement_finder->defaults.format_defaults.halo_fill = color(255, 255, 200);
            placement_finder->defaults.format_defaults.halo_radius = 1.0;
            placement_finder->defaults.set_format_tree(std::make_shared<mapnik::formatting::text_node>(parse_expression("[admin_level]")));
            put<text_placements_ptr>(text_sym, keys::text_placements_, placement_finder);
            put(text_sym, keys::allow_overlap, true);
            r.append(std::move(text_sym));
        }
        text_style.add_rule(std::move(r));
    }
    */
    //m->insert_style("text_1", std::move(text_style));

    //创建图层
    for(int i=0;i<layer_names.size();i++)
    {
        layer lyr(layer_names[i]);
        lyr.set_datasource(ds_vec[i]);
        //lyr.add_style("polygon_1");
        //++styles_num[i][0];
        lyr.add_style("line_1");
        ++styles_num[i][1];
        //lyr.add_style("point_1");
        //++styles_num[i][2];
        //lyr.add_style("text_1");
        //++styles_num[i][3];
        m->add_layer(lyr);
    }

    m->zoom_all();

    //渲染
    mapnik::image_rgba8 im(w, h);
    mapnik::agg_renderer<mapnik::image_rgba8> ren(*m, im);
    ren.apply();
    //mapnik::save_to_file(im, "the_image_1.png");


    bmp.Create(w,h,32);
    wxMapnik::image_to_wxBitmap(im, bmp);

    current_layer = 0;
    UpdataLayerlist();
    UpdataStylelist(0);
    ShowBitmap();
    SaveXML("the_map_1.xml");
    is_load = true;
    }
}

void mapnik_test_imageFrame::OnLoadStyle(wxCommandEvent& event)
{
    if(!is_load)
    {
        wxMessageBox(_("Map has not loaded"),_("Warning"));
        return;
    }
    int dlg = FileDialog1->ShowModal();
    if(dlg == wxID_OK)
    {
        std::string file_name = std::string(FileDialog1->GetPath().ToUTF8().data());
        LoadXML(file_name);
        mapnik::layer lyr= m->get_layer(0);
        //m->zoom_all();
        mapnik::image_rgba8 im(w, h);
        mapnik::agg_renderer<mapnik::image_rgba8> ren(*m, im);
        ren.apply();
        wxMapnik::image_to_wxBitmap(im, bmp);
        ShowBitmap();
        SaveXML("the_map_1.xml");

        wxMapnik::updata_styles_information(styles_information, *m, file_name);
        UpdataStyleData();
    }
}

void mapnik_test_imageFrame::OnMouseWheelInMap(wxMouseEvent& event)
{
    wxMessageBox(_("Map has not loaded"),_("Warning"));
    if(!is_load)
    {
        return;
    }
    int delta = event.GetWheelDelta();
    if(delta)
    {
        int zoom_factor_a = zoom_factor - delta*0.02;
        if(zoom_factor_a > 0 && zoom_factor_a <= 1)
        {
            zoom_factor = zoom_factor_a;
            m->zoom(zoom_factor);

            mapnik::image_rgba8 im(w,h);           //渲染
            mapnik::agg_renderer<mapnik::image_rgba8> ren(*m, im);
            ren.apply();

            wxMapnik::image_to_wxBitmap(im, bmp);
            ShowBitmap();
        }
    }

}

void mapnik_test_imageFrame::OnSaveImg(wxCommandEvent& event)
{
    if(!is_load)
    {
        wxMessageBox(_("Map has not loaded"),_("Warning"));
        return;
    }

    SaveToImg save_to_img(this);
    int dlg= save_to_img.ShowModal();
    if(dlg == wxID_OK)
    {
        std::string file_name = std::string(save_to_img.TextCtrl1->GetValue().ToUTF8().data());
        std::string file_type = std::string(save_to_img.Choice2->GetString(save_to_img.Choice2->GetSelection()).ToUTF8().data());
        int size_selection = save_to_img.Choice1->GetSelection();

        std::stringstream ss;
        ss<<file_name<<"."<<file_type;

        int h_new;
        int w_new;

        switch(size_selection)
        {
        case 0:
            h_new = 256;
            w_new = 256;
            break;
        case 1:
            h_new = 512;
            w_new = 512;
            break;
        case 2:
            h_new = 1024;
            w_new = 1024;
            break;
        case 3:
            h_new = 2048;
            w_new = 2048;
            break;
        case 4:
            h_new = 4096;
            w_new = 4096;
            break;
        }

        mapnik::Map mm(w_new, h_new);

        mapnik::load_map(mm, "the_map_1.xml");

        for(int i = 0; i < ds_vec.size(); i++)
        {
            mapnik::layer& lyr = mm.get_layer(i);
            lyr.set_datasource(ds_vec[i]);
        }

        mm.zoom_all();

        mapnik::image_rgba8 im(w_new, h_new);
        mapnik::agg_renderer<mapnik::image_rgba8> ren(mm, im);
        ren.apply();
        //mapnik::save_map(mm, "the_map_2.xml");

        wxBitmap bmp_(w_new, h_new, 32);
        wxMapnik::image_to_wxBitmap(im, bmp_);
        if(file_type == "png")
        {
            bmp_.SaveFile(ss.str(), wxBitmapType::wxBITMAP_TYPE_PNG);
        }
        else if(file_type == "jpeg")
        {
            bmp_.SaveFile(ss.str(), wxBitmapType::wxBITMAP_TYPE_JPEG);
        }
        else if(file_type == "tif")
        {
            bmp_.SaveFile(ss.str(), wxBitmapType::wxBITMAP_TYPE_TIF);
        }
        //mapnik::save_to_file(im, ss.str());
    }
}

void mapnik_test_imageFrame::OnSaveXML(wxCommandEvent& event)
{
    if(!is_load)
    {
        wxMessageBox(_("Map has not loaded"),_("Warning"));
        return;
    }

    SaveToXML save_to_xml(this);
    int dlg = save_to_xml.ShowModal();
    if(dlg == wxID_OK)
    {
        std::string file_name = save_to_xml.TextCtrl1->GetValue().ToUTF8().data();
        if(!boost::algorithm::ends_with(file_name, ".xml"))
        {
            std::stringstream ss;
            ss<<file_name<<".xml";
            file_name = ss.str();
        }
        SaveXML(file_name);
    }
}

void mapnik_test_imageFrame::OnPaint(wxPaintEvent& WXUNUSED(event))
{
    if(bmp.IsOk()){
       wxClientDC dc(Panel1);
       dc.Clear();
       dc.DrawBitmap(bmp,0,0);
       Update();
   }
}

void mapnik_test_imageFrame::ShowBitmap()
{
    if(bmp.IsOk()){
       wxClientDC dc(Panel1);
       dc.Clear();
       dc.DrawBitmap(bmp,0,0);
       Update();
       SetClientSize(wxSize(980 +size_change[(size_count++)%2],630));
   }
}

void mapnik_test_imageFrame::UpdataStylelist(int pos)
{
    mapnik::layer& lyr = m->get_layer(current_layer);
    std::vector<std::string>& styles = lyr.styles();
    ListBox1->Clear();
    for(auto i=styles.begin();i!=styles.end();i++)
    {
        ListBox1->Append(wxString::FromUTF8(*i));
    }
    ListBox1->SetSelection(pos);
}

void mapnik_test_imageFrame::UpdataLayerlist()
{
    Choice1->Clear();
    for(auto i=layer_names.begin(); i!=layer_names.end(); i++)
    {
        Choice1->Append(wxString::FromUTF8(*i));
    }
    Choice1->SetSelection(current_layer);
}

void mapnik_test_imageFrame::SaveXML(std::string file_name)
{
    using namespace mapnik;
    for(int i=0; i<layer_names.size(); i++)
    {
        layer& lyr = m->get_layer(i);
        parameters p;
        p["type"] = "shape";
        p["file"] = "/home/hbs/mapnik/demo/data/boundaries";
        p["encoding"] = "utf8";
        lyr.set_datasource(datasource_cache::instance().create(p));
    }
    save_map(*m, file_name);
    for(int i=0; i<ds_vec.size(); i++)
    {
        layer& lyr = m->get_layer(i);
        lyr.set_datasource(ds_vec[i]);
    }
}

void mapnik_test_imageFrame::LoadXML(std::string file_name)
{
    if(!is_load)
    {
        wxMessageBox(_("Map has not loaded"),_("Warning"));
        return;
    }
    std::shared_ptr<mapnik::Map> mm = std::make_shared<mapnik::Map>(w, h);
    mapnik::load_map(*mm, file_name);

    std::vector<mapnik::layer>& lyrs = (*mm).layers();
    if(lyrs.size() != ds_vec.size())
    {
        wxMessageBox(_("Unfitted XML"),_("Warning"));
        return;
    }
    for(int i=0; i<lyrs.size(); i++)
    {
        if(lyrs[i].name() != layer_names[i])
        {
            wxMessageBox(_("Unfitted XML"),_("Warning"));
            return;
        }
    }

    mapnik::box2d<double> current_extent = m->get_current_extent();
    mm->zoom_to_box(current_extent);

    m = mm;
    for(int i=0; i<ds_vec.size(); i++)
    {
        mapnik::layer& lyr = m->get_layer(i);
        lyr.set_datasource(ds_vec[i]);
    }
    UpdataStylelist(0);
}

void mapnik_test_imageFrame::UpdataStyleData()
{
    std::map<std::string, mapnik::feature_type_style> styles = m->styles();
    style_polygon_num = 0;
    style_line_num = 0;
    style_point_num = 0;
    style_text_num = 0;
    for(auto i = styles.begin(); i != styles.end(); i++)
    {
        if(boost::algorithm::starts_with(i->first, "polygon"))
        {
            style_polygon_num++;
        }
        else if(boost::algorithm::starts_with(i->first, "line"))
        {
            style_line_num++;
        }
        else if(boost::algorithm::starts_with(i->first, "point"))
        {
            style_point_num++;
        }
        else if(boost::algorithm::starts_with(i->first, "text"))
        {
            style_text_num++;
        }
    }

    std::vector<mapnik::layer> layers = m->layers();
    wxMapnik::init_styles_num(styles_num, layers.size());
    for(int i = 0; i < layers.size(); i++)
    {
        std::vector<std::string> layer_styles = layers[i].styles();
        for(auto j = layer_styles.begin(); j != layer_styles.end(); j++)
        {
            if(boost::algorithm::starts_with(*j, "polygon"))
            {
                styles_num[i][0]++;
            }
            else if(boost::algorithm::starts_with(*j, "line"))
            {
                styles_num[i][1]++;
            }
            else if(boost::algorithm::starts_with(*j, "point"))
            {
                styles_num[i][2]++;
            }
            else if(boost::algorithm::starts_with(*j, "text"))
            {
                styles_num[i][3]++;
            }
        }

    }
}

void mapnik_test_imageFrame::OnButton1Click2(wxCommandEvent& event)
{
    if(!is_load)
    {
        wxMessageBox(_("Map has not loaded"),_("Warning"));
        return;
    }

    int dlg;
    if(type == 3)
    {
        StyleDesignPolygon style_designer_polygon(this);
        dlg = style_designer_polygon.ShowModal();
    }
    else if(type == 2)
    {
        StyleDesignLine style_designer_line(this);
        dlg = style_designer_line.ShowModal();
    }
    else if(type == 1)
    {
        StyleDesignPoint style_designer_point(this);
        dlg = style_designer_point.ShowModal();
    }
    else
    {
        wxMessageBox(_("Unknown geometry type"),_("Warning"));
        return;
    }

    if(dlg == wxID_OK)
    {
        ShowBitmap();
        SaveXML("the_map_1.xml");
        UpdataStylelist(0);
    }
}

void mapnik_test_imageFrame::OnChoice1Select(wxCommandEvent& event)
{
    if(!is_load)
    {
        wxMessageBox(_("Map has not loaded"),_("Warning"));
        return;
    }
    current_layer = Choice1->GetSelection();

    //mapnik::layer lyr = m->get_layer(current_layer);
    //mapnik::datasource_ptr dp= lyr.datasource();
    //auto ds_current = std::static_pointer_cast<mapnik::vector_tile_impl::tile_datasource_pbf>(lyr.datasource());

    wxMapnik::get_fields(ds_vec[current_layer], field_names);

    wxMapnik::get_field_values(ds_vec[current_layer], field_names, values);

    type = wxMapnik::get_geometry_type(ds_vec[current_layer]);
    if(type == 1)
    {
        StaticText3->SetLabel(_("Point"));
    }
    else if(type == 2)
    {
        StaticText3->SetLabel(_("LineString"));
    }
    else if(type == 3)
    {
        StaticText3->SetLabel(_("Polygon"));
    }

    UpdataStylelist(0);
}

void mapnik_test_imageFrame::OnButton2Click1(wxCommandEvent& event)
{
    if(!is_load)
    {
        wxMessageBox(_("Map has not loaded"),_("Warning"));
        return;
    }

    int pos = ListBox1->GetSelection();
    std::string style_selected = std::string(ListBox1->GetString(pos).ToUTF8().data());

    if(boost::algorithm::starts_with(style_selected, "polygon"))
    {
        if(pos >= styles_num[current_layer][0])
        {
            wxMessageBox(_("Data confusion !"),_("Error"));
            return;
        }
        styles_num[current_layer][0]--;
    }
    else if(boost::algorithm::starts_with(style_selected, "line"))
    {
        if(pos >= styles_num[current_layer][0]+styles_num[current_layer][1])
        {
            wxMessageBox(_("Data confusion !"),_("Error"));
            return;
        }
        styles_num[current_layer][1]--;
    }
    else if(boost::algorithm::starts_with(style_selected, "point"))
    {
        if(pos >= styles_num[current_layer][0]+styles_num[current_layer][1]+styles_num[current_layer][2])
        {
            wxMessageBox(_("Data confusion !"),_("Error"));
            return;
        }
        styles_num[current_layer][2]--;
    }
    else if(boost::algorithm::starts_with(style_selected, "text"))
    {
        if(pos >= styles_num[current_layer][0]+styles_num[current_layer][1]+styles_num[current_layer][2]+styles_num[current_layer][3])
        {
            wxMessageBox(_("Data confusion !"),_("Error"));
            return;
        }
        styles_num[current_layer][3]--;
    }
    else
    {
        wxMessageBox(_("Unknown style !"),_("Error"));
        return;
    }

    mapnik::layer& lyr = m->get_layer(current_layer);
    std::vector<std::string>& styles = lyr.styles();
    if(styles.size() < 2)
    {
        wxMessageBox(_("the layer have 1 style at least !"),_("Warning"));
        return;
    }
    auto i = styles.begin() + pos;
    styles.erase(i);

    mapnik::image_rgba8 im(w, h);           //渲染
    mapnik::agg_renderer<mapnik::image_rgba8> ren(*m, im);
    ren.apply();

    wxMapnik::image_to_wxBitmap(im, bmp);
    ShowBitmap();
    SaveXML("the_map_1.xml");
    UpdataStylelist(0);

}

void mapnik_test_imageFrame::OnButton3Click(wxCommandEvent& event)
{
    if(!is_load)
    {
        wxMessageBox(_("Map has not loaded"),_("Warning"));
        return;
    }
    int pos = ListBox1->GetSelection();
    std::string style_selected = std::string(ListBox1->GetString(pos).ToUTF8().data());

    mapnik::layer& lyr = m->get_layer(current_layer);
    std::vector<std::string>& styles = lyr.styles();

    if(styles.size() != styles_num[current_layer][0] + styles_num[current_layer][1] + styles_num[current_layer][2] + styles_num[current_layer][3])
    {
        wxMessageBox(_("Data confusion !"),_("Error"));
        return;
    }

    int style_num_0 = styles_num[current_layer][0];
    int style_num_0_1 = styles_num[current_layer][0] + styles_num[current_layer][1];
    int style_num_0_1_2 = styles_num[current_layer][0] + styles_num[current_layer][1] + styles_num[current_layer][2];
    if(boost::algorithm::starts_with(style_selected, "polygon"))
    {
        if(pos + 1 < style_num_0)
        {
            styles[pos] = styles[pos + 1];
            styles[pos + 1] = style_selected;
            pos++;
        }
        else
        {
            wxMessageBox(_("Polygon style can not be higher than line style !"),_("Error"));
            return;
        }
    }
    else if(boost::algorithm::starts_with(style_selected, "line"))
    {
        if(pos + 1 < style_num_0_1)
        {
            styles[pos] = styles[pos + 1];
            styles[pos + 1] = style_selected;
            pos++;
        }
        else
        {
            wxMessageBox(_("Line style can not be higher than point style !"),_("Error"));
            return;
        }
    }
    else if(boost::algorithm::starts_with(style_selected, "point"))
    {
        if(pos + 1 < style_num_0_1_2)
        {
            styles[pos] = styles[pos + 1];
            styles[pos + 1] = style_selected;
            pos++;
        }
        else
        {
            wxMessageBox(_("Point style can not be higher than text style !"),_("Error"));
            return;
        }
    }
    else if(boost::algorithm::starts_with(style_selected, "text"))
    {
        if(pos + 1 < styles.size())
        {
            styles[pos] = styles[pos + 1];
            styles[pos + 1] = style_selected;
            pos++;
        }
        else
        {
            return;
        }
    }
    else
    {
        wxMessageBox(_("Unknown style !"),_("Error"));
        return;
    }

    mapnik::image_rgba8 im(w,h);           //渲染
    mapnik::agg_renderer<mapnik::image_rgba8> ren(*m, im);
    ren.apply();

    wxMapnik::image_to_wxBitmap(im, bmp);
    ShowBitmap();
    SaveXML("the_map_1.xml");
    UpdataStylelist(pos);
}

void mapnik_test_imageFrame::OnButton4Click(wxCommandEvent& event)
{
    if(!is_load)
    {
        wxMessageBox(_("Map has not loaded"),_("Warning"));
        return;
    }
    int pos = ListBox1->GetSelection();
    std::string style_selected = std::string(ListBox1->GetString(pos).ToUTF8().data());

    mapnik::layer& lyr = m->get_layer(current_layer);
    std::vector<std::string>& styles = lyr.styles();

    if(styles.size() != styles_num[current_layer][0] + styles_num[current_layer][1] + styles_num[current_layer][2] + styles_num[current_layer][3])
    {
        wxMessageBox(_("Data confusion !"),_("Error"));
        return;
    }

    int style_num_0 = styles_num[current_layer][0];
    int style_num_0_1 = styles_num[current_layer][0] + styles_num[current_layer][1];
    int style_num_0_1_2 = styles_num[current_layer][0] + styles_num[current_layer][1] + styles_num[current_layer][2];
    if(boost::algorithm::starts_with(style_selected, "polygon"))
    {
        if(pos > 0)
        {
            styles[pos] = styles[pos - 1];
            styles[pos - 1] = style_selected;
            pos--;
        }
        else
        {
            return;
        }
    }
    else if(boost::algorithm::starts_with(style_selected, "line"))
    {
        if(pos > style_num_0)
        {
            styles[pos] = styles[pos - 1];
            styles[pos - 1] = style_selected;
            pos--;
        }
        else
        {
            wxMessageBox(_("Line style can not be lower than polygon style !"),_("Error"));
            return;
        }
    }
    else if(boost::algorithm::starts_with(style_selected, "point"))
    {
        if(pos > style_num_0_1)
        {
            styles[pos] = styles[pos - 1];
            styles[pos - 1] = style_selected;
            pos--;
        }
        else
        {
            wxMessageBox(_("Point style can not be lower than line style !"),_("Error"));
            return;
        }
    }
    else if(boost::algorithm::starts_with(style_selected, "text"))
    {
        if(pos > style_num_0_1_2)
        {
            styles[pos] = styles[pos - 1];
            styles[pos - 1] = style_selected;
            pos--;
        }
        else
        {
            wxMessageBox(_("Text style can not be lower than point style !"),_("Error"));
            return;
        }
    }
    else
    {
        wxMessageBox(_("Unknown style !"),_("Error"));
        return;
    }

    mapnik::image_rgba8 im(w,h);           //渲染
    mapnik::agg_renderer<mapnik::image_rgba8> ren(*m, im);
    ren.apply();

    wxMapnik::image_to_wxBitmap(im, bmp);
    ShowBitmap();
    SaveXML("the_map_1.xml");

    UpdataStylelist(pos);
}

void mapnik_test_imageFrame::OnListBoxDclick(wxCommandEvent& event)
{
    if(!is_load)
    {
        wxMessageBox(_("Map has not loaded"),_("Warning"));
        return;
    }
    int pos = ListBox1->GetSelection();
    std::string style_selected = std::string(ListBox1->GetString(pos).ToUTF8().data());

    //std::map<std::string, mapnik::feature_type_style> styles_ = m->styles();
    //mapnik::feature_type_style style_ = styles_[style_selected];
    //mapnik::rules rules_ = style_.get_rules();
    //mapnik::rule rule_ = rules_[0];
    //mapnik::rule::symbolizers syms_ = rule_.get_symbolizers();
    //mapnik::symbolizer_base sym_ = syms_[0];

    auto& style_selected_info = styles_information[style_selected];
    if(boost::algorithm::starts_with(style_selected, "polygon"))
    {
        //double op = mapnik::get(sym_, mapnik::keys::fill_opacity);

        StyleInfoPolygon style_info_polygon(this);

        style_info_polygon.name_text->SetLabel(wxString::FromUTF8(style_selected_info->get_name()));

        style_info_polygon.expression_text->SetLabel(wxString::FromUTF8(style_selected_info->get_expression()));

        style_info_polygon.target_text->SetLabel(wxString::FromUTF8(style_selected_info->get_target()));

        style_info_polygon.opacity_double->SetValue(style_selected_info->get_fill_opacity());
        style_info_polygon.opacity = style_selected_info->get_fill_opacity();

        style_info_polygon.ColourPickerCtrl1->SetColour(style_selected_info->get_fill_color());
        style_info_polygon.fill_color = style_selected_info->get_fill_color();

        int dlg = style_info_polygon.ShowModal();
        if(dlg == wxID_OK)
        {
            ShowBitmap();
            SaveXML("the_map_1.xml");
        }
    }
    else if(boost::algorithm::starts_with(style_selected, "line"))
    {
        StyleInfoLine style_info_line(this);

        style_info_line.name_text->SetLabel(wxString::FromUTF8(style_selected_info->get_name()));

        style_info_line.expression_text->SetLabel(wxString::FromUTF8(style_selected_info->get_expression()));

        style_info_line.target_text->SetLabel(wxString::FromUTF8(style_selected_info->get_target()));

        style_info_line.width_double->SetValue(style_selected_info->get_stroke_width());
        style_info_line.stroke_width = style_selected_info->get_stroke_width();

        style_info_line.ColourPickerCtrl1->SetColour(style_selected_info->get_stroke_color());
        style_info_line.stroke_color = style_selected_info->get_stroke_color();

        style_info_line.opacity_double->SetValue(style_selected_info->get_stroke_opacity());
        style_info_line.stroke_opacity = style_selected_info->get_stroke_opacity();

        style_info_line.linecap_choice->SetSelection(style_selected_info->get_stroke_linecap());
        style_info_line.linecap_index = style_selected_info->get_stroke_linecap();

        int dlg = style_info_line.ShowModal();
        if(dlg == wxID_OK)
        {
            ShowBitmap();
            SaveXML("the_map_1.xml");
        }
    }
    else if(boost::algorithm::starts_with(style_selected, "point"))
    {
        StyleInfoPoint style_info_point(this);

        style_info_point.name_text->SetLabel(wxString::FromUTF8(style_selected_info->get_name()));

        style_info_point.expression_text->SetLabel(wxString::FromUTF8(style_selected_info->get_expression()));

        style_info_point.target_text->SetLabel(wxString::FromUTF8(style_selected_info->get_target()));

        style_info_point.opacity_double->SetValue(style_selected_info->get_dot_opacity());
        style_info_point.opacity = style_selected_info->get_dot_opacity();

        style_info_point.file_text->SetValue(wxString::FromUTF8(style_selected_info->get_dot_file()));
        style_info_point.file = style_selected_info->get_dot_file();

        style_info_point.CheckBox2->SetValue(style_selected_info->get_dot_overlap());
        style_info_point.overlap = style_selected_info->get_dot_overlap();

        int dlg = style_info_point.ShowModal();
        if(dlg == wxID_OK)
        {
            ShowBitmap();
            SaveXML("the_map_1.xml");
        }
    }
    else if(boost::algorithm::starts_with(style_selected, "text"))
    {
        StyleInfoText style_info_text(this);

        style_info_text.name_text->SetLabel(wxString::FromUTF8(style_selected_info->get_name()));

        style_info_text.expression_text->SetLabel(wxString::FromUTF8(style_selected_info->get_expression()));

        style_info_text.target_text->SetLabel(wxString::FromUTF8(style_selected_info->get_target()));

        int a = 0;
        int field_index = 0;
        std::string field = style_selected_info->get_label_field();
        style_info_text.field_choice->Clear();
        for(auto i = field_names.begin(); i!=field_names.end();i++)
        {
            style_info_text.field_choice->Append(wxString::FromUTF8(*i));
            if(field == *i){field_index = a;}
            a++;
        }
        style_info_text.field_choice->SetSelection(field_index);
        style_info_text.field = field;

        style_info_text.placement_choice->Clear();
        style_info_text.placement_choice->Append(_("Default"));
        style_info_text.placement_choice->Append(_("Interior"));
        style_info_text.placement_choice->Append(_("Centroid"));
        style_info_text.placement_choice->Append(_("Vertex"));
        style_info_text.placement_choice->Append(_("Edge"));
        style_info_text.placement_choice->SetSelection(style_selected_info->get_label_placement());
        style_info_text.placement = style_selected_info->get_label_placement();

        style_info_text.size_double->SetValue(style_selected_info->get_label_size());
        style_info_text.size_ = style_selected_info->get_label_size();

        style_info_text.ColourPickerCtrl1->SetColour(style_selected_info->get_label_fillColor());
        style_info_text.fillColor = style_selected_info->get_label_fillColor();

        style_info_text.ColourPickerCtrl2->SetColour(style_selected_info->get_label_haloColor());
        style_info_text.haloColor = style_selected_info->get_label_haloColor();

        style_info_text.hradius_double->SetValue(style_selected_info->get_label_haloRadius());
        style_info_text.haloRadius = style_selected_info->get_label_haloRadius();

        int dlg = style_info_text.ShowModal();
        if(dlg == wxID_OK)
        {
            ShowBitmap();
            SaveXML("the_map_1.xml");
        }
    }
    else
    {
        wxMessageBox(_("Unknown style !"),_("Error"));
        return;
    }

}


void mapnik_test_imageFrame::OnButton5Click3(wxCommandEvent& event)
{
    if(!is_load)
    {
        wxMessageBox(_("Map has not loaded"),_("Warning"));
        return;
    }


    m->zoom(0.95);

    mapnik::image_rgba8 im(w,h);           //渲染
    mapnik::agg_renderer<mapnik::image_rgba8> ren(*m, im);
    ren.apply();

    wxMapnik::image_to_wxBitmap(im, bmp);
    ShowBitmap();

}

void mapnik_test_imageFrame::OnButton6Click1(wxCommandEvent& event)
{
    if(!is_load)
    {
        wxMessageBox(_("Map has not loaded"),_("Warning"));
        return;
    }

    m->zoom(1.05);

    mapnik::image_rgba8 im(w,h);           //渲染
    mapnik::agg_renderer<mapnik::image_rgba8> ren(*m, im);
    ren.apply();

    wxMapnik::image_to_wxBitmap(im, bmp);
    ShowBitmap();
}

void mapnik_test_imageFrame::OnButton7Click(wxCommandEvent& event)
{
    if(!is_load)
    {
        wxMessageBox(_("Map has not loaded"),_("Warning"));
        return;
    }

    m->zoom_all();

    mapnik::image_rgba8 im(w,h);           //渲染
    mapnik::agg_renderer<mapnik::image_rgba8> ren(*m, im);
    ren.apply();

    wxMapnik::image_to_wxBitmap(im, bmp);
    ShowBitmap();
}
