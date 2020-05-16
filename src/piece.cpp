#include <string>

#include "piece.hpp"

std::string figure_symbol(Figure fig) {
	return FIGURE_SYMBOLS[fig];
}

std::string fen_symbol_of(Piece p) {
	std::string sym = figure_symbol(figure_of(p));
	if(color_of(p) == BLACK){
		return sym;
	}
	sym[0] = toupper(sym[0]);
	return sym;
}

std::string san_symbol_of(Piece p) {
	return fen_symbol_of(color_figure(WHITE, figure_of(p)));
}

std::string uci_symbol_of(Piece p) {
	return figure_symbol(figure_of(p));
}

std::string san_letter_of(Piece p) {
	return san_symbol_of(p).substr(0, 1);
}