#ifndef STYLEINFOTEXT_H
#define STYLEINFOTEXT_H

//(*Headers(StyleInfoText)
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/choice.h>
#include <wx/clrpicker.h>
#include <wx/dialog.h>
#include <wx/spinctrl.h>
#include <wx/stattext.h>
//*)
#include "mapnik_test_imageMain.h"
#include "wxMapnik.h"

class StyleInfoText: public wxDialog
{
	public:

		StyleInfoText(mapnik_test_imageFrame* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~StyleInfoText();

		//(*Declarations(StyleInfoText)
		wxButton* Button1;
		wxButton* Button2;
		wxCheckBox* CheckBox1;
		wxChoice* field_choice;
		wxChoice* placement_choice;
		wxColourPickerCtrl* ColourPickerCtrl1;
		wxColourPickerCtrl* ColourPickerCtrl2;
		wxSpinCtrlDouble* hradius_double;
		wxSpinCtrlDouble* size_double;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxStaticText* StaticText4;
		wxStaticText* StaticText5;
		wxStaticText* StaticText6;
		wxStaticText* StaticText7;
		wxStaticText* StaticText8;
		wxStaticText* StaticText9;
		wxStaticText* expression_text;
		wxStaticText* name_text;
		wxStaticText* target_text;
		//*)
        std::string field;
        int placement;
        double size_;
        wxColor fillColor;
        wxColor haloColor;
        double haloRadius;

	protected:

		//(*Identifiers(StyleInfoText)
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT5;
		static const long ID_STATICTEXT6;
		static const long ID_STATICTEXT7;
		static const long ID_STATICTEXT8;
		static const long ID_STATICTEXT9;
		static const long ID_STATICTEXT10;
		static const long ID_CHECKBOX1;
		static const long ID_STATICTEXT11;
		static const long ID_STATICTEXT12;
		static const long ID_CHOICE1;
		static const long ID_CHOICE2;
		static const long ID_SPINCTRLDOUBLE1;
		static const long ID_COLOURPICKERCTRL1;
		static const long ID_COLOURPICKERCTRL2;
		static const long ID_SPINCTRLDOUBLE2;
		static const long ID_BUTTON1;
		//*)

	private:

		//(*Handlers(StyleInfoText)
		void OnCheckBox1Click(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		//*)
        std::shared_ptr<mapnik::Map> m;
		std::map<std::string, std::shared_ptr<wxMapnik::style_information>>* styles_information;
		wxBitmap* bmp;

		DECLARE_EVENT_TABLE()
};

#endif
