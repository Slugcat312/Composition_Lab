#include "bankData.h"

//prototypes 

class savingsData : public bankData {
	private:
		double interestRate;
	public:
		savingsData(std::string accNum, const std::string& holderName, double intitalBalance, double interestRate);
		void calculateInterest();

};
