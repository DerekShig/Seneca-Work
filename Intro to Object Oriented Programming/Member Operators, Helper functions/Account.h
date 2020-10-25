//==============================================
// Name:           Derek Shigetomi
// Student Number: 028-970-135
// Email:          dgshigetomi@myseneca.ca
// Date:           10/22/2020
// Section:        NDD
// Workshop:       5 (Lab)
// I have done all the coding by myself
//==============================================

#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>
using namespace std;
namespace sdds {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      ostream& display()const;
      operator bool() const;
      operator int() const;
      operator double() const;
      bool operator~() const;
      Account& operator=(int a);
      Account& operator=(Account& copy);
      Account& operator+=(double value);
      Account& operator-=(double value);
   };
   double operator+(Account& a, Account& b);
   double operator+=(double& a, const Account& b);
}
#endif // SDDS_ACCOUNT_H_