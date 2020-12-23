/*
Program name: Project 2 Zoo Tycoon
Author: Adam Slusser
Date: 10/26/2019
Description: Zoo implamentation file. The zoo class contains the core parts of how the game runs with functions for
a starting menu once the player decides to play, adding and removing animals, determining which type of food the player
would like to feed the animals, a random event generator with varying probabilities to events based on food type the player
selected, resizing animal arrays, the option to purchase an animal and finally whether the user would like to replay or quit the game.
*/
#include"Zoo.hpp"

//Constructor for the zoo class which has initilizatoin for it's variables. 
zoo::zoo(){
	num_tigers = num_bears = num_penguins = num_turtles = bonus = 0;
	tiger_arr_size = bear_arr_size = penguin_arr_size = turtle_arr_size = 10;
	day = 1;

	tiger_array = new tiger * [tiger_arr_size];
	for (int i = 0; i < tiger_arr_size; i++) {
		tiger_array[i] =  0;
	}
	bear_array = new bear * [bear_arr_size];
	for (int i = 0; i < bear_arr_size; i++) {
		bear_array[i] = 0;
	}
	penguin_array = new penguin * [penguin_arr_size];
	for (int i = 0; i < penguin_arr_size; i++) {
		penguin_array[i] = 0;
	}
	turtle_array = new turtle * [turtle_arr_size];
	for (int i = 0; i < turtle_arr_size; i++) {
		turtle_array[i] = 0;
	}
}

//Zoo destructor
zoo::~zoo() {}

//Custom input validation function for zoo menu taking in two arguments. 
string zoo::menu_validation(string entry){
	while (entry.compare("1") != 0 && entry.compare("2") != 0) {
		cout << "I'm sorry please enter 1 or 2." << endl;
		getline(cin, entry);
	}
	return entry;
}



//Input validation for setting up the bear class. 
string zoo::bear_validation(string var, string comp1, string comp2, string comp3){
	while (var.compare(comp1) != 0 && var.compare(comp2) != 0 && var.compare(comp3) != 0) {
		cout << "I'm sorry but that was not a valid choice." << endl;
		getline(cin, var);
	}
	return var;
}

//Setting up the bear class.
void zoo::bear_settings(){
	cout << "In addition to tigers, penguins and turtles we are pleased to announce that" << endl;
	cout << "bears are now also being added to your zoo. You are one of the first people in the country" << endl;
	cout << "to do this. As such you have the option to set how much the bears will cost for you to buy," << endl;
	cout << "how much you will make off of each bear, and what the percentage of profit is that you will make off" << endl;
	cout << "each bear per turn is. With that being said lets get to it. " << endl;
	string bear_price_string = " ";
	cout << "Please choose from the list below how much you would like each bear to cost. " << endl;
	cout << "$5,000, $7,500 or $10,000 (plese enter number only EX: 5000" << endl;
	getline(cin, bear_price_string);
	bear_price_string = bear_validation(bear_price_string, "5000", "7500", "10000");
	bear_price = stoi(bear_price_string);
	
	string num_kids_string = " ";
	cout << "When a bear has babies how many would you like it to have? You can choose between 1 and 3." << endl;
	getline(cin, num_kids_string);
	num_kids_string = bear_validation(num_kids_string, "1", "2", "3");
	num_kids = stoi(num_kids_string);


	string percent_payoff = " ";
	cout << "How much profit would you like to make off of each bear every turn. This will be a percentage" << endl;
	cout << "of the bears cost. EX: If the bear cost $10,000 and you make a 20% profit you would make $2,000 every " << endl;
	cout << "turn for each bear in your zoo. You can choose 10%, 15% or 20%. Please write your percentage as a decimal" << endl;
	cout << "EX: if you would like 15% type 0.15" << endl;
	getline(cin, percent_payoff);
	percent_payoff = bear_validation(percent_payoff, "0.10", "0.15", "0.20");
	//convert string to float.
	payment = std::stof(percent_payoff);

	string food = " ";
	cout << "How should it cost to feed the bear? $40, $60, or $80 per turn? EX: 80" << endl;
	getline(cin, food);
	food = bear_validation(food, "40", "60", "80");
	bear_food_multiplier = stoi(food) / 20;
}



