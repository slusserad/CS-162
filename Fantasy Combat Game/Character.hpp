/*
Program name: Project 3 Fantasy Combat Game
Author: Adam Slusser
Date: 11/07/2019
Description: Chacter class header file. This is the base class
for the Barbarian, Bluemen, Harry Potter, Medusa and Vampire classes.
*/
#ifndef _CHARACTER_HPP
#define _CHARACTER_HPP
#include<iostream>
#include<ctime>
using std::cout;
using std::endl;
using std::rand;
using std::srand;
using std::string;

class Character {
protected:
	int attack_rolls, attack_die_sides;
	int defense_rolls, defense_die_sides;
	int armor;
	int strength;
	string name; 

public:
	Character();
	virtual ~Character();
	virtual void atributes();
	virtual int attack_opponent();
	virtual int defend(int damage);
	virtual int get_strength();
	virtual string get_name();
};
#endif // !_CHARACTER_HPP