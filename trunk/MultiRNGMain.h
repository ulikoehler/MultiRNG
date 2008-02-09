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
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/statbox.h>
#include <wx/choice.h>
#include <wx/button.h>
#include <wx/frame.h>
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
        void OnLibraryChoiceSelect(wxCommandEvent& event);
        void OnDistributionChoiceSelect(wxCommandEvent& event);
        void OnOkButtonClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(MultiRNGFrame)
        static const long ID_BOOSTALGOOPTSBOX;
        static const long ID_TEXTCTRL7;
        static const long ID_TEXTCTRL5;
        static const long ID_TEXTCTRL12;
        static const long ID_TEXTCTRL14;
        static const long ID_TEXTCTRL17;
        static const long ID_TEXTCTRL16;
        static const long ID_TEXTCTRL15;
        static const long ID_TEXTCTRL13;
        static const long ID_TEXTCTRL2;
        static const long ID_TEXTCTRL6;
        static const long ID_TEXTCTRL10;
        static const long ID_TEXTCTRL18;
        static const long ID_TEXTCTRL11;
        static const long ID_TEXTCTRL9;
        static const long ID_BOOSTDISTOPTSBOX;
        static const long ID_LIMITSBOX;
        static const long ID_TEXTCTRL8;
        static const long ID_BOOSTSPECBOX;
        static const long ID_UPLIMITFIELD;
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
        static const long ID_TEXTCTRL1;
        static const long ID_DISTLABEL;
        static const long ID_DISTCHOICE;
        static const long ID_TEXTCTRL3;
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL4;
        static const long ID_CHECKBOX1;
        //*)

        //(*Declarations(MultiRNGFrame)
        wxTextCtrl* boost6thAlgoLabel;
        wxStaticBox* limitsBox;
        wxChoice* libraryChoice;
        wxTextCtrl* lowerLimitLabel;
        wxStaticText* seedLabel;
        wxTextCtrl* lowerLimitField;
        wxStaticBox* boostDistOptionsBox;
        wxTextCtrl* boost7th;
        wxTextCtrl* boost2ndAlgoParameterField;
        wxTextCtrl* boost1stAlgoParameterField;
        wxTextCtrl* boost7thAlgoField;
        wxTextCtrl* boost3rdAlgoField;
        wxTextCtrl* boost2ndAlgoParameterLabel;
        wxTextCtrl* boost3rdAlgoLabel;
        wxCheckBox* CheckBox1;
        wxStaticBox* boostSpecificBox;
        wxTextCtrl* boost4thAlgoLabel;
        wxChoice* algorithmChoice;
        wxTextCtrl* bitsField;
        wxTextCtrl* boost5thAlgoLabel;
        wxStaticText* amountLabel;
        wxTextCtrl* upperLimitLabel;
        wxChoice* distributionChoice;
        wxTextCtrl* filenameField;
        wxTextCtrl* upperLimitField;
        wxStaticBox* boostAlgoOptions;
        wxTextCtrl* boost6thAlgoField;
        wxStaticText* bitsLabel;
        wxStaticText* fileLabel;
        wxTextCtrl* boost5thAlgoField;
        wxStaticText* algorithmLabel;
        wxStaticText* libraryLabel;
        wxButton* okButton;
        wxTextCtrl* boost1stAlgoParameterLabel;
        wxTextCtrl* seedField;
        wxTextCtrl* amountField;
        wxStaticText* distributionLabel;
        wxTextCtrl* boost4thAlgoField;
        //*)
        public:
        ///Custom functions
        ///Custom variables

        DECLARE_EVENT_TABLE()
};

#endif // MULTIRNGMAIN_H
