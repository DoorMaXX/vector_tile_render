#ifndef SAVETOXML_H
#define SAVETOXML_H

//(*Headers(SaveToXML)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/filedlg.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class SaveToXML: public wxDialog
{
	public:

		SaveToXML(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~SaveToXML();

		//(*Declarations(SaveToXML)
		wxButton* Button1;
		wxButton* Button2;
		wxFileDialog* FileDialog1;
		wxStaticText* StaticText1;
		wxTextCtrl* TextCtrl1;
		//*)

	protected:

		//(*Identifiers(SaveToXML)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_BUTTON1;
		//*)

	private:

		//(*Handlers(SaveToXML)
		void OnButton1Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
