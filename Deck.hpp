#ifndef DECK_HPP
#define DECK_HPP

#include "Container.hpp"

class Deck : public Container {
public:
	Deck( );

	void shuffle( );
	void print( ) const;
};
#endif // !DECK_HPP
