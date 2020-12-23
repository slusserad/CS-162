/*
Program name: Project 3 Fantasy Combat Game
Author: Adam Slusser
Date: 11/07/2019
Description: Vampire class functions which allow for the vampire die types and number of sides to be
set in the constructor and functions for attacking, defending(calculates damage in this function), display
the characters attributes, and return their name (Vampire).
*/
#include "Vampire.hpp"

//Constructor
Vampire::Vampire(){
	name = "Vampire";
	attack_rolls = 1;
	attack_die_sides = 12;
	defense_rolls = 1;
	defense_die_sides = 6;
	strength = 18;
	armor = 1;
}

//Destructor
Vampire::~Vampire(){}

//Causes the vampire to attack returns damage dealt. 
int Vampire::attack_opponent(){
	int attack_damage = 0;
	for (int i = 0; i < attack_rolls; i++) {
		attack_damage = attack_damage + rand() % attack_die_sides + 1;
	}
	cout << name << " attacks for " << attack_damage << endl;
	return attack_damage;
}

//Causes the barbarian to defend and returns their defensive roll and damage
//dealt as well as remaining strength. 
int Vampire::defend(int damage_taken){
	int defense = 0;
	int damage = 0;
	int charm = rand() % 2 + 1;

	//Test to see if charm is active. If so vampire takes no damage. 
	if (charm == 1) {
		cout << "Wait ladies and gentlemen I was mistaken it looks like our " << name << " has used" << endl;
		cout << "charm making his opponient believe he has attacked when he's just been standing there. " << endl;
		return 0;
	}
	else {
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
		cout << name << "'s armor rating of " << armor << " further protected him resulting in ";
		cout << damage << " damage." << endl;
		cout << "Our " << name << " (Dracula) now has " << strength << " strength left." << endl;
	}
	return 0;
}

//Returns the name(type) of fighter as well as their armor and strength to be displayed at the start of the 
//fight.
void Vampire::atributes(){
	cout << name << " Armor: " << armor << " Strength: " << strength << endl;
}

//Returns the fighters name(type). To display if they won.
string Vampire::get_name(){
	return name;
}