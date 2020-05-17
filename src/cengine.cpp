#include <iostream>
#include <string>
#include <cstdint>

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

        std::cout << pretty_state(st) << std::endl;

        perft(&lg, 5);

        /*Bitboard bb = queen_mobility(SQUARE_E4, bitboard_of(SQUARE_E6), bitboard_of(SQUARE_F4), true, true);
        std::cout << pretty_bitboard(bb);*/

        /*std::cout << (int)variation_count(bb) << std::endl;

        PartialMask mask = 0;

        while(mask < 5){            
            Bitboard partial_occup = mask_to_partial_occup(mask, bb);            
            std::cout << pretty_bitboard(partial_occup);           
            mask++;
        }*/

        std::cout << "info string engine initialized\n" << std::endl;
    }

    void execute_uci_command(char* command_cstr) {
        std::string command = command_cstr;

        if (command == "x" || command == "exit" || command == "q" || command == "quit") {
            std::cout << command << " command recognized but not supported in this mode" << std::endl;
        } else {
            std::cout << "received command " << command << std::endl;
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
    //uci_loop();
#endif

    return 0;
}
