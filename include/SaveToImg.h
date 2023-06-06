#ifndef SAVETOIMG_H
#define SAVETOIMG_H

//(*Headers(SaveToImg)
#include <wx/button.h>
#include <wx/choice.h>
#include <wx/dialog.h>
#include <wx/filedlg.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)
#include "mapnik_test_imageMain.h"
#include "wxMapnik.h"

class SaveToImg: public wxDialog
{
	public:

		SaveToImg(mapnik_test_imageFrame* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~SaveToImg();

		//(*Declarations(SaveToImg)
		wxButton* Button1;
		wxButton* Button2;
		wxChoice* Choice1;
		wxChoice* Choice2;
		wxFileDialog* FileDialog1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxTextCtrl* TextCtrl1;
		//*)

	protected:

		//(*Identifiers(SaveToImg)
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_CHOICE1;
		static const long ID_TEXTCTRL1;
		static const long ID_BUTTON1;
		static const long ID_CHOICE2;
		static const long ID_STATICTEXT3;
		//*)

	private:

		//(*Handlers(SaveToImg)
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		//*)
		//std::shared_ptr<mapnik::Map> m;
		//std::vector<wxMapnik::ds_ptr>* ds_vec;

		DECLARE_EVENT_TABLE()
};

#endif
