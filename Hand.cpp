#include "Hand.hpp"

Hand::Hand( Container* deck ) : Container(INIT_HAND_SIZE) {
	for ( int i = 0; i < INIT_HAND_SIZE; i++ )
		Cards[i] = deck->removeCard( );
}

void Hand::print( ) const {
	for ( int i = 0; i < Cards.size( ); i++ ) {
		std::cout << "[ " << i + 1 << " ] ";
		Cards[ i ]->print( );
	}
}