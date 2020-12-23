/*
Program name : Final Project Game
Author : Adam Slusser
Date : 12/ 6 / 2019
Description : Header for the Cargo Bay class which is derived from the Space class. Class contains
the functions that display different messages based on if player has fixed a problem, bool if player
has solved problem yet, and an item which player is able to store in their inventory. 
*/
#ifndef _CARGOBAY_HPP
#define _CARGOBAY_HPP
#include "Space.hpp"

class CargoBay : public Space {
protected:
public:
	CargoBay();
	~CargoBay();
	void problem_solved();
	string action_description();
	string action_item_required();
	string room_item();

};
#endif // !_CARGOBAY_HPP