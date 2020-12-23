/*
Program name : Final Project Game
Author : Adam Slusser
Date : 12/ 6 / 2019
Description : Implamentation for the Cargo Bay class which is derived from the Space class. Class contains
the functions that display different messages based on if player has fixed a problem, bool if player
has solved problem yet, and an item which player is able to store in their inventory.
*/
#include "CargoBay.hpp"

//String to describe the rooms apperance to the player. 
string CargoBay_description = "A large suprisingly well lit room with cargo containers stacked to the ceiling.";

//Constructor
CargoBay::CargoBay(): Space(nullptr, nullptr, nullptr, nullptr, CargoBay_description, "Cargo Bay"){}

//Destructor
CargoBay::~CargoBay(){}

//Checks to see if player has solved rooms problem.
void CargoBay::problem_solved() {
	room_solved = true;
}

//Message if player examines room for damage using examine room function in game class.
//Message displayed depends on if player has already fixed rooms problem.
string CargoBay::action_description(){
	string required_action = " ";
	if (room_solved == false) {
		required_action = "The pipes that handle the ships coolant appear to be leaking. You will need a tool kit in the living area.";
	}
	else {
		required_action = "You already fixed the ships cooling system. Great job.";
	}
	return required_action;
}

//Stores item needed for player to fix problem in the cargo bay. Used as a way to check
//if player has item in their inventory.
string CargoBay::action_item_required(){
	string item_required = "Tool Kit";
	return item_required;
}

//Item that player can pick up and is used to solve another problem in the ship.
string CargoBay::room_item(){
	string item = "Cam Shaft";
	return item;
}