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
const long MultiRNGFrame::ID_CHECKBOX1 = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL26 = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL25 = wxNewId();
const long MultiRNGFrame::ID_BOOSTDISTOPTSBOX = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL24 = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL27 = wxNewId();
const long MultiRNGFrame::ID_STATICTEXT6 = wxNewId();
const long MultiRNGFrame::ID_STATICTEXT7 = wxNewId();
const long MultiRNGFrame::ID_STATICTEXT5 = wxNewId();
const long MultiRNGFrame::ID_STATICTEXT4 = wxNewId();
const long MultiRNGFrame::ID_STATICBOX1 = wxNewId();
const long MultiRNGFrame::ID_BOOSTSPECBOX = wxNewId();
const long MultiRNGFrame::ID_LIMITSBOX = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL2 = wxNewId();
const long MultiRNGFrame::ID_TEXTCTRL23 = wxNewId();
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
const long MultiRNGFrame::ID_COMBOBOX2 = wxNewId();
const long MultiRNGFrame::ID_STATICTEXT2 = wxNewId();
const long MultiRNGFrame::ID_STATICTEXT3 = wxNewId();
const long MultiRNGFrame::ID_CHOICE1 = wxNewId();
const long MultiRNGFrame::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(MultiRNGFrame,wxFrame)
    //(*EventTable(MultiRNGFrame)
    //*)
END_EVENT_TABLE()