//Starting menu for the player which explains the game, allows them to pick one or two of each animal and keeps track of their
//bank account balance as they do so. 
void zoo::menu() {
	cout << "------------------------------\n" << endl;
	cout << "You will start with $100,000 in your bank account. Below you will be given the choice to buy one or two of each type\n";
	cout << "of animal the zoo offers. The prices of the animals are listed below. Please keep in mind that the feeding cost of each\n";
	cout << "animal varies (the more expensive the animal the more they cost to feed) and that cost will be deducted from your bank account daily.\n";
	cout << "However the amount that you make off of each anaimal also varies with tigers brining you the most money on a daily basis\n";
	cout << "while turtles make the least. With this in mind please choose your animals carefully." << endl;
	cout << "Your starting bank account balance is $" << bank_balance() << "." << endl;

	cout << "Animal Prices" << endl;
	cout << "-------------" << endl;
	cout << "Tigers: $10,000\n";
	cout << "Bears: $" << bear_price << endl;
	cout << "Penguins: $1,000\n";
	cout << "Turtles: $100" << endl;
	string num = " ";
	cout << "------------------------------\n" << endl;
	cout << "How many tigers would you like to buy? Plese enter 1 or 2" << endl;
	cout << "1) One" << endl;
	cout << "2) Two" << endl;
	getline(cin, num);
	num = menu_validation(num);
	for (int i = 0; i < stoi(num); i++) {
		add_tiger(1);
	}

	//Reset num for next choice
	num = " ";
	cout << "\n------------------------------\n" << endl;
	cout << "Bank Account: $" << bank_balance() << endl;
	cout << "How many bears would you like to buy? Plese enter 1 or 2" << endl;
	cout << "1) One" << endl;
	cout << "2) Two" << endl;
	getline(cin, num);
	num = menu_validation(num);
	for (int i = 0; i < stoi(num); i++) {
		add_bear(1);
	}

	//Reset num for next choice
	num = " ";
	cout << "------------------------------\n" << endl;
	cout << "Bank Account: $" << bank_balance() << endl;
	cout << "How many penguins would you like to buy? Plese enter 1 or 2" << endl;
	cout << "1) One" << endl;
	cout << "2) Two" << endl;
	getline(cin, num);
	num = menu_validation(num);
	for (int i = 0; i < stoi(num); i++) {
		add_penguin(1);
	}

	//Reset num for final choice
	num = " ";
	cout << "------------------------------\n" << endl;
	cout << "Bank Account: $" << bank_balance() << endl;
	cout << "How many turtles would you like to buy? Plese enter 1 or 2" << endl;
	cout << "1) One" << endl;
	cout << "2) Two" << endl;
	getline(cin, num);
	num = menu_validation(num);
	for (int i = 0; i < stoi(num); i++) {
		add_turtle(1);
	}
}

//Process for adding new animals. Same process repeats for each type of animal.
void zoo::add_tiger(int age_in) {
	//Check to see if array needs to be made larger.
	if (num_tigers == tiger_arr_size) {
		tiger** temp = new tiger * [tiger_arr_size * 2];
		for (int i = 0; i < tiger_arr_size; i++) {
			temp[i] = tiger_array[i];
		}
		//Delete old array.
		delete[] tiger_array;
		//Double the standard size for this type (tiger in this case) of array.
		tiger_arr_size = tiger_arr_size * 2;
		//Set the temp array address to the tiger array pointer.
		tiger_array = temp;
	}
	//Store the new object in the tiger array
	tiger_array[num_tigers] = new tiger(age_in);
	//Increase the number of tigers by 1.
	num_tigers++;
	//Subtract the cost of the animal from the bank.
	bank_withdraw(10000);
}

