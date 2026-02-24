#include "bankData.h"
#include <iostream>

//function defintions

bankData::bankData() {
    accountNumber = "000";
    accountHolderName = "N/A";
    balance = 0.0;
}


bankData::bankData(std::string accNum, const std::string& holderName, double initialBalance) {
    accountNumber = accNum;
    accountHolderName = holderName;
    balance = initialBalance;
}

bankData::bankData(const bankData& other) {
    accountNumber = other.accountNumber;
    accountHolderName = other.accountHolderName;
    balance = other.balance;
}

bankData& bankData::operator=(const bankData& other) {
    if (this != &other) {
        accountNumber = other.accountNumber;
        accountHolderName = other.accountHolderName;
        balance = other.balance;
    }
    return *this;
}


bankData::~bankData() {
}

std::string bankData::getAccountNumber() const {
    return accountNumber;
}

std::string bankData::getAccountHolderName() const {
    return accountHolderName;
}

double bankData::getBalance() const {
    return balance;
}

void bankData::setAccountHolderName(const std::string& newName) {
    accountHolderName = newName;
}

bankData& bankData::operator+=(double amount) {
    if (amount > 0) {
        balance += amount;
    }
    else {
        std::cout << "Invalid amount." << std::endl;
    }
    return *this;
}

bankData& bankData::operator-=(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
    }
    else {
        std::cout << "Invalid amount." << std::endl;
    }
    return *this;
}

bool bankData::operator==(const bankData& other) const {
    return accountNumber == other.accountNumber;
}

bool bankData::operator<(const bankData& other) const {
    return balance < other.balance;
}

bool bankData::operator>(const bankData& other) const {
    return balance > other.balance;
}

void bankData::printAccount(const bankData& account) {
    std::cout << "Account Number: " << account.accountNumber << std::endl;
    std::cout << "Holder Name: " << account.accountHolderName << std::endl;
    std::cout << "Balance: $" << account.balance << std::endl;
}


bankData bankData::createAccountFromInput() {
    std::string accNum, name;
    double bal;

    std::cout << "Enter account number:" << std::endl;
    std::cin >> accNum;
    std::cout << "Enter account name:" << std::endl;
    std::cin >> name;

    do {     
        std::cout << "Enter balance:" << std::endl;
        std::cin >> bal;

        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input. Please enter a number." << std::endl;
            continue;
        }
        if (bal < 0) {
            std::cout << "Balance cannot be negative." << std::endl;
        }

    } while (bal < 0);

    return bankData(accNum, name, bal);

}
