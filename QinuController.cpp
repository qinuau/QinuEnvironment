/*
 * Copyright (c) 2010 QINUAU.
 */

#ifndef _QINUCXX_QINUCONTROLLER
#define _QINUCXX_QINUCONTROLLER 1

#include "QinuController"

namespace Qinu 
{
    Controller::Controller (struct struct_plugin_args plugin_args)
    {
        this->qinu = plugin_args.qinu;

        // dispatch
        void (Qinu::Controller::*con_p) () = &Qinu::Controller::con;
        dispatch.insert(std::map <std::string, void (Qinu::Controller::*) ()>::value_type("con", con_p));
        void (Qinu::Controller::*foo_p) () = &Qinu::Controller::foo;
        dispatch.insert(std::map <std::string, void (Qinu::Controller::*) ()>::value_type("foo", foo_p)); 
    }

    Controller::~Controller () 
    {

    }

    void Controller::con ()  
    {   
        std::cout << "<h1>Welcome to this Framework!</h1><br />\r\n";
        std::cout << "<h4>copyright QINUAU 2010.</h4><br />\r\n";
    }

    void Controller::foo () 
    {
        std::cout << "fooooo!!!<br />\r\n";
    }
}

#endif
