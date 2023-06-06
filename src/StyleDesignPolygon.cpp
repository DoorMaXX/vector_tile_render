#include "../include/StyleDesignPolygon.h"
#include <boost/algorithm/algorithm.hpp>
#include <wx/msgdlg.h>

//(*InternalHeaders(StyleDesignPolygon)
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

//(*IdInit(StyleDesignPolygon)
const long StyleDesignPolygon::ID_CHOICE1 = wxNewId();
const long StyleDesignPolygon::ID_CHOICE2 = wxNewId();
const long StyleDesignPolygon::ID_STATICTEXT1 = wxNewId();
const long StyleDesignPolygon::ID_STATICTEXT2 = wxNewId();
const long StyleDesignPolygon::ID_COLOURPICKERCTRL1 = wxNewId();
const long StyleDesignPolygon::ID_STATICTEXT3 = wxNewId();
const long StyleDesignPolygon::ID_STATICLINE1 = wxNewId();
const long StyleDesignPolygon::ID_STATICTEXT4 = wxNewId();
const long StyleDesignPolygon::ID_STATICTEXT5 = wxNewId();
const long StyleDesignPolygon::ID_STATICTEXT6 = wxNewId();
const long StyleDesignPolygon::ID_COLOURPICKERCTRL2 = wxNewId();
const long StyleDesignPolygon::ID_SPINCTRLDOUBLE1 = wxNewId();
const long StyleDesignPolygon::ID_SPINCTRLDOUBLE2 = wxNewId();
const long StyleDesignPolygon::ID_RADIOBUTTON1 = wxNewId();
const long StyleDesignPolygon::ID_BUTTON1 = wxNewId();
const long StyleDesignPolygon::ID_RADIOBUTTON2 = wxNewId();
const long StyleDesignPolygon::ID_TEXTCTRL1 = wxNewId();
const long StyleDesignPolygon::ID_STATICLINE2 = wxNewId();
const long StyleDesignPolygon::ID_STATICTEXT10 = wxNewId();
const long StyleDesignPolygon::ID_SPINCTRLDOUBLE3 = wxNewId();
const long StyleDesignPolygon::ID_STATICLINE3 = wxNewId();
const long StyleDesignPolygon::ID_STATICTEXT14 = wxNewId();
const long StyleDesignPolygon::ID_SPINCTRLDOUBLE5 = wxNewId();
const long StyleDesignPolygon::ID_STATICTEXT15 = wxNewId();
const long StyleDesignPolygon::ID_CHOICE3 = wxNewId();
const long StyleDesignPolygon::ID_CHECKBOX1 = wxNewId();
const long StyleDesignPolygon::ID_TEXTCTRL2 = wxNewId();
const long StyleDesignPolygon::ID_BUTTON2 = wxNewId();
const long StyleDesignPolygon::ID_CHECKBOX2 = wxNewId();
const long StyleDesignPolygon::ID_CHECKBOX3 = wxNewId();
const long StyleDesignPolygon::ID_CHECKBOX4 = wxNewId();
const long StyleDesignPolygon::ID_CHOICE4 = wxNewId();
const long StyleDesignPolygon::ID_CHOICE5 = wxNewId();
const long StyleDesignPolygon::ID_CHECKBOX5 = wxNewId();
const long StyleDesignPolygon::ID_STATICLINE4 = wxNewId();
const long StyleDesignPolygon::ID_STATICTEXT11 = wxNewId();
const long StyleDesignPolygon::ID_SPINCTRLDOUBLE4 = wxNewId();
const long StyleDesignPolygon::ID_COLOURPICKERCTRL3 = wxNewId();
const long StyleDesignPolygon::ID_COLOURPICKERCTRL4 = wxNewId();
const long StyleDesignPolygon::ID_STATICTEXT8 = wxNewId();
const long StyleDesignPolygon::ID_SPINCTRLDOUBLE6 = wxNewId();
//*)

BEGIN_EVENT_TABLE(StyleDesignPolygon,wxDialog)
	//(*EventTable(StyleDesignPolygon)
	//*)
END_EVENT_TABLE()