//Process for bear
void zoo::add_bear(int age_in) {
	if (num_bears == bear_arr_size) {
		bear** temp = new bear * [bear_arr_size * 2];
		for (int i = 0; i < bear_arr_size; i++) {
			temp[i] = bear_array[i];
		}
		delete[] bear_array;
		bear_arr_size = bear_arr_size * 2;
		bear_array = temp;
		bear_array[num_bears] = new bear(age_in, bear_price, num_kids, payment, bear_food_multiplier);
	}
	bear_array[num_bears] = new bear(age_in, bear_price, num_kids, payment, bear_food_multiplier);
	num_bears++;
	bank_withdraw(bear_price);
}
//Process for penguin
void zoo::add_penguin(int age_in) {
	if (num_penguins == penguin_arr_size) {
		penguin** temp = new penguin * [penguin_arr_size * 2];
		for (int i = 0; i < penguin_arr_size; i++) {
			temp[i] = penguin_array[i];
		}
		delete[] penguin_array;
		penguin_arr_size = penguin_arr_size * 2;
		penguin_array = temp;
	}
	penguin_array[num_penguins] = new penguin(age_in);
	num_penguins++;
	bank_withdraw(1000);
}
//Process for turtle. 
void zoo::add_turtle(int age_in) {
	if (num_turtles == turtle_arr_size) {
		turtle** temp = new turtle * [turtle_arr_size * 2];
		for (int i = 0; i < turtle_arr_size; i++) {
			temp[i] = turtle_array[i];
		}
		delete[] turtle_array;
		turtle_arr_size = turtle_arr_size * 2;
		turtle_array = temp;
	}
	turtle_array[num_turtles] = new turtle(age_in);
	num_turtles++;
	bank_withdraw(100);
}

//Allows the player to set what type of food they would like to give the animals. 
//Each choice has a different cost and health attribute to it.
void zoo::set_food_type(){
		string food_choice = " ";
		cout << "------------------------------\n" << endl;
		cout << "In order to help you throughout the game there are a couple different choices of food that\nyou can feed your animals. (1, 2, 3)" << endl;
		cout << "1) Premium: It's twice as expensive but sickness is half as likely to occur." << endl;
		cout << "2) Generic: The same food that you would fee them normally with no added cost or benefits." << endl;
		cout << "3) Cheap: It's half the price of generic food however sickness is twice as likely to occur." << endl;
		getline(cin, food_choice);
		while (food_choice.compare("1") != 0 && food_choice.compare("2") != 0 && food_choice.compare("3") != 0) {
			cout << "I'm sorry but that was not a valid choice. Please choose 1, 2, or 3" << endl;
			getline(cin, food_choice);
		}
		//Convert string to int for further function use.
		food_choice_num = stoi(food_choice);

	//Set food cost for tigers.
		for (int i = 0; i < num_tigers; i++) {

			tiger_array[i]->set_quality_food_cost(food_choice_num);
		}
	//Set food cost for bears.
		for (int i = 0; i < num_bears; i++) {
			bear_array[i]->set_quality_food_cost(food_choice_num);
		}
	//Set food cost for penguins.
		for (int i = 0; i < num_penguins; i++) {
			penguin_array[i]->set_quality_food_cost(food_choice_num);
		}
	//Set food cost for turtles.
		for (int i = 0; i < num_turtles; i++) {
			turtle_array[i]->set_quality_food_cost(food_choice_num);
		}
}

//Function for killing an animal to be called if an animal gets sick and dies.
void zoo::kill_tiger(){
	//Check to see that there is at least one animal remaining.
	if (num_tigers > 0) {
		cout << "Bad news one of your tigers has gotten sick and passed away." << endl;
		//Remove the animal from the array
		delete tiger_array[num_tigers - 1];
		//Set the array pointer to 0.
		tiger_array[num_tigers - 1] = 0;
		//Decrese the number of that animal.
		num_tigers--;
		cout << "You have " << num_tigers << " remaining." << endl;
	}
}


void zoo::kill_bear(){
	if (num_bears > 0) {
		cout << "Bad news one of your bears has gotten sick and passed away." << endl;
		delete bear_array[num_bears - 1];
		bear_array[num_bears - 1] = 0;
		num_bears--;
		cout << "You have " << num_bears << " remaining." << endl;
	}
}

