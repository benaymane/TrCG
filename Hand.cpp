#include "Hand.hpp"

Hand::Hand( Container* deck ) : Container(5) {
	for ( int i = 0; i < 5; i++ )
		Cards[i] = deck->removeCard( );
}