StyleDesignPolygon::StyleDesignPolygon(mapnik_test_imageFrame* parent,wxWindowID id)
{
	//(*Initialize(StyleDesignPolygon)
	wxStaticText* StaticText8;

	Create(parent, wxID_ANY, _("Polygon Style Designer"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(1178,458));
	Choice1 = new wxChoice(this, ID_CHOICE1, wxPoint(80,56), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	Choice2 = new wxChoice(this, ID_CHOICE2, wxPoint(80,96), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Field:"), wxPoint(24,64), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Value:"), wxPoint(24,104), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	ColourPickerCtrl1 = new wxColourPickerCtrl(this, ID_COLOURPICKERCTRL1, wxColour(0,0,0), wxPoint(88,192), wxDefaultSize, 0, wxDefaultValidator, _T("ID_COLOURPICKERCTRL1"));
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Color:"), wxPoint(32,200), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxPoint(16,135), wxSize(744,2), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Width:"), wxPoint(300,248), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Opacity:"), wxPoint(16,248), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("Color:"), wxPoint(304,200), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	ColourPickerCtrl2 = new wxColourPickerCtrl(this, ID_COLOURPICKERCTRL2, wxColour(0,0,0), wxPoint(360,192), wxDefaultSize, 0, wxDefaultValidator, _T("ID_COLOURPICKERCTRL2"));
	SpinCtrlDouble1 = new wxSpinCtrlDouble(this, ID_SPINCTRLDOUBLE1, _T("1"), wxPoint(88,240), wxSize(136,34), 0, 0, 1, 0, 0.01, _T("ID_SPINCTRLDOUBLE1"));
	SpinCtrlDouble1->SetValue(_T("1"));
	SpinCtrlDouble2 = new wxSpinCtrlDouble(this, ID_SPINCTRLDOUBLE2, _T("1"), wxPoint(360,240), wxSize(136,34), 0, 0, 100, 0, 0.01, _T("ID_SPINCTRLDOUBLE2"));
	SpinCtrlDouble2->SetValue(_T("1"));
	RadioButton1 = new wxRadioButton(this, ID_RADIOBUTTON1, _("Attribute"), wxPoint(72,16), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
	RadioButton1->SetValue(true);
	Button1 = new wxButton(this, ID_BUTTON1, _("Apply"), wxPoint(496,392), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button2 = new wxButton(this, wxID_OK, _("End"), wxPoint(648,392), wxDefaultSize, 0, wxDefaultValidator, _T("wxID_OK"));
	RadioButton2 = new wxRadioButton(this, ID_RADIOBUTTON2, _("Expression"), wxPoint(352,16), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON2"));
	StaticText7 = new wxStaticText(this, wxID_ANY, _("Expression"), wxPoint(304,80), wxDefaultSize, 0, _T("wxID_ANY"));
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("[field] = value"), wxPoint(392,72), wxSize(144,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	StaticLine2 = new wxStaticLine(this, ID_STATICLINE2, wxPoint(248,160), wxSize(1,208), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
	StaticText10 = new wxStaticText(this, ID_STATICTEXT10, _("Opacity:"), wxPoint(288,296), wxDefaultSize, 0, _T("ID_STATICTEXT10"));
	SpinCtrlDouble3 = new wxSpinCtrlDouble(this, ID_SPINCTRLDOUBLE3, _T("1"), wxPoint(360,288), wxSize(136,34), 0, 0, 1, 0, 0.01, _T("ID_SPINCTRLDOUBLE3"));
	SpinCtrlDouble3->SetValue(_T("1"));
	StaticLine3 = new wxStaticLine(this, ID_STATICLINE3, wxPoint(520,160), wxSize(1,208), wxLI_HORIZONTAL, _T("ID_STATICLINE3"));
	StaticText14 = new wxStaticText(this, ID_STATICTEXT14, _("Opacity:"), wxPoint(552,200), wxDefaultSize, 0, _T("ID_STATICTEXT14"));
	SpinCtrlDouble4 = new wxSpinCtrlDouble(this, ID_SPINCTRLDOUBLE5, _T("1"), wxPoint(624,192), wxSize(136,34), 0, 0, 1, 0, 0.01, _T("ID_SPINCTRLDOUBLE5"));
	SpinCtrlDouble4->SetValue(_T("1"));
	SpinCtrlDouble4->Disable();
	StaticText15 = new wxStaticText(this, ID_STATICTEXT15, _("Line cap:"), wxPoint(288,344), wxDefaultSize, 0, _T("ID_STATICTEXT15"));
	Choice3 = new wxChoice(this, ID_CHOICE3, wxPoint(360,336), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE3"));
	CheckBox1 = new wxCheckBox(this, ID_CHECKBOX1, _("Center:Point style"), wxPoint(576,152), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	CheckBox1->SetValue(false);
	CheckBox1->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HOTLIGHT));
	CheckBox1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNSHADOW));
	StaticText11 = new wxStaticText(this, wxID_ANY, _("Icon file:"), wxPoint(552,248), wxDefaultSize, 0, _T("wxID_ANY"));
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(624,240), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	TextCtrl2->Disable();
	Button3 = new wxButton(this, ID_BUTTON2, _("..."), wxPoint(728,240), wxSize(48,34), 0, wxDefaultValidator, _T("ID_BUTTON2"));
	Button3->Disable();
	CheckBox2 = new wxCheckBox(this, ID_CHECKBOX2, _("Overlap"), wxPoint(552,296), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
	CheckBox2->SetValue(false);
	CheckBox2->Disable();
	CheckBox3 = new wxCheckBox(this, ID_CHECKBOX3, _("Edge:Line style"), wxPoint(312,152), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX3"));
	CheckBox3->SetValue(true);
	CheckBox3->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HOTLIGHT));
	CheckBox3->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNSHADOW));
	CheckBox4 = new wxCheckBox(this, ID_CHECKBOX4, _("Fill:Polygon style"), wxPoint(48,152), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX4"));
	CheckBox4->SetValue(true);
	CheckBox4->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HOTLIGHT));
	CheckBox4->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNSHADOW));
	Choice4 = new wxChoice(this, ID_CHOICE4, wxPoint(912,72), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE4"));
	Choice4->Disable();
	Choice5 = new wxChoice(this, ID_CHOICE5, wxPoint(912,120), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE5"));
	Choice5->Disable();
	CheckBox5 = new wxCheckBox(this, ID_CHECKBOX5, _("Label:Text style"), wxPoint(856,32), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX5"));
	CheckBox5->SetValue(false);
	CheckBox5->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HOTLIGHT));
	CheckBox5->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNSHADOW));
	StaticLine4 = new wxStaticLine(this, ID_STATICLINE4, wxPoint(800,40), wxSize(1,328), wxLI_HORIZONTAL, _T("ID_STATICLINE4"));
	StaticText8 = new wxStaticText(this, wxID_ANY, _("Field:"), wxPoint(856,80), wxDefaultSize, 0, _T("wxID_ANY"));
	StaticText9 = new wxStaticText(this, wxID_ANY, _("Placement:"), wxPoint(824,128), wxDefaultSize, 0, _T("wxID_ANY"));
	StaticText12 = new wxStaticText(this, ID_STATICTEXT11, _("Size:"), wxPoint(864,176), wxDefaultSize, 0, _T("ID_STATICTEXT11"));
	StaticText13 = new wxStaticText(this, wxID_ANY, _("Fill Color:"), wxPoint(832,224), wxDefaultSize, 0, _T("wxID_ANY"));
	StaticText16 = new wxStaticText(this, wxID_ANY, _("Halo Color:"), wxPoint(824,272), wxDefaultSize, 0, _T("wxID_ANY"));
	SpinCtrlDouble5 = new wxSpinCtrlDouble(this, ID_SPINCTRLDOUBLE4, _T("10"), wxPoint(912,168), wxSize(136,34), 0, 0, 100, 0, 0.01, _T("ID_SPINCTRLDOUBLE4"));
	SpinCtrlDouble5->SetValue(_T("10"));
	SpinCtrlDouble5->Disable();
	ColourPickerCtrl3 = new wxColourPickerCtrl(this, ID_COLOURPICKERCTRL3, wxColour(0,0,0), wxPoint(912,216), wxDefaultSize, 0, wxDefaultValidator, _T("ID_COLOURPICKERCTRL3"));
	ColourPickerCtrl3->Disable();
	ColourPickerCtrl4 = new wxColourPickerCtrl(this, ID_COLOURPICKERCTRL4, wxColour(0,0,0), wxPoint(912,264), wxDefaultSize, 0, wxDefaultValidator, _T("ID_COLOURPICKERCTRL4"));
	ColourPickerCtrl4->Disable();
	StaticText17 = new wxStaticText(this, ID_STATICTEXT8, _("Halo Radius:"), wxPoint(816,320), wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	SpinCtrlDouble6 = new wxSpinCtrlDouble(this, ID_SPINCTRLDOUBLE6, _T("1"), wxPoint(912,312), wxSize(136,34), 0, 0, 100, 0, 0.01, _T("ID_SPINCTRLDOUBLE6"));
	SpinCtrlDouble6->SetValue(_T("1"));
	SpinCtrlDouble6->Disable();
	FileDialog1 = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, _("BMP, JPEG and PNG files|*.bmp;*.jpeg;*.png"), wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));

	Connect(ID_RADIOBUTTON1,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&StyleDesignPolygon::OnRadioButton1Select);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&StyleDesignPolygon::OnButton1Click);
	Connect(ID_RADIOBUTTON2,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&StyleDesignPolygon::OnRadioButton2Select);
	Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&StyleDesignPolygon::OnCheckBox1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&StyleDesignPolygon::OnButton3Click);
	Connect(ID_CHECKBOX3,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&StyleDesignPolygon::OnCheckBox3Click);
	Connect(ID_CHECKBOX4,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&StyleDesignPolygon::OnCheckBox4Click);
	Connect(ID_CHECKBOX5,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&StyleDesignPolygon::OnCheckBox5Click);
	Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&StyleDesignPolygon::OnInit);
	//*)
	//field_names.assign(parent->field_names.begin(),parent->field_names.end());
	//values.assign(parent->values.begin(), parent->values.end());
	field_names = &(parent->field_names);
	values = &(parent->values);
	styles_num = &(parent->styles_num);
	styles_information = &(parent->styles_information);

	current_layer = &(parent->current_layer);
    style_polygon_num = &(parent->style_polygon_num);
    style_line_num = &(parent->style_line_num);
    style_point_num = &(parent->style_point_num);
    style_text_num = &(parent->style_text_num);
	m = parent->m;
	bmp = &(parent->bmp);

	Choice1->Clear();
    for(auto i = field_names->begin(); i != field_names->end(); i++)
    {
        Choice1->Append(wxString::FromUTF8(*i));
    }
    Choice1->SetSelection(0);

    Choice2->Clear();
    Choice2->Append(_("ALL"));
    int pos = Choice1->GetSelection();
    if(values->size() > pos)
    {
        for(auto i=(*values)[pos].begin(); i!=(*values)[pos].end();i++)
        {
            Choice2->Append(wxString::FromUTF8(*i));
        }
    }
    Choice2->SetSelection(0);

    Choice3->Clear();
    Choice3->Append(_("Button cap"));
    Choice3->Append(_("Square cap"));
    Choice3->Append(_("Round cap"));

    Choice3->SetSelection(0);

    Choice4->Clear();
    for(auto i = field_names->begin(); i != field_names->end(); i++)
    {
        Choice4->Append(wxString::FromUTF8(*i));
    }
    Choice4->SetSelection(0);

    Choice5->Clear();
    Choice5->Append(_("Default"));
    Choice5->Append(_("Interior"));
    Choice5->Append(_("Centroid"));
    Choice5->Append(_("Vertex"));
    Choice5->Append(_("Edge"));
    Choice5->SetSelection(0);

	Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&StyleDesignPolygon::OnChoice1Selected);
}

