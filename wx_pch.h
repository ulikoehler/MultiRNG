/***************************************************************
 * Name:      wx_pch.h
 * Purpose:   Header to create Pre-Compiled Header (PCH)
 * Author:    Uli Koehler
 * Created:   2008-01-20
 * Copyright: (c) Uli Koehler 2007-2008
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
#include <iostream>
#include <MersenneTwister.h>
//Boost headers
#include <boost/random.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>
///Include boost thread if multithreading is not disabled
#ifndef NOMTHREADING
    #include <boost/thread.hpp>
#endif
#endif // WX_PCH_H_INCLUDED
