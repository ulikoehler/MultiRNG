/***************************************************************
 * Name:      MultiRNGMain.h
 * Purpose:   Defines Application Frame
 * Author:    Uli Koehler ()
 * Created:   2008-01-20
 * Copyright: Uli Koehler ()
 * License: GPLv2
 **************************************************************/

#ifndef MULTIRNGMAIN_H
#define MULTIRNGMAIN_H

//(*Headers(MultiRNGFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
//*)
///Custom header includes
#include "MultiRNGApp.h"

using namespace std;
using namespace boost;

class MultiRNGFrame: public wxFrame
{
    public:

        MultiRNGFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~MultiRNGFrame();

    private:

        //(*Handlers(MultiRNGFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnDistributionChoiceSelect(wxCommandEvent& event);
        void OnOkButtonClick(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
        //*)

        unsigned long generateSeed();

        //(*Identifiers(MultiRNGFrame)
        static const long ID_TEXTCTRL23;
        static const long ID_ALGOLABEL;
        static const long ID_ALGOCHOICE;
        static const long ID_AMOUNTLABEL;
        static const long ID_AMOUNTFIELD;
        static const long ID_FILELABEL;
        static const long ID_FILEFIELD;
        static const long ID_OKBUTTON;
        static const long ID_DISTCHOICE;
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL1;
        //*)

        //(*Declarations(MultiRNGFrame)
        wxButton* okButton;
        wxTextCtrl* distributionLabel;
        wxTextCtrl* distParam1Field;
        wxStaticText* distParam1Label;
        wxStaticText* amountLabel;
        wxStaticText* fileLabel;
        wxChoice* distributionChoice;
        wxStaticText* algorithmLabel;
        wxTextCtrl* filenameField;
        wxTextCtrl* amountField;
        wxChoice* algorithmChoice;
        //*)
        public:
        ///Custom functions
        ///Custom variables

        DECLARE_EVENT_TABLE()
};

#endif // MULTIRNGMAIN_H
