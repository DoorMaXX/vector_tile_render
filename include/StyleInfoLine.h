#ifndef STYLEINFOLINE_H
#define STYLEINFOLINE_H

//(*Headers(StyleInfoLine)
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/choice.h>
#include <wx/clrpicker.h>
#include <wx/dialog.h>
#include <wx/spinctrl.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)
#include "mapnik_test_imageMain.h"
#include "wxMapnik.h"

class StyleInfoLine: public wxDialog
{
	public:

		StyleInfoLine(mapnik_test_imageFrame* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~StyleInfoLine();

		//(*Declarations(StyleInfoLine)
		wxButton* Button1;
		wxButton* Button2;
		wxCheckBox* CheckBox1;
		wxChoice* linecap_choice;
		wxColourPickerCtrl* ColourPickerCtrl1;
		wxSpinCtrlDouble* opacity_double;
		wxSpinCtrlDouble* width_double;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxStaticText* StaticText4;
		wxStaticText* StaticText5;
		wxStaticText* StaticText6;
		wxStaticText* StaticText7;
		wxStaticText* expression_text;
		wxStaticText* name_text;
		wxStaticText* target_text;
		wxTextCtrl* width_text;
		//*)

		double stroke_width;
		wxColor stroke_color;
		double stroke_opacity;
		int linecap_index;

	protected:

		//(*Identifiers(StyleInfoLine)
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT5;
		static const long ID_STATICTEXT6;
		static const long ID_STATICTEXT7;
		static const long ID_STATICTEXT8;
		static const long ID_TEXTCTRL1;
		static const long ID_CHECKBOX1;
		static const long ID_SPINCTRLDOUBLE1;
		static const long ID_BUTTON1;
		static const long ID_COLOURPICKERCTRL1;
		static const long ID_STATICTEXT9;
		static const long ID_STATICTEXT10;
		static const long ID_CHOICE1;
		static const long ID_SPINCTRLDOUBLE2;
		//*)

	private:

		//(*Handlers(StyleInfoLine)
		void OnCheckBox1Click(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		//*)
        std::shared_ptr<mapnik::Map> m;
		std::map<std::string, std::shared_ptr<wxMapnik::style_information>>* styles_information;
		wxBitmap* bmp;

		DECLARE_EVENT_TABLE()
};

#endif