void zoo::kill_penguin(){
	if (num_penguins > 0) {
		cout << "Bad news one of your penguins has gotten sick and passed away." << endl;
		delete penguin_array[num_penguins - 1];
		penguin_array[num_penguins - 1] = 0;
		num_penguins--;
		cout << "You have " << num_penguins << " remaining." << endl;
	}
}

void zoo::kill_turtle(){
	if (num_turtles > 0) {
		cout << "Bad news one of your turtles has gotten sick and passed away." << endl;
		delete turtle_array[num_turtles - 1];
		turtle_array[num_turtles - 1] = 0;
		num_turtles--;
		cout << "You have " << num_turtles << " remaining." << endl;
	}
}

//Tiger bonus function used in the random event function.
//Function adds a bonus to the players bank account.
void zoo::tiger_bonus(){
	//Initialized to time for more random values.
	srand(time(NULL));
	bonus = rand() % ((500 - 250) + 1) + 250;
	bonus = bonus * num_tigers;
	cout << "Congratulations you had a boom in attendance. As result you are getting a bonus of $" << bonus << endl;
}

//Function for determining which baby animal is born and contigency 
void zoo::animal_born(){
	//Initialized to time for more random values.
	srand(time(NULL));
	//25% chance for each type of animal to be born.
	int type_born = (rand() % 4 + 1);
	//Checks type of animal to be born from rand function above
	//and make sure that there is at least one of those animals in the zoo.
	if (type_born == 1 && num_tigers >= 1) {
		int adult_tigers = 0;
		int tiger_age = 0;
		//Loop through array to see if there is at least one adult
		for (int i = 0; i < num_tigers; i++) {
			tiger_age = tiger_array[i]->get_age();
			if (tiger_age >= 3) {
				adult_tigers++;
			}
		}
		//If there is an adult check to see how many babies that type of animal
		//is supposed to have and add that many to the array. 
		if (adult_tigers >= 1) {
			int num_babies = tiger_array[0]->get_num_babies();
			for (int i = 0; i < num_babies; i++){
			add_tiger(1);
			}
			cout << "Great news a new baby tiger has been born." << endl;
			cout << "This baby will help increase how much money your zoo makes." << endl;
			cout << "You now have a total of" << num_tigers << " tigers." << endl;
		}
		//If there are no adults move to next animal.
		else if (adult_tigers < 1) {
			type_born++;
		}
	}
	else if (type_born == 2 && num_bears >= 1) {
		int adult_bears = 0;
		int bear_age = 0;
		for (int i = 0; i < num_bears; i++) {
			bear_age = bear_array[i]->get_age();
			if (bear_age >= 3) {
				adult_bears++;
			}
		}
		if (adult_bears >= 1) {
			int num_babies = bear_array[0]->get_num_babies();
			for (int i = 0; i < num_babies; i++) {
				add_bear(1);
			}
			cout << "Great news two new baby bears has been born." << endl;
			cout << "These baby bears will help increase how much money your zoo makes." << endl;
			cout << "You now have a total of" << num_bears << " bears." << endl;
		}
		else if (adult_bears < 1) {
			type_born++;
		}
	}
	else if (type_born == 3 && num_penguins >= 1) {
		int adult_penguins = 0;
		int penguins_age = 0;
		for (int i = 0; i < num_penguins; i++) {
			penguins_age = penguin_array[i]->get_age();
			if (penguins_age >= 3) {
				adult_penguins++;
			}
		}
		if (adult_penguins >= 1) {
			int num_babies = penguin_array[0]->get_num_babies();
			for (int i = 0; i < num_babies; i++) {
				add_penguin(1);
			}
			cout << "Great news five new baby penguins has been born." << endl;
			cout << "These baby penguins will help increase how much money your zoo makes." << endl;
			cout << "You now have a total of" << num_penguins << " penguins." << endl;
		}
		else if (adult_penguins < 1 || num_penguins < 1) {
			type_born++;
		}
	}
	else if (type_born == 4 && num_turtles >= 1) {
		int adult_turtles = 0;
		int turtles_age = 0;
		for (int i = 0; i < num_turtles; i++) {
			turtles_age = turtle_array[i]->get_age();
			if (turtles_age >= 3) {
				adult_turtles++;
			}
		}
		if (adult_turtles >= 1) {
			int num_babies = turtle_array[0]->get_num_babies();
			for (int i = 0; i < num_babies; i++) {
				add_turtle(1);
			}
			cout << "Great news ten new baby turtles has been born." << endl;
			cout << "These baby turtles will help increase how much money your zoo makes." << endl;
			cout << "You now have a total of" << num_turtles << " turtles." << endl;
		}
		//Contingency for if there are no adult animals in the zoo.
		//Player gets a bonus for having so many cut baby animals. 
		else if (adult_turtles < 1 || num_turtles < 1) {
			cout << "I'm sorry you were supposed to have some baby animals born however you don't have any adults present." << endl;
			cout << "However due to the cuteness factor of all the baby animals zoo attendance is up and $1,000 extra will be added to your bank account this turn." << endl;
			bank_deposit(1000);
			cout << "Bank account balance $" << bank_balance() << endl;
		}
	}
	else {	
		cout << "I'm sorry you were supposed to have some baby animals born however you don't have any adults present." << endl;
		cout << "However due to the cuteness factor of all the baby animals zoo attendance is up and $1,000 extra will be added to your bank account this turn." << endl;
		bank_deposit(1000);
		cout << "Bank account balance $" << bank_balance() << endl;
	}
}
//Display message for nothing happens even in random even function.
void zoo::nothing_event(){
	cout << "The zoo is opperating normally and nothing special happened today." << endl;
}

