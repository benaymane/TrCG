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
	void addCard( Card* );
	Card* removeCard( int = -1);
	Card* getCard( const int& );

	virtual void print( ) const;
	virtual void shuffle( ) {};

	virtual int getAllowedValue( ) const { return -1; };
	virtual char getAllowedSymbol( ) const { return 0xA; };
	virtual void setAllowedValue( ) {};
	virtual void setAllowedSymbol( ) {};
private:
	int lastCardIndex( );
};

#endif // !CONTAINER_HPP
