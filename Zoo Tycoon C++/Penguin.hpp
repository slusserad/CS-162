/*
Program name: Project 2 Zoo Tycoon
Author: Adam Slusser
Date: 10/26/2019
Description: Implamentation for penguin class which is one of the four animals to be found in the game. 
*/

#ifndef _Penguin_hpp
#define _Penguin_hpp
#include "Animal.hpp"

class penguin : public animal {
protected:
	int cost, food_cost, num_babies;

public:
	penguin(int age);
};
#endif // !_penguin_hpp