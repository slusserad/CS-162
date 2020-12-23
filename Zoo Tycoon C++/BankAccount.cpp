/*
Program name: Project 2 Zoo Tycoon
Author: Adam Slusser
Date: 10/22/2019
Description: Implamentation file for bank account function which handles the balance, deposits and withdrawls for the zoo.
*/
#include "BankAccount.hpp"

int account_balance = 100000;
//Deposit function
void bank_deposit(int dep) {
	account_balance = account_balance + dep;
}
//Withdraw function
void bank_withdraw(int wit) {
	account_balance = account_balance - wit;
}
//Show retrive balance to display. 
int bank_balance() {
	return account_balance;
}