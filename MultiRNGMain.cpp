/***************************************************************
 * Name:      MultiRNGMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Uli Koehler ()
 * Created:   2008-01-20
 * Copyright: Uli Koehler ()
 * License: GPLv2
 **************************************************************/

#include "wx_pch.h"
#include "MultiRNGMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(MultiRNGFrame)
#include <wx/settings.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)
///Custom include
#include "Generators.h"

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(MultiRNGFrame)
const long MultiRNGFrame::ID_BOOSTSPECBOX = wxNewId();
const long MultiRNGFrame::ID_LIMITSBOX = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL2 = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL23 = wxNewId();
const long MultiRNGFrame::ID_BOOSTALGOOPTSBOX = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL17 = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL11 = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL7 = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL5 = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL12 = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL14 = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL22 = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL21 = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL16 = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL15 = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL13 = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL6 = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL10 = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL18 = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL20 = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL19 = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL9 = wxNewId();
const long MultiRNGFrame::ID_BOOSTDISTOPTSBOX = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL8 = wxNewId();
const long MultiRNGFrame::ID_UPLIMITFIELD = wxNewId();
const long MultiRNGFrame::ID_LIBLABEL = wxNewId();
const long MultiRNGFrame::ID_ALGOLABEL = wxNewId();
const long MultiRNGFrame::ID_LIBCHOICE = wxNewId();
const long MultiRNGFrame::ID_ALGOCHOICE = wxNewId();
const long MultiRNGFrame::ID_AMOUNTLABEL = wxNewId();
const long MultiRNGFrame::ID_AMOUNTFIELD = wxNewId();
const long MultiRNGFrame::ID_FILELABEL = wxNewId();
const long MultiRNGFrame::ID_FILEFIELD = wxNewId();
const long MultiRNGFrame::ID_OKBUTTON = wxNewId();
const long MultiRNGFrame::ID_SEEDLABEL = wxNewId();
const long MultiRNGFrame::ID_SEEDFIELD = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL1 = wxNewId();
const long MultiRNGFrame::ID_DISTCHOICE = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL3 = wxNewId();
const long MultiRNGFrame::ID_STATICTEXT1 = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL4 = wxNewId();
const long MultiRNGFrame::ID_CHECKBOX1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(MultiRNGFrame,wxFrame)
    //(*EventTable(MultiRNGFrame)
    //*)
END_EVENT_TABLE()

