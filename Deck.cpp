#include "Deck.hpp"

Deck::Deck( ) : Container( INIT_DECK_SIZE ) {
	int value;
	int index = 0;
	char symbols[] = { SYMBOL_CONCH, SYMBOL_CROWN, SYMBOL_STAR, SYMBOL_TRIDENT };

	//reconfig for shorter code
	for ( int j = 0; j < 4; j++ ) {
		value = 1;
		for ( int i = 0; i < 10; i++ ) {			
			//skiping 8 and 9.
			if ( i == 7 )
				value += 2;

			this->Cards[index] = new Card( value, symbols[j] );
			value++;
			index++;
		}
	}

	this->shuffle( );

	std::cout << "Done making the deck. size = " << Cards.size( ) << std::endl;
}

void Deck::shuffle( ) {

	for ( int i = 0; i < SHUFFLE_LOOP; i++ )
		for ( int j = 0; j < INIT_DECK_SIZE; j++ )
			this->swapCard( j, rand( ) % 40 );
}

//should be gone
void Deck::print( ) const {
	std::cout << "[ ";
	for ( int i = Cards.size() - 1 ; i >= 0; i-- ) {
		if ( i == Cards.size() - 6 )
			break;
		Cards[ i ]->print( );
	}
	std::cout << " ]\n";
}

bool Deck::empty( ) const {
	if ( Cards.size( ) <= 8 )
		return true;

	return false;
}