StyleDesignPolygon::~StyleDesignPolygon()
{
	//(*Destroy(StyleDesignPolygon)
	//*)
}

void StyleDesignPolygon::OnChoice1Selected(wxCommandEvent& event)
{
    Choice2->Clear();
    Choice2->Append(_("ALL"));
    int pos = Choice1->GetSelection();
    for(auto i=(*values)[pos].begin(); i!=(*values)[pos].end();i++)
    {
        Choice2->Append(wxString::FromUTF8(*i));
    }
    Choice2->SetSelection(0);
}


void StyleDesignPolygon::OnButton1Click(wxCommandEvent& event)
{
    bool is_polygon = CheckBox4->GetValue();
    bool is_line = CheckBox3->GetValue();
    bool is_point = CheckBox1->GetValue();
    bool is_text = CheckBox5->GetValue();
    if(!is_polygon && !is_line && !is_point && !is_text)
    {
        return;
    }
    using namespace mapnik;

    std::string field_name = std::string(Choice1->GetString(Choice1->GetSelection()).ToUTF8().data());  //获取字段
    std::string value = std::string(Choice2->GetString(Choice2->GetSelection()).ToUTF8().data());       //获取属性值

    bool is_all = boost::algorithm::starts_with(value, "ALL");

    //得到过滤器的表达式
    std::string s;
    if(RadioButton1->GetValue())
    {
        if(is_all)
        {
            s = "ALL";
        }
        else
        {
            std::stringstream ss;
            if(wxMapnik::have_Chinese(value.data()))
            {
                ss<<"["<<field_name<<"] = '"<<value<<"'";
            }
            else
            {
                ss<<"["<<field_name<<"] = "<<value<<"";
            }
            s = ss.str();
        }
    }
    else if(RadioButton2->GetValue())
    {
        wxString ws = TextCtrl1->GetValue();

        s = std::string(TextCtrl1->GetValue().ToUTF8().data());
    }
    else
    {
        wxMessageBox(_("features are not selected"),_("warning"));
        return;
    }

    layer& lyr = m->get_layer(*current_layer);            //获取图层样式
    std::vector<std::string>& styles = lyr.styles();
    if(styles.size() != (*styles_num)[*current_layer][0]+(*styles_num)[*current_layer][1]+(*styles_num)[*current_layer][2]+(*styles_num)[*current_layer][3])
    {
        wxMessageBox(_("Data confusion !"),_("Error"));
        return;
    }


    if(is_polygon)
    {
        wxColor colour_fill = ColourPickerCtrl1->GetColour();       //面填充色
        double opacity_fill = SpinCtrlDouble1->GetValue();          //面透明度

        feature_type_style polygon_style;        //编写样式
        {
            rule r;
            if((RadioButton1->GetValue() && !is_all)||RadioButton2->GetValue())
            {
                r.set_filter(parse_expression(s));
            }
            {
                polygon_symbolizer polygon_sym;
                put(polygon_sym, keys::fill, color(colour_fill.Red(),colour_fill.Green(),colour_fill.Blue()));
                put(polygon_sym, keys::fill_opacity, opacity_fill);
                put(polygon_sym, keys::clip, true);
                r.append(std::move(polygon_sym));
            }
            polygon_style.add_rule(std::move(r));
        }

        ++(*style_polygon_num);  //样式添加到地图中
        std::stringstream sy;
        sy<<"polygon_"<<*style_polygon_num;
        m->insert_style(sy.str(),std::move(polygon_style));

        auto style_polygon = std::make_shared<wxMapnik::style_information_polygon>(sy.str(), s, "polygon fill", colour_fill, opacity_fill);
        styles_information->insert(std::make_pair(sy.str(),style_polygon));

        int style_num_0 = (*styles_num)[*current_layer][0]++;
        if(style_num_0 == styles.size())
        {
            styles.push_back(sy.str());
        }
        else if(style_num_0 < styles.size())
        {
            styles.insert(styles.begin()+style_num_0, sy.str());
        }

    }

    if(is_line)
    {
        wxColor colour_stroke = ColourPickerCtrl2->GetColour();     //边颜色
        double width_stroke = SpinCtrlDouble2->GetValue();          //边宽度
        double opacity_stroke = SpinCtrlDouble3->GetValue();        //边透明度
        int linecap_stroke = Choice3->GetSelection();               //边线帽类型

        feature_type_style line_style;
        {
            rule r;
            if((RadioButton1->GetValue() && !is_all)||RadioButton2->GetValue())
            {
                r.set_filter(parse_expression(s));
            }
            {
                line_symbolizer line_sym;
                put(line_sym, keys::stroke, color(colour_stroke.Red(),colour_stroke.Green(),colour_stroke.Blue()));
                put(line_sym, keys::stroke_width, width_stroke);
                put(line_sym, keys::stroke_opacity, opacity_stroke);
                switch(linecap_stroke)
                {
                case 0:
                    put(line_sym, keys::stroke_linecap, line_cap_enum::BUTT_CAP);
                    break;
                case 1:
                    put(line_sym, keys::stroke_linecap, line_cap_enum::SQUARE_CAP);
                    break;
                case 2:
                    put(line_sym, keys::stroke_linecap, line_cap_enum::ROUND_CAP);
                    break;
                }
                r.append(std::move(line_sym));
            }
            line_style.add_rule(std::move(r));
        }

        ++(*style_line_num);
        std::stringstream sl;
        sl<<"line_"<<*style_line_num;
        m->insert_style(sl.str(),std::move(line_style));

        auto style_line = std::make_shared<wxMapnik::style_information_line>(sl.str(), s, "polygon edge", colour_stroke, width_stroke, opacity_stroke, linecap_stroke);
        styles_information->insert(std::make_pair(sl.str(), style_line));

        int style_num_0_1 = (*styles_num)[*current_layer][0]+(*styles_num)[*current_layer][1]++;
        if(style_num_0_1 == styles.size())
        {
            styles.push_back(sl.str());
        }
        else if(style_num_0_1 < styles.size())
        {
            styles.insert(styles.begin()+style_num_0_1, sl.str());
        }
    }

    if(is_point)      //若需要添加点样式
    {
        double opacity_center = SpinCtrlDouble4->GetValue();        //中心点透明度
        std::string icon_file = std::string(TextCtrl2->GetValue().ToUTF8().data());
        bool overlap_dot = CheckBox2->GetValue();

        feature_type_style point_style;
        {
            rule r;
            if((RadioButton1->GetValue() && !is_all)||RadioButton2->GetValue())
            {
                r.set_filter(parse_expression(s));
            }
            {
                point_symbolizer point_sym;
                put(point_sym, keys::file, icon_file);
                put(point_sym, keys::allow_overlap, overlap_dot);
                put(point_sym, keys::ignore_placement, true);
                put(point_sym, keys::opacity, opacity_center);
                r.append(std::move(point_sym));
            }
            point_style.add_rule(std::move(r));
        }
        ++(*style_point_num);

        std::stringstream sp;
        sp<<"point_"<<*style_point_num;
        m->insert_style(sp.str(),std::move(point_style));

        auto style_point = std::make_shared<wxMapnik::style_information_point>(sp.str(), s, "point in polygon", icon_file, opacity_center, overlap_dot);
        styles_information->insert(std::make_pair(sp.str(), style_point));

        int style_num_0_1_2 = (*styles_num)[*current_layer][0]+(*styles_num)[*current_layer][1]+(*styles_num)[*current_layer][2]++;
        if(style_num_0_1_2 == styles.size())
        {
            styles.push_back(sp.str());
        }
        else if(style_num_0_1_2 < styles.size())
        {
            styles.insert(styles.begin()+style_num_0_1_2, sp.str());
        }
    }

    if(is_text)
    {
        std::string field_text = std::string(Choice4->GetString(Choice4->GetSelection()).ToUTF8().data());
        int placement_text = Choice5->GetSelection();
        double size_text = SpinCtrlDouble5->GetValue();
        wxColor fillColor_text = ColourPickerCtrl3->GetColour();
        wxColor haloColor_text = ColourPickerCtrl4->GetColour();
        double haloRadius_text = SpinCtrlDouble6->GetValue();

        std::stringstream ss_;
        ss_<<"["<<field_text<<"]";
        std::string s_ = ss_.str();

        //freetype_engine::register_font("/usr/local/lib/mapnik/fonts/DejaVuSans.ttf");
        feature_type_style text_style;
        {
            rule r;
            {
                if((RadioButton1->GetValue() && !is_all)||RadioButton2->GetValue())
                {
                    r.set_filter(parse_expression(s));
                }
                text_symbolizer text_sym;
                text_placements_ptr placement_finder = std::make_shared<text_placements_dummy>();
                switch(placement_text)
                {
                case 0:
                    placement_finder->defaults.expressions.label_placement = enumeration_wrapper(label_placement_enum::POLYLABEL_PLACEMENT);
                    break;
                case 1:
                    placement_finder->defaults.expressions.label_placement = enumeration_wrapper(label_placement_enum::INTERIOR_PLACEMENT);
                    break;
                case 2:
                    placement_finder->defaults.expressions.label_placement = enumeration_wrapper(label_placement_enum::POINT_PLACEMENT);
                    break;
                case 3:
                    placement_finder->defaults.expressions.label_placement = enumeration_wrapper(label_placement_enum::VERTEX_PLACEMENT);
                    break;
                case 4:
                    placement_finder->defaults.expressions.label_placement = enumeration_wrapper(label_placement_enum::LINE_PLACEMENT);
                    break;
                }
                placement_finder->defaults.format_defaults.face_name = "DejaVu Sans Book";
                placement_finder->defaults.format_defaults.text_size = size_text;
                placement_finder->defaults.format_defaults.fill = color(fillColor_text.Red(), fillColor_text.Green(), fillColor_text.Blue());
                placement_finder->defaults.format_defaults.halo_fill = color(haloColor_text.Red(), haloColor_text.Green(), haloColor_text.Blue());
                placement_finder->defaults.format_defaults.halo_radius = haloRadius_text;
                placement_finder->defaults.set_format_tree(std::make_shared<mapnik::formatting::text_node>(parse_expression(s_)));
                put<text_placements_ptr>(text_sym, keys::text_placements_, placement_finder);
                r.append(std::move(text_sym));
            }
            text_style.add_rule(std::move(r));
        }

        ++(*style_text_num);

        std::stringstream st;
        st<<"text_"<<*style_text_num;
        m->insert_style(st.str(),std::move(text_style));

        auto style_text = std::make_shared<wxMapnik::style_information_text>(st.str(), s, "Polygon label", field_text, placement_text, size_text, fillColor_text, haloColor_text, haloRadius_text);
        styles_information->insert(std::make_pair(st.str(), style_text));

        (*styles_num)[*current_layer][3]++;
        styles.push_back(st.str());
    }

    mapnik::image_rgba8 im(m->width(), m->height());           //渲染
    mapnik::agg_renderer<mapnik::image_rgba8> ren(*m, im);
    ren.apply();
    //mapnik::save_to_file(im, "the_image_1.png");

    wxMapnik::image_to_wxBitmap(im, *bmp);


}

