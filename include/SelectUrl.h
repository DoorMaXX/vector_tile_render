#ifndef SELECTURL_H
#define SELECTURL_H

//(*Headers(SelectUrl)
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/dialog.h>
#include <wx/radiobut.h>
#include <wx/spinctrl.h>
#include <wx/statline.h>
#include <wx/stattext.h>
//*)

class SelectUrl: public wxDialog
{
	public:

		SelectUrl(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~SelectUrl();

		//(*Declarations(SelectUrl)
		wxButton* Button1;
		wxCheckBox* admin_cb;
		wxCheckBox* building_cb;
		wxCheckBox* place_cb;
		wxCheckBox* road_cb;
		wxCheckBox* waterarea_cb;
		wxRadioButton* RadioButton1;
		wxRadioButton* RadioButton2;
		wxSpinCtrl* SpinCtrl1;
		wxSpinCtrl* SpinCtrl2;
		wxSpinCtrl* SpinCtrl3;
		wxSpinCtrl* SpinCtrl4;
		wxSpinCtrlDouble* SpinCtrlDouble1;
		wxSpinCtrlDouble* SpinCtrlDouble2;
		wxStaticLine* StaticLine1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxStaticText* StaticText4;
		wxStaticText* StaticText5;
		wxStaticText* StaticText6;
		wxStaticText* StaticText7;
		wxStaticText* StaticText8;
		//*)

	protected:

		//(*Identifiers(SelectUrl)
		static const long ID_CHECKBOX1;
		static const long ID_CHECKBOX2;
		static const long ID_CHECKBOX3;
		static const long ID_CHECKBOX4;
		static const long ID_CHECKBOX5;
		static const long ID_STATICLINE1;
		static const long ID_RADIOBUTTON1;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_SPINCTRL1;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT4;
		static const long ID_SPINCTRL2;
		static const long ID_SPINCTRL3;
		static const long ID_STATICTEXT5;
		static const long ID_RADIOBUTTON2;
		static const long ID_STATICTEXT6;
		static const long ID_STATICTEXT7;
		static const long ID_SPINCTRLDOUBLE1;
		static const long ID_SPINCTRLDOUBLE2;
		static const long ID_STATICTEXT8;
		static const long ID_SPINCTRL4;
		//*)

	private:

		//(*Handlers(SelectUrl)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
