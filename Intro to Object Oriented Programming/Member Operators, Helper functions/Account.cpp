//==============================================
// Name:           Derek Shigetomi
// Student Number: 028-970-135
// Email:          dgshigetomi@myseneca.ca
// Date:           10/22/2020
// Section:        NDD
// Workshop:       5 (Lab)
// I have done all the coding by myself
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
   void Account::setEmpty() {
	  m_number = -1;
	  m_balance = 0.0;
   }
   // New account
   Account::Account() {  
	  m_number = 0;
	  m_balance = 0.0;
   }
   Account::Account(int number, double balance) {
	  setEmpty();
	  if (number >= 10000 && number <= 99999 && balance >= 0) {
		 m_number = number;
		 m_balance = balance;
	  }
   }
   ostream& Account::display() const{
	  if (*this) {  
		 cout << "Acc#: ";
		 if (~(*this)) 
			cout << "Not Set";
		 else
			cout << " " << m_number << " ";
		 cout << ", Balance: ";
		 cout.width(12);
		 cout.precision(2);
		 cout.setf(ios::right);
		 cout.setf(ios::fixed);
		 cout << m_balance;
		 cout.unsetf(ios::right);
	  }
	  else {
		 cout << "Invalid Account";
	  }
	  return cout;
	}
   
   Account::operator bool() const {
	   return (m_number >= 10000 && m_number <= 99999 && m_balance >= 0) || (~*this);
   }

   Account::operator int() const {
	   return m_number;
   }

   Account::operator double() const {
	   return m_balance;
   }

   bool Account::operator~() const {
	   return m_number == 0;
   }

	Account& Account::operator=(int a) {
		if (a < 10000 || a > 99999) {
			setEmpty();
		}
		else if ((a >= 10000 && a <= 99999) && (*this || ~*this)) {
			m_number = a;
		}
		else {
			// do nothing if invalid
		}
		return *this;
	}

	Account& Account::operator=(Account& copy) {
		if ((*this || ~(*this)) && (copy || ~copy)) {
			this->m_balance += copy.m_balance;
			copy.m_balance = 0;
		}
		return *this;
	}

	Account& Account::operator+=(double value) {
		if (value >= 0 && (*this || ~*this)) {
			this->m_balance += value;
		}
		return *this;
	}

	Account& Account::operator-=(double value) {
		if (value >= 0 && (*this || ~*this)) {
			if (this->m_balance >= value) {
				this->m_balance -= value;
			}
		}
		return *this;
	}

	double operator+(Account& a, Account& b) {
		double sum = 0.0;
		if ((a || ~a) && (b || ~b)) {
			sum = double(a) + double(b);
		}
		return sum;
	}

	double operator+=(double& a, const Account& b) {
		return a += double(b);
	}

}