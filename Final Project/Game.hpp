/*
Program name : Final Project Game
Author : Adam Slusser
Date : 12/ 6 / 2019
Description : Header for Game class which is derived from this class controls the game flow and options,
functions include choosing if you want to play or quit, moving throughout the ship, searching the ship, repairing 
the ship, picking up and droping items from players inventory and checking to see if they player won or lost the game.
*/
#ifndef _GAME_HPP
#define _GAME_HPP
#include "Space.hpp"
#include <iostream>
#include <string>
using std::string;
#include <vector>
using std::vector;
#include<algorithm>
using std::find;

#include "validation.hpp"

class Game {
protected:
	int air; 
	int unfixed_problems;
	Space* current_location;
	vector <string> inventory;
	bool common_area_solved;
	bool cargo_bay_solved;
	bool engine_room_solved;
	bool keep_playing;

public:
	Game();
	Game(Space* s);
	~Game();
	void game_start();
	void play_game();
	void print_menu();
	void menu_choice();
	void move(int num);
	void decrease_air_supply();
	void search_room();
	void pick_up_item();
	void solve_problem();
	void show_inventroy();

};
#endif // !_GAME_HPP