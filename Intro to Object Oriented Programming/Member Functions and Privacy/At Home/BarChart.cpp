//==============================================
// Name:           Derek Shigetomi
// Student Number: 028-970-135
// Email:          dgshigetomi@myseneca.ca
// Date:           10/11/2020
// Section:        NDD
// Workshop:       3 (DIY)
// I have done all the coding by myself
//==============================================

#include "BarChart.h"
#include <cstring>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
namespace sdds {

	BarChart::BarChart() {
		num_bars = -1;
		num_added = -1;
	}

	void BarChart::empty() {
		c_title = nullptr;
		bars = nullptr;
	}

	bool BarChart::isValid() const {
		bool valid = true;
		for (int i = 0; i < num_bars && valid == true; i++) {
			if (!bars[i].isValid()) {
				valid = false;
			}
		}
		return valid;
	}


	void BarChart::init(const char* title, int noOfSampels, char fill) {
		if (title[0] == '\0' || noOfSampels < num_bars) {
			empty();
		}
		else {
			c_title = new char[strlen(title) + 1];
			strcpy(c_title, title);
			num_bars = noOfSampels;
			num_added = 0;
			bars = new Bar[num_bars];
			c_fill = fill;
		}
	}

	void BarChart::add(const char* bar_title, int value) {
		if (num_added < num_bars) {
			bars[num_added].set(bar_title, c_fill, value);
			num_added++;
		}
	}

	void BarChart::draw() const {
		if (isValid()) {
			cout << c_title << '\n';
			cout.width(72);
			cout.fill('-');
			cout << '\n';
			for (int i = 0; i < num_bars; i++) {
				bars[i].draw();
			}
			cout.width(72);
			cout.fill('-');
			cout << '\n';
		}
		else {
			cout << "Invalid Chart!" << '\n';
		}
	}

	void BarChart::deallocate() {
		delete[] c_title;
		delete[] bars;
	}

}