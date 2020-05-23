#include <iostream>
#include <string>
#include <cstdint>
#include <map>

#ifndef WASM
#include <thread>
#else
#include <pthread.h>
#endif

#include "main.hpp"
#include "piece.hpp"
#include "square.hpp"
#include "bitboard.hpp"
#include "attack.hpp"
#include "state.hpp"
#include "search.hpp"

#include "matein4.cpp"

#ifdef GCCBUILD
#define __EMSCRIPTEN_PTHREADS__
#endif

std::map<std::string, std::string> command_aliases = {
    {"m1", "setoption name MultiPV value 1"},
    {"m3", "setoption name MultiPV value 3"},
    {"m5", "setoption name MultiPV value 5"},
};

LinearGame lg;

State *curr;

Depth do_search_depth;

int puzzle_ptr;

void *do_search(void *dummy){

    std::cout << "doing search" << std::endl;

    search(&lg, do_search_depth);

    return NULL;
}

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

const int MAX_UCI_OPTIONS = 100;

class Uci{
public:
    std::string engine_name;
    std::string engine_author;
    int num_options;
    UciOption options[MAX_UCI_OPTIONS];    
    Uci set_engine_name(std::string _engine_name);
    Uci set_engine_author(std::string _engine_author);
    Uci add_option(UciOption uo);    
    std::string intro();
    std::string uci();
    UciOption* get_option_by_name(std::string name);
    void set_option(std::string name, std::string value);
    Uci(){
        num_options = 0;
    };
};

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

Uci uci;

void set_multipv_callback(UciOption uo){
    lg.multipv = uo.int_value();
}

void set_uci_variant_callback(UciOption uo){
    lg.state_ptr=0;
    lg.states[0]=state_from_fen("");
    curr=&lg.states[0];                    

    if(uo.value == "Atomic"){
        lg.states[0].atomic = true;
    }
}

