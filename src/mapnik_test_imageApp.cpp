/***************************************************************
 * Name:      mapnik_test_imageApp.cpp
 * Purpose:   Code for Application Class
 * Author:    hbs ()
 * Created:   2023-02-15
 * Copyright: hbs ()
 * License:
 **************************************************************/

#include "../include/mapnik_test_imageApp.h"

//(*AppHeaders
#include "../include/mapnik_test_imageMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(mapnik_test_imageApp);

bool mapnik_test_imageApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	mapnik_test_imageFrame* Frame = new mapnik_test_imageFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