void StyleDesignPolygon::OnRadioButton2Select(wxCommandEvent& event)
{
}

void StyleDesignPolygon::OnRadioButton1Select(wxCommandEvent& event)
{
    Choice1->Clear();
    for(auto i = field_names->begin(); i != field_names->end(); i++)
    {
        Choice1->Append(wxString::FromUTF8(*i));
    }
    Choice1->SetSelection(0);
    Choice2->Clear();
    Choice2->Append(_("ALL"));
    int pos = Choice1->GetSelection();
    for(auto i=(*values)[pos].begin(); i!=(*values)[pos].end();i++)
    {
        Choice2->Append(wxString::FromUTF8(*i));
    }
    Choice2->SetSelection(0);
}

void StyleDesignPolygon::OnInit(wxInitDialogEvent& event)
{
}

void StyleDesignPolygon::OnCheckBox1Click(wxCommandEvent& event)
{
    if(CheckBox1->GetValue())
    {
        SpinCtrlDouble4->Enable(true);
        TextCtrl2->Enable(true);
        Button3->Enable(true);
        CheckBox2->Enable(true);
    }
    else
    {
        SpinCtrlDouble4->Enable(false);
        TextCtrl2->Enable(false);
        Button3->Enable(false);
        CheckBox2->Enable(false);
    }
}

