/***************************************************************
 * Name:      MultiRNGApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Uli Koehler ()
 * Created:   2008-01-20
 * Copyright: Uli Koehler ()
 * License: GPLv2
 **************************************************************/

#include "wx_pch.h"
#include "MultiRNGApp.h"

//(*AppHeaders
#include "MultiRNGMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(MultiRNGApp);
///Declare commonly used Frame.
static MultiRNGFrame* Frame;
static boost::function<void(void)> genrandmth = boost::bind(&GenRandMTH, _1)(Frame);

bool MultiRNGApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	Frame = new MultiRNGFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

    ///Init Boost function pointers

}

typedef unsigned long ulong;

void GenRandMTH(MultiRNGFrame* frame) ///Generate PRN using MersenneTwister.h
{
    unsigned long amount = lexical_cast<unsigned long>(frame->amountField->GetValue().mb_str());
    unsigned long seed = lexical_cast<unsigned long>(frame->seedField->GetValue().mb_str());

    MTRand mtr(seed);

    ///Open fstream
    fstream f.open(lexical_cast<string>(frame->filenameField->GetValue().mb_str()).c_str(), fstream::out);

    unsigned long i = 0;
    ///Init progressGauge
    int steps = (int)floor(amount / 1000);
    progressGauge->SetRange(steps);

    ///Get values of limit fields
    double llDouble = lexical_cast<double>(frame->lowerLimitField->GetValue().mb_str());
    double ulDouble = lexical_cast<double>(frame->upperLimitField->GetValue().mb_str());
    unsigned long ulLong = lexical_cast<unsigned long>(upperLimitField->GetValue().mb_str());

    ///Get random number and
    switch(frame->distributionChoice->GetCurrentSelection())
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
                                        f << mtr.rand(ulDouble) << endl;
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
                                        f << mtr.randExc(ulDouble) << endl;
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
                                        f << mtr.randDblExc(ulDouble) << endl;
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
                                        f << mtr.randInt(ulLong) << endl;
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
                                        f << mtr.randNorm(llDouble, ulDouble) << endl;
                                    }
                                break;
                            }
                        default: break;
                    }
        f.close();

}
