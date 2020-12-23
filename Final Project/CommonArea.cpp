/*
Program name : Final Project Game
Author : Adam Slusser
Date : 12/ 6 / 2019
Description : Implamentation for the Common Area class which is derived from the Space class. Class contains
the functions that display different messages based on if player has fixed a problem, bool if player
has solved problem yet, and an item which player is able to store in their inventory.
*/
#include "CommonArea.hpp"

//String to describe the rooms apperance to the player. 
string CommonArea_description = "This area has a small booth and kitchen for eating as well as seating for reading/gaming.";

//Constructor.
CommonArea::CommonArea(): Space(nullptr, nullptr, nullptr, nullptr, CommonArea_description, "Common Area"){}

//Destructor.
CommonArea::~CommonArea(){}

//Checks to see if player has solved rooms problem.
void CommonArea::problem_solved() {
	room_solved = true;
}

//Message if player examines room for damage using examine room function in game class.
//Message displayed depends on if player has already fixed rooms problem.
string CommonArea::action_description(){
	string required_action;
	if (room_solved == false) {
		required_action = "You found a blown capacitor. This needs to be fixed so that we activate the hyper drive" +
			string("our engines don't blow up. \nThere should be a couple extra in the Engine Bay.");
	}
	else {
		required_action = "You already fixed the electrical system here. Great job.";
	}
	return required_action;
}

//Stores item needed for player to fix problem in the cargo bay. Used as a way to check
//if player has item in their inventory.
string CommonArea::action_item_required(){
	string item = "Capacitor";
	return item;
}

//Displays result of what player finds if they attempt to use search room function in game class. 
string CommonArea::room_item(){
	string item = "There aren't any useful items here. Try searching another room.";
	return item;
}