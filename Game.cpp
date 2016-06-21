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
					if( userPickMediator( choice ) )
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
			Card* compPick;
			if ( ( compPick = comp->pickCard( choice, table ) ) == NULL) {
				std::cout << "Computer drew a card...\n";
				comp->drawCard( deck );
			}
			else {
				checkSpecialCase( compPick );
				comp->removeCard( compPick );
				std::cout << "Computer played: "; 
				compPick->print( );
				std::cout << std::endl;
				table->addCard( compPick );
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

bool Game::userPickMediator( int& choice ) {
	int cardIdx = -1;
	while ( true ) {
		if ( ( cardIdx = user->pickCard( ) ) == 0 ) {
			choice = -1;
			return false;
		}

		if ( checkCard( user->peekCard( cardIdx - 1) ) ) {
			checkSpecialCase( user->peekCard( cardIdx - 1) );
			//std::cout << "adding: " << user->peekCard( cardIdx - 1 )->getValue( ) << std::endl;
			table->addCard( user->playCard( cardIdx - 1) );
			return true;
		}
	}
	
}

void Game::checkSpecialCase( Card* futureCard ) {
	switch ( futureCard->getValue( ) ) {
	case 1:
		if ( turn == user_turn )
			std::cout << "You played an ACE, computer will skip its turn!\n";
		else
			std::cout << "Computer played an ACE, you will skip your turn!\n";
		switchTurns( );
		break;
	case 7:
		promptSuiteChange( );
		break;
	case 2:
		break;
	default:
		std::cout << "nada\n";
		break;
	}
}

void Game::promptSuiteChange( ) {
	if ( turn == user_turn ) {
		int choice;
		symbolChangeMenu( );
		std::cin >> choice;
		while ( true ) {
			if ( choice == 0 )
				break;
			else if ( choice == 1 ) {
				table->setSymbolAllowed( SYMBOL_CONCH );
				break;
			}

			else if ( choice == 2 ) {
				table->setSymbolAllowed( SYMBOL_CROWN );
				break;
			}

			else if ( choice == 3 ) {
				table->setSymbolAllowed( SYMBOL_STAR );
				break;
			}

			else if ( choice == 4 ) {
				table->setSymbolAllowed( SYMBOL_TRIDENT );
				break;
			}
		}
	}
	else {
		std::cout << "Computer has played a 7!\n";
		char symbol = comp->getBestSymbol( );
		if ( symbol != table->getSymbolAllowed( ) )
			std::cout << "The symbol of the cards has changed!\n";
		else
			std::cout << "The symbol of the cards remains unchanged!\n";
		table->setSymbolAllowed( symbol );
	}
}

void Game::symbolChangeMenu( ) {
	std::cout << "Please pick the symbol you want to keep\n"
		<< "==============="
		<< "= 1. CONCH    ="
		<< "= 2. CROWN    ="
		<< "= 3. STAR     ="
		<< "= 4. TRIDENT  ="
		<< "==============="
		<< "Choose 0 to keep as is: ";
}

bool Game::checkCard( Card* futureCard ) {
	if ( futureCard->getSymbol( ) == table->getSymbolAllowed( ) ||
	  futureCard->getValue( ) == table->getValueAllowed( ) )
		return true;
	
	std::cout << "You can't place that card!!\n";
	//std::cout << "table = " << table->getSymbolAllowed() << " and " << table->getValueAllowed() << std::endl;
	//std::cout << "card = " << futureCard->getSymbol( ) << " and " << futureCard->getValue( ) << std::endl;
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