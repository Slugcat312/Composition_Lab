#ifndef BANKDATA_H
#define BANKDATA_H

#include <iostream>
#include <string>

//prototypes

class bankData {
protected:
    std::string accountNumber;
    std::string accountHolderName;
    double balance;

public:
    bankData();
    bankData(std::string accNum, const std::string& holderName, double initialBalance);
    bankData(const bankData& other);
    bankData& operator=(const bankData& other);
    virtual ~bankData();
    std::string getAccountNumber() const;
    std::string getAccountHolderName() const;
    double getBalance() const;
    void setAccountHolderName(const std::string& newName);
    bankData& operator+=(double amount);
    virtual bankData& operator-=(double amount);
    bool operator==(const bankData& other) const;
    bool operator<(const bankData& other) const;
    bool operator>(const bankData& other) const;
    static void printAccount(const bankData& account);
    static bankData createAccountFromInput();
};

#endif


