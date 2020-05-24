#include <iostream>

#include "uci.hpp"
#include "main.hpp"

UciOption UciOption::set_callback(SetOptionCallback* _callback){
    callback = _callback;
    return *this;
}

int UciOption::int_value(){
    ToIntResult ti = to_int(value.c_str());
    if(ti.ok){
        return ti.value;
    }
    return 0;
}

UciOption UciOption::set_name(std::string _name){
    name = _name;
    return *this;
}

UciOption UciOption::set_kind(std::string _kind){
    kind = _kind;
    return *this;
}

UciOption UciOption::set_default_value(std::string _default_value){
    default_value = _default_value;
    value = _default_value;
    return *this;
}

UciOption UciOption::set_value(std::string _value){
    value = _value;
    if(callback){
        callback(*this);
    }
    return *this;
}

UciOption UciOption::set_min_value(std::string _min_value){
    min_value = _min_value;
    return *this;
}

UciOption UciOption::set_max_value(std::string _max_value){
    max_value = _max_value;
    return *this;
}

std::string UciOption::show(){
    std::string buff = "option name " + name + " type " + kind + " default " + default_value;
    if(kind == "spin"){
        buff += " min " + min_value + " max " + max_value;
    }
    return buff;
}

std::string Uci::pretty_option_list(){
    std::string buff = "";
    for(int i=0;i<num_options;i++){
        UciOption uo = options[i];
        BSPRINTF(ubuff, "%-30s", uo.name.c_str());
        buff += ubuff;
        buff += " = " + uo.value + "\n";
    }
    return buff;
}

UciOption* Uci::get_option_by_name(std::string name){
    for(int i=0;i<num_options;i++){
        if(options[i].name == name){
            return &options[i];
        }
    }
    return NULL;
}

void Uci::set_option(std::string name, std::string value){
    UciOption* uo = get_option_by_name(name);
    if(!uo){
        std::cout << "warning invalid option" << std::endl;
    }
    uo->set_value(value);
}

Uci Uci::set_engine_name(std::string _engine_name){
    engine_name = _engine_name;
    return *this;
}

Uci Uci::set_engine_author(std::string _engine_author){
    engine_author = _engine_author;
    return *this;
}

Uci Uci::add_option(UciOption uo){
    options[num_options++] = uo;
    return *this;
}

std::string Uci::intro(){
    return engine_name + " by " + engine_author + "\n";
}

std::string Uci::uci(){
    std::string buff = "id name " + engine_name + "\nid author " + engine_author + "\n\n";
    for(int i=0;i<num_options;i++){
        buff += options[i].show() + "\n";
    }
    return buff + "uciok" + "\n";
}

Uci Uci::set_position_command_callback(PositionCommandCallback* _callback){
	position_command_callback = _callback;
	return *this;
}

Uci Uci::set_go_command_callback(GoCommandCallback* _callback){
	go_command_callback = _callback;
	return *this;
}

bool Uci::execute_uci_command(std::string command){
	std::string alias = command_aliases[command];

    if(alias != ""){
        command = alias;
        std::cout << "++ " << command << std::endl;
    }

	Tokenizer t = Tokenizer(command);

    std::string tcommand = t.get_token();

    if(command == "la"){
        for (auto const& x : command_aliases){
            if(x.second != ""){
                std::cout << x.first << " : " << x.second << std::endl;
            }
        }
        std::cout << std::endl;
        return true;
    }

    if(command == "lu"){
        std::cout << pretty_option_list() << std::endl;
        return true;
    }

    if(tcommand == "setoption"){
        std::string dummy = t.get_token();
        if(dummy != "name"){
            std::cout << "missing name specifier" << std::endl;
            return false;
        }
        std::string name = t.get_up_to("value");
        std::string value = t.get_up_to("");
        set_option(name, value);        
        return true;
    }

    if(tcommand == "position"){
    	if(!position_command_callback) return false;

        std::string specifier = t.get_token();
        std::string fen = "";
        if(specifier == "startpos"){
            fen = "startpos";
        }else if(specifier == "fen"){
            fen = t.get_up_to("moves");            
        }else{
            std::cout << "invalid position command specifier expected startpos or fen" << std::endl;
            return false;
        }                               
        std::string moves = t.get_up_to("moves");                
        if(moves == "") moves = t.get_up_to("");                
        position_command_callback(fen, moves);
        return true;
    }

    if((tcommand == "go")||(tcommand == "g")){
    	if(!go_command_callback){
    		return false;
    	}

    	GoParams go_params = GoParams{
    		0,
    		0,
    	};

    	while(true){
    		std::string token = t.get_token();
    		if(token == "") break;
    		if(token == "depth"){
    			ToIntResult ti = to_int(t.get_token().c_str());
				if(ti.ok){
					go_params.depth = ti.value;
				}else{
					std::cout << "invalid search depth" << std::endl;
				}
    		}
    		if(token == "time"){
    			ToIntResult ti = to_int(t.get_token().c_str());
				if(ti.ok){
					go_params.time = ti.value;
				}else{
					std::cout << "invalid search time" << std::endl;
				}
    		}
    	}

    	go_command_callback(go_params);
    }

    if(tcommand == "uci"){
        std::cout << uci() << std::endl;
        return true;        
    }

    return false;
}

Uci Uci::set_command_aliases(std::map<std::string, std::string> _command_aliases){
	command_aliases = _command_aliases;
	return *this;
}
