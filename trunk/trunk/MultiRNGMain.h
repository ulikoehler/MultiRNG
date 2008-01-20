/***************************************************************
 * Name:      MultiRNGMain.h
 * Purpose:   Defines Application Frame
 * Author:    Uli Koehler ()
 * Created:   2008-01-20
 * Copyright: Uli Koehler ()
 * License:
 **************************************************************/

#ifndef MULTIRNGMAIN_H
#define MULTIRNGMAIN_H

//(*Headers(MultiRNGFrame)
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

class MultiRNGFrame: public wxFrame
{
    public:

        MultiRNGFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~MultiRNGFrame();

    private:

        //(*Handlers(MultiRNGFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnLibraryChoiceSelect(wxCommandEvent& event);
        //*)

        //(*Identifiers(MultiRNGFrame)
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT2;
        static const long ID_CHOICE1;
        static const long ID_CHOICE2;
        static const long ID_STATICTEXT3;
        static const long ID_TEXTCTRL1;
        static const long ID_STATICTEXT4;
        static const long ID_TEXTCTRL2;
        static const long ID_BUTTON1;
        static const long ID_STATICTEXT5;
        static const long ID_TEXTCTRL3;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(MultiRNGFrame)
        wxChoice* libraryChoice;
        wxStaticText* seedLabel;
        wxTextCtrl* fileField;
        wxChoice* algorithmChoice;
        wxStaticText* amountLabel;
        wxStatusBar* StatusBar1;
        wxStaticText* fileLabel;
        wxStaticText* algorithmLabel;
        wxStaticText* libraryLabel;
        wxButton* okButton;
        wxTextCtrl* seedField;
        wxTextCtrl* amountField;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // MULTIRNGMAIN_H