//Process for determining a random event as well as concequences.
void zoo::rand_event() {
	//Initialized to time for more random values.
	srand(time(NULL));
	int random_number = rand() % 200 + 1;
	//Premium food scenario. Sickness is half as likely as usual. 
	if (food_choice_num == 1) {
		if (random_number >= 1 && random_number <= 25) {
			if (random_number >= 1 && random_number <= 6) {
				kill_tiger();
			}
			else if (random_number >= 7 && random_number <= 13) {
				kill_bear();
			}
			else if (random_number >= 14 && random_number <= 19) {
				kill_penguin();
			}
			else if (random_number >= 20 && random_number <= 25) {
				kill_turtle();
			}
		}
		//Larger percentage because health tigers could be more active and attract a larger crowd.
		else if (random_number >= 26 && random_number <= 100) {
			tiger_bonus();
		}
		else if (random_number >= 101 && random_number <= 150) {
			animal_born();
		}
		else {
			nothing_event();
		}
	}
	//Generic food scenario. 
	else if (food_choice_num == 2) {
		if (random_number >= 1 && random_number <= 50) {
			if (random_number >= 1 && random_number <= 12) {
				kill_tiger();
			}
			else if (random_number >= 13 && random_number <= 25) {
				kill_bear();
			}
			else if (random_number >= 26 && random_number <= 38) {
				kill_penguin();
			}
			else if (random_number >= 39 && random_number <= 50) {
				kill_turtle();
			}
		}
		else if (random_number >= 51 && random_number <= 100) {
			tiger_bonus();
		}
		else if (random_number >= 101 && random_number <= 150) {
			animal_born();
		}
		else if (random_number >= 151 && random_number <= 200) {
			nothing_event();
		}
	}
	//Poor quality food. Disease is twice as likely. 
	else if (food_choice_num == 3) {
		if (random_number >= 1 && random_number <= 100) {
			if (random_number >= 1 && random_number <= 25) {
				kill_tiger();
			}
			else if (random_number >= 26 && random_number <= 50) {
				kill_bear();
			}
			else if (random_number >= 51 && random_number <= 75) {
				kill_penguin();
			}
			else if (random_number >= 76 && random_number <= 100) {
				kill_turtle();
			}
		}
		else if (random_number >= 101 && random_number <= 132) {
			tiger_bonus();
		}
		else if (random_number >= 133 && random_number <= 166) {
			animal_born();
		}
		else if (random_number >= 167 && random_number <= 200) {
			nothing_event();
		}
	}
}
//Increase the age of all animals in the zoo.
void zoo::increase_age(){
	for (int i = 0; i < num_tigers; i++) {
		tiger_array[i]->age_increase();
	}
	for (int i = 0; i < num_bears; i++) {
		bear_array[i]->age_increase();
	}
	for (int i = 0; i < num_penguins; i++) {
		penguin_array[i]->age_increase();
	}
	for (int i = 0; i < num_turtles; i++) {
		turtle_array[i]->age_increase();
	}
}
//Calculate total cost to feed animals display it and subtract it from bank account.
//Display updated account balance.
void zoo::feeding_cost(){
	int cost_of_food = 0;
	if (num_tigers > 0) {
		cost_of_food = num_tigers * (tiger_array[0]->get_food_cost());
	}

	if (num_bears > 0) {
		cost_of_food = cost_of_food + (num_bears * (bear_array[0]->get_food_cost()));
	}
	
	if (num_penguins > 0) {
		cost_of_food = cost_of_food + (num_penguins * (penguin_array[0]->get_food_cost()));
	}
	
	if (num_turtles > 0) {
		cost_of_food = cost_of_food + ((num_turtles * turtle_array[0]->get_food_cost()));
	}
	bank_withdraw(cost_of_food);
	cout << "The cost of food for today came out to $" << cost_of_food << "." << endl;
	cout << "Remaining bank balance $" << bank_balance() << endl;
}
//Calculate the total profit for the day add it to the bank account allong with the bonus
//if there was one and display the profit and update bank account balance. 
void zoo::profit(){
	int gross_income = 0;
	if (num_tigers > 0) {
		gross_income = num_tigers * (tiger_array[0]->get_pay_off());
	}

	if (num_bears > 0) {
		gross_income = gross_income + (num_bears * bear_array[0]->get_pay_off());
	}

	if (num_penguins > 0) {
		gross_income = gross_income + (num_penguins * penguin_array[0]->get_pay_off());
	}

	if (num_turtles > 0) {
		gross_income = gross_income + (num_turtles * turtle_array[0]->get_pay_off());
	}

	gross_income = gross_income + bonus;
	bank_deposit(gross_income);
	cout << "Your total profit for the day was $" << gross_income << endl;
	cout << "Bank account balance $" << bank_balance() << endl;
	//Reset bonus for next round.
	bonus = 0;
}
// Prompt user to see if they would like to buy an animal.
void zoo::buy_animal(){
	string purchase_animal = " ";
	cout << "\n------------------------------" << endl;
	cout << "Would you like to purchase a new animal? (yes/no)" << endl;
	getline(cin, purchase_animal);
	purchase_animal = string_validation(purchase_animal, "Yes", "yes", "No", "no");
	if (purchase_animal =="Yes" || purchase_animal == "yes") {
		string animal_bought = " ";
		cout << "\nWould you like to purchse one of the following animals?" << endl;
		cout << "1) Tiger for $10,000" << endl;
		cout << "2) Bear for $" << bear_price << endl;
		cout << "3) Penguin for $1,000" << endl;
		cout << "4) Turtle for $100" << endl;
		getline(cin, animal_bought);
		while (animal_bought.compare("1") != 0 && animal_bought.compare("2") != 0 && animal_bought.compare("3") != 0 && animal_bought.compare("4") != 0) {
			cout << "I'm sorry but that was not a valid choice. Please choose 1, 2, or 3" << endl;
			getline(cin, animal_bought);
		}

		if (animal_bought == "1") {
			add_tiger(3);
			cout << "Congratulations on the purchase of your new tiger. You now have " << num_tigers << " tigers." << endl;
			cout << "Your remaining bank balance is $" << bank_balance() << endl;
		}
		else if (animal_bought == "2") {
			add_bear(3);
			cout << "Congratulations on the purchase of your new bear. You now have " << num_bears << " bears." << endl;
			cout << "Your remaining bank balance is $" << bank_balance() << endl;
		}
		else if (animal_bought == "3") {
			add_penguin(3);
			cout << "Congratulations on the purchase of your new penguin. You now have " << num_penguins << " penguins." << endl;
			cout << "Your remaining bank balance is $" << bank_balance() << endl;
		}
		else if (animal_bought == "4") {
			add_turtle(3);
			cout << "Congratulations on the purchase of your new turtle. You now have " << num_turtles << " turtles." << endl;
			cout << "Your remaining bank balance is $" << bank_balance() << endl;
		}
	}
	else if (purchase_animal == "No" || purchase_animal == "no") {
		cout << "That is okay you will have the option to purchase another animal tomorrow." << endl;
	}
}

