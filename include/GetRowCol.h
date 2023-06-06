#ifndef GETROWCOL_H
#define GETROWCOL_H

//(*Headers(GetRowCol)
#include <wx/dialog.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class GetRowCol: public wxDialog
{
	public:

		GetRowCol(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~GetRowCol();

		//(*Declarations(GetRowCol)
		wxStaticText* StaticText1;
		wxTextCtrl* TextCtrl1;
		//*)

	protected:

		//(*Identifiers(GetRowCol)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		//*)

	private:

		//(*Handlers(GetRowCol)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
