/*
Program name : Final Project Game
Author : Adam Slusser
Date : 12/ 6 / 2019
Description : Header for Outside class which is derived from Space class. Functions included are
to display message when player checks to see if ship is damaged using function from game class and another function
which displays a result of player searching rooms for tools also using functions in game class.
*/
#ifndef _OUTSIDE_HPP
#define _OUTSIDE_HPP
#include "Space.hpp"

class Outside : public Space {
protected:
public:
	Outside();
	~Outside();
	string room_item();
	string action_description();
};
#endif // !_OUTSIDE_HPP