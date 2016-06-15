#include "User.hpp"

User::User( Container* deck ): Players( "User", deck ) {

};

Card* User::pickCard( int& choice ) {
	//assuming no out of bound
	hand->print( );
	std::cout << "\nPick a card or 0 to go back: ";
	std::cin >> choice;

	if ( choice == 0 )
		return NULL;

	return hand->getCard( --choice );

}

Card* User::peekCard( int index ) {
	return hand->getCard( index );
}

void User::showHand( ) const {
	hand->print( );
}