//Process for ending the day and checking to make sure the player has at least $1 in their bank account.
bool zoo::end_day(){
	//Determine if player is bankrupt
	if (bank_balance() >= 1) {
		string play_quit = " ";
		cout << "\n------------------------------" << endl;
		cout << "This is the end of day " << day << "." << endl; day++;
		cout << "Your zoo currently has " << endl;
		cout << "Tigers: " <<num_tigers << endl;
		cout << "Bears: " << num_bears << endl;
		cout << "Penguins: " << num_penguins << endl;
		cout << "Turtles: " << num_turtles << endl;
		cout << "Bank account balance $" << bank_balance() << endl;
		cout << "Would you like to play for another day or quit the game?" << endl;
		cout << "P) Play again. " << endl;
		cout << "Q) Quit the game" << endl;
		getline(cin, play_quit);
		play_quit = string_validation(play_quit, ("P"), ("p"), ("Q"), ("q"));
		if (play_quit == "P" || play_quit == "p") {
			//Reset the food cost so the quality can be changed again next turn.
			tiger_array[0]->set_starting_food_cost(5);
			bear_array[0]->set_starting_food_cost(bear_food_multiplier);
			penguin_array[0]->set_starting_food_cost(1);
			turtle_array[0]->set_starting_food_cost(0.5);
			increase_age();
			return false;
		}
		else if (play_quit == "Q" || play_quit == "q") {
			return true;
		}
	}
	else if (bank_balance() <= 0) {
		cout << "I'm sorry but due to a string of bad luck you've run out of money and the zoo will have to close." << endl;
		cout << "Better luck next time." << endl;
		return true;
	}
}

