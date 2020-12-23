/*
Program name : Final Project Game
Author : Adam Slusser
Date : 12/ 6 / 2019
Description : Header file for the Common Area class which is derived from the Space class. Class contains
the functions that display different messages based on if player has fixed a problem, bool if player
has solved problem yet, and an item which player is able to store in their inventory.
*/
#ifndef _COMMONAREA_HPP
#define _COMMONAREA_HPP
#include "Space.hpp"

class CommonArea : public Space {
protected:
public:
	void problem_solved();
	CommonArea();
	~CommonArea();
	string action_description();
	string action_item_required();
	string room_item();
};
#endif // !_COMMONAREA_HPP