#include "Players.hpp"

class User : public Players {
public:
	User( Container* deck );

	Card* pickCard( int& );
	void showHand( ) const;
	Card* peekCard( int );

	~User( ) { };
};