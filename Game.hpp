#include "Container.hpp"

#include "Card.hpp"
#include "Deck.hpp"
#include "Table.hpp"
#include "User.hpp"
#include "computer.hpp"

class Game {
private:
	Deck* deck;
	Table* table;

	User* user;
	Computer* comp;

	turn turn;

public:
	Game( );

	void launch( );
	void userPickMediator( int& );

private:
	void menu( );
	void promptUser( int& );
	bool checkCard( Card* );
	bool checkWon( );
	void switchTurns( );
	void fillDeck( );
};