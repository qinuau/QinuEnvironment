/*
 * Copyright (c) 2010 QINUAU.
 */

#ifndef _QINUCXX_QINUVIEW
#define _QINUCXX_QINUVIEW 1

#include "QinuView"

namespace Qinu 
{
    View::View (struct struct_plugin_args plugin_args)
    {
        this->qinu = plugin_args.qinu;
    }

    View::~View () 
    {

    }

    void View::process (std::map <std::string, std::string> args) 
    {

    }
}

#endif
