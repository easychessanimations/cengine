#ifndef UCI_HPP

#define UCI_HPP

#include <iostream>
#include <string>
#include <cstdint>
#include <map>

#include "main.hpp"

class UciOption;

typedef void SetOptionCallback(UciOption);

class UciOption {
public:
    std::string name;
    std::string kind;
    std::string *vars;
    std::string default_value;
    std::string value;
    std::string min_value;
    std::string max_value;
    SetOptionCallback* callback;
    int int_value();
    UciOption set_name(std::string _name);
    UciOption set_kind(std::string _kind);
    UciOption set_default_value(std::string _default_value);
    UciOption set_value(std::string _value);
    UciOption set_min_value(std::string _min_value);
    UciOption set_max_value(std::string _max_value);
    UciOption set_callback(SetOptionCallback* _callback);
    std::string show();
    UciOption(){
        name = "";
        kind = "string";
        value = "";
        default_value = "";
        callback = NULL;
    };
};

const int MAX_UCI_OPTIONS = 100;

typedef void PositionCommandCallback(std::string specifier, std::string moves);

class Uci{
public:
    std::string engine_name;
    std::string engine_author;
    int num_options;
    UciOption options[MAX_UCI_OPTIONS];    
    std::map<std::string, std::string> command_aliases;
    PositionCommandCallback* position_command_callback;
    Uci set_engine_name(std::string _engine_name);
    Uci set_engine_author(std::string _engine_author);
    Uci add_option(UciOption uo);    
    std::string intro();
    std::string uci();
    UciOption* get_option_by_name(std::string name);
    void set_option(std::string name, std::string value);
    std::string pretty_option_list();
    Uci set_position_command_callback(PositionCommandCallback* _callback);
    Uci set_command_aliases(std::map<std::string, std::string> _command_aliases);
    bool execute_uci_command(std::string command);
    Uci(){
        num_options = 0;
        position_command_callback = NULL;
        command_aliases = {};
    };
};


#endif