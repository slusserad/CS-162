/*
Program name: Project 3 Fantasy Combat Game
Author: Adam Slusser
Date: 11/07/2019
Description: Barbarian class functions which allow for the barbarian die types and number of sides to be 
set in the constructor and functions for attacking, defending(calculates damage in this function), display
the characters attributes, and return their name (Barbarian). 
*/
#include "Barbarian.hpp"

//Constructor
Barbarian::Barbarian(){
	name = "Barbarian";
	attack_rolls = 2;
	attack_die_sides = 6;
	defense_rolls = 2;
	defense_die_sides = 6;
	strength = 12;
	armor = 0;
}

//Destructor
Barbarian::~Barbarian(){}

//Causes the barbarian to attack returns damage dealt. 
int Barbarian::attack_opponent(){
	int attack_damage = 0;
	for (int i = 0; i < attack_rolls; i++) {
		attack_damage = attack_damage + rand() % attack_die_sides + 1;
	}
	cout << name << " attacks for " << attack_damage << endl;
	return attack_damage;
}

//Causes the barbarian to defend and returns their defensive roll and damage
//dealt as well as remaining strength. 
int Barbarian::defend(int damage_taken){
	int defense = 0; 
	int damage = 0;

	//Simulates die rolls based on how many die character is supposed to have. 
	for (int i = 0; i < defense_rolls; i++) {
		defense = defense + rand() % defense_die_sides + 1;
	}

	//Check to make sure character does not defend against more damage than is being dealt.
	if (defense >= (damage_taken)) {
		defense = damage_taken;
	}
	//Calculate damage taken.
	damage = (damage_taken - defense - armor);

	//Make sure that negative damage isn't done after factoring armor and defense.
	if (damage < 0) {
		damage = 0;
	}

	//Ensure damage is not greater than strength this way characters do not end up with negative strength left. 
	if (damage >= strength) {
		damage = strength;
	}

	//Calculate remaining strength. 
	strength = strength - damage;
	
	//Display battle stats.
	cout << name << " defended against " << defense << " damage." << endl;
	cout << "Since " << name << "'s armor rating is ";
	cout << armor << " he takes " << damage << " damage." << endl;
	cout << name << " now has " << strength << " strength left." << endl;
	return 0;
}

//Returns the name(type) of fighter as well as their armor and strength to be displayed at the start of the 
//fight.
void Barbarian::atributes(){
	cout << name << " Armor: " << armor << " Strength: " << strength << endl;
}

//Returns the fighters name(type). To display if they won.
string Barbarian::get_name(){
	return name;
}
