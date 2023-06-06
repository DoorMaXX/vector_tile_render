#include "../include/StyleDesignLine.h"

//(*InternalHeaders(StyleDesignLine)
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

//(*IdInit(StyleDesignLine)
const long StyleDesignLine::ID_RADIOBUTTON1 = wxNewId();
const long StyleDesignLine::ID_RADIOBUTTON2 = wxNewId();
const long StyleDesignLine::ID_STATICTEXT1 = wxNewId();
const long StyleDesignLine::ID_STATICTEXT2 = wxNewId();
const long StyleDesignLine::ID_CHOICE1 = wxNewId();
const long StyleDesignLine::ID_CHOICE2 = wxNewId();
const long StyleDesignLine::ID_STATICTEXT3 = wxNewId();
const long StyleDesignLine::ID_TEXTCTRL1 = wxNewId();
const long StyleDesignLine::ID_STATICLINE1 = wxNewId();
const long StyleDesignLine::ID_CHECKBOX1 = wxNewId();
const long StyleDesignLine::ID_STATICTEXT4 = wxNewId();
const long StyleDesignLine::ID_STATICTEXT5 = wxNewId();
const long StyleDesignLine::ID_STATICTEXT6 = wxNewId();
const long StyleDesignLine::ID_STATICTEXT7 = wxNewId();
const long StyleDesignLine::ID_COLOURPICKERCTRL1 = wxNewId();
const long StyleDesignLine::ID_SPINCTRLDOUBLE1 = wxNewId();
const long StyleDesignLine::ID_SPINCTRLDOUBLE2 = wxNewId();
const long StyleDesignLine::ID_CHOICE3 = wxNewId();
const long StyleDesignLine::ID_STATICLINE2 = wxNewId();
const long StyleDesignLine::ID_CHECKBOX2 = wxNewId();
const long StyleDesignLine::ID_STATICTEXT8 = wxNewId();
const long StyleDesignLine::ID_STATICTEXT9 = wxNewId();
const long StyleDesignLine::ID_STATICTEXT10 = wxNewId();
const long StyleDesignLine::ID_STATICTEXT12 = wxNewId();
const long StyleDesignLine::ID_STATICTEXT13 = wxNewId();
const long StyleDesignLine::ID_CHOICE4 = wxNewId();
const long StyleDesignLine::ID_CHOICE5 = wxNewId();
const long StyleDesignLine::ID_SPINCTRLDOUBLE3 = wxNewId();
const long StyleDesignLine::ID_COLOURPICKERCTRL2 = wxNewId();
const long StyleDesignLine::ID_COLOURPICKERCTRL3 = wxNewId();
const long StyleDesignLine::ID_SPINCTRLDOUBLE4 = wxNewId();
const long StyleDesignLine::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(StyleDesignLine,wxDialog)
	//(*EventTable(StyleDesignLine)
	//*)
END_EVENT_TABLE()

