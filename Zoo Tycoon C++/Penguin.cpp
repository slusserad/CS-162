/*
Program name: Project 2 Zoo Tycoon
Author: Adam Slusser
Date: 10/26/2019
Description: Implamentation for penguin class with default constructor set to ruberic specifications. 
*/

#include "Penguin.hpp"

penguin::penguin(int age){
	set_age(age);;
	set_cost(1000);
	set_num_babies(5);
	set_pay_off(0.1);
	set_starting_food_cost(1);
}