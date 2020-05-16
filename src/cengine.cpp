#include <iostream>
#include <string>

#include "piece.hpp"
#include "square.hpp"
#include "bitboard.hpp"

extern "C" {

    void init() {
        init_bitboards();

        Bitboard bb = 0x0f00000000000f00;
                
        std::cout << pretty_bitboard(bb);
        while(bb != 0){            
            SquareBitboard sqb = pop_square_bitboard(&bb);                        
            std::cout << pretty_bitboard(bb);
            std::cout << uci_of_square(sqb.sq) << std::endl;            
            std::cout << pretty_bitboard(sqb.bb);
        }

        std::cout << "cengine initialized\n" << std::endl;
    }

    void execute_uci_command(char* command_cstr) {
        std::string command = command_cstr;
        if (command == "x" || command == "exit" || command == "q" || command == "quit") {
            std::cout << command << " command recognized but not supported in this mode" << std::endl;
        }
        else {
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
