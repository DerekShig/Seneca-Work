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
#define MAX_RECORDS 24

#include <iostream>
#include <cstring>
#include<string.h>

#include "School.h"
#include "File.h"

using namespace std;

namespace sdds {

	Record records[MAX_RECORDS] = {0};

	// loading definitions go here
	void load() {
		int i = 0;
		openFile("schools.dat");
		while (i < MAX_RECORDS) {
			readProgram(records[i].program);
			readCode(&records[i].ext);
			i++;
		}
		closeFile();
	}

	int checkMatch(char code[]) {
		int i, index = -1;
		for (i = 0; i < MAX_RECORDS; i++) {
			if (strcmp(code, records[i].program) == 0) {
				index = i;
			}
		}
		return index;
	}

	void printMatch(char code[]) {
		int index = checkMatch(code);
		if (index == -1) {
			cout << code << " School code not found!" << endl;
		} else {
			cout << "416 491 5050 x " << records[index].ext << endl;
		}
	}

}