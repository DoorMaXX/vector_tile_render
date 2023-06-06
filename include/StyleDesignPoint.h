#ifndef STYLEDESIGNPOINT_H
#define STYLEDESIGNPOINT_H

//(*Headers(StyleDesignPoint)
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/choice.h>
#include <wx/clrpicker.h>
#include <wx/dialog.h>
#include <wx/filedlg.h>
#include <wx/radiobut.h>
#include <wx/spinctrl.h>
#include <wx/statline.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)
#include "mapnik_test_imageMain.h"
#include "wxMapnik.h"

class StyleDesignPoint: public wxDialog
{
	public:

		StyleDesignPoint(mapnik_test_imageFrame* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~StyleDesignPoint();
		void OnChoice1Selected(wxCommandEvent& event);

		//(*Declarations(StyleDesignPoint)
		wxButton* Button1;
		wxButton* Button2;
		wxButton* Button3;
		wxCheckBox* CheckBox1;
		wxCheckBox* CheckBox2;
		wxCheckBox* CheckBox3;
		wxChoice* Choice1;
		wxChoice* Choice2;
		wxChoice* Choice3;
		wxColourPickerCtrl* ColourPickerCtrl1;
		wxColourPickerCtrl* ColourPickerCtrl2;
		wxFileDialog* FileDialog1;
		wxRadioButton* RadioButton1;
		wxRadioButton* RadioButton2;
		wxSpinCtrlDouble* SpinCtrlDouble1;
		wxSpinCtrlDouble* SpinCtrlDouble2;
		wxSpinCtrlDouble* SpinCtrlDouble3;
		wxStaticLine* StaticLine1;
		wxStaticLine* StaticLine2;
		wxStaticText* StaticText10;
		wxStaticText* StaticText11;
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
		wxTextCtrl* TextCtrl2;
		//*)

	protected:

		//(*Identifiers(StyleDesignPoint)
		static const long ID_RADIOBUTTON1;
		static const long ID_RADIOBUTTON2;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_CHOICE1;
		static const long ID_CHOICE2;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL1;
		static const long ID_CHECKBOX1;
		static const long ID_STATICLINE1;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT5;
		static const long ID_TEXTCTRL2;
		static const long ID_SPINCTRLDOUBLE1;
		static const long ID_BUTTON1;
		static const long ID_CHECKBOX2;
		static const long ID_STATICLINE2;
		static const long ID_BUTTON2;
		static const long ID_CHECKBOX3;
		static const long ID_STATICTEXT6;
		static const long ID_STATICTEXT7;
		static const long ID_STATICTEXT8;
		static const long ID_STATICTEXT9;
		static const long ID_STATICTEXT10;
		static const long ID_STATICTEXT11;
		static const long ID_CHOICE3;
		static const long ID_SPINCTRLDOUBLE2;
		static const long ID_COLOURPICKERCTRL1;
		static const long ID_COLOURPICKERCTRL2;
		static const long ID_SPINCTRLDOUBLE3;
		//*)

	private:

		//(*Handlers(StyleDesignPoint)
		void OnButton2Click(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		//*)
        std::vector<std::string>* field_names;
		std::vector<std::vector<std::string>>* values;
		std::shared_ptr<mapnik::Map> m;
		int* current_layer;
        std::vector<std::vector<int>>* styles_num;
        std::map<std::string, std::shared_ptr<wxMapnik::style_information>>* styles_information;
        int* style_point_num;
        int* style_text_num;

        wxBitmap* bmp;

		DECLARE_EVENT_TABLE()
};

#endif
