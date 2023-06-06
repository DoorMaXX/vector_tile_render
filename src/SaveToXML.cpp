#include "../include/SaveToXML.h"

//(*InternalHeaders(SaveToXML)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(SaveToXML)
const long SaveToXML::ID_STATICTEXT1 = wxNewId();
const long SaveToXML::ID_TEXTCTRL1 = wxNewId();
const long SaveToXML::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(SaveToXML,wxDialog)
	//(*EventTable(SaveToXML)
	//*)
END_EVENT_TABLE()

SaveToXML::SaveToXML(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(SaveToXML)
	Create(parent, id, _("Save to xml"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(287,148));
	Move(wxDefaultPosition);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Path:"), wxPoint(40,40), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(88,32), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	Button1 = new wxButton(this, ID_BUTTON1, _("..."), wxPoint(200,32), wxSize(48,34), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button2 = new wxButton(this, wxID_OK, _("Save"), wxPoint(104,96), wxDefaultSize, 0, wxDefaultValidator, _T("wxID_OK"));
	FileDialog1 = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, _("XML Files|*.xml"), wxFD_SAVE|wxFD_OVERWRITE_PROMPT, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SaveToXML::OnButton1Click);
	//*)
}

SaveToXML::~SaveToXML()
{
	//(*Destroy(SaveToXML)
	//*)
}


void SaveToXML::OnButton1Click(wxCommandEvent& event)
{
    int dlg = FileDialog1->ShowModal();
    if(dlg == wxID_OK)
    {
        TextCtrl1->SetValue(FileDialog1->GetPath());
    }
}
