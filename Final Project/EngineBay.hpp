/*
Program name : Final Project Game
Author : Adam Slusser
Date : 12/ 6 / 2019
Description : Implamentation for the Engine Bay class which is derived from the Space class. Class contains
the functions that display different messages based on if player has fixed a problem, bool if player
has solved problem yet, and an item which player is able to store in their inventory.
*/
#ifndef _ENGINEBAY_HPP
#define _ENGINEBAY_HPP
#include "Space.hpp"

class EngineBay : public Space {
protected:
public:
	EngineBay();
	~EngineBay();
	void problem_solved();
	string action_description();
	string action_item_required();
	string room_item();
};
#endif // !_ENGINEBAY_HPP