/*
Program name: Project 2 Zoo Tycoon
Author: Adam Slusser
Date: 10/26/2019
Description: Zoo header file which sets the frame work for the game. Zoo class houses all the member 
variables such as age, cost, food cost, payoff, day, as well as the sizes of the arrays for the different
animal classes. 
*/

#ifndef _Zoo_hpp
#define _Zoo_hpp
#include "Tiger.hpp"
#include "Bear.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include "Animal.hpp"
#include "BankAccount.hpp"
#include "StringValidation.hpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include<sstream>	
#include<ctime>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::getline;
using std::rand;
using std::srand;
using std::stoi;

class zoo{
private:
	int num_tigers, num_penguins, num_turtles, num_bears;
	int tiger_arr_size, penguin_arr_size, turtle_arr_size, bear_arr_size;
	int feed_type, food_choice_num, day, bonus, bear_food_multiplier, bear_price, num_kids;
	float payment;

	tiger** tiger_array;
	bear** bear_array;
	penguin** penguin_array;
	turtle** turtle_array;

public:
	zoo();
	void menu();
	string menu_validation(string entry);
	string bear_validation(string var, string comp1, string comp2, string comp3);
	void bear_settings();
	void add_tiger(int);
	void add_bear(int);
	void add_penguin(int);
	void add_turtle(int);
	void set_food_type();
	void rand_event();
	void kill_tiger();
	void kill_bear();
	void kill_penguin();
	void kill_turtle();
	void tiger_bonus();
	void animal_born();
	void nothing_event();
	void increase_age();
	void feeding_cost();
	void profit();
	void buy_animal();
	bool end_day();
	void play_game();
	void free_memory();

	~zoo();
};
#endif // !_zoo_hpp