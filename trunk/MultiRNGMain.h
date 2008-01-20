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
#include <wx/textctrl.h>
#include <wx/choice.h>
#include <wx/button.h>
#include <wx/frame.h>
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
        static const long ID_LIBLABEL;
        static const long ID_ALGOLABEL;
        static const long ID_LIBCHOICE;
        static const long ID_ALGOCHOICE;
        static const long ID_AMOUNTLABEL;
        static const long ID_AMOUNTFIELD;
        static const long ID_FILELABEL;
        static const long ID_FILEFIELD;
        static const long ID_OKBUTTON;
        static const long ID_SEEDLABEL;
        static const long ID_SEEDFIELD;
        //*)

        //(*Declarations(MultiRNGFrame)
        wxChoice* libraryChoice;
        wxStaticText* seedLabel;
        wxTextCtrl* fileField;
        wxChoice* algorithmChoice;
        wxStaticText* amountLabel;
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
