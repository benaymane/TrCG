#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <vector>
#include <time.h>

#include "Card.hpp"

class Container {
protected:
	std::vector<Card*> Cards;
	bool swapCard( const int&, const int& );

public:
	//Constructors
	Container( ) { };
	Container( const int& );

	//Container functionality
	virtual void addCard( Card* );
	Card* removeCard( int = -1);
	Card* getCard( int = -1 );
	virtual bool empty( );

	virtual void print( ) const;
	virtual void shuffle( ) {};

	virtual int getValueAllowed( ) const { return -1; };
	virtual char getSymbolAllowed( ) const { return 0xA; };
	virtual void setAllowedValue( ) {};
	virtual void setAllowedSymbol( ) {};

	//this is temporary for non-inteligent computer
	virtual std::vector<Card*> getCards( ) { return Cards; }
private:
	int lastCardIndex( );
};

#endif // !CONTAINER_HPP
