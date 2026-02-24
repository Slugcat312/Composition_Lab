#include "checkingData.h"

//defintions

checkingData::checkingData(std::string accNum, const std::string& holderName, double intitalBalance, double fee) 
	: bankData(accNum, holderName, intitalBalance), transactionFee(fee) {}

bankData& checkingData::operator-=(double amount) {
    double total;
    total = amount + transactionFee;

    if (amount > 0 && total <= balance) {
        balance -= total;
    }
    else {
        std::cout << "Invalid amount." << std::endl;
    }
    return *this;
}

