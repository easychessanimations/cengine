#include <iostream>
#include <string>
#include <cstdint>

#include "main.hpp"
#include "piece.hpp"
#include "square.hpp"
#include "bitboard.hpp"
#include "attack.hpp"
#include "state.hpp"

LinearGame lg;

extern "C" {

    void init() {
        init_bitboards();
        init_attacks();

        State st = state_from_fen("");

        //std::cout << pretty_bitboard(st.by_color[WHITE]);

        //make_move(&st, move_ft(SQUARE_E2, SQUARE_E4));

        lg.states[0] = st;
        lg.state_ptr = 0;

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

    State *curr;

    void print_state(){
        std::cout << pretty_state(curr);
    }

    void execute_uci_command(char* command_cstr) {
        std::string command = command_cstr;

        std::cout << std::endl;

        if (command == "x" || command == "exit" || command == "q" || command == "quit") {
            std::cout << command << " command recognized but not supported in this mode" << std::endl;
        } else {
            //std::cout << "received command " << command << std::endl;

            curr=&lg.states[lg.state_ptr];

            if(command == "p"){
                perft(&lg, 5);
                return;
            }

            ToIntResult ti = to_int(command.c_str());

            if(ti.ok){                
                Move* last_move = sorted_moves(curr);                
                if((ti.value >= 0)&&(ti.value < (last_move-sorted_move_buff))){
                    push_state(&lg);
                    curr=&lg.states[lg.state_ptr];
                    make_move(curr, sorted_move_buff[ti.value]);
                    print_state();
                }
                return;
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
                curr=&lg.states[lg.state_ptr];
                print_state();
                return;
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

    return 0;
}
