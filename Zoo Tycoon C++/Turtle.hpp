/*
Program name: Project 2 Zoo Tycoon
Author: Adam Slusser
Date: 10/26/2019
Description: Turtle class header file. Tiger is one of 4 animals in the game.
*/
#ifndef _Turtle_hpp
#define _Turtle_hpp
#include "Animal.hpp"

class turtle : public animal {

public:
	turtle(int age);
};
#endif // !turtle_hpp