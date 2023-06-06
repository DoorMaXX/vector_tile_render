#include "../include/SaveToImg.h"

//(*InternalHeaders(SaveToImg)
#include <wx/intl.h>
#include <wx/string.h>
//*)
#include <wx/filename.h>
#include <boost/algorithm/algorithm.hpp>

//(*IdInit(SaveToImg)
const long SaveToImg::ID_STATICTEXT1 = wxNewId();
const long SaveToImg::ID_STATICTEXT2 = wxNewId();
const long SaveToImg::ID_CHOICE1 = wxNewId();
const long SaveToImg::ID_TEXTCTRL1 = wxNewId();
const long SaveToImg::ID_BUTTON1 = wxNewId();
const long SaveToImg::ID_CHOICE2 = wxNewId();
const long SaveToImg::ID_STATICTEXT3 = wxNewId();
//*)

BEGIN_EVENT_TABLE(SaveToImg,wxDialog)
	//(*EventTable(SaveToImg)
	//*)
END_EVENT_TABLE()

SaveToImg::SaveToImg(mapnik_test_imageFrame* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(SaveToImg)
	Create(parent, id, _("Save to image file"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(294,227));
	Move(wxDefaultPosition);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Size:"), wxPoint(32,24), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Path:"), wxPoint(32,72), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	Choice1 = new wxChoice(this, ID_CHOICE1, wxPoint(80,16), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(80,64), wxSize(136,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	Button1 = new wxButton(this, ID_BUTTON1, _("..."), wxPoint(224,64), wxSize(40,34), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Choice2 = new wxChoice(this, ID_CHOICE2, wxPoint(80,112), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Type:"), wxPoint(32,120), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	Button2 = new wxButton(this, wxID_OK, _("Save"), wxPoint(112,176), wxDefaultSize, 0, wxDefaultValidator, _T("wxID_OK"));
	FileDialog1 = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, _("PNG files|*.png| TIF files|*.tif|JPEG files|*.jpeg"), wxFD_SAVE|wxFD_OVERWRITE_PROMPT, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SaveToImg::OnButton1Click);
	//*)
	//m = parent->m;
	//ds_vec = &(parent->ds_vec);

	Choice1->Append(_("256 X 256"));
	Choice1->Append(_("512 X 512"));
	Choice1->Append(_("1024 X 1024"));
	Choice1->Append(_("2048 X 2048"));
	Choice1->Append(_("4096 X 4096"));
	Choice1->SetSelection(1);

    Choice2->Append(_("png"));
    Choice2->Append(_("tif"));
    Choice2->Append(_("jpeg"));
    Choice2->SetSelection(0);
}

SaveToImg::~SaveToImg()
{
	//(*Destroy(SaveToImg)
	//*)
}


void SaveToImg::OnButton1Click(wxCommandEvent& event)
{
    int dlg = FileDialog1->ShowModal();
    if(dlg == wxID_OK)
    {
        TextCtrl1->SetValue(FileDialog1->GetPath());
    }
}

void SaveToImg::OnButton2Click(wxCommandEvent& event)
{
    /*
    std::string file_name = std::string(TextCtrl1->GetValue().ToUTF8().data());
    std::string file_type = std::string(Choice2->GetString(Choice2->GetSelection()).ToUTF8().data());
    int size_selection = Choice1->GetSelection();

    std::stringstream ss;
    ss<<file_name<<"."<<file_type;

    int h = m->height();
    int w = m->width();

    int h_new;
    int w_new;

    switch(size_selection)
    {
    case 0:
        h_new = 256;
        w_new = 256;
        break;
    case 1:
        h_new = 512;
        w_new = 512;
        break;
    case 2:
        h_new = 1024;
        w_new = 1024;
        break;
    case 3:
        h_new = 2048;
        w_new = 2048;
        break;
    case 4:
        h_new = 4096;
        w_new = 4096;
        break;
    }

    m->set_height(h_new);
    m->set_width(w_new);

    for(int i = 0; i < ds_vec->size(); i++)
    {
        mapnik::layer& lyr = m->get_layer(i);
        lyr.set_datasource((*ds_vec)[i]);
    }

    mapnik::image_rgba8 im(h_new, w_new);
    mapnik::agg_renderer<mapnik::image_rgba8> ren(*m, im);
    ren.apply();
    mapnik::save_to_file(im, ss.str());

    m->set_height(h);
    m->set_width(w);
    */
}
