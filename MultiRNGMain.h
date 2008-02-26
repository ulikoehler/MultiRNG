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
#include <wx/combobox.h>
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
        void OnBoostAlgoParametersCheckboxClick(wxCommandEvent& event);
        void OnGenerateSeedButtonClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(MultiRNGFrame)
        static const long ID_TEXTCTRL26;
        static const long ID_TEXTCTRL25;
        static const long ID_BOOSTDISTOPTSBOX;
        static const long ID_TEXTCTRL24;
        static const long ID_TEXTCTRL27;
        static const long ID_STATICTEXT6;
        static const long ID_STATICTEXT7;
        static const long ID_STATICTEXT5;
        static const long ID_STATICTEXT4;
        static const long ID_STATICBOX1;
        static const long ID_BOOSTALGOOPTSBOX;
        static const long ID_BOOSTSPECBOX;
        static const long ID_LIMITSBOX;
        static const long ID_TEXTCTRL2;
        static const long ID_TEXTCTRL23;
        static const long ID_TEXTCTRL17;
        static const long ID_TEXTCTRL11;
        static const long ID_TEXTCTRL7;
        static const long ID_TEXTCTRL5;
        static const long ID_TEXTCTRL12;
        static const long ID_TEXTCTRL14;
        static const long ID_TEXTCTRL22;
        static const long ID_TEXTCTRL21;
        static const long ID_TEXTCTRL16;
        static const long ID_TEXTCTRL15;
        static const long ID_TEXTCTRL13;
        static const long ID_TEXTCTRL6;
        static const long ID_TEXTCTRL10;
        static const long ID_TEXTCTRL18;
        static const long ID_TEXTCTRL20;
        static const long ID_TEXTCTRL19;
        static const long ID_TEXTCTRL9;
        static const long ID_TEXTCTRL8;
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
        static const long ID_DISTCHOICE;
        static const long ID_TEXTCTRL3;
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL4;
        static const long ID_CHECKBOX1;
        static const long ID_COMBOBOX2;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT3;
        static const long ID_CHOICE1;
        static const long ID_BUTTON1;
        //*)

        //(*Declarations(MultiRNGFrame)
        wxTextCtrl* boost1stDistPArameterFieldresourceobjectclasswxFrametitleMultiRNGtitlesize708545sizeid_arg0id_argobjectclasswxStaticTextnameID_STATICTEXT6variableboost3rdDistParameterLabelmemberyeslabel3rdlabelpos32432posobjectobjectclasswxStaticBoxnameID_BOOSTDISTOPTSBOXvariableboostDistOptionsBoxmemberyeslabelBoostSpecificDistributionOptionslabelpos16352possize344152sizefgwxSYS_COLOUR_MENUTEXTfgobjectobjectclasswxStaticTextnameID_STATICTEXT7variableboost4thDistParameterLabelmemberyeslabel4thlabelpos32456posobjectobjectclasswxStaticTextnameID_STATICTEXT5variableboost2ndDistributionLabelresourceobjectclasswxStaticTextnameID_STATICTEXT4variableboost1stDistParameterLabelmemberyeslabel1stlabelpos32384posobjectresourcememberyeslabel2ndlabelpos32408posobjectobjectclasswxStaticTextnameID_STATICTEXT4variableboost1stDistParameterLabelmemberyeslabel1stlabelpos32384posobjectobjectclasswxStaticBoxnameID_STATICBOX1variableStaticBox1memberyeslabelSoftwarePostprocessinglabelpos3768possize320184sizefgwxSYS_COLOUR_MENUTEXTfgobjectobjectclasswxStaticBoxnameID_BOOSTALGOOPTSBOXvariableboostAlgoOptionsBoxmemberyeslabelBoostSpecificAlgorithmOptionslabelpos16200possize344144sizefgwxSYS_COLOUR_MENUTEXTfgobjectobjectclasswxStaticBoxnameID_BOOSTSPECBOXvariableboostSpecificBoxmemberyeslabelAdvancedoptionslabelpos160104possize20888sizefgwxSYS_COLOUR_MENUTEXTfgobjectobjectclasswxStaticBoxnameID_LIMITSBOXvariablelimitsBoxmemberyeslabelLimitslabelpos16104possize12888sizefgwxSYS_COLOUR_MENUTEXTfgobjectobjectclasswxTextCtrlnameID_TEXTCTRL2variablelowerLimitLabelmemberyesvalueLowervaluepos24128possize4021sizebgwxSYS_COLOUR_APPWORKSPACEbgstylewxTE_READONLYwxTE_CENTREwxNO_BORDERstyleobjectobjectclasswxTextCtrlnameID_TEXTCTRL23variabledistributionLabelmemberyesvalueRangevaluepos168128possize5621sizebgwxSYS_COLOUR_APPWORKSPACEbgstylewxTE_READONLYwxTE_RIGHTwxNO_BORDERstyleobjectobjectclasswxTextCtrlnameID_TEXTCTRL17variableboost7thAlgoParameterLabelmemberyesvalue7thvaluepos184264possize4021sizebgwxSYS_COLOUR_APPWORKSPACEbgstylewxTE_READONLYwxTE_CENTREwxNO_BORDERstyleobjectobjectclasswxTextCtrlnameID_TEXTCTRL11variableboost7thAlgoParameterFieldmemberyesvalue7valuepos224264possize12821sizeenabled0enabledfocused1focusedobjectobjectclasswxTextCtrlnameID_TEXTCTRL7variableboost1stAlgoParameterLabelmemberyesvalue1stvaluepos24240possize4021sizebgwxSYS_COLOUR_APPWORKSPACEbgstylewxTE_READONLYwxTE_CENTREwxNO_BORDERstyleobjectobjectclasswxTextCtrlnameID_TEXTCTRL5variableboost1stAlgoParameterFieldmemberyesvalue1valuepos64240possize12021sizeenabled0enabledobjectobjectclasswxTextCtrlnameID_TEXTCTRL12variableboost4thAlgoParameterFieldmemberyesvalue4valuepos64312possize12021sizeenabled0enabledobjectobjectclasswxTextCtrlnameID_TEXTCTRL14variableboost4thAlgoParameterLabelmemberyesvalue4thvaluepos24312possize4021sizebgwxSYS_COLOUR_APPWORKSPACEbgstylewxTE_READONLYwxTE_CENTREwxNO_BORDERstyleobjectobjectclasswxTextCtrlnameID_TEXTCTRL22variableboost8thParamLabelmemberyesvalue8thvaluepos184288possize4021sizebgwxSYS_COLOUR_APPWORKSPACEbgstylewxTE_READONLYwxTE_CENTREwxNO_BORDERstyleobjectobjectclasswxTextCtrlnameID_TEXTCTRL21variableboost9thParamLabelmemberyesvalue9thvaluepos184312possize4021sizebgwxSYS_COLOUR_APPWORKSPACEbgstylewxTE_READONLYwxTE_CENTREwxNO_BORDERstyleobjectobjectclasswxTextCtrlnameID_TEXTCTRL16variableboost3rdAlgoParameterLabelmemberyesvalue3rdvaluepos24288possize4021sizebgwxSYS_COLOUR_APPWORKSPACEbgstylewxTE_READONLYwxTE_CENTREwxNO_BORDERstyleobjectobjectclasswxTextCtrlnameID_TEXTCTRL15variableboost6thAlgoParameterLabelmemberyesvalue6thvaluepos184240possize4016sizebgwxSYS_COLOUR_APPWORKSPACEbgstylewxTE_READONLYwxTE_CENTREwxNO_BORDERstyleobjectobjectclasswxTextCtrlnameID_TEXTCTRL13variableboost5thAlgoParameterLabelmemberyesvalue5thvaluepos184216possize4016sizebgwxSYS_COLOUR_APPWORKSPACEbgstylewxTE_READONLYwxTE_CENTREwxNO_BORDERstyleobjectobjectclasswxTextCtrlnameID_TEXTCTRL6variableboost2ndAlgoParameterFieldmemberyesvalue2valuepos64264possize12021sizeenabled0enabledobjectobjectclasswxTextCtrlnameID_TEXTCTRL10variableboost3rdAlgoParameterFieldmemberyesvalue3valuepos64288possize12021sizeenabled0enabledobjectobjectclasswxTextCtrlnameID_TEXTCTRL18variableboost6thAlgoParameterFieldmemberyesvalue6valuepos224240possize12821sizeenabled0enabledobjectobjectclasswxTextCtrlnameID_TEXTCTRL20variableboost8thAlgoParameterFieldmemberyesvalue8valuepos224288possize12821sizeenabled0enabledfocused1focusedobjectobjectclasswxTextCtrlnameID_TEXTCTRL19variableboost9thAlgoParameterFieldmemberyesvalue9valuepos224312possize12821sizeenabled0enabledfocused1focusedobjectobjectclasswxTextCtrlnameID_TEXTCTRL9variableboost5thAlgoParameterFieldmemberyesvalue5valuepos224216possize12821sizeenabled0enabledobjectobjectclasswxTextCtrlnameID_TEXTCTRL8variableboost2ndAlgoParameterLabelmemberyesvalue2ndvaluepos24264possize4021sizebgwxSYS_COLOUR_APPWORKSPACEbgstylewxTE_READONLYwxTE_CENTREwxNO_BORDERstyleobjectobjectclasswxTextCtrlnameID_UPLIMITFIELDvariablelowerLimitFieldmemberyesvalue500valuepos64128possize7221sizeobjectobjectclasswxStaticTextnameID_LIBLABELvariablelibraryLabelmemberyeslabelLibrarylabelpos816posobjectobjectclasswxStaticTextnameID_ALGOLABELvariablealgorithmLabelmemberyeslabelAlgorithmlabelpos18416posobjectobjectclasswxChoicenameID_LIBCHOICEvariablelibraryChoicememberyescontentitemboostrandomitemitemMersenneTwisterhitemitemGMPitemcontentselection1selectionpos5616possize12021sizehandlerfunctionOnLibraryChoiceSelectentryEVT_CHOICEobjectobjectclasswxChoicenameID_ALGOCHOICEvariablealgorithmChoicememberyescontentitemMT19937itemcontentselection0selectionpos24016posobjectobjectclasswxStaticTextnameID_AMOUNTLABELvariableamountLabelmemberyeslabelAmountlabelpos848posobjectobjectclasswxTextCtrlnameID_AMOUNTFIELDvariableamountFieldmemberyesvalue100valuepos5648posobjectobjectclasswxStaticTextnameID_FILELABELvariablefileLabelmemberyeslabelFilelabelpos18448posobjectobjectclasswxTextCtrlnameID_FILEFIELDvariablefilenameFieldmemberyesvaluerandomtxtvaluepos21648possize15221sizeobjectobjectclasswxButtonnameID_OKBUTTONvariableokButtonmemberyeslabelOKlabelpos120512possize13623sizehandlerfunctionOnOkButtonClickentryEVT_BUTTONobjectobjectclasswxStaticTextnameID_SEEDLABELvariableseedLabelmemberyeslabelSeedlabelpos880posobjectobjectclasswxTextCtrlnameID_SEEDFIELDvariableseedFieldmemberyesvalue1234567890valuepos5680possize31221sizeobjectobjectclasswxTextCtrlnameID_TEXTCTRL1variableupperLimitFieldmemberyesvalue1000valuepos64152possize7221sizeenabled0enabledobjectobjectclasswxChoicenameID_DISTCHOICEvariabledistributionChoicememberyescontentitem32BitRealin01itemitem32BitRealin0nitemitem32BitRealin01itemitem32BitRealin0nitemitem32BitRealin01itemitem32BitRealin0nitemitemIntegerin02321itemitemIntegerin0nfornlt232itemitem53bitrealnumberin01itemitemNonuniformitemcontentselection0selectionpos232120possize12821sizehandlerfunctionOnDistributionChoiceSelectentryEVT_CHOICEobjectobjectclasswxTextCtrlnameID_TEXTCTRL3variableupperLimitLabelmemberyesvalueUppervaluepos24152possize4021sizebgwxSYS_COLOUR_APPWORKSPACEbgstylewxTE_READONLYwxTE_CENTREwxNO_BORDERstyleobjectobjectclasswxStaticTextnameID_STATICTEXT1variablebitsLabelmemberyeslabelBitslabelpos200152possize2413sizetooltipBitstouseinGMPLinearCongruentialalgorithmtooltipobjectobjectclasswxTextCtrlnameID_TEXTCTRL4variablebitsFieldmemberyesvalue64valuemaxlength20maxlengthpos232144possize12821sizeenabled0enabledobjectobjectclasswxCheckBoxnameID_CHECKBOX1variableboostAlgoParametersCheckboxmemberyeslabelEnablecustomizedalgorithmlabelpos30220poshandlerfunctionOnBoostAlgoParametersCheckboxClickentryEVT_CHECKBOXobjectobjectclasswxComboBoxnameID_COMBOBOX2variableComboBox1memberyescontentitemNothingitemitemCharReplaceitemcontentselection0selectionpos41632posobjectobjectclasswxComboBoxnameID_COMBOBOX1variablefirstPostprocChoicememberyescontentitemNothingitemitemCharReplaceitemcontentselection0selectionpos56832posobjectobjectclasswxStaticTextnameID_STATICTEXT2variablefirstPostprocLabelmemberyeslabelFirstlabelpos38432posobjectobjectclasswxStaticTextnameID_STATICTEXT3variablesecondPostprocLabelmemberyeslabelSecondlabelpos52032posobjectobjectresource;
        wxStaticBox* limitsBox;
        wxChoice* libraryChoice;
        wxTextCtrl* boost5thAlgoParameterField;
        wxStaticText* boost2ndDistributionLabelresourceobjectclasswxStaticTextnameID_STATICTEXT4variableboost1stDistParameterLabelmemberyeslabel1stlabelpos32384posobjectresource;
        wxTextCtrl* lowerLimitLabel;
        wxStaticText* boost4thDistParameterLabel;
        wxStaticText* seedLabel;
        wxTextCtrl* lowerLimitField;
        wxTextCtrl* boost3rdAlgoParameterLabel;
        wxCheckBox* boostAlgoParametersCheckbox;
        wxTextCtrl* boost3rdDistParameterBox;
        wxTextCtrl* boost4thAlgoParameterLabel;
        wxStaticBox* boostDistOptionsBox;
        wxComboBox* postprocMethodChoice;
        wxTextCtrl* boost2ndAlgoParameterField;
        wxTextCtrl* boost5thAlgoParameterLabel;
        wxTextCtrl* boost1stAlgoParameterField;
        wxTextCtrl* distributionLabel;
        wxStaticBox* StaticBox1;
        wxTextCtrl* boost2ndAlgoParameterLabel;
        wxTextCtrl* boost3rdAlgoParameterField;
        wxTextCtrl* boost8thAlgoParameterField;
        wxStaticText* boost3rdDistParameterLabel;
        wxStaticBox* boostAlgoOptionsBox;
        wxStaticBox* boostSpecificBox;
        wxChoice* algorithmChoice;
        wxTextCtrl* boost6thAlgoParameterField;
        wxTextCtrl* boost8thParamLabel;
        wxTextCtrl* boost4thDistParameterBox;
        wxTextCtrl* bitsField;
        wxStaticText* amountLabel;
        wxTextCtrl* boost7thAlgoParameterLabel;
        wxTextCtrl* upperLimitLabel;
        wxTextCtrl* boost9thParamLabel;
        wxTextCtrl* boost2ndDistParameterBox;
        wxTextCtrl* boost6thAlgoParameterLabel;
        wxChoice* distributionChoice;
        wxTextCtrl* boost7thAlgoParameterField;
        wxTextCtrl* filenameField;
        wxTextCtrl* upperLimitField;
        wxStaticText* bitsLabel;
        wxStaticText* fileLabel;
        wxStaticText* boost1stDistParameterLabel;
        wxStaticText* algorithmLabel;
        wxStaticText* libraryLabel;
        wxButton* okButton;
        wxChoice* postprocHashAlgoChoice;
        wxTextCtrl* boost1stAlgoParameterLabel;
        wxTextCtrl* boost9thAlgoParameterField;
        wxTextCtrl* seedField;
        wxTextCtrl* amountField;
        wxButton* generateSeedButton;
        wxStaticText* postprocHashAlgoLabel;
        wxStaticText* postprocLabel;
        wxTextCtrl* boost4thAlgoParameterField;
        //*)
        public:
        ///Custom functions
        ///Custom variables

        DECLARE_EVENT_TABLE()
};

#endif // MULTIRNGMAIN_H
