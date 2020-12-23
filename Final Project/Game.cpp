/*
Program name : Final Project Game
Author : Adam Slusser
Date : 12/ 6 / 2019
Description : Implamentation for Game class which is derived from this class controls the game flow and options,
functions include choosing if you want to play or quit, moving throughout the ship, searching the ship, repairing
the ship, picking up and droping items from players inventory and checking to see if they player won or lost the game.
*/
#include "Game.hpp"

//Constructor
Game::Game(){
	air = 100;
}

//Constructor with args
Game::Game(Space* s){
	air = 100;
	unfixed_problems = 3;
	current_location = s;
	common_area_solved = false;
	cargo_bay_solved = false;
	engine_room_solved = false;
	keep_playing = true;
}

//Destructor
Game::~Game(){
}

//Displays the background story and objectives the the game then asks player if they would like to play.
void Game::game_start(){
	bool exit = false;

	while (exit == false) {
		int choice = 0;
		cout << "Welcome to Space Spy" << endl;
		cout << "You are a hot shot space pilot who works for the Resistance as a courier. A resistance" << endl;
		cout << "spy has recently uncovered plans for the new University's Dork Star; designed to turn an" << endl;
		cout << "entire planet into dorks with one shot of its dork beam. The plans were handed to you to" << endl;
		cout << "deliver to the Rebel command, however, along the way, you experience some engine trouble," << endl;
		cout << "and were forced to land on a desolate planet.  Scans show there are no signs of life on " << endl;
		cout << "the plant, and that its environment is suitable for humans. Unfortunately, this planet " << endl;
		cout << "is out of the way of any shipping plans, however, no one will discover you here while" << endl;
		cout << "you are make repairs. You realize that your engines are currently broken, and " << endl;
		cout << "your life support is running on backup systems; meant for these types of situations. " << endl;
		cout << "However, this is only a temporary fix to your problem, and the system will not hold out" << endl;
		cout << "forever.As you move throughout the ship, you realize that the energy supply to the backup" << endl;
		cout << "system decreases by 2 % every time you move from one room to another. You also gravely " << endl;
		cout << "realize that once the system reaches 0 %, your oxygen will run outand you will die. Your" << endl;
		cout << "goal is to workand move throughout the ship efficiently.\n\n" << endl;
		cout << "There are a total of 3 problems with the ship which are located in the Cargo Bay, Engine Bay" << endl;
		cout << "and Common Area. Move to each one of these areas and choose option 6 to check the room for" << endl;
		cout << "for damage and find out where the parts are to fix the problem." << endl;
		cout << "Would you like to play or quit the game?" << endl;
		cout << "1) Play" << endl;
		cout << "2) Quit" << endl;
		cin >> choice; 
		choice = binary_choice_validation(choice);
		if (choice == 1) {
			play_game();
			exit = true;
		}
		else if (choice == 2) {
			exit = true;
		}
	}
}

//Game loop which displays menu with options for player actions. Also checks to see if player
//won or lost.
void Game::play_game(){
	while (keep_playing == true) {
		cout << "Map:" << endl;
		current_location->ship_map();
		print_menu();
		menu_choice();
		//Check to see if player air supply has run out. 
		if (air <= 0) {
			cout << "GAME OVER" << endl;
			cout << "Your air supply ran out and you have died." << endl;
			keep_playing = false;
		}
		else if (common_area_solved == true && cargo_bay_solved == true && engine_room_solved == true) {
			cout << "YOU WIN" << endl;
			cout << "You manage to fix all the ships problems and are leaving the planet as we speak to deliver those plans." << endl;
			cout << "deliver those plans. Great Job." << endl;
			//return 0;
			keep_playing = false;
		}
	}
}

//Prints menu for player to choose activity.
void Game::print_menu(){
	cout << "\n\nCurrent Location: " << current_location->get_room_name() << " " << current_location->get_description() << endl;
	cout << "Remaining Air: " << air << "	Current Inventory (Max Capacity 2): "; show_inventroy();
	cout << "	Repairs still needed: " << unfixed_problems << endl;
	cout << "1) Go North" << endl;
	cout << "2) Go East" << endl;
	cout << "3) Go South" << endl;
	cout << "4) Go West" << endl;
	cout << "5) Search Room" << endl;
	cout << "6) Check room for damage" << endl;
	cout << "7) Take Item" << endl;
	cout << "8) Use required item." << endl;
}

