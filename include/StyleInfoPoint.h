#ifndef STYLEINFOPOINT_H
#define STYLEINFOPOINT_H

//(*Headers(StyleInfoPoint)
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/dialog.h>
#include <wx/filedlg.h>
#include <wx/spinctrl.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)
#include "mapnik_test_imageMain.h"
#include "wxMapnik.h"

class StyleInfoPoint: public wxDialog
{
	public:

		StyleInfoPoint(mapnik_test_imageFrame* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~StyleInfoPoint();

		//(*Declarations(StyleInfoPoint)
		wxButton* Button1;
		wxButton* Button2;
		wxButton* Button3;
		wxCheckBox* CheckBox1;
		wxCheckBox* CheckBox2;
		wxFileDialog* FileDialog1;
		wxSpinCtrlDouble* opacity_double;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxStaticText* StaticText4;
		wxStaticText* StaticText5;
		wxStaticText* expression_text;
		wxStaticText* name_text;
		wxStaticText* target_text;
		wxTextCtrl* file_text;
		//*)
		double opacity;
		bool overlap;
		std::string file;

	protected:

		//(*Identifiers(StyleInfoPoint)
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT5;
		static const long ID_STATICTEXT6;
		static const long ID_STATICTEXT7;
		static const long ID_SPINCTRLDOUBLE1;
		static const long ID_CHECKBOX1;
		static const long ID_BUTTON1;
		static const long ID_STATICTEXT8;
		static const long ID_TEXTCTRL1;
		static const long ID_CHECKBOX2;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(StyleInfoPoint)
		void OnCheckBox1Click(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		void OnButton3Click(wxCommandEvent& event);
		//*)
		std::shared_ptr<mapnik::Map> m;
		std::map<std::string, std::shared_ptr<wxMapnik::style_information>>* styles_information;
		wxBitmap* bmp;

		DECLARE_EVENT_TABLE()
};

#endif
