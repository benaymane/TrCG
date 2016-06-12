#ifndef TABLE_HPP
#define TABLE_HPP

#include "Container.hpp"

class Table : public Container {
private:
	int valueAllowed;
	char symbolAllowed;

public:
	Table( Container* );
	
	//getters
	int getValueAllowed( ) const;
	char getSymbolAllowed( ) const;

	//setter
	void setValueAllowed( const int& );
	void setSymbolAllowed( const char& );

	void print( ) const;
private:
	bool checkValidity( ) const;
};
#endif // !TABLE_HPP