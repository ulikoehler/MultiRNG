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
#include <wx/string.h>
#include <wx/intl.h>
//*)
///Custom include
#include "Generators.h"

#include <boost/random.hpp>

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
const long MultiRNGFrame::ID_TEXTCTRL23 = wxNewId();
const long MultiRNGFrame::ID_ALGOLABEL = wxNewId();
const long MultiRNGFrame::ID_ALGOCHOICE = wxNewId();
const long MultiRNGFrame::ID_AMOUNTLABEL = wxNewId();
const long MultiRNGFrame::ID_AMOUNTFIELD = wxNewId();
const long MultiRNGFrame::ID_FILELABEL = wxNewId();
const long MultiRNGFrame::ID_FILEFIELD = wxNewId();
const long MultiRNGFrame::ID_OKBUTTON = wxNewId();
const long MultiRNGFrame::ID_DISTCHOICE = wxNewId();
const long MultiRNGFrame::ID_STATICTEXT1 = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(MultiRNGFrame,wxFrame)
    //(*EventTable(MultiRNGFrame)
    //*)
END_EVENT_TABLE()

MultiRNGFrame::MultiRNGFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(MultiRNGFrame)
    Create(parent, wxID_ANY, _("MultiRNG"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(585,174));
    distributionLabel = new wxTextCtrl(this, ID_TEXTCTRL23, _("Range:"), wxPoint(224,8), wxSize(56,21), wxTE_READONLY|wxTE_RIGHT|wxNO_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL23"));
    distributionLabel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_APPWORKSPACE));
    algorithmLabel = new wxStaticText(this, ID_ALGOLABEL, _("Algorithm:"), wxPoint(8,16), wxDefaultSize, 0, _T("ID_ALGOLABEL"));
    algorithmChoice = new wxChoice(this, ID_ALGOCHOICE, wxPoint(64,8), wxSize(160,27), 0, 0, 0, wxDefaultValidator, _T("ID_ALGOCHOICE"));
    amountLabel = new wxStaticText(this, ID_AMOUNTLABEL, _("Amount:"), wxPoint(8,48), wxDefaultSize, 0, _T("ID_AMOUNTLABEL"));
    amountField = new wxTextCtrl(this, ID_AMOUNTFIELD, _("100"), wxPoint(56,48), wxDefaultSize, 0, wxDefaultValidator, _T("ID_AMOUNTFIELD"));
    fileLabel = new wxStaticText(this, ID_FILELABEL, _("File:"), wxPoint(144,48), wxDefaultSize, 0, _T("ID_FILELABEL"));
    filenameField = new wxTextCtrl(this, ID_FILEFIELD, _("random.txt"), wxPoint(176,48), wxSize(216,21), 0, wxDefaultValidator, _T("ID_FILEFIELD"));
    okButton = new wxButton(this, ID_OKBUTTON, _("OK"), wxPoint(8,136), wxSize(384,23), 0, wxDefaultValidator, _T("ID_OKBUTTON"));
    distributionChoice = new wxChoice(this, ID_DISTCHOICE, wxPoint(296,8), wxSize(152,32), 0, 0, 0, wxDefaultValidator, _T("ID_DISTCHOICE"));
    distParam1Label = new wxStaticText(this, ID_STATICTEXT1, _("Dist param 1:"), wxPoint(24,96), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    distParam1Field = new wxTextCtrl(this, ID_TEXTCTRL1, _("10.0"), wxPoint(104,96), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));

    Connect(ID_OKBUTTON,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MultiRNGFrame::OnOkButtonClick);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&MultiRNGFrame::OnClose);
    //*)
    //Fill the algorithm and distribution combo boxes
    ///Set Algorithm choices
    algorithmChoice->Append(_("Mersenne Twister 19937"));   ///1
    algorithmChoice->Append(_("MInstdRand (LC Variant)"));  ///2
    algorithmChoice->Append(_("Ecuyer 1988"));              ///3
    algorithmChoice->Append(_("Kreutzer 1986"));            ///4
    algorithmChoice->Append(_("Hellekalek 1995"));          ///5
    algorithmChoice->Append(_("Mersenne Twister 11213b"));  ///6
    algorithmChoice->Append(_("Lagged Fibonacci 607"));     ///7
    algorithmChoice->Append(_("Lagged Fibonacci 1279"));    ///8
    algorithmChoice->Append(_("Lagged Fibonacci 2281"));    ///9
    algorithmChoice->Append(_("Lagged Fibonacci 3217"));    ///10
    algorithmChoice->Append(_("Lagged Fibonacci 4423"));    ///11
    algorithmChoice->Append(_("Lagged Fibonacci 9689"));    ///12
    algorithmChoice->Append(_("Lagged Fibonacci 19937"));   ///13
    algorithmChoice->Append(_("Lagged Fibonacci 23209"));   ///14
    algorithmChoice->Append(_("Lagged Fibonacci 44497"));   ///15
    algorithmChoice->SetSelection(0);
    ///Set Distribution choices
    distributionChoice->Append(wxT("Uniform Small Integer"));
    distributionChoice->Append(wxT("Uniform Integer"));
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

void MultiRNGFrame::OnOkButtonClick(wxCommandEvent& event)
{
    ///Init static variables
    amountParam = lexical_cast<unsigned long long>(amountField->GetValue().mb_str());
    seedParam = generateSeed();
    ulParam = 100000; //TODO
    llParam = 1; //TODO
    distributionSelectionParam = distributionChoice->GetCurrentSelection();
    algorithmSelectionParam = algorithmChoice->GetCurrentSelection();
    filenameParam = lexical_cast<string>(filenameField->GetValue().mb_str());
    distParam1 = lexical_cast<string>(distParam1Field->GetValue().mb_str());
    ///Create a new thread if Multithreading is enabled or call function directly else
    //boost::thread boostThread(&GenRandBoost);
    GenRandBoost();
}

unsigned long MultiRNGFrame::generateSeed()
{
    return 1000100;
    unsigned long seed;
    ///Read from /dev/random if we are using linux or use time(0) on windows
    #ifdef __linux__
    ifstream f;
    ///Dependent on the state of highEntropyCheckbox open either /dev/random or /dev/urandom for read
    f.open("/dev/urandom", ifstream::in);
    f.read(reinterpret_cast<char*>(&seed), sizeof(unsigned long));
    f.close();
    #else
    MTRand mtr(time(0)); ///Create random state variable and seed with time(0)
    seed = mtr.randInt();
    #endif
    return seed;
}

void MultiRNGFrame::OnClose(wxCloseEvent& event)
{
    exit(0);
}
