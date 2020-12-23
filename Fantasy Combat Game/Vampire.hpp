/*
Program name: Project 3 Fantasy Combat Game
Author: Adam Slusser
Date: 11/07/2019
Description: Barbarian class header file. Class is a derived from Character class.
All functions are inherited from the Character class.
*/
#ifndef _VAMPIRE_HPP
#define _VAMPIRE_HPP
#include"Character.hpp"

class Vampire : public Character {
public:
	Vampire();
	~Vampire();
	int attack_opponent();
	int defend(int damage_taken);
	void atributes();
	string get_name();
};
#endif // !_VAMPIRE_HPP