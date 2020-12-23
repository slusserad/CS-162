/*
Program name: Project 2 Zoo Tycoon
Author: Adam Slusser
Date: 10/26/2019
Description: Implamentation for the turtle class with default constructor which sets
the age, cost, number of babies born, payoff and the cost of food to the values
specified in the regeric.
*/
#include "Turtle.hpp"

turtle::turtle(int age){
	set_age(age);
	set_cost(100);
	set_num_babies(10);
	set_pay_off(0.05);
	set_starting_food_cost(0.5);
}