void zoo::play_game(){
		string play_quit = " ";
		cout << "Welcome to Zoo Tycoon" << endl;
		cout << "----------------------" << endl;
		cout << "The game where you can create your own zoo." << endl;
		cout << "Would you like to play or quit the game? Please enter P or Q." << endl;
		cout << "P) Play" << endl;
		cout << "Q) Quit" << endl;
		getline(cin, play_quit);
		play_quit = string_validation(play_quit, ("P"), ("p"), ("Q"), ("q"));
		if (play_quit.compare("P") == 0 || play_quit.compare("p") == 0) {
			bear_settings();
			menu();
			do {
				set_food_type();
				feeding_cost();
				rand_event();
				profit();
				buy_animal();
			} while (end_day() == false);
			free_memory();
		}
		else if (play_quit.compare("Q") == 0 || play_quit.compare("q") == 0) {
			exit (0);
		}
}

void zoo::free_memory(){
	for (int i = 0; i < tiger_arr_size; i++) {
		delete[] tiger_array[i];
	}
	delete[] tiger_array;

	for (int i = 0; i < bear_arr_size; i++) {
		delete[] bear_array[i];
	}
	delete[] bear_array;

	for (int i = 0; i < penguin_arr_size; i++) {
		delete[] penguin_array[i];
	}
	delete[] penguin_array;

	for (int i = 0; i < turtle_arr_size; i++) {
		delete[] turtle_array[i];
	}
	delete[] turtle_array;
}