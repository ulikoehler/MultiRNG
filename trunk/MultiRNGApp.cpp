/***************************************************************
 * Name:      MultiRNGApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Uli Koehler ()
 * Created:   2008-01-20
 * Copyright: Uli Koehler ()
 * License: GPLv2
 **************************************************************/

#include "wx_pch.h"
#include "MultiRNGApp.h"

//(*AppHeaders
#include "MultiRNGMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(MultiRNGApp);
MultiRNGFrame* Frame;

bool MultiRNGApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	Frame = new MultiRNGFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}

void StartMTH()
{
    Frame->GenRandMTH();
}
