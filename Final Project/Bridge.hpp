/*
Program name : Final Project Game
Author : Adam Slusser
Date : 12/ 6 / 2019
Description : Header for Bridge class which is derived from Space class. Functions included are
to display message when player checks to see if ship is damaged using function from game class and another function
which displays a result of player searching rooms for tools also using functions in game class.
*/


#ifndef _BRIDGE_HPP
#define _BRIDGE_HPP
#include "Space.hpp"

class Bridge : public Space {
protected:
public:
	Bridge();
	~Bridge();
	string room_item();
	string action_description();
};
#endif // !_BRIDGE_HPP