MultiRNGFrame::MultiRNGFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(MultiRNGFrame)
    Create(parent, wxID_ANY, _("MultiRNG"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(708,214));
    highEntropyCheckbox = new wxCheckBox(this, ID_CHECKBOX1, _("HE"), wxPoint(224,80), wxSize(54,24), 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    highEntropyCheckbox->SetValue(true);
    boost3rdDistParameterBox = new wxTextCtrl(this, ID_TEXTCTRL26, _("3"), wxPoint(544,64), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL26"));
    boost2ndDistParameterBox = new wxTextCtrl(this, ID_TEXTCTRL25, _("2"), wxPoint(544,40), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL25"));
    boostDistOptionsBox = new wxStaticBox(this, ID_BOOSTDISTOPTSBOX, _("Boost-Specific Distribution Options"), wxPoint(384,16), wxSize(272,72), 0, _T("ID_BOOSTDISTOPTSBOX"));
    boostDistOptionsBox->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUTEXT));
    boost1stDistPArameterFieldresourceobjectclasswxFrametitleMultiRNGtitlesize708545sizeid_arg0id_argobjectclasswxStaticTextnameID_STATICTEXT6variableboost3rdDistParameterLabelmemberyeslabel3rdlabelpos32432posobjectobjectclasswxStaticBoxnameID_BOOSTDISTOPTSBOXvariableboostDistOptionsBoxmemberyeslabelBoostSpecificDistributionOptionslabelpos16352possize344152sizefgwxSYS_COLOUR_MENUTEXTfgobjectobjectclasswxStaticTextnameID_STATICTEXT7variableboost4thDistParameterLabelmemberyeslabel4thlabelpos32456posobjectobjectclasswxStaticTextnameID_STATICTEXT5variableboost2ndDistributionLabelresourceobjectclasswxStaticTextnameID_STATICTEXT4variableboost1stDistParameterLabelmemberyeslabel1stlabelpos32384posobjectresourcememberyeslabel2ndlabelpos32408posobjectobjectclasswxStaticTextnameID_STATICTEXT4variableboost1stDistParameterLabelmemberyeslabel1stlabelpos32384posobjectobjectclasswxStaticBoxnameID_STATICBOX1variableStaticBox1memberyeslabelSoftwarePostprocessinglabelpos3768possize320184sizefgwxSYS_COLOUR_MENUTEXTfgobjectobjectclasswxStaticBoxnameID_BOOSTALGOOPTSBOXvariableboostAlgoOptionsBoxmemberyeslabelBoostSpecificAlgorithmOptionslabelpos16200possize344144sizefgwxSYS_COLOUR_MENUTEXTfgobjectobjectclasswxStaticBoxnameID_BOOSTSPECBOXvariableboostSpecificBoxmemberyeslabelAdvancedoptionslabelpos160104possize20888sizefgwxSYS_COLOUR_MENUTEXTfgobjectobjectclasswxStaticBoxnameID_LIMITSBOXvariablelimitsBoxmemberyeslabelLimitslabelpos16104possize12888sizefgwxSYS_COLOUR_MENUTEXTfgobjectobjectclasswxTextCtrlnameID_TEXTCTRL2variablelowerLimitLabelmemberyesvalueLowervaluepos24128possize4021sizebgwxSYS_COLOUR_APPWORKSPACEbgstylewxTE_READONLYwxTE_CENTREwxNO_BORDERstyleobjectobjectclasswxTextCtrlnameID_TEXTCTRL23variabledistributionLabelmemberyesvalueRangevaluepos168128possize5621sizebgwxSYS_COLOUR_APPWORKSPACEbgstylewxTE_READONLYwxTE_RIGHTwxNO_BORDERstyleobjectobjectclasswxTextCtrlnameID_TEXTCTRL17variableboost7thAlgoParameterLabelmemberyesvalue7thvaluepos184264possize4021sizebgwxSYS_COLOUR_APPWORKSPACEbgstylewxTE_READONLYwxTE_CENTREwxNO_BORDERstyleobjectobjectclasswxTextCtrlnameID_TEXTCTRL11variableboost7thAlgoParameterFieldmemberyesvalue7valuepos224264possize12821sizeenabled0enabledfocused1focusedobjectobjectclasswxTextCtrlnameID_TEXTCTRL7variableboost1stAlgoParameterLabelmemberyesvalue1stvaluepos24240possize4021sizebgwxSYS_COLOUR_APPWORKSPACEbgstylewxTE_READONLYwxTE_CENTREwxNO_BORDERstyleobjectobjectclasswxTextCtrlnameID_TEXTCTRL5variableboost1stAlgoParameterFieldmemberyesvalue1valuepos64240possize12021sizeenabled0enabledobjectobjectclasswxTextCtrlnameID_TEXTCTRL12variableboost4thAlgoParameterFieldmemberyesvalue4valuepos64312possize12021sizeenabled0enabledobjectobjectclasswxTextCtrlnameID_TEXTCTRL14variableboost4thAlgoParameterLabelmemberyesvalue4thvaluepos24312possize4021sizebgwxSYS_COLOUR_APPWORKSPACEbgstylewxTE_READONLYwxTE_CENTREwxNO_BORDERstyleobjectobjectclasswxTextCtrlnameID_TEXTCTRL22variableboost8thParamLabelmemberyesvalue8thvaluepos184288possize4021sizebgwxSYS_COLOUR_APPWORKSPACEbgstylewxTE_READONLYwxTE_CENTREwxNO_BORDERstyleobjectobjectclasswxTextCtrlnameID_TEXTCTRL21variableboost9thParamLabelmemberyesvalue9thvaluepos184312possize4021sizebgwxSYS_COLOUR_APPWORKSPACEbgstylewxTE_READONLYwxTE_CENTREwxNO_BORDERstyleobjectobjectclasswxTextCtrlnameID_TEXTCTRL16variableboost3rdAlgoParameterLabelmemberyesvalue3rdvaluepos24288possize4021sizebgwxSYS_COLOUR_APPWORKSPACEbgstylewxTE_READONLYwxTE_CENTREwxNO_BORDERstyleobjectobjectclasswxTextCtrlnameID_TEXTCTRL15variableboost6thAlgoParameterLabelmemberyesvalue6thvaluepos184240possize4016sizebgwxSYS_COLOUR_APPWORKSPACEbgstylewxTE_READONLYwxTE_CENTREwxNO_BORDERstyleobjectobjectclasswxTextCtrlnameID_TEXTCTRL13variableboost5thAlgoParameterLabelmemberyesvalue5thvaluepos184216possize4016sizebgwxSYS_COLOUR_APPWORKSPACEbgstylewxTE_READONLYwxTE_CENTREwxNO_BORDERstyleobjectobjectclasswxTextCtrlnameID_TEXTCTRL6variableboost2ndAlgoParameterFieldmemberyesvalue2valuepos64264possize12021sizeenabled0enabledobjectobjectclasswxTextCtrlnameID_TEXTCTRL10variableboost3rdAlgoParameterFieldmemberyesvalue3valuepos64288possize12021sizeenabled0enabledobjectobjectclasswxTextCtrlnameID_TEXTCTRL18variableboost6thAlgoParameterFieldmemberyesvalue6valuepos224240possize12821sizeenabled0enabledobjectobjectclasswxTextCtrlnameID_TEXTCTRL20variableboost8thAlgoParameterFieldmemberyesvalue8valuepos224288possize12821sizeenabled0enabledfocused1focusedobjectobjectclasswxTextCtrlnameID_TEXTCTRL19variableboost9thAlgoParameterFieldmemberyesvalue9valuepos224312possize12821sizeenabled0enabledfocused1focusedobjectobjectclasswxTextCtrlnameID_TEXTCTRL9variableboost5thAlgoParameterFieldmemberyesvalue5valuepos224216possize12821sizeenabled0enabledobjectobjectclasswxTextCtrlnameID_TEXTCTRL8variableboost2ndAlgoParameterLabelmemberyesvalue2ndvaluepos24264possize4021sizebgwxSYS_COLOUR_APPWORKSPACEbgstylewxTE_READONLYwxTE_CENTREwxNO_BORDERstyleobjectobjectclasswxTextCtrlnameID_UPLIMITFIELDvariablelowerLimitFieldmemberyesvalue500valuepos64128possize7221sizeobjectobjectclasswxStaticTextnameID_LIBLABELvariablelibraryLabelmemberyeslabelLibrarylabelpos816posobjectobjectclasswxStaticTextnameID_ALGOLABELvariablealgorithmLabelmemberyeslabelAlgorithmlabelpos18416posobjectobjectclasswxChoicenameID_LIBCHOICEvariablelibraryChoicememberyescontentitemboostrandomitemitemMersenneTwisterhitemitemGMPitemcontentselection1selectionpos5616possize12021sizehandlerfunctionOnLibraryChoiceSelectentryEVT_CHOICEobjectobjectclasswxChoicenameID_ALGOCHOICEvariablealgorithmChoicememberyescontentitemMT19937itemcontentselection0selectionpos24016posobjectobjectclasswxStaticTextnameID_AMOUNTLABELvariableamountLabelmemberyeslabelAmountlabelpos848posobjectobjectclasswxTextCtrlnameID_AMOUNTFIELDvariableamountFieldmemberyesvalue100valuepos5648posobjectobjectclasswxStaticTextnameID_FILELABELvariablefileLabelmemberyeslabelFilelabelpos18448posobjectobjectclasswxTextCtrlnameID_FILEFIELDvariablefilenameFieldmemberyesvaluerandomtxtvaluepos21648possize15221sizeobjectobjectclasswxButtonnameID_OKBUTTONvariableokButtonmemberyeslabelOKlabelpos120512possize13623sizehandlerfunctionOnOkButtonClickentryEVT_BUTTONobjectobjectclasswxStaticTextnameID_SEEDLABELvariableseedLabelmemberyeslabelSeedlabelpos880posobjectobjectclasswxTextCtrlnameID_SEEDFIELDvariableseedFieldmemberyesvalue1234567890valuepos5680possize31221sizeobjectobjectclasswxTextCtrlnameID_TEXTCTRL1variableupperLimitFieldmemberyesvalue1000valuepos64152possize7221sizeenabled0enabledobjectobjectclasswxChoicenameID_DISTCHOICEvariabledistributionChoicememberyescontentitem32BitRealin01itemitem32BitRealin0nitemitem32BitRealin01itemitem32BitRealin0nitemitem32BitRealin01itemitem32BitRealin0nitemitemIntegerin02321itemitemIntegerin0nfornlt232itemitem53bitrealnumberin01itemitemNonuniformitemcontentselection0selectionpos232120possize12821sizehandlerfunctionOnDistributionChoiceSelectentryEVT_CHOICEobjectobjectclasswxTextCtrlnameID_TEXTCTRL3variableupperLimitLabelmemberyesvalueUppervaluepos24152possize4021sizebgwxSYS_COLOUR_APPWORKSPACEbgstylewxTE_READONLYwxTE_CENTREwxNO_BORDERstyleobjectobjectclasswxStaticTextnameID_STATICTEXT1variablebitsLabelmemberyeslabelBitslabelpos200152possize2413sizetooltipBitstouseinGMPLinearCongruentialalgorithmtooltipobjectobjectclasswxTextCtrlnameID_TEXTCTRL4variablebitsFieldmemberyesvalue64valuemaxlength20maxlengthpos232144possize12821sizeenabled0enabledobjectobjectclasswxCheckBoxnameID_CHECKBOX1variableboostAlgoParametersCheckboxmemberyeslabelEnablecustomizedalgorithmlabelpos30220poshandlerfunctionOnBoostAlgoParametersCheckboxClickentryEVT_CHECKBOXobjectobjectclasswxComboBoxnameID_COMBOBOX2variableComboBox1memberyescontentitemNothingitemitemCharReplaceitemcontentselection0selectionpos41632posobjectobjectclasswxComboBoxnameID_COMBOBOX1variablefirstPostprocChoicememberyescontentitemNothingitemitemCharReplaceitemcontentselection0selectionpos56832posobjectobjectclasswxStaticTextnameID_STATICTEXT2variablefirstPostprocLabelmemberyeslabelFirstlabelpos38432posobjectobjectclasswxStaticTextnameID_STATICTEXT3variablesecondPostprocLabelmemberyeslabelSecondlabelpos52032posobjectobjectresource = new wxTextCtrl(this, ID_TEXTCTRL24, _("1"), wxPoint(424,40), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL24"));
    boost4thDistParameterBox = new wxTextCtrl(this, ID_TEXTCTRL27, _("3"), wxPoint(424,64), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL27"));
    boost3rdDistParameterLabel = new wxStaticText(this, ID_STATICTEXT6, _("3rd:"), wxPoint(392,64), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    boost4thDistParameterLabel = new wxStaticText(this, ID_STATICTEXT7, _("4th:"), wxPoint(512,64), wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    boost2ndDistributionLabelresourceobjectclasswxStaticTextnameID_STATICTEXT4variableboost1stDistParameterLabelmemberyeslabel1stlabelpos32384posobjectresource = new wxStaticText(this, ID_STATICTEXT5, _("Max:"), wxPoint(512,40), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    boost1stDistParameterLabel = new wxStaticText(this, ID_STATICTEXT4, _("Min:"), wxPoint(392,40), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    postProcStaticBox = new wxStaticBox(this, ID_STATICBOX1, _("Software Postprocessing"), wxPoint(376,96), wxSize(320,80), 0, _T("ID_STATICBOX1"));
    postProcStaticBox->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUTEXT));
    boostSpecificBox = new wxStaticBox(this, ID_BOOSTSPECBOX, _("Advanced options"), wxPoint(160,104), wxSize(208,88), 0, _T("ID_BOOSTSPECBOX"));
    boostSpecificBox->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUTEXT));
    limitsBox = new wxStaticBox(this, ID_LIMITSBOX, _("Bounds"), wxPoint(16,104), wxSize(128,88), wxSIMPLE_BORDER, _T("ID_LIMITSBOX"));
    limitsBox->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUTEXT));
    lowerLimitLabel = new wxTextCtrl(this, ID_TEXTCTRL2, _("Lower:"), wxPoint(24,128), wxSize(40,21), wxTE_READONLY|wxTE_CENTRE|wxNO_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    lowerLimitLabel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_APPWORKSPACE));
    distributionLabel = new wxTextCtrl(this, ID_TEXTCTRL23, _("Range:"), wxPoint(136,128), wxSize(56,21), wxTE_READONLY|wxTE_RIGHT|wxNO_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL23"));
    distributionLabel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_APPWORKSPACE));
    lowerLimitField = new wxTextCtrl(this, ID_UPLIMITFIELD, _("500"), wxPoint(64,128), wxSize(72,21), 0, wxDefaultValidator, _T("ID_UPLIMITFIELD"));
    libraryLabel = new wxStaticText(this, ID_LIBLABEL, _("Library:"), wxPoint(8,16), wxDefaultSize, 0, _T("ID_LIBLABEL"));
    algorithmLabel = new wxStaticText(this, ID_ALGOLABEL, _("Algorithm:"), wxPoint(208,16), wxDefaultSize, 0, _T("ID_ALGOLABEL"));
    libraryChoice = new wxChoice(this, ID_LIBCHOICE, wxPoint(56,16), wxSize(144,21), 0, 0, 0, wxDefaultValidator, _T("ID_LIBCHOICE"));
    libraryChoice->Append(_("boost/random"));
    libraryChoice->SetSelection( libraryChoice->Append(_("MersenneTwister.h")) );
    libraryChoice->Append(_("GMP"));
    algorithmChoice = new wxChoice(this, ID_ALGOCHOICE, wxPoint(272,16), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_ALGOCHOICE"));
    algorithmChoice->SetSelection( algorithmChoice->Append(_("MT 19937")) );
    amountLabel = new wxStaticText(this, ID_AMOUNTLABEL, _("Amount:"), wxPoint(8,48), wxDefaultSize, 0, _T("ID_AMOUNTLABEL"));
    amountField = new wxTextCtrl(this, ID_AMOUNTFIELD, _("100"), wxPoint(56,48), wxDefaultSize, 0, wxDefaultValidator, _T("ID_AMOUNTFIELD"));
    fileLabel = new wxStaticText(this, ID_FILELABEL, _("File:"), wxPoint(144,48), wxDefaultSize, 0, _T("ID_FILELABEL"));
    filenameField = new wxTextCtrl(this, ID_FILEFIELD, _("random.txt"), wxPoint(176,48), wxSize(152,21), 0, wxDefaultValidator, _T("ID_FILEFIELD"));
    okButton = new wxButton(this, ID_OKBUTTON, _("OK"), wxPoint(8,184), wxSize(688,23), 0, wxDefaultValidator, _T("ID_OKBUTTON"));
    seedLabel = new wxStaticText(this, ID_SEEDLABEL, _("Seed:"), wxPoint(8,80), wxDefaultSize, 0, _T("ID_SEEDLABEL"));
    seedField = new wxTextCtrl(this, ID_SEEDFIELD, _("1234567890"), wxPoint(56,80), wxSize(160,21), 0, wxDefaultValidator, _T("ID_SEEDFIELD"));
    upperLimitField = new wxTextCtrl(this, ID_TEXTCTRL1, _("1000"), wxPoint(64,152), wxSize(72,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    upperLimitField->Disable();
    distributionChoice = new wxChoice(this, ID_DISTCHOICE, wxPoint(192,128), wxSize(152,21), 0, 0, 0, wxDefaultValidator, _T("ID_DISTCHOICE"));
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
    bitsLabel = new wxStaticText(this, ID_STATICTEXT1, _("Bits:"), wxPoint(152,152), wxSize(24,13), 0, _T("ID_STATICTEXT1"));
    bitsLabel->SetToolTip(_("Bits to use in GMP Linear Congruential algorithm"));
    bitsField = new wxTextCtrl(this, ID_TEXTCTRL4, _("64"), wxPoint(192,152), wxSize(152,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    bitsField->SetMaxLength(20);
    bitsField->Disable();
    postprocMethodChoice = new wxComboBox(this, ID_COMBOBOX2, wxEmptyString, wxPoint(472,120), wxSize(216,21), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX2"));
    postprocMethodChoice->SetSelection( postprocMethodChoice->Append(_("Nothing")) );
    postprocMethodChoice->Append(_("Hash"));
    postprocLabel = new wxStaticText(this, ID_STATICTEXT2, _("Postprocessing:"), wxPoint(376,120), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    postprocHashAlgoLabel = new wxStaticText(this, ID_STATICTEXT3, _("Hash algorithm:"), wxPoint(376,144), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    postprocAlgoChoice = new wxChoice(this, ID_CHOICE1, wxPoint(472,144), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    postprocAlgoChoice->Append(_("MD5"));
    postprocAlgoChoice->SetSelection( postprocAlgoChoice->Append(_("SHA1")) );
    postprocAlgoChoice->Append(_("SHA256"));
    postprocAlgoChoice->Append(_("SHA384"));
    postprocAlgoChoice->Append(_("SHA512"));
    postprocAlgoChoice->Disable();
    generateSeedButton = new wxButton(this, ID_BUTTON1, _("Generate"), wxPoint(272,80), wxSize(88,23), 0, wxDefaultValidator, _T("ID_BUTTON1"));

    Connect(ID_LIBCHOICE,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&MultiRNGFrame::OnLibraryChoiceSelect);
    Connect(ID_OKBUTTON,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MultiRNGFrame::OnOkButtonClick);
    Connect(ID_DISTCHOICE,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&MultiRNGFrame::OnDistributionChoiceSelect);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MultiRNGFrame::OnGenerateSeedButtonClick);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&MultiRNGFrame::OnClose);
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
                algorithmChoice->Append(_("Mersenne Twister 191937"));   ///1
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
    postprocMethodParam = postprocMethodChoice->GetCurrentSelection();
    postprocAlgorithmParam  = postprocAlgoChoice->GetCurrentSelection();
    //Check if postprocessing should be enabled
    if (postprocMethodParam != 0) {postprocEnabledParam = true;}

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

void MultiRNGFrame::OnGenerateSeedButtonClick(wxCommandEvent& event)
{
    unsigned long seed;
    ///Read from /dev/random if we are using linux or use time(0) on windows
    #ifdef __linux__
    ifstream f;
    ///Dependent on the state of highEntropyCheckbox open either /dev/random or /dev/urandom for read
    highEntropyCheckbox->IsChecked() ? f.open("/dev/random", ifstream::in) : f.open("/dev/urandom", ifstream::in);
    f.read(reinterpret_cast<char*>(&seed), sizeof(unsigned long));
    f.close();
    #else
    MTRand mtr(time(0)); ///Create random state variable and seed with time(0)
    seed = mtr.randInt();
    #endif
    string s = lexical_cast<string>(seed);
    seedField->SetValue(wxString(s.c_str(), wxConvUTF8));
}

void MultiRNGFrame::OnClose(wxCloseEvent& event)
{
}
