#include "Card.hpp"

Card::Card( int& value, char& symbol ) {
	this->value = value;
	this->symbol = symbol;
}

int Card::getValue( ) const {
	return this->value;
}

char Card::getSymbol( ) const {
	return this->symbol;
}

std::string Card::getFullSymbol( ) const {
	switch ( this->symbol ) {
		case SYMBOL_CONCH:
			return STR_CONCH;

		case SYMBOL_CROWN:
			return STR_CROWN;

		case SYMBOL_STAR:
			return STR_STAR;

		case SYMBOL_TRIDENT:
			return STR_TRIDENT;

		default:
			return "";
	}
}

void Card::print( ) const {
	std::cout << "( " << this->value
		<< ", " << this->symbol << " ) -- ";
}