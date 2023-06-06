#include "../include/StyleInfoPolygon.h"

//(*InternalHeaders(StyleInfoPolygon)
#include <wx/intl.h>
#include <wx/string.h>
//*)
#include <wx/msgdlg.h>

//(*IdInit(StyleInfoPolygon)
const long StyleInfoPolygon::ID_STATICTEXT1 = wxNewId();
const long StyleInfoPolygon::ID_STATICTEXT2 = wxNewId();
const long StyleInfoPolygon::ID_STATICTEXT3 = wxNewId();
const long StyleInfoPolygon::ID_STATICTEXT4 = wxNewId();
const long StyleInfoPolygon::ID_STATICTEXT5 = wxNewId();
const long StyleInfoPolygon::ID_COLOURPICKERCTRL1 = wxNewId();
const long StyleInfoPolygon::ID_CHECKBOX1 = wxNewId();
const long StyleInfoPolygon::ID_STATICTEXT6 = wxNewId();
const long StyleInfoPolygon::ID_STATICTEXT7 = wxNewId();
const long StyleInfoPolygon::ID_STATICTEXT8 = wxNewId();
const long StyleInfoPolygon::ID_BUTTON1 = wxNewId();
const long StyleInfoPolygon::ID_SPINCTRLDOUBLE1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(StyleInfoPolygon,wxDialog)
	//(*EventTable(StyleInfoPolygon)
	//*)
END_EVENT_TABLE()

StyleInfoPolygon::StyleInfoPolygon(mapnik_test_imageFrame* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(StyleInfoPolygon)
	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(270,400));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Name:"), wxPoint(40,48), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Expression:"), wxPoint(24,96), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Target:"), wxPoint(40,144), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Fill Color:"), wxPoint(32,192), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Opacity:"), wxPoint(40,240), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	ColourPickerCtrl1 = new wxColourPickerCtrl(this, ID_COLOURPICKERCTRL1, wxColour(0,0,0), wxPoint(120,184), wxDefaultSize, 0, wxDefaultValidator, _T("ID_COLOURPICKERCTRL1"));
	CheckBox1 = new wxCheckBox(this, ID_CHECKBOX1, _("Editable"), wxPoint(176,8), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	CheckBox1->SetValue(false);
	name_text = new wxStaticText(this, ID_STATICTEXT6, _("Unknown"), wxPoint(120,48), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	expression_text = new wxStaticText(this, ID_STATICTEXT7, _("Unknown"), wxPoint(120,96), wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	target_text = new wxStaticText(this, ID_STATICTEXT8, _("Unknown"), wxPoint(120,144), wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	Button1 = new wxButton(this, ID_BUTTON1, _("Edit"), wxPoint(32,312), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button2 = new wxButton(this, wxID_OK, _("Close"), wxPoint(144,312), wxDefaultSize, 0, wxDefaultValidator, _T("wxID_OK"));
	opacity_double = new wxSpinCtrlDouble(this, ID_SPINCTRLDOUBLE1, _T("0"), wxPoint(120,232), wxSize(144,34), 0, 0, 100, 0, 0.01, _T("ID_SPINCTRLDOUBLE1"));
	opacity_double->SetValue(_T("0"));

	Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&StyleInfoPolygon::OnCheckBox1Click);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&StyleInfoPolygon::OnButton1Click);
	//*)
	opacity_double->Enable(false);
	ColourPickerCtrl1->Enable(false);

	m = parent->m;
	bmp = &(parent->bmp);
	styles_information = &(parent->styles_information);
}

StyleInfoPolygon::~StyleInfoPolygon()
{
	//(*Destroy(StyleInfoPolygon)
	//*)
}


void StyleInfoPolygon::OnCheckBox1Click(wxCommandEvent& event)
{
    if(CheckBox1->GetValue())
    {
        opacity_double->Enable(true);
        ColourPickerCtrl1->Enable(true);
    }
    else
    {
        opacity_double->SetValue(opacity);
        ColourPickerCtrl1->SetColour(fill_color);

        opacity_double->Enable(false);
        ColourPickerCtrl1->Enable(false);
    }
}

void StyleInfoPolygon::OnButton1Click(wxCommandEvent& event)
{
    using namespace mapnik;
    if(!(CheckBox1->GetValue()))
    {
        wxMessageBox(_("Can't edit now"), _("Warning"));
        return;
    }

    std::string style_name = std::string(name_text->GetLabel().ToUTF8().data());
    std::string expression = std::string(expression_text->GetLabel().ToUTF8().data());

    opacity = opacity_double->GetValue();
    fill_color = ColourPickerCtrl1->GetColour();

    auto& style_info = (*styles_information)[style_name];
    style_info->set_fill_color(fill_color);
    style_info->set_fill_opacity(opacity);

    m->remove_style(style_name);

    bool is_all = boost::algorithm::starts_with(expression, "ALL");

    feature_type_style polygon_style;        //编写样式
    {
        rule r;
        if(!is_all)
        {
            r.set_filter(parse_expression(expression));
        }
        {
            polygon_symbolizer polygon_sym;
            put(polygon_sym, keys::fill, color(fill_color.Red(),fill_color.Green(),fill_color.Blue()));
            put(polygon_sym, keys::fill_opacity, opacity);
            put(polygon_sym, keys::clip, true);
            r.append(std::move(polygon_sym));
        }
        polygon_style.add_rule(std::move(r));
    }

    m->insert_style(style_name, std::move(polygon_style));

    mapnik::image_rgba8 im(m->width(), m->height());           //渲染
    mapnik::agg_renderer<mapnik::image_rgba8> ren(*m, im);
    ren.apply();
    //mapnik::save_to_file(im, "the_image_1.png");

    wxMapnik::image_to_wxBitmap(im, *bmp);
}
