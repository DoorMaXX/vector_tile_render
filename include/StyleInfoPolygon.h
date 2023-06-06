#ifndef STYLEINFOPOLYGON_H
#define STYLEINFOPOLYGON_H

//(*Headers(StyleInfoPolygon)
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/clrpicker.h>
#include <wx/dialog.h>
#include <wx/spinctrl.h>
#include <wx/stattext.h>
//*)
#include "mapnik_test_imageMain.h"
#include "wxMapnik.h"

class StyleInfoPolygon: public wxDialog
{
	public:

		StyleInfoPolygon(mapnik_test_imageFrame* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~StyleInfoPolygon();

		//(*Declarations(StyleInfoPolygon)
		wxButton* Button1;
		wxButton* Button2;
		wxCheckBox* CheckBox1;
		wxColourPickerCtrl* ColourPickerCtrl1;
		wxSpinCtrlDouble* opacity_double;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxStaticText* StaticText4;
		wxStaticText* StaticText5;
		wxStaticText* expression_text;
		wxStaticText* name_text;
		wxStaticText* target_text;
		//*)
		double opacity;
		wxColor fill_color;

	protected:

		//(*Identifiers(StyleInfoPolygon)
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT5;
		static const long ID_COLOURPICKERCTRL1;
		static const long ID_CHECKBOX1;
		static const long ID_STATICTEXT6;
		static const long ID_STATICTEXT7;
		static const long ID_STATICTEXT8;
		static const long ID_BUTTON1;
		static const long ID_SPINCTRLDOUBLE1;
		//*)

	private:

		//(*Handlers(StyleInfoPolygon)
		void OnCheckBox1Click(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		//*)

		std::shared_ptr<mapnik::Map> m;
		std::map<std::string, std::shared_ptr<wxMapnik::style_information>>* styles_information;
		wxBitmap* bmp;
		DECLARE_EVENT_TABLE()
};

#endif
