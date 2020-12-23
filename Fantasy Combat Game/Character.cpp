/*
Program name: Project 3 Fantasy Combat Game
Author: Adam Slusser
Date: 11/07/2019
Description: Chacter class implamentation. This is the base class
for the Barbarian, Bluemen, Harry Potter, Medusa and Vampire classes.
*/
#include"Character.hpp"

//Constructor
Character::Character(){}

//Destructor
Character::~Character() {}

//Attack function for attacking other combatant.
int Character::attack_opponent(){
	return 0;
}

//Defense function for calculating actual damage 
//taken after defensive rolls and armor are taken into account.
int Character::defend(int damage) {
	return 0;
}

//Display the name, armor and strength of the character. 
void Character::atributes(){
}

//Returns the characters remaining strength.
int Character::get_strength(){
	return strength;
}

//Return the characters name to display if they are the victor. 
string Character::get_name(){
	return string();
}