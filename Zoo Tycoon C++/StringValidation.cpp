/*
Program name: Project 2 Zoo Tycoon
Author: Adam Slusser
Date: 10/26/2019
Description: Implamentation for string validation input for use in zoo class input prompts.
*/
#include "StringValidation.hpp"

string string_validation(string var_name, string comp_one_v1, string comp_one_v2, string comp_two_v1, string comp_two_v2) {

	while (var_name.compare(comp_one_v1) != 0 && var_name.compare(comp_one_v2) != 0 && var_name.compare(comp_two_v1) != 0 && var_name.compare(comp_two_v2) != 0) {
		cout << "Sorry the selection you chose is not valid. Please enter " << comp_one_v1 << " or " << comp_two_v1 << "." << endl;
		getline(cin, var_name);
	}
	return var_name;
}