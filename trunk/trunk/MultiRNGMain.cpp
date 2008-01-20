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
const long MultiRNGFrame::ID_STATICTEXT1 = wxNewId();
const long MultiRNGFrame::ID_STATICTEXT2 = wxNewId();
const long MultiRNGFrame::ID_CHOICE1 = wxNewId();
const long MultiRNGFrame::ID_CHOICE2 = wxNewId();
const long MultiRNGFrame::ID_STATICTEXT3 = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL1 = wxNewId();
const long MultiRNGFrame::ID_STATICTEXT4 = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL2 = wxNewId();
const long MultiRNGFrame::ID_BUTTON1 = wxNewId();
const long MultiRNGFrame::ID_STATICTEXT5 = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL3 = wxNewId();
const long MultiRNGFrame::idMenuQuit = wxNewId();
const long MultiRNGFrame::idMenuAbout = wxNewId();
const long MultiRNGFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(MultiRNGFrame,wxFrame)
    //(*EventTable(MultiRNGFrame)
    //*)
END_EVENT_TABLE()

MultiRNGFrame::MultiRNGFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(MultiRNGFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, id, _("MultiRNG"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(373,164));
    libraryLabel = new wxStaticText(this, ID_STATICTEXT1, _("Library:"), wxPoint(8,16), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    algorithmLabel = new wxStaticText(this, ID_STATICTEXT2, _("Algorithm:"), wxPoint(184,16), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    libraryChoice = new wxChoice(this, ID_CHOICE1, wxPoint(56,16), wxSize(120,21), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    libraryChoice->Append(_("boost/random"));
    libraryChoice->SetSelection( libraryChoice->Append(_("MersenneTwister.h")) );
    libraryChoice->Append(_("GMP"));
    algorithmChoice = new wxChoice(this, ID_CHOICE2, wxPoint(240,16), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
    algorithmChoice->SetSelection( algorithmChoice->Append(_("MT 19937")) );
    amountLabel = new wxStaticText(this, ID_STATICTEXT3, _("Amount:"), wxPoint(8,48), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    amountField = new wxTextCtrl(this, ID_TEXTCTRL1, _("100"), wxPoint(56,48), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    fileLabel = new wxStaticText(this, ID_STATICTEXT4, _("File:"), wxPoint(184,48), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    fileField = new wxTextCtrl(this, ID_TEXTCTRL2, _("random.txt"), wxPoint(216,48), wxSize(144,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    okButton = new wxButton(this, ID_BUTTON1, _("OK"), wxPoint(144,128), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    seedLabel = new wxStaticText(this, ID_STATICTEXT5, _("Seed:"), wxPoint(8,80), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    seedField = new wxTextCtrl(this, ID_TEXTCTRL3, _("1234567890"), wxPoint(48,80), wxSize(312,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&MultiRNGFrame::OnLibraryChoiceSelect);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MultiRNGFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MultiRNGFrame::OnAbout);
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
    static const wxString boost[] = {wxT("MT19939"), wxT("Linear congruential"), wxT("Additive combine"), wxT("Inverse congruential"), wxT("Shuffle output"), wxT("Lagged fibonacci")};
    switch(libraryChoice->GetCurrentSelection)
    {
        case 0: ///boost/random
            {
                algorithmChoice->Set
            }
        case 1: ///MersenneTwister.h
        case 2: ///GMP
        default: break;
    }
}
