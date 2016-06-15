#include <iostream>
#include "Container.hpp"
#include "Deck.hpp"
#include "Hand.hpp"
#include "Table.hpp"
#include "Game.hpp"
using namespace std;

int main( int argc, char* argv[] ) {

	Game myGame;
	myGame.launch( );
	/*
	cout << "Making a deck" << endl;
	Container* deck = new Deck( );
	deck->print( );

	cout << "Making a hand" << endl;
	Container* hand = new Hand( deck );
	hand->print( );

	cout << "Showing next in deck" << endl;
	deck->print( );
	
	cout << "Making a table" << endl;
	Container* table = new Table( deck );
	table->print( );

	cout << "Showing next in deck" << endl;
	deck->print( );
	*/
	system( "pause" );
	return 0;
}