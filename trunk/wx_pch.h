/***************************************************************
 * Name:      wx_pch.h
 * Purpose:   Header to create Pre-Compiled Header (PCH)
 * Author:    Uli Koehler ()
 * Created:   2008-01-20
 * Copyright: Uli Koehler ()
 * License:
 **************************************************************/

#ifndef WX_PCH_H_INCLUDED
#define WX_PCH_H_INCLUDED

// basic wxWidgets headers
#include <wx/wxprec.h>

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#ifdef WX_PRECOMP
    // put here all your rarely-changing header files
#endif // WX_PRECOMP
///Custom header includes
#include <fstream>
#include <gmp.h>
#include <boost/lexical_cast.hpp>
#include <boost/random.hpp>
#include <boost/random/additive_combine.hpp>
#include <boost/random/linear_congruential.hpp>
#include <boost/random/inversive_congruential.hpp>
#include <boost/random/shuffle_output.hpp>
#include <boost/random/lagged_fibonacci.hpp>
#include <iostream>
#include <MersenneTwister.h>
#include <boost/thread.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#endif // WX_PCH_H_INCLUDED