//Receives input from player for their choice.
void Game::menu_choice(){
	int choice;
	cout << "What would you like to choose? " << endl;
	cin >> choice;
	choice = game_validation(choice);
	move(choice);
}

//Checks to see if a player can move in a given direction if they can they are moved.
//If the can't an error message appears.
void Game::move(int num) {
	if (num == 1) {
		if (current_location->get_north() == nullptr) {
			cout << "\n\n==============================================================================\n";
			cout << "You aren't able to go north here." << endl;
		}
		else {
			current_location = current_location->get_north();
			cout << "\n\n==============================================================================\n";
			decrease_air_supply();
		}
	}
	if (num == 2) {
		if (current_location->get_east() == nullptr) {
			cout << "\n\n==============================================================================\n";
			cout << "You aren't able to go east here." << endl;
		}
		else{
			current_location = current_location->get_east();
			cout << "\n\n==============================================================================\n";
			decrease_air_supply();
		}
	}
	if (num == 3) {
		if (current_location->get_south() == nullptr) {
			cout << "\n\n==============================================================================\n";
			cout << "You aren't able to go south here." << endl;
		}
		else{
			current_location = current_location->get_south();
			cout << "\n\n==============================================================================\n";
			decrease_air_supply();
		}
	}
	if (num == 4) {
		if (current_location->get_west() == nullptr) {
			cout << "\n\n==============================================================================\n";
			cout << "You aren't able to go west here." << endl;
		}
		else{
			current_location = current_location->get_west();
			cout << "\n\n==============================================================================\n";
			decrease_air_supply();
		}
	}
	if (num == 5) {
		cout << "\n\n==============================================================================\n";
		search_room();
	}
	if (num == 6) {
		cout << "\n\n==============================================================================\n";
		cout << current_location->action_description() <<endl;
	}
	if (num == 7) {
		cout << "\n\n==============================================================================\n";
		pick_up_item();
	}
	if (num == 8) {
		cout << "\n\n==============================================================================\n";
		solve_problem();
	}
}

// Decreases the remainng air supply when you move to another room. 
void Game::decrease_air_supply(){
	air = air - 2;
}

//Displays the item a player finds when the search a room.
void Game::search_room(){
	if (current_location->get_room_name() == "Engine Bay" || current_location->get_room_name() == "Living Area" ||
		current_location->get_room_name() == "Cargo Bay") {
		cout << "You found a " << current_location->room_item() << " press 7 to pick it up." << endl;
	}
	else {
		cout << current_location->room_item() << endl;
	}
}

void Game::pick_up_item(){
	//Check to see if you are in one of the rooms where you can pick something up.
	if (current_location->get_room_name() == "Engine Bay" || current_location->get_room_name() == "Living Area" ||
		current_location->get_room_name() == "Cargo Bay") {
		if (inventory.size() < 2) {
			inventory.push_back(current_location->room_item());
			cout << "A " << current_location->room_item() << " has been added to your inventory." << endl;
		}
		else if (inventory.size() == 2) {
			int drop_choice = 0;
			cout << "Would you like to drop an item in your inventory?" << endl;
			cout << "1) Yes" << endl;
			cout << "2) No" << endl;
			cin >> drop_choice;
			drop_choice = binary_choice_validation(drop_choice);
			if (drop_choice == 1) {
				int choice = 0;
				cout << "Your inventory is currently full at two items. You ahave to drop one in order pick up another." << endl;
				cout << "Items in your inventory." << endl;
				cout << "1) " << inventory[0] << endl;
				cout << "2) " << inventory[1] << endl;
				cout << "Which item would you like to drop?" << endl;
				cin >> choice;
				choice = binary_choice_validation(choice);
				cout << "You droped the " << inventory[choice - 1] << " damaging it in the process. If you need another." << endl;
				cout << "You can return to the location where you found it and grab another one." << endl;
				inventory.erase(inventory.begin() + choice - 1);
			}
			
		}
	}
	//If there is nothing in the room to pick up.
	else {
		cout << "There isn't anything here for you to pick up." << endl;
	}
}

