#include "../include/StyleDesignPoint.h"

//(*InternalHeaders(StyleDesignPoint)
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

//(*IdInit(StyleDesignPoint)
const long StyleDesignPoint::ID_RADIOBUTTON1 = wxNewId();
const long StyleDesignPoint::ID_RADIOBUTTON2 = wxNewId();
const long StyleDesignPoint::ID_STATICTEXT1 = wxNewId();
const long StyleDesignPoint::ID_STATICTEXT2 = wxNewId();
const long StyleDesignPoint::ID_CHOICE1 = wxNewId();
const long StyleDesignPoint::ID_CHOICE2 = wxNewId();
const long StyleDesignPoint::ID_STATICTEXT3 = wxNewId();
const long StyleDesignPoint::ID_TEXTCTRL1 = wxNewId();
const long StyleDesignPoint::ID_CHECKBOX1 = wxNewId();
const long StyleDesignPoint::ID_STATICLINE1 = wxNewId();
const long StyleDesignPoint::ID_STATICTEXT4 = wxNewId();
const long StyleDesignPoint::ID_STATICTEXT5 = wxNewId();
const long StyleDesignPoint::ID_TEXTCTRL2 = wxNewId();
const long StyleDesignPoint::ID_SPINCTRLDOUBLE1 = wxNewId();
const long StyleDesignPoint::ID_BUTTON1 = wxNewId();
const long StyleDesignPoint::ID_CHECKBOX2 = wxNewId();
const long StyleDesignPoint::ID_STATICLINE2 = wxNewId();
const long StyleDesignPoint::ID_BUTTON2 = wxNewId();
const long StyleDesignPoint::ID_CHECKBOX3 = wxNewId();
const long StyleDesignPoint::ID_STATICTEXT6 = wxNewId();
const long StyleDesignPoint::ID_STATICTEXT7 = wxNewId();
const long StyleDesignPoint::ID_STATICTEXT8 = wxNewId();
const long StyleDesignPoint::ID_STATICTEXT9 = wxNewId();
const long StyleDesignPoint::ID_STATICTEXT10 = wxNewId();
const long StyleDesignPoint::ID_STATICTEXT11 = wxNewId();
const long StyleDesignPoint::ID_CHOICE3 = wxNewId();
const long StyleDesignPoint::ID_SPINCTRLDOUBLE2 = wxNewId();
const long StyleDesignPoint::ID_COLOURPICKERCTRL1 = wxNewId();
const long StyleDesignPoint::ID_COLOURPICKERCTRL2 = wxNewId();
const long StyleDesignPoint::ID_SPINCTRLDOUBLE3 = wxNewId();
//*)

BEGIN_EVENT_TABLE(StyleDesignPoint,wxDialog)
	//(*EventTable(StyleDesignPoint)
	//*)
END_EVENT_TABLE()

