//==============================================
// Name:           Derek Shigetomi
// Student Number: 028-970-135
// Email:          dgshigetomi@myseneca.ca
// Date:           10/11/2020
// Section:        NDD
// Workshop:       3 (DIY)
// I have done all the coding by myself
//==============================================

#ifndef _BARCHART_H_
#define _BARCHART_H_
#define _CRT_SECURE_NO_WARNINGS

#include "Bar.h"

namespace sdds {

	class BarChart {
		char* c_title;
		Bar* bars;
		char c_fill;
		int num_bars;
		int num_added;
		void empty();
		bool isValid()const;
	public:
		BarChart();
		void init(const char* title, int noOfSampels, char fill);
		void add(const char* bar_title, int value);
		void draw()const;
		void deallocate();
	};


}

#endif