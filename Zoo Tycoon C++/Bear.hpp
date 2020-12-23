/*
Program name: Project 2 Zoo Tycoon
Author: Adam Slusser
Date: 10/26/2019
Description: Header file for bear class which sets up the bear class according to user input with 
default constructor that accepts arguments. 
*/
#ifndef _Bear_hpp
#define _Bear_hpp
#include "Animal.hpp"

class bear : public animal {
public:
	bear();
	bear(int age, int price, int number_babies, float profit, int food);

};
#endif // !_bear_hpp