MultiRNGFrame::MultiRNGFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(MultiRNGFrame)
    Create(parent, wxID_ANY, _("MultiRNG"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(373,545));
    boostSpecificBox = new wxStaticBox(this, ID_BOOSTSPECBOX, _("Advanced options"), wxPoint(160,104), wxSize(208,88), 0, _T("ID_BOOSTSPECBOX"));
    boostSpecificBox->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUTEXT));
    limitsBox = new wxStaticBox(this, ID_LIMITSBOX, _("Limits"), wxPoint(16,104), wxSize(128,88), 0, _T("ID_LIMITSBOX"));
    limitsBox->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUTEXT));
    lowerLimitLabel = new wxTextCtrl(this, ID_TEXTCTRL2, _("Lower:"), wxPoint(24,128), wxSize(40,21), wxTE_READONLY|wxTE_CENTRE|wxNO_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    lowerLimitLabel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_APPWORKSPACE));
    distributionLabel = new wxTextCtrl(this, ID_TEXTCTRL23, _("Range:"), wxPoint(168,128), wxSize(56,21), wxTE_READONLY|wxTE_RIGHT|wxNO_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL23"));
    distributionLabel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_APPWORKSPACE));
    boostAlgoOptions = new wxStaticBox(this, ID_BOOSTALGOOPTSBOX, _("Boost-Specific Algorithm Options"), wxPoint(16,200), wxSize(344,144), 0, _T("ID_BOOSTALGOOPTSBOX"));
    boostAlgoOptions->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUTEXT));
    boost7thAlgoParameterLabel = new wxTextCtrl(this, ID_TEXTCTRL17, _("7th:"), wxPoint(184,264), wxSize(40,21), wxTE_READONLY|wxTE_CENTRE|wxNO_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL17"));
    boost7thAlgoParameterLabel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_APPWORKSPACE));
    boost7thAlgoParameterField = new wxTextCtrl(this, ID_TEXTCTRL11, _("7"), wxPoint(224,264), wxSize(128,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL11"));
    boost7thAlgoParameterField->Disable();
    boost7thAlgoParameterField->SetFocus();
    boost1stAlgoParameterLabel = new wxTextCtrl(this, ID_TEXTCTRL7, _("1st:"), wxPoint(24,240), wxSize(40,21), wxTE_READONLY|wxTE_CENTRE|wxNO_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL7"));
    boost1stAlgoParameterLabel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_APPWORKSPACE));
    boost1stAlgoParameterField = new wxTextCtrl(this, ID_TEXTCTRL5, _("1"), wxPoint(64,240), wxSize(120,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    boost1stAlgoParameterField->Disable();
    boost4thAlgoParameterField = new wxTextCtrl(this, ID_TEXTCTRL12, _("4"), wxPoint(64,312), wxSize(120,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL12"));
    boost4thAlgoParameterField->Disable();
    boost4thAlgoParameterLabel = new wxTextCtrl(this, ID_TEXTCTRL14, _("4th:"), wxPoint(24,312), wxSize(40,21), wxTE_READONLY|wxTE_CENTRE|wxNO_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL14"));
    boost4thAlgoParameterLabel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_APPWORKSPACE));
    boost8thParamLabel = new wxTextCtrl(this, ID_TEXTCTRL22, _("8th:"), wxPoint(184,288), wxSize(40,21), wxTE_READONLY|wxTE_CENTRE|wxNO_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL22"));
    boost8thParamLabel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_APPWORKSPACE));
    boost9thParamLabel = new wxTextCtrl(this, ID_TEXTCTRL21, _("9th:"), wxPoint(184,312), wxSize(40,21), wxTE_READONLY|wxTE_CENTRE|wxNO_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL21"));
    boost9thParamLabel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_APPWORKSPACE));
    boost3rdAlgoParameterLabel = new wxTextCtrl(this, ID_TEXTCTRL16, _("3rd:"), wxPoint(24,288), wxSize(40,21), wxTE_READONLY|wxTE_CENTRE|wxNO_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL16"));
    boost3rdAlgoParameterLabel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_APPWORKSPACE));
    boost6thAlgoParameterLabel = new wxTextCtrl(this, ID_TEXTCTRL15, _("6th:"), wxPoint(184,240), wxSize(40,16), wxTE_READONLY|wxTE_CENTRE|wxNO_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL15"));
    boost6thAlgoParameterLabel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_APPWORKSPACE));
    boost5thAlgoParameterLabel = new wxTextCtrl(this, ID_TEXTCTRL13, _("5th:"), wxPoint(184,216), wxSize(40,16), wxTE_READONLY|wxTE_CENTRE|wxNO_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL13"));
    boost5thAlgoParameterLabel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_APPWORKSPACE));
    boost2ndAlgoParameterField = new wxTextCtrl(this, ID_TEXTCTRL6, _("2"), wxPoint(64,264), wxSize(120,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
    boost2ndAlgoParameterField->Disable();
    boost3rdAlgoParameterField = new wxTextCtrl(this, ID_TEXTCTRL10, _("3"), wxPoint(64,288), wxSize(120,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL10"));
    boost3rdAlgoParameterField->Disable();
    boost6thAlgoParameterField = new wxTextCtrl(this, ID_TEXTCTRL18, _("6"), wxPoint(224,240), wxSize(128,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL18"));
    boost6thAlgoParameterField->Disable();
    boost8thAlgoParameterField = new wxTextCtrl(this, ID_TEXTCTRL20, _("8"), wxPoint(224,288), wxSize(128,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL20"));
    boost8thAlgoParameterField->Disable();
    boost8thAlgoParameterField->SetFocus();
    boost9thAlgoParameterField = new wxTextCtrl(this, ID_TEXTCTRL19, _("9"), wxPoint(224,312), wxSize(128,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL19"));
    boost9thAlgoParameterField->Disable();
    boost9thAlgoParameterField->SetFocus();
    boost5thAlgoParameterField = new wxTextCtrl(this, ID_TEXTCTRL9, _("5"), wxPoint(224,216), wxSize(128,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL9"));
    boost5thAlgoParameterField->Disable();
    boostDistOptionsBox = new wxStaticBox(this, ID_BOOSTDISTOPTSBOX, _("Boost-Specific Distribution Options"), wxPoint(16,352), wxSize(344,152), 0, _T("ID_BOOSTDISTOPTSBOX"));
    boostDistOptionsBox->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUTEXT));
    boost2ndAlgoParameterLabel = new wxTextCtrl(this, ID_TEXTCTRL8, _("2nd:"), wxPoint(24,264), wxSize(40,21), wxTE_READONLY|wxTE_CENTRE|wxNO_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL8"));
    boost2ndAlgoParameterLabel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_APPWORKSPACE));
    lowerLimitField = new wxTextCtrl(this, ID_UPLIMITFIELD, _("500"), wxPoint(64,128), wxSize(72,21), 0, wxDefaultValidator, _T("ID_UPLIMITFIELD"));
    libraryLabel = new wxStaticText(this, ID_LIBLABEL, _("Library:"), wxPoint(8,16), wxDefaultSize, 0, _T("ID_LIBLABEL"));
    algorithmLabel = new wxStaticText(this, ID_ALGOLABEL, _("Algorithm:"), wxPoint(184,16), wxDefaultSize, 0, _T("ID_ALGOLABEL"));
    libraryChoice = new wxChoice(this, ID_LIBCHOICE, wxPoint(56,16), wxSize(120,21), 0, 0, 0, wxDefaultValidator, _T("ID_LIBCHOICE"));
    libraryChoice->Append(_("boost/random"));
    libraryChoice->SetSelection( libraryChoice->Append(_("MersenneTwister.h")) );
    libraryChoice->Append(_("GMP"));
    algorithmChoice = new wxChoice(this, ID_ALGOCHOICE, wxPoint(240,16), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_ALGOCHOICE"));
    algorithmChoice->SetSelection( algorithmChoice->Append(_("MT 19937")) );
    amountLabel = new wxStaticText(this, ID_AMOUNTLABEL, _("Amount:"), wxPoint(8,48), wxDefaultSize, 0, _T("ID_AMOUNTLABEL"));
    amountField = new wxTextCtrl(this, ID_AMOUNTFIELD, _("100"), wxPoint(56,48), wxDefaultSize, 0, wxDefaultValidator, _T("ID_AMOUNTFIELD"));
    fileLabel = new wxStaticText(this, ID_FILELABEL, _("File:"), wxPoint(184,48), wxDefaultSize, 0, _T("ID_FILELABEL"));
    filenameField = new wxTextCtrl(this, ID_FILEFIELD, _("random.txt"), wxPoint(216,48), wxSize(152,21), 0, wxDefaultValidator, _T("ID_FILEFIELD"));
    okButton = new wxButton(this, ID_OKBUTTON, _("OK"), wxPoint(120,512), wxSize(136,23), 0, wxDefaultValidator, _T("ID_OKBUTTON"));
    seedLabel = new wxStaticText(this, ID_SEEDLABEL, _("Seed:"), wxPoint(8,80), wxDefaultSize, 0, _T("ID_SEEDLABEL"));
    seedField = new wxTextCtrl(this, ID_SEEDFIELD, _("1234567890"), wxPoint(56,80), wxSize(312,21), 0, wxDefaultValidator, _T("ID_SEEDFIELD"));
    upperLimitField = new wxTextCtrl(this, ID_TEXTCTRL1, _("1000"), wxPoint(64,152), wxSize(72,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    upperLimitField->Disable();
    distributionChoice = new wxChoice(this, ID_DISTCHOICE, wxPoint(232,120), wxSize(128,21), 0, 0, 0, wxDefaultValidator, _T("ID_DISTCHOICE"));
    distributionChoice->SetSelection( distributionChoice->Append(_("32-Bit Real in [0,1]")) );
    distributionChoice->Append(_("32-Bit Real in [0,n]"));
    distributionChoice->Append(_("32-Bit Real in [0,1)"));
    distributionChoice->Append(_("32-Bit Real in [0,n)"));
    distributionChoice->Append(_("32-Bit Real in (0,1)"));
    distributionChoice->Append(_("32-Bit Real in (0,n)"));
    distributionChoice->Append(_("Integer in [0,2^32-1]"));
    distributionChoice->Append(_("Integer in [0,n] for n < 2^32"));
    distributionChoice->Append(_("53-bit real number in [0,1)"));
    distributionChoice->Append(_("Nonuniform"));
    upperLimitLabel = new wxTextCtrl(this, ID_TEXTCTRL3, _("Upper:"), wxPoint(24,152), wxSize(40,21), wxTE_READONLY|wxTE_CENTRE|wxNO_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    upperLimitLabel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_APPWORKSPACE));
    bitsLabel = new wxStaticText(this, ID_STATICTEXT1, _("Bits:"), wxPoint(200,152), wxSize(24,13), 0, _T("ID_STATICTEXT1"));
    bitsLabel->SetToolTip(_("Bits to use in GMP Linear Congruential algorithm"));
    bitsField = new wxTextCtrl(this, ID_TEXTCTRL4, _("64"), wxPoint(232,144), wxSize(128,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    bitsField->SetMaxLength(20);
    bitsField->Disable();
    boostAlgoParametersCheckbox = new wxCheckBox(this, ID_CHECKBOX1, _("Enable customized algorithm"), wxPoint(30,220), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    boostAlgoParametersCheckbox->SetValue(false);

    Connect(ID_LIBCHOICE,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&MultiRNGFrame::OnLibraryChoiceSelect);
    Connect(ID_OKBUTTON,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MultiRNGFrame::OnOkButtonClick);
    Connect(ID_DISTCHOICE,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&MultiRNGFrame::OnDistributionChoiceSelect);
    Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&MultiRNGFrame::OnBoostAlgoParametersCheckboxClick);
    //*)
}

MultiRNGFrame::~MultiRNGFrame()
{
    //(*Destroy(MultiRNGFrame)
    //*)
}

void MultiRNGFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void MultiRNGFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void MultiRNGFrame::OnLibraryChoiceSelect(wxCommandEvent& event)
{
    switch(libraryChoice->GetCurrentSelection())
    {
        case 0: ///boost/random
            {
                ///Set distribution/range text
                distributionLabel->SetValue(wxT("Distribution:"));
                ///Set Algorithm choices
                algorithmChoice->Clear();
                algorithmChoice->Append(_("MT 19937"));
                algorithmChoice->Append(_("Linear Congruential"));
                algorithmChoice->Append(_("Additive Combine"));
                algorithmChoice->Append(_("Inverse Congruential"));
                algorithmChoice->Append(_("Shuffle output"));
                algorithmChoice->Append(_("Lagged fibonacci"));
                algorithmChoice->SetSelection(0);
                ///Set Distribution choices
                distributionChoice->Enable(true);
                distributionChoice->Clear();
                distributionChoice->Append(wxT("Uniform Small Integer"));
                distributionChoice->Append(wxT("Uniform Integer"));
                distributionChoice->Append(wxT("Uniform 01"));
                distributionChoice->Append(wxT("Uniform Real"));
                distributionChoice->Append(wxT("Triangle"));
                distributionChoice->Append(wxT("Bernoulli"));
                distributionChoice->Append(wxT("Cauchy"));
                distributionChoice->Append(wxT("Exponential"));
                distributionChoice->Append(wxT("Geometric"));
                distributionChoice->Append(wxT("Normal"));
                distributionChoice->Append(wxT("Lognormal"));
                distributionChoice->Append(wxT("Uniform on Sphere"));
                distributionChoice->SetSelection(0);
                ///Enable and disable fields
                upperLimitField->Enable(true);
                upperLimitLabel->Enable(true);
                lowerLimitField->Enable(true);
                lowerLimitLabel->Enable(true);
                break;
            }
        case 1: ///MersenneTwister.h
            {
                ///Set distribution/range text
                distributionLabel->SetValue(wxT("Range:"));
                ///Set Algorithm choices
                algorithmChoice->Clear();
                algorithmChoice->Append(_("MT 19937"));
                algorithmChoice->SetSelection(0);
                ///Set Distribution choices
                distributionChoice->Enable(true);
                distributionChoice->Clear();
                distributionChoice->Append(wxT("32-Bit Real in [0,1]"));
                distributionChoice->Append(wxT("32-Bit Real in [0,n]"));
                distributionChoice->Append(wxT("32-Bit Real in [0,1)"));
                distributionChoice->Append(wxT("32-Bit Real in [0,n)"));
                distributionChoice->Append(wxT("32-Bit Real in (0,1)"));
                distributionChoice->Append(wxT("32-Bit Real in (0,n)"));
                distributionChoice->Append(wxT("Integer in [0,2^32-1]"));
                distributionChoice->Append(wxT("Integer in [0,n] for n < 2^32"));
                distributionChoice->Append(wxT("53-bit real number in [0,1)"));
                distributionChoice->Append(wxT("Nonuniform"));
                distributionChoice->SetSelection(0);
                ///Enable and disable fields
                lowerLimitField->Enable(false);
                upperLimitField->Enable(false);
                break;
            }
        case 2: ///GMP
            {
                ///Set distribution/range text
                distributionLabel->SetValue(wxT("Distribution:"));
                ///Set Algorithm options
                algorithmChoice->Clear();
                algorithmChoice->Append(_("MT 19937"));
                algorithmChoice->Append(_("Linear Congruential"));
                algorithmChoice->SetSelection(0);
                ///Disable distribution choice
                distributionChoice->Enable(false);
                break;
            }
        default: break;
    }
}


void MultiRNGFrame::OnDistributionChoiceSelect(wxCommandEvent& event) ///Function to disable/enable Lower/Upper limits field and set labels
{
    ///Disable all fields
    lowerLimitField->Enable(false);
    upperLimitField->Enable(false);
    bitsField->Enable(false);

    switch(libraryChoice->GetCurrentSelection())
    {
        case 0: ///Boost/random
            {
                lowerLimitField->Enable(true);
                upperLimitField->Enable(true);
                ///Force parameter selection for Lagged fibonacci Generator
                switch(algorithmChoice->GetCurrentSelection())
                {
                    case 7:
                        {
                         boost1stAlgoParameterField->Enable(true);
                         boost2ndAlgoParameterField->Enable(true);
                         boost3rdAlgoParameterField->Enable(true);
                         boost4thAlgoParameterField->Enable(true);
                         boost1stAlgoParameterLabel->SetValue(wxT("w:"));
                         boost2ndAlgoParameterLabel->SetValue(wxT("p:"));
                         boost3rdAlgoParameterLabel->SetValue(wxT("q:"));
                         boost4thAlgoParameterField->SetValue(wxT("val:"));
                        }
                }
            }
        case 1: ///MersenneTwister.h
            {
                switch(distributionChoice->GetCurrentSelection())
                    {
                        //case 0: ///32-Bit Real in [0,1]
                        case 1: ///32-Bit Real in [0,n]
                            {
                                upperLimitField->Enable(true);
                                upperLimitLabel->Enable(true);
                                upperLimitLabel->SetValue(wxT("n"));
                                break;
                            }
                        //case 2: ///32-Bit Real in [0,1)
                        case 3: ///32-Bit Real in [0,n)
                            {
                                lowerLimitField->Enable(false);
                                upperLimitField->Enable(true);
                                upperLimitLabel->Enable(true);
                                upperLimitLabel->SetValue(wxT("n:"));
                                break;
                            }
                        //case 4: ///32-Bit Real in (0,1)
                        case 5: ///32-Bit Real in (0,n)
                            {
                                lowerLimitField->Enable(false);
                                upperLimitField->Enable(true);
                                upperLimitLabel->Enable(true);
                                upperLimitLabel->SetValue(wxT("n:"));
                                break;
                            }
                        //case 6: ///Integer in [0,2^32-1]
                        case 7: ///Integer in [0,n] for n < 2^32
                            {
                                lowerLimitField->Enable(false);
                                upperLimitField->Enable(true);
                                upperLimitLabel->Enable(true);
                                upperLimitLabel->SetValue(wxT("n:"));
                                break;
                            }
                        //case 8: ///53-bit real number in [0,1)
                        case 9: ///Nonuniform
                            {
                                lowerLimitField->Enable(true);
                                upperLimitField->Enable(true);
                                lowerLimitLabel->Enable(true);
                                upperLimitLabel->Enable(true);
                                upperLimitLabel->SetValue(wxT("Mean:"));
                                upperLimitLabel->SetValue(wxT("Var:"));
                                break;
                            }
                        default: break;
                    }
                    break;
            }
        case 2: ///GMP
            {
                upperLimitLabel->Enable(true);
                bitsField->Enable(true);
            }
    }
}

void MultiRNGFrame::OnOkButtonClick(wxCommandEvent& event)
{
    ///Init static variables
    amountParam = lexical_cast<unsigned long>(amountField->GetValue().mb_str());
    seedParam = lexical_cast<string>(seedField->GetValue().mb_str());
    ulParam = lexical_cast<string>(upperLimitField->GetValue().mb_str());
    llParam = lexical_cast<string>(lowerLimitField->GetValue().mb_str());
    distributionSelectionParam = distributionChoice->GetCurrentSelection();
    algorithmSelectionParam = algorithmChoice->GetCurrentSelection();
    filenameParam = lexical_cast<string>(filenameField->GetValue().mb_str());
    customAlgorithm = boostAlgoParametersCheckbox->IsChecked();

    ///Init algorithm parameters
    boostAlgoParam1 = lexical_cast<int>(boost1stAlgoParameterField->GetValue().mb_str());
    boostAlgoParam2 = lexical_cast<int>(boost2ndAlgoParameterField->GetValue().mb_str());
    boostAlgoParam3 = lexical_cast<int>(boost3rdAlgoParameterField->GetValue().mb_str());
    boostAlgoParam4 = lexical_cast<int>(boost4thAlgoParameterField->GetValue().mb_str());
    boostAlgoParam5 = lexical_cast<int>(boost5thAlgoParameterField->GetValue().mb_str());
    boostAlgoParam6 = lexical_cast<int>(boost6thAlgoParameterField->GetValue().mb_str());
    boostAlgoParam7 = lexical_cast<int>(boost7thAlgoParameterField->GetValue().mb_str());

    switch(libraryChoice->GetCurrentSelection())
    {
        case 0: ///Boost/random
            {
                ///Create a new thread if Multithreading is enabled or call function directly else
                #ifndef NOMTHREADING
                    boost::thread boostThread(&GenRandBoost);
                #else
                    GenRandBoost();
                #endif
                break;
            }
        case 1: ///MersenneTwister.h
            {

                #ifndef NOMTHREADING
                    boost::thread mthThread(&GenRandMTH);
                #else
                    GenRandMTH();
                #endif
                break;
            }
        case 2: ///GMP
            {
                #ifndef NOMTHREADING
                    boost::thread gmpThread(&GenRandGMP);
                #else
                    GenRandGMP();
                #endif
                break;
            }
        default: break;
    }

}

void MultiRNGFrame::OnBoostAlgoParametersCheckboxClick(wxCommandEvent& event)
{
    if(boostAlgoParametersCheckbox->IsChecked())
        {
            boost1stAlgoParameterField->Enable(true);
            boost2ndAlgoParameterField->Enable(true);
            boost3rdAlgoParameterField->Enable(true);
            boost4thAlgoParameterField->Enable(true);
            boost5thAlgoParameterField->Enable(true);
            boost6thAlgoParameterField->Enable(true);
            boost7thAlgoParameterField->Enable(true);
        }
    else
        {
            ///Deactive only if selected Generator is not lagged fibonacci.
            if(algorithmChoice->GetCurrentSelection()!=7)
                {
                    boost1stAlgoParameterField->Enable(false);
                    boost2ndAlgoParameterField->Enable(false);
                    boost3rdAlgoParameterField->Enable(false);
                    boost4thAlgoParameterField->Enable(false);
                }
            boost4thAlgoParameterField->Enable(false);
            boost5thAlgoParameterField->Enable(false);
            boost6thAlgoParameterField->Enable(false);
            boost7thAlgoParameterField->Enable(false);
        }
}