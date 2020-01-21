/*
James Lee Kennedy
CS 285
*/

#include <iostream>
#include "bankAccount.h"
#include <string>
using namespace std;

int main() {
  std::string name;
  int ch, acc[10], accno, flag = 0, j, n, type;
  
  double amt;
  std::cout << "Enter the number of accounts to create: ";
  std::cin >> n;
  
  BankAccount **bankAccount = new BankAccount * [n];
  
  for (int i = 0; i < n; i++) {
    bankAccount[i] = new BankAccount();
    acc[i] = bankAccount[i] -> getAccNo();
    std::cout << "\n" << i + 1 << "Enter name: ";
    
    std::cin.ignore();
    getline(std::cin, name);
    do {
      flag = 0;
      std::cout << "Enter account type (1 = Saving, 2 = Checking): ";
      
      std:: cin >> type;
      if (type != 1 && type != 2) {
        std::cout << "** ERROR: Invalid Input**\n";
        flag = 1;
      }
    } while (flag);
    bankAccount[i] -> setHolderSetType(name, type);
    
    std::cout << "\n***" << bankAccount[i] -> getName() <<
      "Account #: " << bankAccount[i] -> getAccNo() << "***\n";
  }
  
  do {
    flag = 0;
    std::cout << "\nEnter Account #: ";
    std::cin >> accno;
    
    for (j = 0; j < n; j++) {
      if (accno == acc[j])
        break;
    }
    
    if (j >= n) {
      std::cout << "\nACCESS DENIED: ";
      flag = 1;
    }
    
    else {
      std::cout << "\nACCESS GRANTED: Welcome back " << bankAccount[j] -> getName() << endl;
    }
  }
  
  while (flag);
  flag = 1;
  
  do {
    std::cout << "\n\nMenu\n1. Account Info\n2. Deposit\n3. Withdraw\n4.Exit\n";
    std::cout << "\nEnter your choice: ";
    
    std::cin >> ch;
    switch (ch) {
      case 1:
        bankAccount[j] -> checkInfo();
        break;
        
      case 2:
        std::cout << "\nEnter deposit amount: ";
        std::cin >> amt;
        
        bankAccount[j] -> deposit(amt);
        break;
        
      case 3:
        std::cout << "\nEnter withdraw amount: ";
        std::cin >> amt;
        
        bankAccount[j] -> withdraw(amt);
        break;
        
      case 4:
        flag = 0;
        break;
        
      default:
        std::cout << "\nERROR: Invalid Input";
    }
  }
  
  while (flag);
  return 0;
}