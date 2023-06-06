#include "../include/StyleInfoText.h"

//(*InternalHeaders(StyleInfoText)
#include <wx/intl.h>
#include <wx/string.h>
//*)
#include <wx/msgdlg.h>

//(*IdInit(StyleInfoText)
const long StyleInfoText::ID_STATICTEXT1 = wxNewId();
const long StyleInfoText::ID_STATICTEXT2 = wxNewId();
const long StyleInfoText::ID_STATICTEXT3 = wxNewId();
const long StyleInfoText::ID_STATICTEXT4 = wxNewId();
const long StyleInfoText::ID_STATICTEXT5 = wxNewId();
const long StyleInfoText::ID_STATICTEXT6 = wxNewId();
const long StyleInfoText::ID_STATICTEXT7 = wxNewId();
const long StyleInfoText::ID_STATICTEXT8 = wxNewId();
const long StyleInfoText::ID_STATICTEXT9 = wxNewId();
const long StyleInfoText::ID_STATICTEXT10 = wxNewId();
const long StyleInfoText::ID_CHECKBOX1 = wxNewId();
const long StyleInfoText::ID_STATICTEXT11 = wxNewId();
const long StyleInfoText::ID_STATICTEXT12 = wxNewId();
const long StyleInfoText::ID_CHOICE1 = wxNewId();
const long StyleInfoText::ID_CHOICE2 = wxNewId();
const long StyleInfoText::ID_SPINCTRLDOUBLE1 = wxNewId();
const long StyleInfoText::ID_COLOURPICKERCTRL1 = wxNewId();
const long StyleInfoText::ID_COLOURPICKERCTRL2 = wxNewId();
const long StyleInfoText::ID_SPINCTRLDOUBLE2 = wxNewId();
const long StyleInfoText::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(StyleInfoText,wxDialog)
	//(*EventTable(StyleInfoText)
	//*)
END_EVENT_TABLE()

