#include <iostream>
#include <string>
#include <cstdint>

#include "piece.hpp"
#include "square.hpp"
#include "bitboard.hpp"
#include "attack.hpp"

extern "C" {

    void init() {
        init_bitboards();
        init_attacks();

        /*Bitboard bb = jump_attack(SQUARE_B2, (Delta*)KNIGHT_DELTAS);        
        std::cout << pretty_bitboard(bb);

        std::cout << (int)variation_count(bb) << std::endl;

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
    uci_loop();
#endif

    return 0;
}
