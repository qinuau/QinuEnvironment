/*
 * Copyright (c) 2010 QINUAU.
 */

#ifndef _QINUCXX_QINUENVIRONMENT
#define _QINUCXX_QINUENVIRONMENT 1

#include "QinuEnvironment"

namespace Qinu 
{
    Environment::Environment ()  
    {
        if (std::getenv("QUERY_STRING") != false && strcmp(std::getenv("QUERY_STRING"), "") != 0) {
            std::map <std::string, std::string> query_string_hash; 

            char *query_string = (char *)malloc(sizeof(char *));
            query_string = std::getenv("QUERY_STRING");
            char **query_string_splited = (char **)malloc(SIZE_POINTER_ARRAY);
            query_string_splited = split(query_string_splited, query_string, "&");

            char **query_string_splited_each = (char **)malloc(SIZE_POINTER_ARRAY);
            char **query_string_splited_each_mem = query_string_splited_each;

            int i = 0;
            while (1) {
                if (query_string_splited[i] == false) {
                    break;
                }

                query_string_splited_each = split(query_string_splited_each, query_string_splited[i], "=");
                query_string_hash.insert(std::map<std::string, std::string>::value_type(query_string_splited_each[0], query_string_splited_each[1]));
                i++;
            }
            query_string_splited_each = query_string_splited_each_mem;
            free(query_string_splited_each);

            char **q_splited = (char **)malloc(SIZE_POINTER_ARRAY);
            char **q_splited_mem = q_splited;
            q_splited = split(q_splited, (char *)query_string_hash["q"].c_str(), "/");
            action = q_splited[0];

            i = 1;
            while (1) {
                if (q_splited[i] == false) {
                    break;
                }
                std::string key(q_splited[i]);
                std::string value;
                if (q_splited[i + 1]) {
                    value = q_splited[i + 1];
                }
                else {
                    value = "";
                }
                path_info_ary.insert(std::map<std::string, std::string>::value_type(key, value));
                i += 2;
            }
            query_string_hash.clear();

            q_splited = q_splited_mem;
            free(q_splited);

            // dispatch and assign library
            assign_library();

            if (controller->dispatch[action] != false) {
                void (Qinu::Controller::*p) () = controller->dispatch[action];
                (controller->*p)();
            }
            else {
                void (Qinu::Controller::*p) () = controller->dispatch["con"];
                (controller->*p)();
            }
        }
        else {
            // dispatch and assign library
            assign_library();

            void (Qinu::Controller::*p) () = controller->dispatch["con"];
            (controller->*p)();
        }
    }

    Environment::~Environment () 
    {

    }

    void Environment::assign_library () 
    {
            struct struct_plugin_args plugin_args;
            plugin_args.qinu = this;

            // dispatch
            this->view = new Qinu::View(plugin_args);
            this->model = new Qinu::Model(plugin_args);
            this->controller = new Qinu::Controller(plugin_args);

            // Plugin assign
            //class_member_plugin_name = new Qinu::PluginName(plugin_args);
    }
}

#endif

