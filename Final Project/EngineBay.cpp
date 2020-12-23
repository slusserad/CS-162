/*
Program name : Final Project Game
Author : Adam Slusser
Date : 12/ 6 / 2019
Description : Implamentation for the Engine Bay class which is derived from the Space class. Class contains
the functions that display different messages based on if player has fixed a problem, bool if player
has solved problem yet, and an item which player is able to store in their inventory.
*/
#include "EngineBay.hpp"

//String to describe the rooms apperance to the player. 
string EngineBay_description = "A larger room that contains the engines as well as life support systems.";

//Constructor.
EngineBay::EngineBay() : Space(nullptr, nullptr, nullptr, nullptr, EngineBay_description, "Engine Bay"){}

//Destructor.
EngineBay::~EngineBay(){}

//Checks to see if player has solved rooms problem.
void EngineBay::problem_solved() {
	room_solved = true;
}

//Message if player examines room for damage using examine room function in game class.
//Message displayed depends on if player has already fixed rooms problem.
string EngineBay::action_description(){
	string required_action = " ";
	if (room_solved == false) {
		required_action = "You found a snapped cam shaft. There should a couple extra in the cargo bay.";
	}
	else {
		required_action = "You already fixed the ships engines. Great job.";
	}
	return required_action;
}

//Stores item needed for player to fix problem in the cargo bay. Used as a way to check
//if player has item in their inventory.
string EngineBay::action_item_required(){
	string item_required = "Cam Shaft";
	return item_required;
}

//Displays result of what player finds if they attempt to use search room function in game class. 
string EngineBay::room_item(){
	string item = "Capacitor";
	return item;
}