StyleDesignLine::StyleDesignLine(mapnik_test_imageFrame* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(StyleDesignLine)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(507,597));
	Move(wxDefaultPosition);
	RadioButton1 = new wxRadioButton(this, ID_RADIOBUTTON1, _("Attribute"), wxPoint(64,32), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
	RadioButton2 = new wxRadioButton(this, ID_RADIOBUTTON2, _("Expression"), wxPoint(288,32), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON2"));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Field:"), wxPoint(16,80), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Value:"), wxPoint(16,128), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	Choice1 = new wxChoice(this, ID_CHOICE1, wxPoint(64,72), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	Choice2 = new wxChoice(this, ID_CHOICE2, wxPoint(64,120), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Expression:"), wxPoint(248,88), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("[field] = value"), wxPoint(336,80), wxSize(128,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxPoint(16,160), wxSize(480,1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
	CheckBox1 = new wxCheckBox(this, ID_CHECKBOX1, _("Line:Line style"), wxPoint(64,184), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	CheckBox1->SetValue(true);
	CheckBox1->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HOTLIGHT));
	CheckBox1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNSHADOW));
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Color:"), wxPoint(32,232), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Width:"), wxPoint(32,280), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("Opacity:"), wxPoint(16,328), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("Line cap:"), wxPoint(16,368), wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	ColourPickerCtrl1 = new wxColourPickerCtrl(this, ID_COLOURPICKERCTRL1, wxColour(0,0,0), wxPoint(88,224), wxDefaultSize, 0, wxDefaultValidator, _T("ID_COLOURPICKERCTRL1"));
	SpinCtrlDouble1 = new wxSpinCtrlDouble(this, ID_SPINCTRLDOUBLE1, _T("1"), wxPoint(88,272), wxSize(136,34), 0, 0, 100, 0, 0.01, _T("ID_SPINCTRLDOUBLE1"));
	SpinCtrlDouble1->SetValue(_T("1"));
	SpinCtrlDouble2 = new wxSpinCtrlDouble(this, ID_SPINCTRLDOUBLE2, _T("1"), wxPoint(88,320), wxSize(136,34), 0, 0, 1, 0, 0.01, _T("ID_SPINCTRLDOUBLE2"));
	SpinCtrlDouble2->SetValue(_T("1"));
	Choice3 = new wxChoice(this, ID_CHOICE3, wxPoint(88,368), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE3"));
	StaticLine2 = new wxStaticLine(this, ID_STATICLINE2, wxPoint(240,168), wxSize(0,344), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
	CheckBox2 = new wxCheckBox(this, ID_CHECKBOX2, _("Label:Text style"), wxPoint(312,184), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
	CheckBox2->SetValue(false);
	CheckBox2->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HOTLIGHT));
	CheckBox2->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNSHADOW));
	StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("Field:"), wxPoint(296,232), wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	StaticText9 = new wxStaticText(this, ID_STATICTEXT9, _("Placement:"), wxPoint(256,280), wxDefaultSize, 0, _T("ID_STATICTEXT9"));
	StaticText10 = new wxStaticText(this, ID_STATICTEXT10, _("Size:"), wxPoint(296,328), wxDefaultSize, 0, _T("ID_STATICTEXT10"));
	StaticText11 = new wxStaticText(this, wxID_ANY, _("Fill Color:"), wxPoint(264,376), wxDefaultSize, 0, _T("wxID_ANY"));
	StaticText12 = new wxStaticText(this, ID_STATICTEXT12, _("Halo Color:"), wxPoint(256,424), wxDefaultSize, 0, _T("ID_STATICTEXT12"));
	StaticText13 = new wxStaticText(this, ID_STATICTEXT13, _("Haro Radius:"), wxPoint(248,472), wxDefaultSize, 0, _T("ID_STATICTEXT13"));
	Choice4 = new wxChoice(this, ID_CHOICE4, wxPoint(344,224), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE4"));
	Choice5 = new wxChoice(this, ID_CHOICE5, wxPoint(344,272), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE5"));
	SpinCtrlDouble3 = new wxSpinCtrlDouble(this, ID_SPINCTRLDOUBLE3, _T("10"), wxPoint(344,320), wxSize(136,34), 0, 0, 100, 0, 0.01, _T("ID_SPINCTRLDOUBLE3"));
	SpinCtrlDouble3->SetValue(_T("10"));
	ColourPickerCtrl2 = new wxColourPickerCtrl(this, ID_COLOURPICKERCTRL2, wxColour(0,0,0), wxPoint(344,368), wxDefaultSize, 0, wxDefaultValidator, _T("ID_COLOURPICKERCTRL2"));
	ColourPickerCtrl3 = new wxColourPickerCtrl(this, ID_COLOURPICKERCTRL3, wxColour(0,0,0), wxPoint(344,416), wxDefaultSize, 0, wxDefaultValidator, _T("ID_COLOURPICKERCTRL3"));
	SpinCtrlDouble4 = new wxSpinCtrlDouble(this, ID_SPINCTRLDOUBLE4, _T("1"), wxPoint(344,464), wxSize(136,34), 0, 0, 100, 0, 0.01, _T("ID_SPINCTRLDOUBLE4"));
	SpinCtrlDouble4->SetValue(_T("1"));
	Button1 = new wxButton(this, ID_BUTTON1, _("Apply"), wxPoint(128,536), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button2 = new wxButton(this, wxID_OK, _("End"), wxPoint(256,536), wxDefaultSize, 0, wxDefaultValidator, _T("wxID_OK"));

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&StyleDesignLine::OnButton1Click);
	//*)
    field_names = &(parent->field_names);
	values = &(parent->values);
	styles_num = &(parent->styles_num);
	styles_information = &(parent->styles_information);

	current_layer = &(parent->current_layer);
    style_line_num = &(parent->style_line_num);
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
    int pos_ = Choice1->GetSelection();
    if(values->size() > pos_)
    {
        for(auto i=(*values)[pos_].begin(); i!=(*values)[pos_].end();i++)
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
    Choice5->Append(_("Vertex"));
    Choice5->SetSelection(0);

    Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&StyleDesignLine::OnChoice1Selected);
}

StyleDesignLine::~StyleDesignLine()
{
	//(*Destroy(StyleDesignLine)
	//*)
}

void StyleDesignLine::OnChoice1Selected(wxCommandEvent& event)
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


void StyleDesignLine::OnButton1Click(wxCommandEvent& event)
{
    bool is_line = CheckBox1->GetValue();
    bool is_text = CheckBox2->GetValue();
    if(!is_line && !is_text)
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

    if(is_line)
    {
        wxColor colour_stroke = ColourPickerCtrl1->GetColour();     //边颜色
        double width_stroke = SpinCtrlDouble1->GetValue();          //边宽度
        double opacity_stroke = SpinCtrlDouble2->GetValue();        //边透明度
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

    if(is_text)
    {
        std::string field_text = std::string(Choice4->GetString(Choice4->GetSelection()).ToUTF8().data());
        int placement_text = Choice5->GetSelection();
        double size_text = SpinCtrlDouble3->GetValue();
        wxColor fillColor_text = ColourPickerCtrl2->GetColour();
        wxColor haloColor_text = ColourPickerCtrl3->GetColour();
        double haloRadius_text = SpinCtrlDouble4->GetValue();

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
                case 1:
                    placement_finder->defaults.expressions.label_placement = enumeration_wrapper(label_placement_enum::VERTEX_PLACEMENT);
                    break;
                case 0:
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
