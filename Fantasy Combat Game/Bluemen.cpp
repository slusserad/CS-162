/*
Program name: Project 3 Fantasy Combat Game
Author: Adam Slusser
Date: 11/07/2019
Description: Barbarian class header file. Class is a derived from Character class.
All functions are inherited from the Character class.
*/
#include "Bluemen.hpp"

//Bluemen constructor.
Bluemen::Bluemen(){
	name = "Bluemen";
	attack_rolls = 2;
	attack_die_sides = 10;
	defense_rolls = 3;
	defense_die_sides = 6;
	strength = 12;
	armor = 3;
}

//Bluemen destructor.
Bluemen::~Bluemen(){}

//Causes the barbarian to attack returns damage dealt. 
int Bluemen::attack_opponent(){
	int attack_damage = 0;
	for (int i = 0; i < attack_rolls; i++) {
		attack_damage = attack_damage + rand() % attack_die_sides + 1;
	}
	cout << name << " attacks for " << attack_damage << endl;
	return attack_damage;
}

//Causes the barbarian to defend and returns how.
int Bluemen::defend(int damage_taken){
	int defense = 0;
	int damage = 0;

	//Checks to see how much strengh bluemen have left and adjusts number of 
	//defensive dice accordingly.
	if (strength <= 8 && strength > 4) {
		defense_rolls = 2;
	}
	else if (strength <= 4) {
		defense_rolls = 1;
	}

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
	cout << name << "'s armor rating of " << armor << " further protected them resulting in ";
	cout << damage << " damage." << endl;
	cout << "Our " << name << " (battle smurfs) now has " << strength << " strength left." << endl;
	return 0;
}

//Returns the name(type) of fighter as well as their armor and strength to be displayed at the start of the 
//fight.
void Bluemen::atributes(){
	cout << name << " Armor: " << armor << " Strength: " << strength << endl;
}

//Returns the fighters name(type). To display if they won.
string Bluemen::get_name(){
	return name;
}