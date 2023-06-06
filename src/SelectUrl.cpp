#include "../include/SelectUrl.h"

//(*InternalHeaders(SelectUrl)
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

//(*IdInit(SelectUrl)
const long SelectUrl::ID_CHECKBOX1 = wxNewId();
const long SelectUrl::ID_CHECKBOX2 = wxNewId();
const long SelectUrl::ID_CHECKBOX3 = wxNewId();
const long SelectUrl::ID_CHECKBOX4 = wxNewId();
const long SelectUrl::ID_CHECKBOX5 = wxNewId();
const long SelectUrl::ID_STATICLINE1 = wxNewId();
const long SelectUrl::ID_RADIOBUTTON1 = wxNewId();
const long SelectUrl::ID_STATICTEXT1 = wxNewId();
const long SelectUrl::ID_STATICTEXT2 = wxNewId();
const long SelectUrl::ID_SPINCTRL1 = wxNewId();
const long SelectUrl::ID_STATICTEXT3 = wxNewId();
const long SelectUrl::ID_STATICTEXT4 = wxNewId();
const long SelectUrl::ID_SPINCTRL2 = wxNewId();
const long SelectUrl::ID_SPINCTRL3 = wxNewId();
const long SelectUrl::ID_STATICTEXT5 = wxNewId();
const long SelectUrl::ID_RADIOBUTTON2 = wxNewId();
const long SelectUrl::ID_STATICTEXT6 = wxNewId();
const long SelectUrl::ID_STATICTEXT7 = wxNewId();
const long SelectUrl::ID_SPINCTRLDOUBLE1 = wxNewId();
const long SelectUrl::ID_SPINCTRLDOUBLE2 = wxNewId();
const long SelectUrl::ID_STATICTEXT8 = wxNewId();
const long SelectUrl::ID_SPINCTRL4 = wxNewId();
//*)

BEGIN_EVENT_TABLE(SelectUrl,wxDialog)
	//(*EventTable(SelectUrl)
	//*)
END_EVENT_TABLE()

SelectUrl::SelectUrl(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(SelectUrl)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(528,405));
	Move(wxDefaultPosition);
	admin_cb = new wxCheckBox(this, ID_CHECKBOX1, _("administrative district"), wxPoint(24,256), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	admin_cb->SetValue(false);
	waterarea_cb = new wxCheckBox(this, ID_CHECKBOX2, _("water area"), wxPoint(24,280), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
	waterarea_cb->SetValue(false);
	building_cb = new wxCheckBox(this, ID_CHECKBOX3, _("building"), wxPoint(24,304), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX3"));
	building_cb->SetValue(false);
	road_cb = new wxCheckBox(this, ID_CHECKBOX4, _("road"), wxPoint(232,256), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX4"));
	road_cb->SetValue(false);
	place_cb = new wxCheckBox(this, ID_CHECKBOX5, _("place"), wxPoint(232,280), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX5"));
	place_cb->SetValue(false);
	Button1 = new wxButton(this, wxID_OK, _("OK"), wxPoint(136,352), wxDefaultSize, 0, wxDefaultValidator, _T("wxID_OK"));
	StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxPoint(24,210), wxSize(312,1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
	RadioButton1 = new wxRadioButton(this, ID_RADIOBUTTON1, _("Tile number"), wxPoint(32,48), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Layers"), wxPoint(32,224), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticText1->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HOTLIGHT));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Extent"), wxPoint(32,16), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	StaticText2->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HOTLIGHT));
	SpinCtrl1 = new wxSpinCtrl(this, ID_SPINCTRL1, _T("837"), wxPoint(64,72), wxSize(152,34), 0, 0, 999999999, 837, _T("ID_SPINCTRL1"));
	SpinCtrl1->SetValue(_T("837"));
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Row:"), wxPoint(24,80), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Col:"), wxPoint(32,120), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	SpinCtrl2 = new wxSpinCtrl(this, ID_SPINCTRL2, _T("421"), wxPoint(64,112), wxSize(152,34), 0, 0, 99999999, 421, _T("ID_SPINCTRL2"));
	SpinCtrl2->SetValue(_T("421"));
	SpinCtrl3 = new wxSpinCtrl(this, ID_SPINCTRL3, _T("10"), wxPoint(64,152), wxSize(152,34), 0, 0, 18, 10, _T("ID_SPINCTRL3"));
	SpinCtrl3->SetValue(_T("10"));
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Level:"), wxPoint(16,160), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	RadioButton2 = new wxRadioButton(this, ID_RADIOBUTTON2, _("coordinates"), wxPoint(328,48), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON2"));
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("X:"), wxPoint(296,80), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("Y:"), wxPoint(296,120), wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	SpinCtrlDouble1 = new wxSpinCtrlDouble(this, ID_SPINCTRLDOUBLE1, _T("12742033.87"), wxPoint(320,72), wxSize(192,34), 0, -1e+08, 1e+08, 0, 0.01, _T("ID_SPINCTRLDOUBLE1"));
	SpinCtrlDouble1->SetValue(_T("12742033.87"));
	SpinCtrlDouble2 = new wxSpinCtrlDouble(this, ID_SPINCTRLDOUBLE2, _T("3544656.366"), wxPoint(320,112), wxSize(192,34), 0, -1e+08, 1e+08, 0, 0.01, _T("ID_SPINCTRLDOUBLE2"));
	SpinCtrlDouble2->SetValue(_T("3544656.366"));
	StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("Level:"), wxPoint(272,160), wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	SpinCtrl4 = new wxSpinCtrl(this, ID_SPINCTRL4, _T("10"), wxPoint(320,152), wxSize(160,34), 0, 0, 18, 10, _T("ID_SPINCTRL4"));
	SpinCtrl4->SetValue(_T("10"));
	//*)
}

SelectUrl::~SelectUrl()
{
	//(*Destroy(SelectUrl)
	//*)
}

