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

        Bitboard bb = 0x3000000000000001;        
        std::cout << pretty_bitboard(bb);

        std::cout << (int)pop_cnt(bb) << std::endl;

        PartialMask mask = 0;

        while(mask < variation_count(bb)){            
            Bitboard partial_occup = mask_to_partial_occup(mask, bb);
            std::cout << pretty_bitboard((Bitboard)mask);
            std::cout << pretty_bitboard(partial_occup);           
            mask++;
        }

        std::cout << "cengine initialized\n" << std::endl;
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
