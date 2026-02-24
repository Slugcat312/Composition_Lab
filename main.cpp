/*Name: Ashley Ball
Date: 2/23/2026
Purpose: Bank account but with inheritance
Assignment Name:  Inhertiance*/
#include <iostream>
#include <vector>
#include "bankData.h"
#include "savingsData.h"
#include "checkingData.h"

int PrintMenu() { //The Menu
    std::cout << "--- Bank Menu ---" << std::endl;
    std::cout << "1. Create an Account" << std::endl;
    std::cout << "2. Deposit" << std::endl;
    std::cout << "3. Withdraw" << std::endl;
    std::cout << "4. Calculate interest" << std::endl;
    std::cout << "5. Display all Accounts" << std::endl; 
    std::cout << "6. Change Account Holder Name" << std::endl;
    std::cout << "7. Compare accounts." << std::endl;
    std::cout << "8. Exit" << std::endl;
    std::cout << "Enter choice: ";
    int choice;
    std::cin >> choice;
    return choice;
    }

int main() {
    std::vector<bankData*> accounts;
    int choice;

    do {
        choice = PrintMenu();

        switch (choice) {

        case 1: { //creates new accounts
            int newChoice;

            std::cout << "1. Savings Account." << std::endl;
            std::cout << "2. Checking Account." << std::endl;
            std::cout << "Enter choice: " << std::endl;
            std::cin >> newChoice;

            switch (newChoice) {
            case 1: {
                std::string num, name;
                double bal, rate;
                std::cout << "Account number: ";
                std::cin >> num;
                std::cout << "Name: ";
                std::cin >> name;
                std::cout << "Initial balance: ";
                std::cin >> bal;
                std::cout << "Interest rate:";
                std::cin >> rate;
                accounts.push_back(new savingsData(num, name, bal, rate));

                break;
            }
            case 2: {
                std::string num, name;
                double bal, fee;
                std::cout << "Account number: ";
                std::cin >> num;
                std::cout << "Name: ";
                std::cin >> name;
                std::cout << "Initial balance: ";
                std::cin >> bal;
                std::cout << "Transaction fee: ";
                std::cin >> fee;
                accounts.push_back(new checkingData(num, name, bal, fee));
                break;
            }
            default: {
                std::cout << "Invalid choice." << std::endl;
                break;
            }

            }
            break;
        }

        case 2: { //deposits if the input is valid
            if (accounts.empty()) {
                std::cout << "No accounts available." << std::endl;
                break;
            }

            std::string num;
            double deposit;
            std::cout << "Account number: ";
            std::cin >> num;
            for (auto* acc : accounts) {
                if (acc->getAccountNumber() == num) {
                    std::cout << "Deposit amount: ";
                    std::cin >> deposit;
                    *acc += deposit;
                    bankData::printAccount(*acc);
                }
            }
            break;
        }

        case 3: { //withdraws if the input is valid
            if (accounts.empty()) {
                std::cout << "No accounts available." << std::endl;
                break;
            }

            std::string num;
            double withdraw;
            std::cout << "Account number: ";
            std::cin >> num;
            for (auto* acc : accounts) {
                if (acc->getAccountNumber() == num) {
                    std::cout << "Withdraw amount: ";
                    std::cin >> withdraw;
                    *acc -= withdraw;
                    bankData::printAccount(*acc);
                }
            }
            break;
        }

        case 4: { //calculates interest
            if (accounts.empty()) {
                std::cout << "No accounts available." << std::endl;
                break;
            }
            std::string num;

            std::cout << "Account number: ";
            std::cin >> num;
            for (auto* acc : accounts) {
                if (acc->getAccountNumber() == num) {
                    savingsData* interest = dynamic_cast<savingsData*>(acc);
                    if (interest) {
                        interest->calculateInterest();
                    }
                }
            }
            /*
            I was also having issues on calling on calculateInterest()
            I ended up searching up how to fix it, said to use dynamic_cast
            */

            break;
        }

        case 5: { //prints accounts
            if (accounts.empty()) {
                std::cout << "No accounts available." << std::endl;
                break;
            }

            for (const auto& acc : accounts) {
                bankData::printAccount(*acc);
            }
            break;
        }


        case 6: { //changes the account holder's name
            if (accounts.empty()) {
                std::cout << "No accounts available." << std::endl;
                break;
            }

            std::string accNum;
            std::string newName;
            std::cout << "Enter account number: ";
            std::cin >> accNum;


            for (auto& acc : accounts) {
                if (acc->getAccountNumber() == accNum) {

                    std::cout << "Enter new account holder name: ";
                    std::cin >> newName;
                    acc->setAccountHolderName(newName);
                    std::cout << "Name updated." << std::endl;
                    break;
                }
            }
            break;
        }
        case 7: {
            if (accounts.size() < 2) {
                std::cout << "Need at least two accounts to compare." << std::endl;
                break;
            }

            std::string a;
            std::string b;
            std::cout << "Enter first account number: ";
            std::cin >> a;
            std::cout << "Enter second account number: ";
            std::cin >> b;
            bankData* acc1 = nullptr, * acc2 = nullptr;

            for (auto& acc : accounts) {
                if (acc->getAccountNumber() == a) acc1 = acc;
                if (acc->getAccountNumber() == b) acc2 = acc;
            }

            if (!acc1 || !acc2) {
                std::cout << "One or both accounts not found." << std::endl;
                break;
            }

            std::cout << "Comparison Results:";
            std::cout << "Same account number: " << ((*acc1 == *acc2) ? "Yes" : "No") << std::endl;
            std::cout << "Account 1 < Account 2 (balance): " << ((*acc1 < *acc2) ? "Yes" : "No") << std::endl;
            std::cout << "Account 1 > Account 2 (balance): " << ((*acc1 > *acc2) ? "Yes" : "No") << std::endl;
        }

            break;
        case 8:
            std::cout << "Exiting program." << std::endl;
            break;

        default:
            std::cout << "Invalid option." << std::endl;
        }

    } while (choice != 8);

    return 0;
}
