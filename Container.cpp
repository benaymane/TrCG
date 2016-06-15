#include "Container.hpp"

Container::Container( const int& size ) {
	Cards.resize( size );
}

void Container::addCard( Card* newCard ) {
	Cards.push_back( newCard );
}

//public
Card* Container::removeCard( int index ) {
	if ( index == -1 )
		index = lastCardIndex( );

	if ( index >= Cards.size( ) )
		return NULL;

	Card* cardSave = Cards[ index ];
	
	for ( int i = index; i < Cards.size( ); i++ ) {
		if ( i < Cards.size( ) - 1 ) {
			Cards[ i ] = Cards[ i + 1 ];
		}
	}

	Cards.resize( Cards.size( ) - 1 );

	return cardSave;
}

Card* Container::getCard( int index ) {
	if ( index == -1 )
		return Cards[ Cards.size( ) - 1 ];

	return Cards[ index ];
}

int Container::lastCardIndex( ) {
	return Cards.size( ) - 1;
}

void Container::print( ) const {
	std::cout << "[ ";

	for ( auto card : Cards )
		card->print( );

	std::cout << " ]\n";
}

bool Container::empty( ) {
	return Cards.empty( );
}

//protected
bool Container::swapCard( const int& aIdx, const int& bIdx ) {
	if ( aIdx >= Cards.size( ) || bIdx >= Cards.size( ) )
		return false;
	
	if ( aIdx == bIdx )
		return true;

	Card* cardSave = Cards[ aIdx ];
	Cards[ aIdx ] = Cards[ bIdx ];
	Cards[ bIdx ] = cardSave;

	return true;
}

//private
