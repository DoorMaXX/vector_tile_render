#ifndef STYLEDESIGNPOLYGON_H
#define STYLEDESIGNPOLYGON_H

//(*Headers(StyleDesignPolygon)
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

class StyleDesignPolygon: public wxDialog
{
	public:

		StyleDesignPolygon(mapnik_test_imageFrame* parent,wxWindowID id=wxID_ANY);
		virtual ~StyleDesignPolygon();
		void OnChoice1Selected(wxCommandEvent& event);

		//(*Declarations(StyleDesignPolygon)
		wxButton* Button1;
		wxButton* Button2;
		wxButton* Button3;
		wxCheckBox* CheckBox1;
		wxCheckBox* CheckBox2;
		wxCheckBox* CheckBox3;
		wxCheckBox* CheckBox4;
		wxCheckBox* CheckBox5;
		wxChoice* Choice1;
		wxChoice* Choice2;
		wxChoice* Choice3;
		wxChoice* Choice4;
		wxChoice* Choice5;
		wxColourPickerCtrl* ColourPickerCtrl1;
		wxColourPickerCtrl* ColourPickerCtrl2;
		wxColourPickerCtrl* ColourPickerCtrl3;
		wxColourPickerCtrl* ColourPickerCtrl4;
		wxFileDialog* FileDialog1;
		wxRadioButton* RadioButton1;
		wxRadioButton* RadioButton2;
		wxSpinCtrlDouble* SpinCtrlDouble1;
		wxSpinCtrlDouble* SpinCtrlDouble2;
		wxSpinCtrlDouble* SpinCtrlDouble3;
		wxSpinCtrlDouble* SpinCtrlDouble4;
		wxSpinCtrlDouble* SpinCtrlDouble5;
		wxSpinCtrlDouble* SpinCtrlDouble6;
		wxStaticLine* StaticLine1;
		wxStaticLine* StaticLine2;
		wxStaticLine* StaticLine3;
		wxStaticLine* StaticLine4;
		wxStaticText* StaticText10;
		wxStaticText* StaticText11;
		wxStaticText* StaticText12;
		wxStaticText* StaticText13;
		wxStaticText* StaticText14;
		wxStaticText* StaticText15;
		wxStaticText* StaticText16;
		wxStaticText* StaticText17;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxStaticText* StaticText4;
		wxStaticText* StaticText5;
		wxStaticText* StaticText6;
		wxStaticText* StaticText7;
		wxStaticText* StaticText9;
		wxTextCtrl* TextCtrl1;
		wxTextCtrl* TextCtrl2;
		//*)

	protected:

		//(*Identifiers(StyleDesignPolygon)
		static const long ID_CHOICE1;
		static const long ID_CHOICE2;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_COLOURPICKERCTRL1;
		static const long ID_STATICTEXT3;
		static const long ID_STATICLINE1;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT5;
		static const long ID_STATICTEXT6;
		static const long ID_COLOURPICKERCTRL2;
		static const long ID_SPINCTRLDOUBLE1;
		static const long ID_SPINCTRLDOUBLE2;
		static const long ID_RADIOBUTTON1;
		static const long ID_BUTTON1;
		static const long ID_RADIOBUTTON2;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICLINE2;
		static const long ID_STATICTEXT10;
		static const long ID_SPINCTRLDOUBLE3;
		static const long ID_STATICLINE3;
		static const long ID_STATICTEXT14;
		static const long ID_SPINCTRLDOUBLE5;
		static const long ID_STATICTEXT15;
		static const long ID_CHOICE3;
		static const long ID_CHECKBOX1;
		static const long ID_TEXTCTRL2;
		static const long ID_BUTTON2;
		static const long ID_CHECKBOX2;
		static const long ID_CHECKBOX3;
		static const long ID_CHECKBOX4;
		static const long ID_CHOICE4;
		static const long ID_CHOICE5;
		static const long ID_CHECKBOX5;
		static const long ID_STATICLINE4;
		static const long ID_STATICTEXT11;
		static const long ID_SPINCTRLDOUBLE4;
		static const long ID_COLOURPICKERCTRL3;
		static const long ID_COLOURPICKERCTRL4;
		static const long ID_STATICTEXT8;
		static const long ID_SPINCTRLDOUBLE6;
		//*)

	private:

		//(*Handlers(StyleDesignPolygon)
		void OnButton1Click(wxCommandEvent& event);
		void OnRadioButton2Select(wxCommandEvent& event);
		void OnRadioButton1Select(wxCommandEvent& event);
		void OnInit(wxInitDialogEvent& event);
		void OnCheckBox1Click(wxCommandEvent& event);
		void OnButton3Click(wxCommandEvent& event);
		void OnCheckBox4Click(wxCommandEvent& event);
		void OnCheckBox3Click(wxCommandEvent& event);
		void OnCheckBox3Click1(wxCommandEvent& event);
		void OnCheckBox4Click1(wxCommandEvent& event);
		void OnCheckBox5Click(wxCommandEvent& event);
		//*)
		std::vector<std::string>* field_names;
		std::vector<std::vector<std::string>>* values;
		std::shared_ptr<mapnik::Map> m;
		int* current_layer;
        std::vector<std::vector<int>>* styles_num;
        std::map<std::string, std::shared_ptr<wxMapnik::style_information>>* styles_information;
        int* style_polygon_num;
        int* style_line_num;
        int* style_point_num;
        int* style_text_num;

        wxBitmap* bmp;

		DECLARE_EVENT_TABLE()
};

#endif
