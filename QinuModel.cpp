/*
 * Copyright (c) 2010 QINUAU.
 */

#ifndef _QINUCXX_QINUMODEL
#define _QINUCXX_QINUMODEL 1

#include "QinuModel"

namespace Qinu 
{
    Model::Model (struct struct_plugin_args plugin_args)
    {
        this->qinu = plugin_args.qinu;
    }

    Model::~Model () 
    {

    }
}

#endif
