//==============================================
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

#include "File.h"

using namespace std;

namespace sdds {

	FILE* fptr;

	// file definitions go here
	void openFile(const char filename[]) {
		fptr = fopen(filename, "r");
	}

	// closes the data file
	void closeFile() {
		if (fptr) fclose(fptr);
	}

	void readProgram(char program[]) {
		fscanf(fptr, "%4s", program);
	}

	void readCode(int *ext) {
		fscanf(fptr, "%d", ext);
	}

}