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
const long MultiRNGFrame::ID_BOOSTALGOOPTSBOX = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL7 = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL5 = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL12 = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL14 = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL17 = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL16 = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL15 = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL13 = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL2 = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL6 = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL10 = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL18 = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL11 = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL9 = wxNewId();
const long MultiRNGFrame::ID_BOOSTDISTOPTSBOX = wxNewId();
const long MultiRNGFrame::ID_LIMITSBOX = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL8 = wxNewId();
const long MultiRNGFrame::ID_BOOSTSPECBOX = wxNewId();
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
const long MultiRNGFrame::ID_DISTLABEL = wxNewId();
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
    SetClientSize(wxSize(373,477));
    boostAlgoOptions = new wxStaticBox(this, ID_BOOSTALGOOPTSBOX, _("Boost-Specific Algorithm Options"), wxPoint(16,200), wxSize(336,120), 0, _T("ID_BOOSTALGOOPTSBOX"));
    boostAlgoOptions->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUTEXT));
    boost1stAlgoParameterLabel = new wxTextCtrl(this, ID_TEXTCTRL7, _("1st:"), wxPoint(24,248), wxSize(40,21), wxTE_READONLY|wxTE_CENTRE|wxNO_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL7"));
    boost1stAlgoParameterLabel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_APPWORKSPACE));
    boost1stAlgoParameterField = new wxTextCtrl(this, ID_TEXTCTRL5, _("Text"), wxPoint(64,248), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    boost1stAlgoParameterField->Disable();
    boost4thAlgoField = new wxTextCtrl(this, ID_TEXTCTRL12, _("Text"), wxPoint(224,216), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL12"));
    boost4thAlgoField->Disable();
    boost4thAlgoLabel = new wxTextCtrl(this, ID_TEXTCTRL14, _("4th:"), wxPoint(184,216), wxSize(40,21), wxTE_READONLY|wxTE_CENTRE|wxNO_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL14"));
    boost4thAlgoLabel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_APPWORKSPACE));
    boost7th = new wxTextCtrl(this, ID_TEXTCTRL17, _("7th:"), wxPoint(184,288), wxSize(40,21), wxTE_READONLY|wxTE_CENTRE|wxNO_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL17"));
    boost7th->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_APPWORKSPACE));
    boost3rdAlgoLabel = new wxTextCtrl(this, ID_TEXTCTRL16, _("3rd:"), wxPoint(24,296), wxSize(40,21), wxTE_READONLY|wxTE_CENTRE|wxNO_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL16"));
    boost3rdAlgoLabel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_APPWORKSPACE));
    boost6thAlgoLabel = new wxTextCtrl(this, ID_TEXTCTRL15, _("6th:"), wxPoint(184,264), wxSize(40,16), wxTE_READONLY|wxTE_CENTRE|wxNO_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL15"));
    boost6thAlgoLabel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_APPWORKSPACE));
    boost5thAlgoLabel = new wxTextCtrl(this, ID_TEXTCTRL13, _("5th:"), wxPoint(184,240), wxSize(40,16), wxTE_READONLY|wxTE_CENTRE|wxNO_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL13"));
    boost5thAlgoLabel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_APPWORKSPACE));
    lowerLimitLabel = new wxTextCtrl(this, ID_TEXTCTRL2, _("Lower:"), wxPoint(24,128), wxSize(40,21), wxTE_READONLY|wxTE_CENTRE|wxNO_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    lowerLimitLabel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_APPWORKSPACE));
    boost2ndAlgoParameterField = new wxTextCtrl(this, ID_TEXTCTRL6, _("Text"), wxPoint(64,272), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
    boost2ndAlgoParameterField->Disable();
    boost3rdAlgoField = new wxTextCtrl(this, ID_TEXTCTRL10, _("Text"), wxPoint(64,296), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL10"));
    boost3rdAlgoField->Disable();
    boost6thAlgoField = new wxTextCtrl(this, ID_TEXTCTRL18, _("Text"), wxPoint(224,264), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL18"));
    boost6thAlgoField->Disable();
    boost7thAlgoField = new wxTextCtrl(this, ID_TEXTCTRL11, _("Text"), wxPoint(224,288), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL11"));
    boost7thAlgoField->SetFocus();
    boost5thAlgoField = new wxTextCtrl(this, ID_TEXTCTRL9, _("Text"), wxPoint(224,240), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL9"));
    boost5thAlgoField->Disable();
    boostDistOptionsBox = new wxStaticBox(this, ID_BOOSTDISTOPTSBOX, _("Boost-Specific Distribution Options"), wxPoint(16,328), wxSize(336,112), 0, _T("ID_BOOSTDISTOPTSBOX"));
    boostDistOptionsBox->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUTEXT));
    limitsBox = new wxStaticBox(this, ID_LIMITSBOX, _("Limits"), wxPoint(16,104), wxSize(128,80), 0, _T("ID_LIMITSBOX"));
    limitsBox->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUTEXT));
    boost2ndAlgoParameterLabel = new wxTextCtrl(this, ID_TEXTCTRL8, _("2nd:"), wxPoint(24,272), wxSize(40,21), wxTE_READONLY|wxTE_CENTRE|wxNO_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL8"));
    boost2ndAlgoParameterLabel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_APPWORKSPACE));
    boostSpecificBox = new wxStaticBox(this, ID_BOOSTSPECBOX, _("Advanced options"), wxPoint(160,104), wxSize(192,80), 0, _T("ID_BOOSTSPECBOX"));
    boostSpecificBox->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUTEXT));
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
    okButton = new wxButton(this, ID_OKBUTTON, _("OK"), wxPoint(120,448), wxSize(136,23), 0, wxDefaultValidator, _T("ID_OKBUTTON"));
    seedLabel = new wxStaticText(this, ID_SEEDLABEL, _("Seed:"), wxPoint(8,80), wxDefaultSize, 0, _T("ID_SEEDLABEL"));
    seedField = new wxTextCtrl(this, ID_SEEDFIELD, _("1234567890"), wxPoint(56,80), wxSize(312,21), 0, wxDefaultValidator, _T("ID_SEEDFIELD"));
    upperLimitField = new wxTextCtrl(this, ID_TEXTCTRL1, _("1000"), wxPoint(64,152), wxSize(72,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    upperLimitField->Disable();
    distributionLabel = new wxStaticText(this, ID_DISTLABEL, _("Distribution:"), wxPoint(168,128), wxDefaultSize, 0, _T("ID_DISTLABEL"));
    distributionChoice = new wxChoice(this, ID_DISTCHOICE, wxPoint(232,120), wxSize(112,21), 0, 0, 0, wxDefaultValidator, _T("ID_DISTCHOICE"));
    distributionChoice->Append(_("Uniform Small Integer"));
    distributionChoice->SetSelection( distributionChoice->Append(_("Uniform Integer")) );
    distributionChoice->Append(_("Uniform 01"));
    distributionChoice->Append(_("Uniform Real"));
    distributionChoice->Append(_("Triangle"));
    distributionChoice->Append(_("Bernoulli"));
    distributionChoice->Append(_("Cauchy"));
    distributionChoice->Append(_("Exponential"));
    distributionChoice->Append(_("Geometric"));
    distributionChoice->Append(_("Normal"));
    distributionChoice->Append(_("Lognormal"));
    distributionChoice->Append(_("Uniform on Sphere"));
    upperLimitLabel = new wxTextCtrl(this, ID_TEXTCTRL3, _("Upper:"), wxPoint(24,152), wxSize(40,21), wxTE_READONLY|wxTE_CENTRE|wxNO_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    upperLimitLabel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_APPWORKSPACE));
    bitsLabel = new wxStaticText(this, ID_STATICTEXT1, _("Bits:"), wxPoint(200,152), wxSize(24,13), 0, _T("ID_STATICTEXT1"));
    bitsLabel->SetToolTip(_("Bits to use in GMP Linear Congruential algorithm"));
    bitsField = new wxTextCtrl(this, ID_TEXTCTRL4, _("64"), wxPoint(232,144), wxSize(112,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    bitsField->SetMaxLength(20);
    bitsField->Disable();
    CheckBox1 = new wxCheckBox(this, ID_CHECKBOX1, _("Enable special parameters"), wxPoint(24,224), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    CheckBox1->SetValue(false);

    Connect(ID_LIBCHOICE,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&MultiRNGFrame::OnLibraryChoiceSelect);
    Connect(ID_OKBUTTON,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MultiRNGFrame::OnOkButtonClick);
    Connect(ID_DISTCHOICE,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&MultiRNGFrame::OnDistributionChoiceSelect);
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
    lowerLimitLabel->Enable(false);
    upperLimitLabel->Enable(false);
    bitsField->Enable(false);

    switch(libraryChoice->GetCurrentSelection())
    {
        case 0: ///Boost/random
            {

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
    ///Init s                                                            tatic variables
    amountParam = lexical_cast<unsigned long>(amountField->GetValue().mb_str());
    seedParam = lexical_cast<unsigned long>(seedField->GetValue().mb_str());
    ulParam = lexical_cast<string>(upperLimitField->GetValue().mb_str());
    llParam = lexical_cast<string>(lowerLimitField->GetValue().mb_str());
    distributionSelectionParam = distributionChoice->GetCurrentSelection();
    algorithmSelectionParam = algorithmChoice->GetCurrentSelection();
    filenameParam = lexical_cast<string>(filenameField->GetValue().mb_str());
    switch(libraryChoice->GetCurrentSelection())
    {
        case 0: ///Boost/random
            {
                boost::thread boostThread(&GenRandBoost);
                break;
            }
        case 1: ///MersenneTwister.h
            {
                boost::thread mthTread(&GenRandMTH);
                break;
            }
        case 2: ///GMP
            {
                boost::thread mthTread(&GenRandGMP);
                break;
            }
        default: break;
    }

}



