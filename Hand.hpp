#ifndef HAND_HPP
#define HAND_HPP
#include "Container.hpp"

class Hand : public Container {
public:
	Hand( Container* );
	void print( ) const;
};

#endif