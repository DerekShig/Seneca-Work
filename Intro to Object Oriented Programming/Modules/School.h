//==============================================
// Name:           Derek Shigetomi
// Student Number: 028-970-135
// Email:          dgshigetomi@myseneca.ca
// Date:           9/27/2020
// Section:        NDD
// Workshop:       1
// I have done all the coding by myself
//==============================================

#ifndef _SCHOOL_H_
#define _SCHOOL_H_

namespace sdds {

	struct Record {
		char program[5];
		int ext;
	};

	void load();
	int checkMatch(char code[]);
	void printMatch(char code[]);
}

#endif
