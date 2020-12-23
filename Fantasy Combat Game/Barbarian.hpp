/*
Program name: Project 3 Fantasy Combat Game
Author: Adam Slusser
Date: 11/07/2019
Description: Barbarian class header file. Class is a derived from Character class. 
All functions are inherited from the Character class.
*/
#ifndef _BARBARIAN_HPP
#define _BARBARIAN_HPP
#include"Character.hpp"
class Barbarian : public Character {

public:
	Barbarian();
	~Barbarian();
	int attack_opponent();
	int defend(int damage_taken);
	void atributes();
	string get_name();
};
#endif // !_BARBARIAN_HPP