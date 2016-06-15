#ifndef PLAYERS_HPP
#define PLAYERS_HPP

#include "Hand.hpp"

class Players {
protected:
	std::string name;
	Hand* hand;

public:
	Players( std::string name, Container* deck) {
		this->name = name;
		hand = new Hand( deck );
	}
	bool empty( ) const;
	
	virtual void drawCard( Container* deck );
	virtual Card* playCard( int );
	
	virtual Card* pickCard( int& ) = 0;

	virtual ~Players() {
		delete hand;
	}
};

#endif // !PLAYERS_HPP
