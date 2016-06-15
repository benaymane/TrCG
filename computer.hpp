#include "Players.hpp"

class Computer : public Players {
public:
	Computer( Container* deck );

	Card* pickCard( int& );
	bool pickCard( int&, Container* );

	~Computer( ) { };
};