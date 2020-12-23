/*
Program name: Project 2 Zoo Tycoon
Author: Adam Slusser
Date: 10/26/2019
Description: Implamentation file for bear class. Has a default constructor and one with arguments
allowing the player to choose the settings of the bear class with the exception of age.
*/
#include "Bear.hpp"

bear::bear(){
	set_age(1);
	set_cost(1);
	set_num_babies(1);
	set_pay_off(.10);
	set_starting_food_cost(1);
}

bear::bear(int age, int price, int number_babies, float profit, int food){
	set_age(age);
	set_cost(price);
	set_num_babies(number_babies);
	set_pay_off(profit);
	set_starting_food_cost(food);
}