StyleInfoText::StyleInfoText(mapnik_test_imageFrame* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(StyleInfoText)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(270,532));
	Move(wxDefaultPosition);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Name:"), wxPoint(56,48), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Expression:"), wxPoint(24,96), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Target:"), wxPoint(48,144), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Field:"), wxPoint(56,192), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Placement:"), wxPoint(24,240), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("Size:"), wxPoint(56,288), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("Fill Color:"), wxPoint(32,336), wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("Halo Color:"), wxPoint(24,384), wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	StaticText9 = new wxStaticText(this, ID_STATICTEXT9, _("Halo Radius:"), wxPoint(16,432), wxDefaultSize, 0, _T("ID_STATICTEXT9"));
	name_text = new wxStaticText(this, ID_STATICTEXT10, _("Unknown"), wxPoint(120,48), wxDefaultSize, 0, _T("ID_STATICTEXT10"));
	CheckBox1 = new wxCheckBox(this, ID_CHECKBOX1, _("Editable"), wxPoint(176,16), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	CheckBox1->SetValue(false);
	expression_text = new wxStaticText(this, ID_STATICTEXT11, _("Unknown"), wxPoint(120,96), wxDefaultSize, 0, _T("ID_STATICTEXT11"));
	target_text = new wxStaticText(this, ID_STATICTEXT12, _("Unknown"), wxPoint(120,144), wxDefaultSize, 0, _T("ID_STATICTEXT12"));
	field_choice = new wxChoice(this, ID_CHOICE1, wxPoint(112,184), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	field_choice->Disable();
	placement_choice = new wxChoice(this, ID_CHOICE2, wxPoint(112,232), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
	placement_choice->Disable();
	size_double = new wxSpinCtrlDouble(this, ID_SPINCTRLDOUBLE1, _T("0"), wxPoint(112,280), wxSize(136,34), 0, 0, 100, 0, 0.01, _T("ID_SPINCTRLDOUBLE1"));
	size_double->SetValue(_T("0"));
	size_double->Disable();
	ColourPickerCtrl1 = new wxColourPickerCtrl(this, ID_COLOURPICKERCTRL1, wxColour(0,0,0), wxPoint(112,328), wxDefaultSize, 0, wxDefaultValidator, _T("ID_COLOURPICKERCTRL1"));
	ColourPickerCtrl1->Disable();
	ColourPickerCtrl2 = new wxColourPickerCtrl(this, ID_COLOURPICKERCTRL2, wxColour(0,0,0), wxPoint(112,376), wxDefaultSize, 0, wxDefaultValidator, _T("ID_COLOURPICKERCTRL2"));
	ColourPickerCtrl2->Disable();
	hradius_double = new wxSpinCtrlDouble(this, ID_SPINCTRLDOUBLE2, _T("0"), wxPoint(112,424), wxSize(136,34), 0, 0, 100, 0, 0.01, _T("ID_SPINCTRLDOUBLE2"));
	hradius_double->SetValue(_T("0"));
	hradius_double->Disable();
	Button1 = new wxButton(this, ID_BUTTON1, _("Edit"), wxPoint(24,480), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button2 = new wxButton(this, wxID_OK, _("Close"), wxPoint(144,480), wxDefaultSize, 0, wxDefaultValidator, _T("wxID_OK"));

	Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&StyleInfoText::OnCheckBox1Click);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&StyleInfoText::OnButton1Click);
	//*)
    m = parent->m;
	bmp = &(parent->bmp);
	styles_information = &(parent->styles_information);
}

StyleInfoText::~StyleInfoText()
{
	//(*Destroy(StyleInfoText)
	//*)
}


void StyleInfoText::OnCheckBox1Click(wxCommandEvent& event)
{
    if(CheckBox1->GetValue())
    {
        field_choice->Enable(true);
        placement_choice->Enable(true);
        size_double->Enable(true);
        ColourPickerCtrl1->Enable(true);
        ColourPickerCtrl2->Enable(true);
        hradius_double->Enable(true);
    }
    else
    {
        field_choice->Enable(false);
        placement_choice->Enable(false);
        size_double->Enable(false);
        ColourPickerCtrl1->Enable(false);
        ColourPickerCtrl2->Enable(false);
        hradius_double->Enable(false);
    }
}

void StyleInfoText::OnButton1Click(wxCommandEvent& event)
{
    using namespace mapnik;
    if(!(CheckBox1->GetValue()))
    {
        wxMessageBox(_("Can't edit now"), _("Warning"));
        return;
    }

    std::string style_name = std::string(name_text->GetLabel().ToUTF8().data());
    std::string expression = std::string(expression_text->GetLabel().ToUTF8().data());

    field = std::string(field_choice->GetString(field_choice->GetSelection()).ToUTF8().data());
    placement = placement_choice->GetSelection();
    size_ = size_double->GetValue();
    fillColor = ColourPickerCtrl1->GetColour();
    haloColor = ColourPickerCtrl2->GetColour();
    haloRadius = hradius_double->GetValue();

    auto& style_info = (*styles_information)[style_name];
    style_info->set_label_field(field);
    style_info->set_label_placement(placement);
    style_info->set_label_size(size_);
    style_info->set_label_fillColor(fillColor);
    style_info->set_label_haloColor(haloColor);
    style_info->set_label_haloRadius(haloRadius);

    m->remove_style(style_name);

    bool is_all = boost::algorithm::starts_with(expression, "ALL");

    std::stringstream ss_;
    ss_<<"["<<field<<"]";
    std::string s_ = ss_.str();

    feature_type_style text_style;
    {
        rule r;
        {
            if(!is_all)
            {
                r.set_filter(parse_expression(expression));
            }
            text_symbolizer text_sym;
            text_placements_ptr placement_finder = std::make_shared<text_placements_dummy>();
            switch(placement)
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
            placement_finder->defaults.format_defaults.text_size = size_;
            placement_finder->defaults.format_defaults.fill = color(fillColor.Red(), fillColor.Green(), fillColor.Blue());
            placement_finder->defaults.format_defaults.halo_fill = color(haloColor.Red(), haloColor.Green(), haloColor.Blue());
            placement_finder->defaults.format_defaults.halo_radius = haloRadius;
            placement_finder->defaults.set_format_tree(std::make_shared<mapnik::formatting::text_node>(parse_expression(s_)));
            put<text_placements_ptr>(text_sym, keys::text_placements_, placement_finder);
            r.append(std::move(text_sym));
        }
        text_style.add_rule(std::move(r));
    }

    m->insert_style(style_name, std::move(text_style));

    mapnik::image_rgba8 im(m->width(), m->height());           //渲染
    mapnik::agg_renderer<mapnik::image_rgba8> ren(*m, im);
    ren.apply();
    //mapnik::save_to_file(im, "the_image_1.png");

    wxMapnik::image_to_wxBitmap(im, *bmp);
}
