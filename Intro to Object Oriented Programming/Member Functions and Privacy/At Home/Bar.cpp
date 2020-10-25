//==============================================
// Name:           Derek Shigetomi
// Student Number: 028-970-135
// Email:          dgshigetomi@myseneca.ca
// Date:           10/11/2020
// Section:        NDD
// Workshop:       3 (DIY)
// I have done all the coding by myself
//==============================================

#include "Bar.h"
#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
namespace sdds {
	Bar::Bar() {
		b_title[0] = '\0';
		b_fill = '\0';
		b_length = -1;
	}

	void Bar::setEmpty() {
		b_title[0] = '\0';
		b_fill = '\0';
		b_length = -1;
	}

	void Bar::set(const char *title, char fill, int length) {
		if (length < 0 || length > 100) {
			setEmpty();
		}
		else {
			b_length = length;
			strcpy(b_title, title);
			b_fill = fill;
		}

	}

	bool Bar::isValid()const  {
		return b_length > 0 && b_length <= 100;
	}

	void Bar::draw() const {
		if (isValid()) {
			cout << b_title;
			cout.width(21-strlen(b_title));
			cout.fill('.');
			cout << '|';
			for (int i = 0; i < int(b_length/2); i++) {
				cout << b_fill;
			}
			cout << '\n';
		}
	}

}
