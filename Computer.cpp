#include "computer.hpp"
#include "Container.hpp"

Computer::Computer( Container * deck ): Players( "Computer", deck ) { 

};

Card* Computer::pickCard( int& choice ) {
	//just empty for now
	return NULL;
}

bool Computer::pickCard( int& choice, Container* table ) {
	//no a.i. about this, will change later
	//no SRP either
	
	for ( int i = 0; i < hand->getCards( ).size( );i++ ) {
		if ( hand->getCard( i )->getSymbol( ) == table->getCard( )->getSymbol( ) ||
			hand->getCard( i )->getValue( ) == table->getCard( )->getValue( ) ) {
			table->addCard( hand->removeCard( i ) );
			return true;
		}
	}
	
	return false;
}