extern "C" {

    void init() {
        puzzle_ptr = 5;

        init_bitboards();
        init_attacks();

        State st = state_from_fen("");

        search_stopped = true;

        uci = Uci()
            .set_engine_name("cengine")
            .set_engine_author("easychessanimations")
            .add_option(
                UciOption()
                .set_name("UCI_Variant")                
                .set_default_value("Standard")                
                .set_callback(set_uci_variant_callback)
            )        
            .add_option(
                UciOption()
                .set_name("MultiPV")
                .set_kind("spin")
                .set_default_value("1")
                .set_min_value("1")
                .set_max_value("20")
                .set_callback(set_multipv_callback)
            );        

        std::cout << uci.intro() << std::endl;
        
        //std::cout << "least attacker " << pretty_bitboard(ROOK_ATTACK[SQUARE_F8]) << std::endl;
        //std::cout << "least attacker " << pretty_bitboard(ROOK_MAGIC_ATTACK[SQUARE_F8]) << std::endl;
        //std::cout << "least attacker " << pretty_bitboard(rook_mobility(SQUARE_F8, 0, 0, true, true)) << std::endl;
        //std::cout << "least attacker " << pretty_bitboard(mobility_for_piece_at_square(&st, color_figure(BLACK, ROOK), SQUARE_F8, true, true)) << std::endl;

        //return;

        //std::cout << pretty_bitboard(st.by_color[WHITE]);

        //make_move(&st, move_ft(SQUARE_E2, SQUARE_E4));

        lg.states[0] = st;
        lg.state_ptr = 0;
        lg.multipv = 3;

        /*std::cout << pretty_bitboard(lg.states[lg.state_ptr].by_color[WHITE]);    
        std::cout << pretty_bitboard(lg.states[lg.state_ptr].by_color[BLACK]);*/

        std::cout << pretty_state(&st) << std::endl;

        /*BSPRINTF(sbuff, "buff %10s", "test");

        std::cout << sbuff << std::endl;*/

        /*for(Square sq=0;sq<BOARD_AREA;sq++){
            Bitboard bb = bitboard_of(sq);
            Square tsq = pop_square(&bb);
            std::cout << uci_of_square(tsq) << std::endl;
        }*/

        //perft(&lg, 5);

        /*Bitboard bb = rook_mobility(SQUARE_A1, bitboard_of(SQUARE_A2), bitboard_of(SQUARE_B7), true, true);
        std::cout << pretty_bitboard(ROOK_MAGIC_ATTACK[SQUARE_A1]);*/

        /*std::cout << (int)variation_count(bb) << std::endl;

        PartialMask mask = 0;

        while(mask < 5){            
            Bitboard partial_occup = mask_to_partial_occup(mask, bb);            
            std::cout << pretty_bitboard(partial_occup);           
            mask++;
        }*/

        std::cout << "info string engine initialized\n" << std::endl;
    }

    void print_state(){
        std::cout << pretty_state(curr);
    }

    void execute_uci_command(char* command_cstr) {
        std::string command = command_cstr;

        std::string alias = command_aliases[command];

        if(alias != ""){
            command = alias;
            std::cout << "++ " << command << std::endl;
        }

        if((command != "s")&&(command != "stop")) std::cout << std::endl;

        if (command == "x" || command == "exit" || command == "q" || command == "quit") {
            std::cout << command << " command recognized but not supported in this mode" << std::endl;
        } else {
            //std::cout << "received command " << command << std::endl;

            if(!search_stopped){
                if((command != "s")&&(command != "stop")){
                    std::cout << command << " command not allowed while searching" << std::endl;
                    return;
                }                
            }            

            if(command == "uci"){
                std::cout << uci.uci() << std::endl;
            }

            curr=&lg.states[lg.state_ptr];

            ToIntResult ti = to_int(command.c_str());

            Move* last_move = sorted_moves(curr);                

            if(ti.ok){                
                ti.value--;
                if((ti.value >= 0)&&(ti.value < (last_move-sorted_move_buff))){
                    push_state(&lg);
                    curr=&lg.states[lg.state_ptr];
                    make_move(curr, sorted_move_buff[ti.value]);
                    print_state();
                }
                return;
            }

            for(Move *ptr = sorted_move_buff; ptr < last_move; ptr++){
                if(move_to_san(curr, *ptr) == command){
                    push_state(&lg);
                    curr=&lg.states[lg.state_ptr];
                    make_move(curr, *ptr);
                    print_state();
                    return;
                }
            }

            if(command == "d"){                                
                if(lg.state_ptr>0){                    
                    lg.state_ptr--;
                    curr=&lg.states[lg.state_ptr];
                    print_state();
                }
                return;
            }

            if(command == "r"){   
                lg.state_ptr=0;
                lg.states[lg.state_ptr]=state_from_fen("");
                curr=&lg.states[lg.state_ptr];
                print_state();
                return;
            }

            if(command == "i"){
                print_state();
                return;
            }

            Tokenizer t = Tokenizer(command);

            std::string tcommand = t.get_token();

            if(tcommand == "setoption"){
                std::string dummy = t.get_token();
                if(dummy != "name"){
                    std::cout << "missing name specifier" << std::endl;
                    return;
                }
                std::string name = t.get_up_to("value");
                std::string value = t.get_up_to("");
                uci.set_option(name, value);
            }

            if(tcommand == "position"){
                std::string specifier = t.get_token();
                if(specifier == "startpos"){
                    lg.state_ptr=0;
                    lg.states[0]=state_from_fen("");
                    curr=&lg.states[0];                    
                }else if(specifier == "fen"){
                    lg.state_ptr = 0;
                    std::string fen = t.get_up_to("moves");
                    lg.states[0] = state_from_fen(fen);
                    curr=&lg.states[0];                  
                }else{
                    std::cout << "invalid position command specifier expected startpos or fen" << std::endl;
                    return;
                }                               
                std::string moves = t.get_up_to("moves");                
                if(moves == "") moves = t.get_up_to("");                
                if(moves != ""){
                    std::string move_ucis[MAX_STATES];
                    int num_moves = split(moves, " ", move_ucis);
                    for(int i=0;i<num_moves;i++){
                        make_uci_move(&lg, move_ucis[i]);
                    }
                }
                return;
            }

            std::string tokens[20];
            int num_tokens = split(command, " ", tokens);

            command = tokens[0];

            if(command == "p"){
                int depth = 5;
                if(num_tokens > 1){                    
                    ti = to_int(tokens[1].c_str());
                    if(ti.ok){
                        depth = ti.value;
                    }
                }
                if(depth <= 0) depth = 1;
                if(depth > 6) depth = 7;
                std::cout << "doing perft " << depth << std::endl << std::endl;
                perft(&lg, depth);
                std::cout << std::endl;
                return;
            }

            if(command=="g"){
                search_stopped = false;
                int depth = MAX_STATES - 1;
                if(num_tokens > 1){                    
                    ti = to_int(tokens[1].c_str());
                    if(ti.ok){
                        depth = ti.value;
                    }
                }
#ifndef WASM
                std::thread search_th(search, &lg, depth);
                search_th.detach();
#else
#ifdef __EMSCRIPTEN_PTHREADS__
                pthread_t t1;

                do_search_depth = depth;

                pthread_create(&t1, NULL, &do_search, NULL);
#else
                search(&lg, depth);
#endif
#endif
            }

            if(command=="s"){
                search_stopped = true;
            }

            std::string puzzle_solution = "";

            std::string set_fen = "";

            if(command == "u"){
                puzzle_ptr += ( gen_magic() & 0x3f ) + 3;
                if(puzzle_ptr > 460) puzzle_ptr = 0;

                Puzzle pu = PUZZLES[puzzle_ptr];

                puzzle_solution = pu.solution;

                command = "f";

                set_fen = pu.fen;
            }

            if(command == "f"){
                lg.state_ptr = 0;
                std::string fen = set_fen;
                if(fen == ""){
                    for(int i = 1; i < num_tokens; i++){
                        fen += tokens[i];
                        if(i < (num_tokens - 1)){
                            fen += " ";
                        }
                    }
                }                
                lg.states[0] = state_from_fen(fen);
                print_state();
            }

            if(puzzle_solution != ""){
                std::cout << std::endl << puzzle_solution << std::endl << std::endl;
            }

            if(command == "a"){
                lg.states[lg.state_ptr].atomic = !lg.states[lg.state_ptr].atomic;
                std::cout << (lg.states[lg.state_ptr].atomic ? "atomic on" : "atomic off") << std::endl << std::endl;
            }
        }
    }

}

void uci_loop() {
    std::string line;
    bool ok = true;

    while (ok) {
        std::getline(std::cin, line);

        if (line == "x" || line == "exit" || line == "q" || line == "quit") {
            ok = false;
        }

        execute_uci_command((char*)line.c_str());
    }
}

int main() {        
    init();
    
#ifndef WASM
    uci_loop();
#endif

#ifdef GCCBUILD
    uci_loop();
#endif

    return 0;
}
