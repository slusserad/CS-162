/*
Program name: Project 3 Fantasy Combat Game
Author: Adam Slusser
Date: 11/07/2019
Description: Menu class implamentation file. Class contains the pointers
for fighter one and fighter two as well as functions for displaying
the introduction/instructions, a game menu to choose your fighters,
carrying out combat until one fighter has died and asking the player
if they would like to quit or play again.
*/
#include "Menu.hpp"
#include "Barbarian.hpp"
#include "Bluemen.hpp"
#include "Character.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"
#include "utilities.hpp"
#include<iostream>
#include<string>
using std::string;
using std::getline; 

//Constructor
menu::menu(){}

//Destructor
menu::~menu(){}

//Introduction
void menu::introduction(){
	cout << "================================== BATTLE DOME =================================================" << endl;
	cout << "Welcome to Battle Dome where the bravest come to duke it out for fame and fortune. Here" << endl;
	cout << "you will choose who enters the dome. You have your choice of a vampire, barbarian, blue men" << endl;
	cout << "(angry smurfs), medusa, or Harry Potter (a fan favorite). You can select two people includeing " << endl;
	cout << "two of the same same class (2 vampires for example) to fight to the death. Contestants come from" << endl;
	cout << "far and wide to test their skill and gain fame and fortune; with that being said let us get to fighting." << endl;
	cout << "================================================================================================\n\n";
}

//Menu allowing player to choose two combatants
void menu::game_menu() {

	//Choose the first combatant
	int combatant_one = 0;
	cout << "Who will be the first combatant?" << endl;
	cout << "1) Vampire: Just as ruthless and cunning as he is handsome." << endl;
	cout << "2) Barbarian: The greatest pleasure is to crush your enemies." << endl;
	cout << "3) Blue men: They may be angry smurfs but quantity has a quality all its own." << endl;
	cout << "4) Medusa: Gaze upon her and she will turn you into stone." << endl;
	cout << "5) Harry Potter: The wonder kid." << endl;
	cin >> combatant_one;
	
	//Input validation.
	combatant_one = combatant_validation(combatant_one);

	//Switch statement which directs program.
	switch (combatant_one)
	{
	case 1:
		fighter_one = new Vampire;
		break;
	case 2:
		fighter_one = new Barbarian;
		break;
	case 3:
		fighter_one = new Bluemen;
		break;
	case 4:
		fighter_one = new Medusa;
		break;
	case 5:
		fighter_one = new HarryPotter;
		break;
	}

	//Choose second combatant.
	int combatant_two = 0;
	cout << "\n\n";
	cout << "Who will be the second combatant?" << endl;
	cout << "1) Vampire: Just as ruthless and cunning as he is handsome." << endl;
	cout << "2) Barbarian: The greatest pleasure is to crush your enemies." << endl;
	cout << "3) Blue men: They may be angry smurfs but quantity has a quality all its own." << endl;
	cout << "4) Medusa: Gaze upon her and she will turn you into stone." << endl;
	cout << "5) Harry Potter: The wonder kid." << endl;
	cin >> combatant_two;

	//Input validation.
	combatant_two = combatant_validation(combatant_two);

	//Switch statement which directs program.
	switch (combatant_two)
	{
	case 1:
		fighter_two = new Vampire;
		break;
	case 2:
		fighter_two = new Barbarian;
		break;
	case 3:
		fighter_two = new Bluemen;
		break;
	case 4:
		fighter_two = new Medusa;
		break;
	case 5:
		fighter_two = new HarryPotter;
		break;
	}
	
	//Display each fighter name(type), armor and strength. 
	cout << "Attacker: "; fighter_one->atributes(); cout << "\n";
	cout << "Defender: "; fighter_two->atributes(); cout << "\n";
	cout << "Now I want a good clean match no hitting below the belt, " << endl;
	cout << "no eye gougeing, and no dirty tricks." << endl;
	cout << "Ready.....FIGHT" << endl;

	//Call function to allow combat to take place. 
	mortal_combat();
}

//Allows players to carry out combat continues until one fighter dies. 
void menu::mortal_combat(){
	int round = 1;
	//Seed for random dice rolls for attack and defense functions in each class.
	srand(time(NULL));
	while (fighter_one->get_strength() > 0 && fighter_two->get_strength() > 0) {
		int damage = 0; 
		cout << "\n\nRound: " << round << endl;
		cout << "===============================================================================\n\n";

		//Fighter one attacks while fighter two defends. 
		damage = fighter_one->attack_opponent();
		fighter_two->defend(damage);
		//Check to see if fighter 2 was killed in the first round. 
		if (fighter_two->get_strength() <= 0) {
			break;
		}
		//Have fighter two attack while fighter one defends. 
		cout << "\n\nTime for our second combatant to get a little payback." << endl;
		damage = fighter_two->attack_opponent();
		fighter_one->defend(damage);
		round++;
	}

	//Check to see which fighter won.
	if (fighter_one->get_strength() > 0) {
		cout << "=============================================================\n\n";
		cout << "Let's hear it for our winner " << fighter_one->get_name() << endl;
	}
	else {
		cout << "=============================================================\n\n";
		cout << "Let's hear it for our winner " << fighter_two->get_name() << endl;
	}
	//Delete the pointers. 
	delete fighter_one;
	delete fighter_two;

	play_quit();
}

//Play quit function checks to see if the player wants to quit or play again.
int menu::play_quit(){
	int choice = 0;
	cout << "=============================================================\n\n";
	cout << "What would you like to do? " << endl;
	cout << "1) Play again" << endl;
	cout << "2) Quit" << endl;
	cin >> choice;
	choice = play_quit_validation(choice);
	if (choice == 1) {
		cout << "\n Get ready for another exciting match." << endl;
		cout << "=============================================================\n\n";
		game_menu();
	}
	else {
		return 0;
	}
	return 0;
}