void StyleDesignPolygon::OnButton3Click(wxCommandEvent& event)
{
    if(!(CheckBox1->GetValue()))
    {
        return;
    }
    int dlg = FileDialog1->ShowModal();
    if(dlg == wxID_OK)
    {
        TextCtrl2->SetValue(FileDialog1->GetPath());
    }
}

void StyleDesignPolygon::OnCheckBox4Click(wxCommandEvent& event)
{
    if(CheckBox4->GetValue())
    {
        ColourPickerCtrl1->Enable(true);
        SpinCtrlDouble1->Enable(true);
    }
    else
    {
        ColourPickerCtrl1->Enable(false);
        SpinCtrlDouble1->Enable(false);
    }
}

void StyleDesignPolygon::OnCheckBox3Click(wxCommandEvent& event)
{
    if(CheckBox3->GetValue())
    {
        ColourPickerCtrl2->Enable(true);
        SpinCtrlDouble2->Enable(true);
        SpinCtrlDouble3->Enable(true);
        Choice3->Enable(true);
    }
    else
    {
        ColourPickerCtrl2->Enable(false);
        SpinCtrlDouble2->Enable(false);
        SpinCtrlDouble3->Enable(false);
        Choice3->Enable(false);
    }
}

void StyleDesignPolygon::OnCheckBox5Click(wxCommandEvent& event)
{
    if(CheckBox5->GetValue())
    {
        Choice4->Enable(true);
        Choice5->Enable(true);
        SpinCtrlDouble5->Enable(true);
        SpinCtrlDouble6->Enable(true);
        ColourPickerCtrl3->Enable(true);
        ColourPickerCtrl4->Enable(true);
    }
    else
    {
        Choice4->Enable(false);
        Choice5->Enable(false);
        SpinCtrlDouble5->Enable(false);
        SpinCtrlDouble6->Enable(false);
        ColourPickerCtrl3->Enable(false);
        ColourPickerCtrl4->Enable(false);
    }
}
