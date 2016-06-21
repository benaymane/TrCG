#ifndef TABLE_HPP
#define TABLE_HPP

#include "Container.hpp"

class Table : public Container {
private:
	int valueAllowed;
	char symbolAllowed;

public:
	Table( Container* );
	void addCard( Card* newCard );

	//getters
	int getValueAllowed( ) const;
	char getSymbolAllowed( ) const;

	//setter
	void setValueAllowed( int );
	void setSymbolAllowed( char );

	void print( ) const;
	bool empty( ) const;
private:
	bool checkValidity( ) const;
};
#endif // !TABLE_HPP