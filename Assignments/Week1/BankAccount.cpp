/*
James Lee Kennedy
CS 285
*/

#include <iostream>
#include <string>
#include "bankAccount.h"
using namespace std;

BankAccount::BankAccount() {
  assignAccNo();
  balance = 0;
  intRate = 0.08;
}

void BankAccount::assignAccNo() {
  static int x = 10000;
  accNo = x++;
}

int BankAccount::getAccNo() {
  return accNo;
}

void BankAccount::setHolderSetType(string name, int type) {
  holderName = name;
  
  if (type == 1)
    accType = "Savings";
    
  else if (type == 2)
    accType = "Checking";
}

string BankAccount::getName() {
  return holderName;
}

void BankAccount::withdraw(double amount) {
  if (amount <= balance) {
    balance -= amount;
    cout << "\n**Success!**\n New balance = $" << balance << "**";
  }
  
  else
    cout << "\n**ERROR: Insufficient funds **\n**Account balance = $" << balance << "**";
}

void BankAccount::deposit(double amount) {
  balance += amount;
  cout << "\n**Deposit Successful **\n** New balance = $" << balance << "**";
}

void BankAccount::checkInfo() {
  cout << "\n******************\n Account Owner: " << holderName <<
    "\n Account Number: " << accNo <<
    "\n Account Type: " << accType <<
    "\n Account Balance: $ " << balance <<
    "\n Account Interest: " << intRate <<
    "%\n ********************\n";
}