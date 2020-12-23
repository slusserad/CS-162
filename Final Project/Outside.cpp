/*
Program name : Final Project Game
Author : Adam Slusser
Date : 12/ 6 / 2019
Description : Implamentation for Outside class which is derived from Space class. Functions included are
to display message when player checks to see if ship is damaged using function from game class and another function
which displays a result of player searching rooms for tools also using functions in game class.
*/
#include "Outside.hpp"

//String which describes apperance of game area.
string Outside_description = "Dark dimly lit planet with nothing but rocks as far as the eye can see. Best to get back in the ship.";

//Constructor.
Outside::Outside(): Space(nullptr, nullptr, nullptr, nullptr, Outside_description, "Outer Space"){}

//Destructor.
Outside::~Outside(){}

//Displays result of what player finds if they attempt to use search room function in game class. 
string Outside::room_item() {
	string item = "There aren't any useful items here. Try searching another room.";
	return item;
}

//Message if player examines room for damage using examine room function in game class.
string Outside::action_description(){
	string required_action = "There doesn't appear to be anything damaged here.";
	return required_action;
}