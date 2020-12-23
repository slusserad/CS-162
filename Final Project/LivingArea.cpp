/*
Program name : Final Project Game
Author : Adam Slusser
Date : 12/ 6 / 2019
Description : Implamentation for Living Area class which is derived from Space class. Functions included are
to display message when player checks to see if ship is damaged using function from game class and another function
which displays a result of player searching rooms for tools also using functions in game class.
*/
#include "LivingArea.hpp"

//String which describes apperance of game area.
string LivingArea_description = "A small room with a bed, desk, closet, a reading area and a small bathroom.";

//Constructor.
LivingArea::LivingArea(): Space(nullptr, nullptr, nullptr, nullptr, LivingArea_description, "Living Area"){
}

//Destructor.
LivingArea::~LivingArea(){}

//Displays result of what player finds if they attempt to use search room function in game class. 
string LivingArea::room_item(){
	string item = "Tool Kit";
	return item;
}

//Message if player examines room for damage using examine room function in game class.
string LivingArea::action_description(){
	string required_action = "There doesn't appear to be anything damaged here.";
	return required_action;
}