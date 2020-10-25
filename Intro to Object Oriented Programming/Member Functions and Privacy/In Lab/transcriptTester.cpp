//==============================================
// Name:           Derek Shigetomi
// Student Number: 028-970-135
// Email:          dgshigetomi@myseneca.ca
// Date:           10/5/2020
// Section:        NDD
// Workshop:       3 (LAB)
// I have done all the coding by myself
//==============================================

#include "Transcript.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
using namespace sdds;
int main() {
   Transcript T;
   T.init("Fred Soley", 5);
   T.add("EAC150", 65);
   T.add("DBS211", 85);
   T.add("DCF255", 75);
   T.add("OOP244", 95);
   // Premature call to display will result an error
   T.display();
   T.add("WEB222", 100);
   T.display();
   T.deallocate();
   return 0;
}