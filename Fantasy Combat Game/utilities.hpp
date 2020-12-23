/*
Program name: Project 3 Fantasy Combat Game
Author: Adam Slusser
Date: 11/07/2019
Description: Utilities header file. Handles input validation functions.
*/
#ifndef _UTILITIES_HPP
#define _UTILITIES_HPP

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

int combatant_validation(int choice);
int play_quit_validation(int choice);

#endif // !_UTILITIES_HPP