/*
Program name: Project 3 Fantasy Combat Game
Author: Adam Slusser
Date: 11/07/2019
Description: Main function creates a menu class displays the introduction
then plays the game. All handling of the game is handle by the menu class. 
*/
#include "Menu.hpp"
#include<iostream>
using std::cout; 
using std::cin;
using std::endl;

int main() {

	menu menu1;
	menu1.introduction();
	menu1.game_menu();
}