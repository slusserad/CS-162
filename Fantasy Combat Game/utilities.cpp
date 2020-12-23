/*
Program name: Project 3 Fantasy Combat Game
Author: Adam Slusser
Date: 11/07/2019
Description: Utilities functions for input validation. 
*/

#include "utilities.hpp"

//Validates the users choice for the combatant they choose.
int combatant_validation(int choice) {
	while (cin.fail() || cin.get() != '\n' || choice <= 0 || choice > 5) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Please choose from one of the five combatants listed above." << endl;
		cin >> choice;
	}
	return choice;
}

//Input validation for whether the player would like to play or quit the game. 
int play_quit_validation(int choice) {
	while (cin.fail() || cin.get() != '\n' || choice < 1 || choice > 2) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "That wasn't a valid entery please press 1 to play again or 2 to quit the game." << endl;
		cin >> choice;
	}
	return choice;
}