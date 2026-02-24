#include "savingsData.h"
#include <iostream>

//defintions

savingsData::savingsData(std::string accNum, const std::string& holderName, double initialBalance, double rate)
	: bankData(accNum, holderName, initialBalance), interestRate(rate) {}

void savingsData::calculateInterest() {
	double interest = balance * interestRate; 
	balance += interest; 
	std::cout << "Interest added: " << interest << std::endl;
}


