/*
Program name: Project 3 Fantasy Combat Game
Author: Adam Slusser
Date: 11/07/2019
Description: Menu class header file. Class contains the pointers 
for fighter one and fighter two as well as functions for displaying
the introduction/instructions, a game menu to choose your fighters, 
carrying out combat until one fighter has died and asking the player
if they would like to quit or play again. 
*/
#ifndef _MENU_HPP
#define _MENU_HPP
#include "Character.hpp"

class menu {

protected:
	Character* fighter_one;
	Character* fighter_two;

public: 
	menu();
	~menu();
	void introduction();
	void game_menu();
	void mortal_combat();
	int play_quit();
};
#endif // !_MENU_HPP