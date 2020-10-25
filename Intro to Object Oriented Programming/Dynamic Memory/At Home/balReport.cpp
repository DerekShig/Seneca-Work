//==============================================
// Name:           Derek Shigetomi
// Student Number: 028-970-135
// Email:          dgshigetomi@myseneca.ca
// Date:           10/4/2020
// Section:        NDD
// Workshop:       2 (DIY)
// I have done all the coding by myself
//==============================================

#include "Account.h"
#include <iostream>
using namespace std;
using namespace sdds;

int main() {
   if (load("accounts.csv")) {
      display();
   }
   deallocateMemory();
   return 0;
}