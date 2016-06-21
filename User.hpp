#include "Players.hpp"

class User : public Players {
public:
	User( Container* deck );

	int pickCard( void );
	void showHand( ) const;
	Card* peekCard( int );

	~User( ) { };
};