/***************************************************************
 * Name:      MultiRNGMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Uli Koehler ()
 * Created:   2008-01-20
 * Copyright: Uli Koehler ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "MultiRNGMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(MultiRNGFrame)
#include <wx/settings.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

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
const long MultiRNGFrame::ID_LIMITSBOX = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL2 = wxNewId();
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
const long MultiRNGFrame::ID_PROGRESSGAUGE = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL3 = wxNewId();
//*)

BEGIN_EVENT_TABLE(MultiRNGFrame,wxFrame)
    //(*EventTable(MultiRNGFrame)
    //*)
END_EVENT_TABLE()

MultiRNGFrame::MultiRNGFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(MultiRNGFrame)
    Create(parent, id, _("MultiRNG"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(373,250));
    limitsBox = new wxStaticBox(this, ID_LIMITSBOX, _("Limits"), wxPoint(16,104), wxSize(128,80), 0, _T("ID_LIMITSBOX"));
    limitsBox->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUTEXT));
    lowerLimitLabel = new wxTextCtrl(this, ID_TEXTCTRL2, _("Lower:"), wxPoint(24,128), wxSize(40,21), wxTE_READONLY|wxTE_CENTRE|wxNO_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    lowerLimitLabel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_APPWORKSPACE));
    boostSpecificBox = new wxStaticBox(this, ID_BOOSTSPECBOX, _("Advanced options"), wxPoint(160,104), wxSize(192,80), 0, _T("ID_BOOSTSPECBOX"));
    boostSpecificBox->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUTEXT));
    lowerLimitField = new wxTextCtrl(this, ID_UPLIMITFIELD, _("1000"), wxPoint(64,128), wxSize(72,21), 0, wxDefaultValidator, _T("ID_UPLIMITFIELD"));
    libraryLabel = new wxStaticText(this, ID_LIBLABEL, _("Library:"), wxPoint(8,16), wxDefaultSize, 0, _T("ID_LIBLABEL"));
    algorithmLabel = new wxStaticText(this, ID_ALGOLABEL, _("Algorithm:"), wxPoint(184,16), wxDefaultSize, 0, _T("ID_ALGOLABEL"));
    libraryChoice = new wxChoice(this, ID_LIBCHOICE, wxPoint(56,16), wxSize(120,21), 0, 0, 0, wxDefaultValidator, _T("ID_LIBCHOICE"));
    libraryChoice->SetSelection( libraryChoice->Append(_("boost/random")) );
    libraryChoice->Append(_("MersenneTwister.h"));
    libraryChoice->Append(_("GMP"));
    algorithmChoice = new wxChoice(this, ID_ALGOCHOICE, wxPoint(240,16), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_ALGOCHOICE"));
    algorithmChoice->SetSelection( algorithmChoice->Append(_("MT 19937")) );
    amountLabel = new wxStaticText(this, ID_AMOUNTLABEL, _("Amount:"), wxPoint(8,48), wxDefaultSize, 0, _T("ID_AMOUNTLABEL"));
    amountField = new wxTextCtrl(this, ID_AMOUNTFIELD, _("100"), wxPoint(56,48), wxDefaultSize, 0, wxDefaultValidator, _T("ID_AMOUNTFIELD"));
    fileLabel = new wxStaticText(this, ID_FILELABEL, _("File:"), wxPoint(184,48), wxDefaultSize, 0, _T("ID_FILELABEL"));
    filenameField = new wxTextCtrl(this, ID_FILEFIELD, _("random.txt"), wxPoint(216,48), wxSize(152,21), 0, wxDefaultValidator, _T("ID_FILEFIELD"));
    okButton = new wxButton(this, ID_OKBUTTON, _("OK"), wxPoint(112,216), wxSize(136,23), 0, wxDefaultValidator, _T("ID_OKBUTTON"));
    seedLabel = new wxStaticText(this, ID_SEEDLABEL, _("Seed:"), wxPoint(8,80), wxDefaultSize, 0, _T("ID_SEEDLABEL"));
    seedField = new wxTextCtrl(this, ID_SEEDFIELD, _("1234567890"), wxPoint(56,80), wxSize(312,21), 0, wxDefaultValidator, _T("ID_SEEDFIELD"));
    upperLimitField = new wxTextCtrl(this, ID_TEXTCTRL1, _("1000"), wxPoint(64,152), wxSize(72,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    distributionLabel = new wxStaticText(this, ID_DISTLABEL, _("Distribution:"), wxPoint(168,136), wxDefaultSize, 0, _T("ID_DISTLABEL"));
    distributionChoice = new wxChoice(this, ID_DISTCHOICE, wxPoint(232,136), wxSize(112,21), 0, 0, 0, wxDefaultValidator, _T("ID_DISTCHOICE"));
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
    progressGauge = new wxGauge(this, ID_PROGRESSGAUGE, 100, wxPoint(16,192), wxSize(344,20), 0, wxDefaultValidator, _T("ID_PROGRESSGAUGE"));
    progressGauge->SetShadowWidth(5);
    progressGauge->SetBezelFace(5);
    upperLimitLabel = new wxTextCtrl(this, ID_TEXTCTRL3, _("Upper:"), wxPoint(24,152), wxSize(40,21), wxTE_READONLY|wxTE_CENTRE|wxNO_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    upperLimitLabel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_APPWORKSPACE));

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

void MultiRNGFrame::GenRandMTH() ///Generate PRN using mersenneTwister.h
{
    unsigned long amount = lexical_cast<unsigned long>(amountField->GetValue().mb_str());
    unsigned long seed = lexical_cast<unsigned long>(seedField->GetValue().mb_str());


    MTRand mtr(seed);

    ///Open fstream
    //ff
    f.open(lexical_cast<string>(filenameField->GetValue().mb_str()).c_str(), fstream::out);
    cerr << "fopen fin" << endl;;

    unsigned long i = 0;

    ///Get random number and
    switch(distributionChoice->GetCurrentSelection())
                    {
                        case 0: ///32-Bit Real in [0,1]
                            {
                                for(;i < amount;i++)
                                    {
                                    f << mtr.rand() << endl;
                                    }
                                break;
                            }
                        case 1: ///32-Bit Real in [0,n]
                            {
                                for(;i < amount;i++)
                                    {
                                        f << mtr.rand(lexical_cast<double>(upperLimitField->GetValue().mb_str())) << endl;
                                    }
                                break;
                            }
                        case 2: ///32-Bit Real in [0,1)
                            {
                                for(;i < amount;i++)
                                    {
                                        f << mtr.randExc() << endl;
                                    }
                                break;
                            }
                        case 3: ///32-Bit Real in [0,n)
                            {
                                for(;i < amount;i++)
                                    {
                                        f << mtr.randExc(lexical_cast<double>(upperLimitField->GetValue().mb_str())) << endl;
                                    }
                                break;
                            }
                        case 4: ///32-Bit Real in (0,1)
                            {
                                for(;i < amount;i++)
                                    {
                                        f << mtr.randDblExc() << endl;
                                    }
                                break;
                            }
                        case 5: ///32-Bit Real in (0,n)
                            {
                                for(;i < amount;i++)
                                    {
                                        f << mtr.randDblExc(lexical_cast<double>(upperLimitField->GetValue().mb_str())) << endl;
                                    }
                                break;
                            }
                        case 6: ///Integer in [0,2^32-1]
                            {
                                for(;i < amount;i++)
                                    {
                                        f << mtr.randInt() << endl;
                                    }
                                break;
                            }
                        case 7: ///Integer in [0,n] for n < 2^32
                            {
                                for(;i < amount;i++)
                                    {
                                        f << mtr.randInt(lexical_cast<unsigned long>(upperLimitField->GetValue().mb_str())) << endl;
                                    }
                                break;
                            }
                        case 8: ///53-bit real number in [0,1)
                            {
                                for(;i < amount;i++)
                                    {
                                        f << mtr.rand53() << endl;
                                    }
                                break;
                            }
                        case 9: ///Nonuniform
                            {
                                for(;i < amount;i++)
                                    {
                                        f << mtr.randNorm(lexical_cast<double>(lowerLimitField->GetValue().mb_str()), lexical_cast<double>(upperLimitField->GetValue().mb_str())) << endl;
                                    }
                                break;
                            }
                        default: break;
                    }
        f.close();

}

void MultiRNGFrame::OnDistributionChoiceSelect(wxCommandEvent& event) ///Function to disable/enable Lower/Upper limits field and set labels
{
    switch(libraryChoice->GetCurrentSelection())
    {
        case 0: ///Boost/random
            {

            }
        case 1: ///MersenneTwister.h
            {
                switch(distributionChoice->GetCurrentSelection())
                    {
                        case 0: ///32-Bit Real in [0,1]
                            {
                                lowerLimitField->Enable(false);
                                upperLimitField->Enable(false);
                                break;
                            }
                        case 1: ///32-Bit Real in [0,n]
                            {
                                lowerLimitField->Enable(false);
                                upperLimitField->Enable(true);
                                upperLimitLabel->SetValue(wxT("n"));
                                break;
                            }
                        case 2: ///32-Bit Real in [0,1)
                            {
                                lowerLimitField->Enable(false);
                                upperLimitField->Enable(false);
                                break;
                            }
                        case 3: ///32-Bit Real in [0,n)
                            {
                                lowerLimitField->Enable(false);
                                upperLimitField->Enable(true);
                                upperLimitLabel->SetValue(wxT("n:"));
                                break;
                            }
                        case 4: ///32-Bit Real in (0,1)
                            {
                                lowerLimitField->Enable(false);
                                upperLimitField->Enable(false);
                                break;
                            }
                        case 5: ///32-Bit Real in (0,n)
                            {
                                lowerLimitField->Enable(false);
                                upperLimitField->Enable(true);
                                upperLimitLabel->SetValue(wxT("n:"));
                                break;
                            }
                        case 6: ///Integer in [0,2^32-1]
                            {
                                lowerLimitField->Enable(false);
                                upperLimitField->Enable(false);
                                break;
                            }
                        case 7: ///Integer in [0,n] for n < 2^32
                            {
                                lowerLimitField->Enable(false);
                                upperLimitField->Enable(true);
                                upperLimitLabel->SetValue(wxT("n:"));
                                break;
                            }
                        case 8: ///53-bit real number in [0,1)
                            {
                                lowerLimitField->Enable(false);
                                upperLimitField->Enable(false);
                                break;
                            }
                        case 9: ///Nonuniform
                            {
                                lowerLimitField->Enable(true);
                                upperLimitField->Enable(true);
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

            }
    }
}

void MultiRNGFrame::OnOkButtonClick(wxCommandEvent& event)
{
    switch(libraryChoice->GetCurrentSelection())
    {
        case 0: ///Boost/random
            {
                break;
            }
        case 1: ///MersenneTwister.h
            {
                GenRandMTH();
                break;
            }
        case 2: ///GMP
            {
                break;
            }
        default: break;
    }

}
