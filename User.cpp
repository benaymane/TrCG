#include "User.hpp"

User::User( Container* deck ): Players( "User", deck ) {

};

int User::pickCard( ) {
	int choice = -1;
	//assuming no out of bound
	hand->print( );
	std::cout << "\nPick a card or 0 to go back: ";
	std::cin >> choice;

	return choice;
}

Card* User::peekCard( int index ) {
	return hand->getCard( index );
}

void User::showHand( ) const {
	hand->print( );
}