#include "../include/GetRowCol.h"

//(*InternalHeaders(GetRowCol)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(GetRowCol)
const long GetRowCol::ID_STATICTEXT1 = wxNewId();
const long GetRowCol::ID_TEXTCTRL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(GetRowCol,wxDialog)
	//(*EventTable(GetRowCol)
	//*)
END_EVENT_TABLE()

GetRowCol::GetRowCol(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(GetRowCol)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(333,406));
	Move(wxDefaultPosition);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("X:"), wxPoint(40,40), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(64,32), wxSize(144,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	//*)
}

GetRowCol::~GetRowCol()
{
	//(*Destroy(GetRowCol)
	//*)
}

