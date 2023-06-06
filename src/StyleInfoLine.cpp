#include "../include/StyleInfoLine.h"

//(*InternalHeaders(StyleInfoLine)
#include <wx/intl.h>
#include <wx/string.h>
//*)
#include <wx/msgdlg.h>

//(*IdInit(StyleInfoLine)
const long StyleInfoLine::ID_STATICTEXT1 = wxNewId();
const long StyleInfoLine::ID_STATICTEXT2 = wxNewId();
const long StyleInfoLine::ID_STATICTEXT3 = wxNewId();
const long StyleInfoLine::ID_STATICTEXT4 = wxNewId();
const long StyleInfoLine::ID_STATICTEXT5 = wxNewId();
const long StyleInfoLine::ID_STATICTEXT6 = wxNewId();
const long StyleInfoLine::ID_STATICTEXT7 = wxNewId();
const long StyleInfoLine::ID_STATICTEXT8 = wxNewId();
const long StyleInfoLine::ID_TEXTCTRL1 = wxNewId();
const long StyleInfoLine::ID_CHECKBOX1 = wxNewId();
const long StyleInfoLine::ID_SPINCTRLDOUBLE1 = wxNewId();
const long StyleInfoLine::ID_BUTTON1 = wxNewId();
const long StyleInfoLine::ID_COLOURPICKERCTRL1 = wxNewId();
const long StyleInfoLine::ID_STATICTEXT9 = wxNewId();
const long StyleInfoLine::ID_STATICTEXT10 = wxNewId();
const long StyleInfoLine::ID_CHOICE1 = wxNewId();
const long StyleInfoLine::ID_SPINCTRLDOUBLE2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(StyleInfoLine,wxDialog)
	//(*EventTable(StyleInfoLine)
	//*)
END_EVENT_TABLE()

StyleInfoLine::StyleInfoLine(mapnik_test_imageFrame* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(StyleInfoLine)
	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(270,441));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Name:"), wxPoint(56,48), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Expression:"), wxPoint(24,96), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Target:"), wxPoint(56,144), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Color:"), wxPoint(64,192), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Width:"), wxPoint(60,240), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	name_text = new wxStaticText(this, ID_STATICTEXT6, _("Unknown"), wxPoint(120,48), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	expression_text = new wxStaticText(this, ID_STATICTEXT7, _("Unknown"), wxPoint(120,96), wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	target_text = new wxStaticText(this, ID_STATICTEXT8, _("Unknown"), wxPoint(120,144), wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	width_text = new wxTextCtrl(this, ID_TEXTCTRL1, _("Unknown"), wxPoint(120,232), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	CheckBox1 = new wxCheckBox(this, ID_CHECKBOX1, _("Editable"), wxPoint(176,8), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	CheckBox1->SetValue(false);
	width_double = new wxSpinCtrlDouble(this, ID_SPINCTRLDOUBLE1, _T("0"), wxPoint(120,232), wxSize(144,34), 0, 0, 100, 0, 0.01, _T("ID_SPINCTRLDOUBLE1"));
	width_double->SetValue(_T("0"));
	Button1 = new wxButton(this, ID_BUTTON1, _("Edit"), wxPoint(24,392), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button2 = new wxButton(this, wxID_OK, _("Close"), wxPoint(144,392), wxDefaultSize, 0, wxDefaultValidator, _T("wxID_OK"));
	ColourPickerCtrl1 = new wxColourPickerCtrl(this, ID_COLOURPICKERCTRL1, wxColour(0,0,0), wxPoint(120,184), wxDefaultSize, 0, wxDefaultValidator, _T("ID_COLOURPICKERCTRL1"));
	StaticText6 = new wxStaticText(this, ID_STATICTEXT9, _("Opacity:"), wxPoint(48,288), wxDefaultSize, 0, _T("ID_STATICTEXT9"));
	StaticText7 = new wxStaticText(this, ID_STATICTEXT10, _("Line cap:"), wxPoint(48,336), wxDefaultSize, 0, _T("ID_STATICTEXT10"));
	linecap_choice = new wxChoice(this, ID_CHOICE1, wxPoint(120,328), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	opacity_double = new wxSpinCtrlDouble(this, ID_SPINCTRLDOUBLE2, _T("0"), wxPoint(120,280), wxSize(144,34), 0, 0, 1, 0, 0.01, _T("ID_SPINCTRLDOUBLE2"));
	opacity_double->SetValue(_T("0"));

	Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&StyleInfoLine::OnCheckBox1Click);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&StyleInfoLine::OnButton1Click);
	//*)
    linecap_choice->Append(_("Button cap"));
    linecap_choice->Append(_("Square cap"));
    linecap_choice->Append(_("Round cap"));

    width_double->Enable(false);
	ColourPickerCtrl1->Enable(false);
	opacity_double->Enable(false);
	linecap_choice->Enable(false);

    m = parent->m;
	bmp = &(parent->bmp);
	styles_information = &(parent->styles_information);
}

StyleInfoLine::~StyleInfoLine()
{
	//(*Destroy(StyleInfoLine)
	//*)
}


void StyleInfoLine::OnCheckBox1Click(wxCommandEvent& event)
{
    if(CheckBox1->GetValue())
    {
        width_double->Enable(true);
        ColourPickerCtrl1->Enable(true);
        opacity_double->Enable(true);
	    linecap_choice->Enable(true);
    }
    else
    {
        width_double->SetValue(stroke_width);
        ColourPickerCtrl1->SetColour(stroke_color);
        opacity_double->SetValue(stroke_opacity);
        linecap_choice->SetSelection(linecap_index);

        width_double->Enable(false);
        ColourPickerCtrl1->Enable(false);
        opacity_double->Enable(false);
	    linecap_choice->Enable(false);
    }
}

void StyleInfoLine::OnButton1Click(wxCommandEvent& event)
{
    using namespace mapnik;
    if(!(CheckBox1->GetValue()))
    {
        wxMessageBox(_("Can't edit now"), _("Warning"));
        return;
    }

    std::string style_name = std::string(name_text->GetLabel().ToUTF8().data());
    std::string expression = std::string(expression_text->GetLabel().ToUTF8().data());

    stroke_width = width_double->GetValue();
    stroke_color = ColourPickerCtrl1->GetColour();
    stroke_opacity = opacity_double->GetValue();
    linecap_index = linecap_choice->GetSelection();

    auto& style_info = (*styles_information)[style_name];
    style_info->set_stroke_width(stroke_width);
    style_info->set_stroke_color(stroke_color);
    style_info->set_stroke_opacity(stroke_opacity);
    style_info->set_stroke_linecap(linecap_index);

    m->remove_style(style_name);

    bool is_all = boost::algorithm::starts_with(expression, "ALL");

    feature_type_style line_style;
    {
        rule r;
        if(!is_all)
        {
            r.set_filter(parse_expression(expression));
        }
        {
            line_symbolizer line_sym;
            put(line_sym, keys::stroke, color(stroke_color.Red(),stroke_color.Green(),stroke_color.Blue()));
            put(line_sym, keys::stroke_width, stroke_width);
            put(line_sym, keys::stroke_opacity, stroke_opacity);
            switch(linecap_index)
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

    m->insert_style(style_name, std::move(line_style));

    mapnik::image_rgba8 im(m->width(), m->height());           //渲染
    mapnik::agg_renderer<mapnik::image_rgba8> ren(*m, im);
    ren.apply();
    //mapnik::save_to_file(im, "the_image_1.png");

    wxMapnik::image_to_wxBitmap(im, *bmp);
}
