/*
Program name : Final Project Game
Author : Adam Slusser
Date : 12/ 6 / 2019
Description : Header for Living Area class which is derived from Space class. Functions included are
to display message when player checks to see if ship is damaged using function from game class and another function
which displays a result of player searching rooms for tools also using functions in game class.
*/
#ifndef _LIVINGAREA_HPP
#define _LIVINGAREA_HPP
#include "Space.hpp"

class LivingArea : public Space {
protected:
public:
	LivingArea();
	~LivingArea();
	string room_item();
	string action_description();
};
#endif // !_LIVINGAREA_HPP