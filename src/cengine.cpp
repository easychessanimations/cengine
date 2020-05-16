#include <iostream>
#include <string>

#include "piece.hpp"
#include "square.hpp"

extern "C" {

    void init() {
        std::cout << "cengine initialized " << uci_of_square(SQUARE_D4) << std::endl;
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