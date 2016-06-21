#include "Table.hpp"

Table::Table( Container* deck ) {
	while ( true ) {
		this->addCard( deck->removeCard( ) );

		if ( checkValidity( ) ) {
			std::cout << "IN";
			valueAllowed = Cards[0]->getValue( );
			symbolAllowed = Cards[0]->getSymbol( );
			break;
		}

		deck->addCard( removeCard( ) );
	}
}
void Table::addCard( Card* newCard ) {
	//Container::addCard( newCard );
	Cards.push_back( newCard );
	valueAllowed = newCard->getValue( );
	symbolAllowed = newCard->getSymbol( );
	//std::cout << "added to table: " << newCard->getValue( )
		//<< " New value is: " << valueAllowed << std::endl;
}

int Table::getValueAllowed( ) const {
	return valueAllowed;
}

char Table::getSymbolAllowed( ) const {
	return symbolAllowed;
}

void Table::setValueAllowed( int value ) {
	valueAllowed = value;
}

void Table::setSymbolAllowed( char symbol ) {
	symbolAllowed = symbol;
}

void Table::print( ) const {
	std::cout << "[ ( "
		<< Cards[ Cards.size( ) - 1 ]->getValue( )
		<< ", "
		<< symbolAllowed
		<< " ) ]\n";
}

bool Table::checkValidity( ) const {
	switch ( Cards[ 0 ]->getValue( ) ) {
		case 1:
			return false;
		case 2:
			return false;
		case 7:
			return false;
		default:
			return true;
	}
}

bool Table::empty( ) const{
	if ( Cards.size( ) <= 1 )
		return true;
	return false;
}