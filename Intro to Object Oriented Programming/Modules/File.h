//==============================================
// Name:           Derek Shigetomi
// Student Number: 028-970-135
// Email:          dgshigetomi@myseneca.ca
// Date:           9/27/2020
// Section:        NDD
// Workshop:       1
// I have done all the coding by myself
//==============================================

#ifndef _FILE_H_
#define _FILE_H_

namespace sdds {
	// file protos go here
	void openFile(const char filename[]);
	void closeFile();
	void readProgram(char program[]);
	void readCode(int *ext);
}

#endif