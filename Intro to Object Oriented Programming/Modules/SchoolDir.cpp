///==============================================
// Name:           Derek Shigetomi
// Student Number: 028-970-135
// Email:          dgshigetomi@myseneca.ca
// Date:           9/27/2020
// Section:        NDD
// Workshop:       1
// I have done all the coding by myself
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdio>

#include "School.h"

using namespace std;
using namespace sdds;

void flushkeys();
bool yes();

int main() {
    char code[5];
    bool loop = true;
    cout << "Seneca School Extension search.\n\n";
    do {
        cout << "Enter the School code: ";
        cin >> code;
        flushkeys();
        load();
        printMatch(code);
        cout << "Do another search? (Y)es: ";
        loop = yes();
        cout << endl;
    } while (loop);
    cout << "Goodbye!" << endl;
    return 0;
}

// flushes the keyboard
void flushkeys() {
    while (cin.get() != '\n');
}

// returns true if user enter y or Y
bool yes() {
    char ch = cin.get();
    flushkeys();
    return ch == 'y' || ch == 'Y';
}


