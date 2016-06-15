#include "Players.hpp"

void Players::drawCard( Container* deck ) {
	hand->addCard( deck->removeCard( ) );
}

Card* Players::playCard( int index ) {
	return hand->removeCard( index );
}

bool Players::empty( ) const {
	return hand->empty( );
}