StyleDesignPoint::StyleDesignPoint(mapnik_test_imageFrame* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(StyleDesignPoint)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(529,536));
	Move(wxDefaultPosition);
	RadioButton1 = new wxRadioButton(this, ID_RADIOBUTTON1, _("Attribute"), wxPoint(64,24), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
	RadioButton2 = new wxRadioButton(this, ID_RADIOBUTTON2, _("Expression"), wxPoint(312,24), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON2"));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Field:"), wxPoint(24,72), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Value:"), wxPoint(24,120), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	Choice1 = new wxChoice(this, ID_CHOICE1, wxPoint(80,64), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	Choice2 = new wxChoice(this, ID_CHOICE2, wxPoint(80,112), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Expression:"), wxPoint(280,88), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("[field] = value"), wxPoint(376,80), wxSize(128,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	CheckBox1 = new wxCheckBox(this, ID_CHECKBOX1, _("Point:Point style"), wxPoint(56,200), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	CheckBox1->SetValue(true);
	CheckBox1->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HOTLIGHT));
	CheckBox1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNSHADOW));
	StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxPoint(24,168), wxSize(464,1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Opacity:"), wxPoint(24,248), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Icon file:"), wxPoint(24,296), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(96,288), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	SpinCtrlDouble1 = new wxSpinCtrlDouble(this, ID_SPINCTRLDOUBLE1, _T("1"), wxPoint(96,240), wxSize(136,34), 0, 0, 1, 0, 0.01, _T("ID_SPINCTRLDOUBLE1"));
	SpinCtrlDouble1->SetValue(_T("1"));
	Button1 = new wxButton(this, ID_BUTTON1, _("..."), wxPoint(200,288), wxSize(40,34), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	CheckBox2 = new wxCheckBox(this, ID_CHECKBOX2, _("Overlap"), wxPoint(24,344), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
	CheckBox2->SetValue(false);
	StaticLine2 = new wxStaticLine(this, ID_STATICLINE2, wxPoint(248,184), wxSize(1,232), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
	Button2 = new wxButton(this, ID_BUTTON2, _("Apply"), wxPoint(120,472), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	Button3 = new wxButton(this, wxID_OK, _("End"), wxPoint(296,472), wxDefaultSize, 0, wxDefaultValidator, _T("wxID_OK"));
	CheckBox3 = new wxCheckBox(this, ID_CHECKBOX3, _("Label:Text style"), wxPoint(328,200), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX3"));
	CheckBox3->SetValue(false);
	CheckBox3->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HOTLIGHT));
	CheckBox3->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNSHADOW));
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("Field:"), wxPoint(288,248), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	StaticText7 = new wxStaticText(this, ID_STATICTEXT7, wxEmptyString, wxPoint(288,272), wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("Size:"), wxPoint(296,296), wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	StaticText9 = new wxStaticText(this, ID_STATICTEXT9, _("Fill Color:"), wxPoint(264,344), wxDefaultSize, 0, _T("ID_STATICTEXT9"));
	StaticText10 = new wxStaticText(this, ID_STATICTEXT10, _("Halo Color:"), wxPoint(256,392), wxDefaultSize, 0, _T("ID_STATICTEXT10"));
	StaticText11 = new wxStaticText(this, ID_STATICTEXT11, _("Halo Radius:"), wxPoint(248,432), wxDefaultSize, 0, _T("ID_STATICTEXT11"));
	Choice3 = new wxChoice(this, ID_CHOICE3, wxPoint(344,240), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE3"));
	SpinCtrlDouble2 = new wxSpinCtrlDouble(this, ID_SPINCTRLDOUBLE2, _T("10"), wxPoint(344,288), wxSize(152,34), 0, 0, 100, 0, 0.01, _T("ID_SPINCTRLDOUBLE2"));
	SpinCtrlDouble2->SetValue(_T("10"));
	ColourPickerCtrl1 = new wxColourPickerCtrl(this, ID_COLOURPICKERCTRL1, wxColour(0,0,0), wxPoint(344,336), wxDefaultSize, 0, wxDefaultValidator, _T("ID_COLOURPICKERCTRL1"));
	ColourPickerCtrl2 = new wxColourPickerCtrl(this, ID_COLOURPICKERCTRL2, wxColour(0,0,0), wxPoint(344,384), wxDefaultSize, 0, wxDefaultValidator, _T("ID_COLOURPICKERCTRL2"));
	SpinCtrlDouble3 = new wxSpinCtrlDouble(this, ID_SPINCTRLDOUBLE3, _T("1"), wxPoint(344,432), wxSize(152,34), 0, 0, 100, 0, 0.01, _T("ID_SPINCTRLDOUBLE3"));
	SpinCtrlDouble3->SetValue(_T("1"));
	FileDialog1 = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, _("BMP, JPEG and PNG files|*.bmp;*.jpeg;*.png"), wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&StyleDesignPoint::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&StyleDesignPoint::OnButton2Click);
	//*)
    field_names = &(parent->field_names);
	values = &(parent->values);
	styles_num = &(parent->styles_num);
	styles_information = &(parent->styles_information);

	current_layer = &(parent->current_layer);
    style_point_num = &(parent->style_line_num);
    style_text_num = &(parent->style_text_num);
	m = parent->m;
	bmp = &(parent->bmp);

    Choice1->Clear();
    for(auto i = field_names->begin(); i != field_names->end(); i++)
    {
        Choice1->Append(wxString::FromUTF8(*i));
        Choice3->Append(wxString::FromUTF8(*i));
    }
    Choice1->SetSelection(0);
    Choice3->SetSelection(0);

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

    Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&StyleDesignPoint::OnChoice1Selected);
}

StyleDesignPoint::~StyleDesignPoint()
{
	//(*Destroy(StyleDesignPoint)
	//*)
}

void StyleDesignPoint::OnChoice1Selected(wxCommandEvent& event)
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

void StyleDesignPoint::OnButton2Click(wxCommandEvent& event)
{
    bool is_point = CheckBox1->GetValue();
    bool is_text = CheckBox3->GetValue();
    if(!is_point && !is_text)
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

    if(is_point)      //若需要添加点样式
    {
        double opacity_center = SpinCtrlDouble1->GetValue();        //中心点透明度
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

        auto style_point = std::make_shared<wxMapnik::style_information_point>(sp.str(), s, "point", icon_file, opacity_center, overlap_dot);
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
        std::string field_text = std::string(Choice3->GetString(Choice3->GetSelection()).ToUTF8().data());
        double size_text = SpinCtrlDouble2->GetValue();
        wxColor fillColor_text = ColourPickerCtrl1->GetColour();
        wxColor haloColor_text = ColourPickerCtrl2->GetColour();
        double haloRadius_text = SpinCtrlDouble3->GetValue();

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
                placement_finder->defaults.expressions.label_placement = enumeration_wrapper(label_placement_enum::POINT_PLACEMENT);
                placement_finder->defaults.format_defaults.face_name = "DejaVu Sans Book";
                placement_finder->defaults.format_defaults.text_size = size_text;
                placement_finder->defaults.format_defaults.fill = color(fillColor_text.Red(), fillColor_text.Green(), fillColor_text.Blue());
                placement_finder->defaults.format_defaults.halo_fill = color(haloColor_text.Red(), haloColor_text.Green(), haloColor_text.Blue());
                placement_finder->defaults.format_defaults.halo_radius = haloRadius_text;
                placement_finder->defaults.set_format_tree(std::make_shared<mapnik::formatting::text_node>(parse_expression(s_)));
                put<text_placements_ptr>(text_sym, keys::text_placements_, placement_finder);
                put(text_sym, keys::allow_overlap, true);
                r.append(std::move(text_sym));
            }
            text_style.add_rule(std::move(r));
        }

        ++(*style_text_num);

        std::stringstream st;
        st<<"text_"<<*style_text_num;
        m->insert_style(st.str(),std::move(text_style));

        auto style_text = std::make_shared<wxMapnik::style_information_text>(st.str(), s, "Point label", field_text, 2, size_text, fillColor_text, haloColor_text, haloRadius_text);
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

void StyleDesignPoint::OnButton1Click(wxCommandEvent& event)
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
