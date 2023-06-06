/***************************************************************
 * Name:      mapnik_test_imageMain.h
 * Purpose:   Defines Application Frame
 * Author:    hbs ()
 * Created:   2023-02-15
 * Copyright: hbs ()
 * License:
 **************************************************************/

#ifndef MAPNIK_TEST_IMAGEMAIN_H
#define MAPNIK_TEST_IMAGEMAIN_H

//(*Headers(mapnik_test_imageFrame)
#include <wx/button.h>
#include <wx/choice.h>
#include <wx/filedlg.h>
#include <wx/frame.h>
#include <wx/listbox.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/scrolwin.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
//*)
#include "wxMapnik.h"
#include <sstream>
#include <cstring>

using ds_ptr = std::shared_ptr<mapnik::vector_tile_impl::tile_datasource_pbf>;

class mapnik_test_imageFrame: public wxFrame
{
    public:

        mapnik_test_imageFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~mapnik_test_imageFrame();

        std::string buffer_compress;
        std::vector<std::string> buffer_url;

        int h,w;
        std::shared_ptr<mapnik::Map> m;
        std::vector<ds_ptr> ds_vec;
        std::vector<std::string> layer_names;
        int current_layer = 0;

        std::vector<std::string> field_names;
        std::vector<std::vector<std::string>> values;
        std::vector<std::vector<int>> styles_num;
        std::map<std::string, std::shared_ptr<wxMapnik::style_information>> styles_information;

        int style_polygon_num = 0;
        int style_line_num = 0;
        int style_point_num = 0;
        int style_text_num = 0;

        wxBitmap bmp;

    private:

        //(*Handlers(mapnik_test_imageFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnClearClick(wxCommandEvent& event);
        void OnPanel2Paint(wxPaintEvent& event);
        void OnLoadClick(wxCommandEvent& event);
        void OnclearClick(wxCommandEvent& event);
        void OnButton1Click1(wxCommandEvent& event);
        void OnOpenStyleDesignerClick(wxCommandEvent& event);
        void OnButton1Click2(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnChoice1Select(wxCommandEvent& event);
        void OnButton2Click1(wxCommandEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        void OnButton4Click(wxCommandEvent& event);
        void OnButton5Click(wxCommandEvent& event);
        void OnCheckBox1Click(wxCommandEvent& event);
        void OnButton5Click1(wxCommandEvent& event);
        void OnButton5Click2(wxCommandEvent& event);
        void OnButton6Click(wxCommandEvent& event);
        void OnButton7Click(wxCommandEvent& event);
        void OnButton5Click3(wxCommandEvent& event);
        void OnButton6Click1(wxCommandEvent& event);
        //*)
        void OnPaint(wxPaintEvent& WXUNUSED(event));
        void OnLoad(wxCommandEvent& event);
        void OnLoadUrl(wxCommandEvent& event);
        void OnLoadStyle(wxCommandEvent& event);
        void OnSaveImg(wxCommandEvent& event);
        void OnSaveXML(wxCommandEvent& event);
        void OnChoice1Selected(wxCommandEvent& event);
        void OnChoice3Selected(wxCommandEvent& event);
        void OnListBoxDclick(wxCommandEvent& event);
        void OnMouseWheelInMap(wxMouseEvent& event);

        void ShowBitmap();
        void UpdataStylelist(int pos);
        void UpdataLayerlist();
        void SaveXML(std::string file_name);
        void LoadXML(std::string file_name);
        void UpdataStyleData();


        //(*Identifiers(mapnik_test_imageFrame)
        static const long ID_SCROLLEDWINDOW2;
        static const long ID_CHOICE1;
        static const long ID_STATICTEXT1;
        static const long ID_BUTTON1;
        static const long ID_LISTBOX1;
        static const long ID_BUTTON2;
        static const long ID_BUTTON3;
        static const long ID_BUTTON4;
        static const long ID_PANEL1;
        static const long ID_BUTTON5;
        static const long ID_BUTTON6;
        static const long ID_BUTTON7;
        static const long ID_SCROLLEDWINDOW1;
        static const long idMenuLoad;
        static const long idMenuLoadUrl;
        static const long idMenuLoadStyle;
        static const long idMenuSaveXML;
        static const long idMenuSaveImg;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(mapnik_test_imageFrame)
        wxButton* Button1;
        wxButton* Button2;
        wxButton* Button3;
        wxButton* Button4;
        wxButton* Button5;
        wxButton* Button6;
        wxButton* Button7;
        wxChoice* Choice1;
        wxFileDialog* FileDialog1;
        wxFileDialog* FileDialog2;
        wxListBox* ListBox1;
        wxMenuItem* MenuItem3;
        wxMenuItem* MenuItem4;
        wxMenuItem* MenuItem5;
        wxMenuItem* MenuItem6;
        wxMenuItem* MenuItem7;
        wxPanel* Panel2;
        wxScrolledWindow* Panel1;
        wxScrolledWindow* ScrolledWindow1;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        wxStaticText* StaticText4;
        wxStatusBar* StatusBar1;
        //*)
        wxMapnik::tile_number tn;
        ds_ptr tile_datasource_ptr;
        int type = 0;
        int size_count = 0;
        std::vector<int> size_change = {-1, 1};
        double zoom_factor = 1;
        bool is_load = false;

        DECLARE_EVENT_TABLE()
};

#endif // MAPNIK_TEST_IMAGEMAIN_H
