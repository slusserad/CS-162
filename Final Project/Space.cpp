/*
Program name : Final Project Game
Author : Adam Slusser
Date : 12/ 6 / 2019
Description : Header for Space class which is the base class for the Bridge, Cargo Bay, Common Area, Engine Bay,
Living Area, and Outside classes. Functions included control direction, description of room (class) player is in,
if there is an item that player can pick up, describes the problem in the room, if the problem has been solved and
a map of the ship.
*/
#include "Space.hpp"

//Constructor.
Space::Space(){
	this->North = nullptr;
	this->East = nullptr;
	this->South = nullptr;
	this->West = nullptr;

	this->room_solved = false;

	this->room_description = "";
	this->room_name = "";
}

//Constructor with arguments.
Space::Space(Space* N, Space* S, Space* E, Space* W, string descript, string name){
	this->North = N;
	this->East = E;
	this->South = S;
	this->West = W;

	this->room_solved = false;

	this->room_description = descript;
	this->room_name = name;
}

//Pure virtual destructor.
Space::~Space() {};

//Sets north.
void Space::set_north(Space* N){
	this->North = N;
}

//Set east.
void Space::set_east(Space* E){
	this->East = E;
}

//Sets south.
void Space::set_south(Space* S){
	this->South = S;
}

//Sets west.
void Space::set_west(Space* W){
	this->West = W;
}

//Retrieves north.
Space* Space::get_north(){
	return North;
}

//Retrieves east.
Space* Space::get_east(){
	return East;
}

//Retrieves south.
Space* Space::get_south(){
	return South;
}

//Retrieves west.
Space* Space::get_west(){
	return West;
}

//Returns the name of the current room the player is in.
string Space::get_room_name() {
	return this->room_name;
}

//Retruns the description of the room the player is in.
string Space::get_description(){
	return room_description;
}

//Keeps track of if the player has fixed the problem in the room yet.
void Space::problem_solved(){
	this->room_solved = true;
}

//Tells the player if there is a problem in the room and what it is if there is one.
string Space::action_description(){
	string action_description = " ";
	return action_description;
}

//Used to check if the player has the required item in their inventory to fix rooms problem.
string Space::action_item_required(){
	string required_item = " ";
	return required_item;
}

//Stores a item that the player can put in their inventory to fix a problem in the ship.
string Space::room_item(){
	string tool = " ";
	return tool;
}