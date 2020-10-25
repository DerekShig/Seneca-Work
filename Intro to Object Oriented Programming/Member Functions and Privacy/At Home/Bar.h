//==============================================
// Name:           Derek Shigetomi
// Student Number: 028-970-135
// Email:          dgshigetomi@myseneca.ca
// Date:           10/11/2020
// Section:        NDD
// Workshop:       3 (DIY)
// I have done all the coding by myself
//==============================================

#ifndef _BAR_H_
#define _BAR_H_

#define _CRT_SECURE_NO_WARNINGS

namespace sdds {

	class Bar {
		char b_title[21];
		char b_fill;
		int b_length;
	public:
		Bar();
		void setEmpty();
		void set(const char *title, char fill, int length);
		bool isValid()const;
		void draw()const;
	};

}

#endif
