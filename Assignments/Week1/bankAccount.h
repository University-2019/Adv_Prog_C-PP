/*
James Lee Kennedy
CS 285
*/

#include <iostream>
#include <cstring>
#include <cstdlib>

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
using namespace std;

// BankAccount class
class BankAccount {
  private:
    string holderName;
    int accNo;
    
    string accType;
    double balance;
    
    double intRate;
    
    // Private Member Function
    void assignAccNo();
    public:
    
    // Member Functions of Class
    BankAccount();
    int getAccNo();
    
    void setHolderSetType(string name, int type);
    string getName();
    
    void withdraw(double amount);
    void deposit(double amount);
    
    void checkInfo();
};

#endif