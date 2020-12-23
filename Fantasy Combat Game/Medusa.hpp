/*
Program name: Project 3 Fantasy Combat Game
Author: Adam Slusser
Date: 11/07/2019
Description: Medusa class header file. Class is a derived from Character class.
All functions are inherited from the Character class.
*/
#ifndef _MEDUSA_HPP
#define _MEDUSA_HPP
#include "Character.hpp"

class Medusa : public Character {

public:
	Medusa();
	~Medusa();
	int attack_opponent();
	int defend(int damage_taken);
	void atributes();
	string get_name();
};
#endif // !_MEDUSA_HPP