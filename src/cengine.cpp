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
#include "uci.hpp"

#include "matein4.cpp"

#ifdef GCCBUILD
#define __EMSCRIPTEN_PTHREADS__
#endif

Uci uci;

LinearGame lg;

State *curr;

Depth do_search_depth;

int puzzle_ptr;

void *do_search(void *dummy){

    std::cout << "doing search" << std::endl;

    search(&lg, do_search_depth);

    return NULL;
}

void print_state(){
    std::cout << pretty_state(curr);
}

void set_multipv_callback(UciOption uo){
    lg.multipv = uo.int_value();
}

void position_command_callback(std::string specifier, std::string moves){
    if(specifier == "startpos"){
        lg.state_ptr=0;
        lg.states[0]=state_from_fen("");
        curr=&lg.states[0];                    
    }else{
        lg.state_ptr = 0;        
        lg.states[0] = state_from_fen(specifier);
        curr=&lg.states[0];                  
    }    
    if(moves != ""){
        std::string move_ucis[MAX_STATES];
        int num_moves = split(moves, " ", move_ucis);
        for(int i=0;i<num_moves;i++){
            make_uci_move(&lg, move_ucis[i]);
        }
        curr=&lg.states[lg.state_ptr];
    }
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
        init_bitboards();
        init_attacks();

        puzzle_ptr = 5;

        State st = state_from_fen("");

        lg.states[0] = st;
        lg.state_ptr = 0;
        lg.multipv = 3;

        curr=&lg.states[lg.state_ptr];

        search_stopped = true;

        uci = Uci()
            .set_engine_name("cengine")
            .set_engine_author("easychessanimations")
            .set_position_command_callback(position_command_callback)
            .set_command_aliases({
                {"m1", "setoption name MultiPV value 1"},
                {"m3", "setoption name MultiPV value 3"},
                {"m5", "setoption name MultiPV value 5"},
                {"vs", "setoption name UCI_Variant value Standard"},
                {"va", "setoption name UCI_Variant value Atomic"},
            })
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

        std::cout << pretty_state(&st) << std::endl;

        std::cout << "info string engine initialized\n" << std::endl;
    }

    void execute_uci_command(char* command_cstr) {
        std::string command = command_cstr;

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

            if(uci.execute_uci_command(command)){
                print_state();
                return;
            }

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

            if((command=="s")||(command == "stop")){
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

    while(true) {
        std::getline(std::cin, line);

        if (line == "x" || line == "exit" || line == "q" || line == "quit") {
            return;
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
