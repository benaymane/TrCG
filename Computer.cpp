#include "computer.hpp"
#include "Container.hpp"

Computer::Computer( Container * deck ): Players( "Computer", deck ) { 

};

int Computer::pickCard( ) {
	//just empty for now
	return -1;
}

Card* Computer::pickCard( int& choice, Container* table ) {
	//no a.i. about this, will change later
	//no SRP either
	
	for ( int i = 0; i < hand->getCards( ).size( );i++ ) {
		if ( hand->getCard( i )->getSymbol( ) == table->getCard( )->getSymbol( ) ||
			hand->getCard( i )->getValue( ) == table->getCard( )->getValue( ) ) {
			//table->addCard( hand->removeCard( i ) );
			return hand->getCard(i);
		}
	}
	
	return NULL;
}
//these all temporary
void Computer::removeCard( Card* card ) {
	for ( int i = 0; i < hand->getCards( ).size( ); i++ ) {
		if ( hand->getCard( i ) == card )
			hand->removeCard( i );
	}
}

char Computer::getBestSymbol( ) {
	int maxIdx = 0;
	int counter[ ] = { 0, 0, 0, 0 };

	for ( int i = 0; i < hand->getCards( ).size( ); i++ ) {
		switch ( hand->getCard( i )->getSymbol( ) ) {
		case SYMBOL_CONCH :
			counter[ 0 ]++;
			break;
		case SYMBOL_CROWN:
			counter[ 1 ]++;
			break;
		case SYMBOL_STAR:
			counter[ 2 ]++;
			break;
		case SYMBOL_TRIDENT:
			counter[ 3 ]++;
			break;
		}
	}

	for ( int i = 1; i < 4; i++ ) {
		if ( counter[ maxIdx ] < counter[ i ] )
			maxIdx = i;
	}

	return maxIdx;
}
