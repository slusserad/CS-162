/*
Program name: Project 3 Fantasy Combat Game
Author: Adam Slusser
Date: 11/07/2019
Description: Bluemen class header file. Class is a derived from Character class.
All functions are inherited from the Character class.
*/
#ifndef _BLUEMEN_HPP
#define _BLUEMEN_HPP
#include "Character.hpp"

class Bluemen : public Character {

public:
	Bluemen();
	~Bluemen();
	int attack_opponent();
	int defend(int damage_taken);
	void atributes();
	string get_name();
};
#endif // !_BLUEMEN_HPP