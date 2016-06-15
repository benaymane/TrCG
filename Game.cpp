#include "Game.hpp"

Game::Game( ) {
	deck = new Deck( );
	table = new Table( deck );
	user = new User( deck );
	comp = new Computer( deck );
	turn = user_turn;
}

void Game::launch( ) {
	std::cout << "LUNCHING GAME!!!\n";
	int choice;
	int cardIdx = -1;
	//Card* cardPtr;
	while ( !checkWon( ) ) {
		fillDeck( );
		if ( turn == user_turn ) {
			menu( );
			choice = -1;
			while ( choice == -1 ) {
				promptUser( choice );

				switch ( choice ) {
				case 1:
					userPickMediator( choice );
					switchTurns( );
					break;
				case 2:
					user->drawCard( deck );
					switchTurns( );
					break;
				case 3:
					std::cout << "DEFEAT!!!!\n";
					return;
				}
			}
		}
		else {
			std::cout << "Computer turn...\n";
			if ( !comp->pickCard( choice, table ) ) {
				std::cout << "Computer drew a card...\n";
				comp->drawCard( deck );
			}
			switchTurns( );
		}
	}
}

void Game::menu( ) {
	std::cout << "Table: ";
	table->print( );
	std::cout << "Your hand: ";
	user->showHand( );
	std::cout << "\n========================\n"
		<< "= 1. Play a card       =\n"
		<< "= 2. Draw a card       =\n"
		<< "= 3. Forfeit           =\n"
		<< "========================\n";
		//<< "Option: ";
		//<< "Your hand: ";
	//user->showHand( );
}

void Game::promptUser( int& choice ) {
	while ( true ) {
		std::cout << "\nPlease enter your choice: ";
		std::cin >> choice;
		if ( choice == 1 || choice == 2 || choice == 3 )
			break;
	}
}

void Game::userPickMediator( int& choice ) {
	int cardIdx = -1;
	while ( true ) {
		if ( user->pickCard( cardIdx ) == NULL ) {
			choice = -1;
			break;
		}

		if ( checkCard( user->peekCard( cardIdx ) ) ) {
			table->addCard( user->playCard( cardIdx ) );
			break;
		}
	}
	
}

bool Game::checkCard( Card* futureCard ) {
	if ( futureCard->getSymbol( ) == table->getSymbolAllowed( ) ||
		futureCard->getValue( ) == table->getValueAllowed( ) )
		return true;

	std::cout << "table = " << table->getSymbolAllowed() << " and " << table->getValueAllowed() << std::endl;
	std::cout << "card = " << futureCard->getSymbol( ) << " and " << futureCard->getValue( ) << std::endl;
	return false;
}

//reversed
bool Game::checkWon( ) {
	if ( turn == user_turn ) {
		if ( comp->empty( ) ) {
			std::cout << "DEFEAT!!!!!\n";
			return true;
		}
		return false;
	}

	if ( user->empty( ) ) {
		std::cout << "YOU WON!!!\n";
		return true;
	}
	return false;
}

void Game::switchTurns( ) {
	if ( turn == user_turn )
		turn = computer_turn;
	else
		turn = user_turn;
}

void Game::fillDeck( ) {
	if ( !deck->empty( ) )
		return;

	while ( !table->empty( ) )
		deck->addCard( table->removeCard( 0 ) );
}