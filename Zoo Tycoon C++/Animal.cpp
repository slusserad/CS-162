/*
Program name: Project 2 Zoo Tycoon
Author: Adam Slusser
Date: 10/26/2019
Description: Animal implamentation file. This is the parent file for all the rest of the animal classes. This file has the ability to 
set and retrive the animals age, cost, cost to feed, and how much the zoo owner will profit from the animal.
*/

#include"Animal.hpp"

//Destructor
animal::animal(){}

//Function to set age
void animal::set_age(int set_age) {
	age = set_age;
}
//Retrive age
int animal::get_age(){
	return age;
}
//Increase animals age to be used at the end of the day.
void animal::age_increase(){
	age++;
}
//Set how many babies the animal is capable of having in a litter.
void animal::set_num_babies(int num_baby) {
	num_babies = num_baby;
}
//Retrive the number of babies in a litter.
int animal::get_num_babies(){
	return num_babies;
}
//Set the purchase price of the animal.
void animal::set_cost(int costSet){
	cost = costSet;
}
//Retrive cost of the animal
int animal::get_cost(){
	return cost;
}
//Set the cost to feed the animal
void animal::set_starting_food_cost(float multiplier){
	food_cost = base_food_cost * multiplier;
}
//Set the cost to feed the animal after the quality of the food has been determined.
void animal::set_quality_food_cost(int food_choice){
	if (food_choice == 1) {
		food_cost = food_cost * 2;
	}
	else if (food_choice == 2) {
		food_cost = food_cost;
	}
	else if (food_choice == 3) {
		food_cost = food_cost / 2;
	}
}
//Retrive the cost to feed the animal
float animal::get_food_cost(){
	return food_cost;
}
//Set the amount of money the owner makes off the animal each turn
void animal::set_pay_off(float payoff){
	pay_off = cost * payoff;
}
//Retrive the amount of money the owner makes off each animal. 
float animal::get_pay_off(){
	return pay_off;
}

 animal::~animal() {}
