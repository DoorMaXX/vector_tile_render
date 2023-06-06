#ifndef STYLEDESIGNLINE_H
#define STYLEDESIGNLINE_H

//(*Headers(StyleDesignLine)
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/choice.h>
#include <wx/clrpicker.h>
#include <wx/dialog.h>
#include <wx/radiobut.h>
#include <wx/spinctrl.h>
#include <wx/statline.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)
#include "mapnik_test_imageMain.h"
#include "wxMapnik.h"

class StyleDesignLine: public wxDialog
{
	public:

		StyleDesignLine(mapnik_test_imageFrame* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~StyleDesignLine();
		void OnChoice1Selected(wxCommandEvent& event);

		//(*Declarations(StyleDesignLine)
		wxButton* Button1;
		wxButton* Button2;
		wxCheckBox* CheckBox1;
		wxCheckBox* CheckBox2;
		wxChoice* Choice1;
		wxChoice* Choice2;
		wxChoice* Choice3;
		wxChoice* Choice4;
		wxChoice* Choice5;
		wxColourPickerCtrl* ColourPickerCtrl1;
		wxColourPickerCtrl* ColourPickerCtrl2;
		wxColourPickerCtrl* ColourPickerCtrl3;
		wxRadioButton* RadioButton1;
		wxRadioButton* RadioButton2;
		wxSpinCtrlDouble* SpinCtrlDouble1;
		wxSpinCtrlDouble* SpinCtrlDouble2;
		wxSpinCtrlDouble* SpinCtrlDouble3;
		wxSpinCtrlDouble* SpinCtrlDouble4;
		wxStaticLine* StaticLine1;
		wxStaticLine* StaticLine2;
		wxStaticText* StaticText10;
		wxStaticText* StaticText11;
		wxStaticText* StaticText12;
		wxStaticText* StaticText13;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxStaticText* StaticText4;
		wxStaticText* StaticText5;
		wxStaticText* StaticText6;
		wxStaticText* StaticText7;
		wxStaticText* StaticText8;
		wxStaticText* StaticText9;
		wxTextCtrl* TextCtrl1;
		//*)

	protected:

		//(*Identifiers(StyleDesignLine)
		static const long ID_RADIOBUTTON1;
		static const long ID_RADIOBUTTON2;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_CHOICE1;
		static const long ID_CHOICE2;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICLINE1;
		static const long ID_CHECKBOX1;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT5;
		static const long ID_STATICTEXT6;
		static const long ID_STATICTEXT7;
		static const long ID_COLOURPICKERCTRL1;
		static const long ID_SPINCTRLDOUBLE1;
		static const long ID_SPINCTRLDOUBLE2;
		static const long ID_CHOICE3;
		static const long ID_STATICLINE2;
		static const long ID_CHECKBOX2;
		static const long ID_STATICTEXT8;
		static const long ID_STATICTEXT9;
		static const long ID_STATICTEXT10;
		static const long ID_STATICTEXT12;
		static const long ID_STATICTEXT13;
		static const long ID_CHOICE4;
		static const long ID_CHOICE5;
		static const long ID_SPINCTRLDOUBLE3;
		static const long ID_COLOURPICKERCTRL2;
		static const long ID_COLOURPICKERCTRL3;
		static const long ID_SPINCTRLDOUBLE4;
		static const long ID_BUTTON1;
		//*)

	private:

		//(*Handlers(StyleDesignLine)
		void OnButton1Click(wxCommandEvent& event);
		//*)
        std::vector<std::string>* field_names;
		std::vector<std::vector<std::string>>* values;
		std::shared_ptr<mapnik::Map> m;
		int* current_layer;
        std::vector<std::vector<int>>* styles_num;
        std::map<std::string, std::shared_ptr<wxMapnik::style_information>>* styles_information;
        int* style_line_num;
        int* style_text_num;

        wxBitmap* bmp;

		DECLARE_EVENT_TABLE()
};

#endif
