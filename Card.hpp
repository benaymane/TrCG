#ifndef CARD_HPP
#define CARD_HPP

#include <string>
#include <iostream>

#include "Phrases.hpp"

class Card {
private:
	int value;
	char symbol;

public:
	Card( int&, char& );

	//getter
	int getValue( ) const;
	char getSymbol( ) const;
	std::string getFullSymbol( ) const;

	void print( ) const;
};

#endif // !CARD_HPP
