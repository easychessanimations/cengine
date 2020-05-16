#include <iostream>
#include <string>

#include "piece.hpp"
#include "square.hpp"
#include "bitboard.hpp"

extern "C" {

    void init() {
        init_bitboards();

        Bitboard bb = 0x0000000000000f00;
                
        std::cout << pretty_bitboard(bb);
        while(bb != 0){            
            SquareBitboard sqb = pop_square_bitboard(&bb);                        
            std::cout << pretty_bitboard(bb);
            std::cout << uci_of_square(sqb.sq) << std::endl;            
            std::cout << pretty_bitboard(sqb.bb);
        }

        std::cout << "cengine initialized\n" << std::endl;
    }

    void execute_uci_command(char* command) {
        std::cout << "received command " << command << std::endl;
    }

}

int main() {        
    init();

    std::string line;
    bool ok = true;

    while (ok) {
        std::getline(std::cin, line);

        execute_uci_command((char*)line.c_str());

        if (line == "x" || line == "exit" || line == "q" || line=="quit") {
            ok = false;
        }
    }    

    return 0;
}