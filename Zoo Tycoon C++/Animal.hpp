/*
Program name: Project 2 Zoo Tycoon
Author: Adam Slusser
Date: 10/26/2019
Description: Animal header. This is the parent class for the tiger, bear, penguin, and turtle classes. 
Contains the getter and setter function for age, number of babies, food cost, and payoff of each animal.
*/

#ifndef _Animal_hpp
#define _Animal_hpp
#include<string>
using std::string;

class animal{

protected:
	int age, num_babies, cost, pay_off, food_cost;
	int base_food_cost = 20;

public:
	animal();
	virtual	void set_age(int set_age);
	virtual	int get_age();
	virtual	void age_increase();
	virtual void set_num_babies(int num_baby);
	virtual int get_num_babies();
	virtual void set_cost(int cost);
	virtual int get_cost();
	virtual void set_starting_food_cost(float multiplier);
	virtual void set_quality_food_cost(int food_price);
	virtual float get_food_cost();
	virtual void set_pay_off(float payoff);
	virtual float get_pay_off();
	virtual ~animal();
};
#endif // !_animal_hpp