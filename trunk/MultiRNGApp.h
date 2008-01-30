/***************************************************************
 * Name:      MultiRNGApp.h
 * Purpose:   Defines Application Class
 * Author:    Uli Koehler ()
 * Created:   2008-01-20
 * Copyright: Uli Koehler ()
 * License: GPLv2
 **************************************************************/

#ifndef MULTIRNGAPP_H
#define MULTIRNGAPP_H

#include <wx/app.h>

class MultiRNGApp : public wxApp
{
    public:
        virtual bool OnInit();
};

void StartMTH();

#endif // MULTIRNGAPP_H
