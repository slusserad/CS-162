/*
Program name : Final Project Game
Author : Adam Slusser
Date : 12/ 6 / 2019
Description : Header file for input validation functions. For menu
and percentages.
*/
#include "validation.hpp"
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int binary_choice_validation(int num){
	while (cin.fail() || cin.get() != '\n' || num < 1 || num > 2) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "I'm sorry but that was not a valid entry." << endl;
		cout << "Please choose one of the numbers listed in the menu above." << endl;
		cin >> num;
	}
	return num;
}

//Validation for menu options. 
int game_validation(int num_test) {
	while (cin.fail() || cin.get() != '\n' || num_test < 1 || num_test > 8) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "I'm sorry but that was not a valid entry." << endl;
		cout << "Please choose one of the numbers listed in the menu above." << endl;
		cin >> num_test;
	}
	return num_test;
}