//Function checks to make sure that you are in the correct room and that you haven't not previously sovled the problem.
//Find function taken from https://www.techiedelight.com/check-vector-contains-given-element-cpp/ and
//https://www.geeksforgeeks.org/std-find-in-cpp/
void Game::solve_problem(){
	//Iterator which indicates if a player has the required part in their inventory and 
	//reports it's position in vector so it can be removed once player uses it.
	vector<string>::iterator it;

	//Check which area of the ship player is in and that problem has not already been solved.
	if (current_location->get_room_name() == "Common Area" && common_area_solved == false) {
		//Check if item required to solve issue is in player inventory. 
		it = find(inventory.begin(), inventory.end(), current_location->action_item_required());
		if (it != inventory.end()){
			cout << "You used the " << current_location->action_item_required() << " to fix the electrical system." << endl;
			common_area_solved = true;
			//Set problem solved in class to true so that a different messsage is displayed when player searchs for damage.
			current_location->problem_solved();
			inventory.erase(it);
			cout << current_location->action_item_required() << " removed from inventory." << endl;
			unfixed_problems--;
		}
		else {
			cout << "You will need to get the " << current_location->action_item_required() << " to fix this." << endl;
			cout << "Try the Engine Bay." << endl;
		}
	}
	else if (current_location->get_room_name() == "Common Area" && common_area_solved == true) {
		cout << "It looks like you already solved the issue in the " << current_location->get_room_name();
	}

	//Check to see if cargo by has been fixed.
	if (current_location->get_room_name() == "Cargo Bay" && cargo_bay_solved == false) {
		//Check if item required to solve issue is in player inventory. 
		it = find(inventory.begin(), inventory.end(), current_location->action_item_required());
		if (it != inventory.end()) {
			cout << "You used the " << current_location->action_item_required() << " to fix the ships exhaust system." << endl;
			cargo_bay_solved = true;
			//Set problem solved in class to true so that a different messsage is displayed when player searchs for damage.
			current_location->problem_solved();
			inventory.erase(it);
			cout << current_location->action_item_required() << " removed from inventory." << endl;
			unfixed_problems--;
		}
		else {
			cout << "You will need to get the " << current_location->action_item_required() << " to fix this." << endl;
			cout << "Try the Living Area." << endl;
		}
	}
	else if (current_location->get_room_name() == "Cargo Bay" && cargo_bay_solved == true) {
		cout << "It looks like you already solved the issue in the " << current_location->get_room_name();
	}
	
	//Check to see if you are in the engine room and if the engine has already been fixed. 
	if (current_location->get_room_name() == "Engine Bay" && engine_room_solved == false) {
		//Check if item required to solve issue is in player inventory. 
		it = find(inventory.begin(), inventory.end(), current_location->action_item_required());
		if (it != inventory.end()) {
			cout << "You used the " << current_location->action_item_required() << " to fix the ships engines." << endl;
			engine_room_solved = true;
			//Set problem solved in class to true so that a different messsage is displayed when player searchs for damage.
			current_location->problem_solved();
			inventory.erase(it);
			cout << current_location->action_item_required() << " removed from inventory." << endl;
			unfixed_problems--;
		}
		else {
			cout << "You will need to get the " << current_location->action_item_required() << " to fix this." << endl;
			cout << "Try the Cargo Bay." << endl;
		}
	}
	else if (current_location->get_room_name() == "Engine Bay" && engine_room_solved == true) {
		cout << "You will need to get the " << current_location->action_item_required() << " to fix this." << endl;
	}
	//Message to be displayed if a player is in a room where there is nothing that needs to be fixed.
	if (current_location->get_room_name() == "Living Area" || current_location->get_room_name() == "Bridge" ||
		current_location->get_room_name() == "Outer Space") {
		cout << "There isn't anything here for you to fix." << endl;
	}
}

//Used as part of the menu to keep player updated on what they have in their inventory.
void Game::show_inventroy(){
	if (inventory.size() == 0) {
		cout << "Empty";
	}
	else if (inventory.size() == 1) {
		for (int i = 0; i < inventory.size(); i++) {
			cout << inventory[i];
		}
	}
	else if (inventory.size() == 2) {
		for (int i = 0; i < inventory.size(); i++) {
			if (i == 0) {
				cout << inventory[i] << ", ";
			}
			else {
				cout << inventory[i];
			}
		}
	}
}