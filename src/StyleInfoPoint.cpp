#include "../include/StyleInfoPoint.h"

//(*InternalHeaders(StyleInfoPoint)
#include <wx/intl.h>
#include <wx/string.h>
//*)
#include <wx/msgdlg.h>

//(*IdInit(StyleInfoPoint)
const long StyleInfoPoint::ID_STATICTEXT1 = wxNewId();
const long StyleInfoPoint::ID_STATICTEXT2 = wxNewId();
const long StyleInfoPoint::ID_STATICTEXT3 = wxNewId();
const long StyleInfoPoint::ID_STATICTEXT4 = wxNewId();
const long StyleInfoPoint::ID_STATICTEXT5 = wxNewId();
const long StyleInfoPoint::ID_STATICTEXT6 = wxNewId();
const long StyleInfoPoint::ID_STATICTEXT7 = wxNewId();
const long StyleInfoPoint::ID_SPINCTRLDOUBLE1 = wxNewId();
const long StyleInfoPoint::ID_CHECKBOX1 = wxNewId();
const long StyleInfoPoint::ID_BUTTON1 = wxNewId();
const long StyleInfoPoint::ID_STATICTEXT8 = wxNewId();
const long StyleInfoPoint::ID_TEXTCTRL1 = wxNewId();
const long StyleInfoPoint::ID_CHECKBOX2 = wxNewId();
const long StyleInfoPoint::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(StyleInfoPoint,wxDialog)
	//(*EventTable(StyleInfoPoint)
	//*)
END_EVENT_TABLE()

StyleInfoPoint::StyleInfoPoint(mapnik_test_imageFrame* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(StyleInfoPoint)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(270,400));
	Move(wxDefaultPosition);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Name:"), wxPoint(56,48), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Expression:"), wxPoint(24,96), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Target:"), wxPoint(56,144), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Opacity:"), wxPoint(48,192), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	name_text = new wxStaticText(this, ID_STATICTEXT5, _("Unknown"), wxPoint(120,48), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	expression_text = new wxStaticText(this, ID_STATICTEXT6, _("Unknown"), wxPoint(120,96), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	target_text = new wxStaticText(this, ID_STATICTEXT7, _("Unknown"), wxPoint(120,144), wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	opacity_double = new wxSpinCtrlDouble(this, ID_SPINCTRLDOUBLE1, _T("0"), wxPoint(112,184), wxSize(144,34), 0, 0, 1, 0, 0.01, _T("ID_SPINCTRLDOUBLE1"));
	opacity_double->SetValue(_T("0"));
	CheckBox1 = new wxCheckBox(this, ID_CHECKBOX1, _("Editable"), wxPoint(176,8), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	CheckBox1->SetValue(false);
	Button1 = new wxButton(this, ID_BUTTON1, _("Edit"), wxPoint(24,320), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button2 = new wxButton(this, wxID_OK, _("Close"), wxPoint(144,320), wxDefaultSize, 0, wxDefaultValidator, _T("wxID_OK"));
	StaticText5 = new wxStaticText(this, ID_STATICTEXT8, _("Icon file:"), wxPoint(48,240), wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	file_text = new wxTextCtrl(this, ID_TEXTCTRL1, _("Unknown"), wxPoint(112,232), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	CheckBox2 = new wxCheckBox(this, ID_CHECKBOX2, _("Overlap"), wxPoint(48,280), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
	CheckBox2->SetValue(false);
	Button3 = new wxButton(this, ID_BUTTON2, _("..."), wxPoint(216,232), wxSize(40,34), 0, wxDefaultValidator, _T("ID_BUTTON2"));
	FileDialog1 = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, _("BMP, JPEG and PNG files|*.bmp;*.jpeg;*.png"), wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));

	Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&StyleInfoPoint::OnCheckBox1Click);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&StyleInfoPoint::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&StyleInfoPoint::OnButton3Click);
	//*)

    opacity_double->Enable(false);
    file_text->Enable(false);
    CheckBox2->Enable(false);
    Button3->Enable(false);

	m = parent->m;
	bmp = &(parent->bmp);
	styles_information = &(parent->styles_information);
}

StyleInfoPoint::~StyleInfoPoint()
{
	//(*Destroy(StyleInfoPoint)
	//*)
}


void StyleInfoPoint::OnCheckBox1Click(wxCommandEvent& event)
{
    if(CheckBox1->GetValue())
    {
        opacity_double->Enable(true);
        file_text->Enable(true);
        CheckBox2->Enable(true);
        Button3->Enable(true);
    }
    else
    {
        opacity_double->SetValue(opacity);
        file_text->SetValue(wxString::FromUTF8(file));
        CheckBox2->SetValue(overlap);

        opacity_double->Enable(false);
        file_text->Enable(false);
        CheckBox2->Enable(false);
        Button3->Enable(false);
    }
}

void StyleInfoPoint::OnButton1Click(wxCommandEvent& event)
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
    overlap = CheckBox2->GetValue();
    file = std::string(file_text->GetValue().ToUTF8().data());

    auto& style_info = (*styles_information)[style_name];
    style_info->set_dot_opacity(opacity);
    style_info->set_dot_file(file);
    style_info->set_dot_overlap(overlap);

    m->remove_style(style_name);

    bool is_all = boost::algorithm::starts_with(expression, "ALL");

    feature_type_style point_style;        //编写样式
    {
        rule r;
        if(!is_all)
        {
            r.set_filter(parse_expression(expression));
        }
        {
            point_symbolizer point_sym;
            put(point_sym, keys::opacity, opacity);
            put(point_sym, keys::allow_overlap, overlap);
            put(point_sym, keys::file, file);
            r.append(std::move(point_sym));
        }
        point_style.add_rule(std::move(r));
    }

    m->insert_style(style_name, std::move(point_style));

    mapnik::image_rgba8 im(m->width(), m->height());           //渲染
    mapnik::agg_renderer<mapnik::image_rgba8> ren(*m, im);
    ren.apply();
    //mapnik::save_to_file(im, "the_image_1.png");

    wxMapnik::image_to_wxBitmap(im, *bmp);
}

void StyleInfoPoint::OnButton3Click(wxCommandEvent& event)
{
    int dlg = FileDialog1->ShowModal();
    if(dlg == wxID_OK)
    {
        file_text->SetValue(FileDialog1->GetPath());
    }
}
