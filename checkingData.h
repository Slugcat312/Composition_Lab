#ifndef CHECKINGACCOUNT_H 
#define CHECKINGACCOUNT_H
#include "bankData.h"

//prototypes

class checkingData : public bankData {
	private:
		double transactionFee;
	public:
		checkingData(std::string accNum, const std::string& name, double bal, double fee);
		bankData& operator-=(double amount);
		
};

#endif
