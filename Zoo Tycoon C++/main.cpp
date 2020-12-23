/*
Program name: Project 2 Zoo Tycoon
Author: Adam Slusser
Date: 10/26/2019
Description: Main function for zoo class which asks player if they would like to play 
or quit the game. If they would like to play the game starts and loops until the player
decides to quit. 
EC: I did do the extra credit for the different types of feed.
EC: I also did the extra credit of adding an extra animal class. 
*/

#include"Zoo.hpp"

int main(void) {
	zoo zoo_tycoon1;
	zoo_tycoon1.play_game();
	zoo_tycoon1.~zoo();
}