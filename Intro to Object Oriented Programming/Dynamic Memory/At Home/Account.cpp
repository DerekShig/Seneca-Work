//==============================================
// Name:           Derek Shigetomi
// Student Number: 028-970-135
// Email:          dgshigetomi@myseneca.ca
// Date:           10/4/2020
// Section:        NDD
// Workshop:       2 (DIY)
// I have done all the coding by myself
//==============================================

#include "Account.h"
#include "File.h"
#include <iostream>

using namespace std;

namespace sdds {
	int numOfRecords;
	Info* rec = nullptr;

	void sort() {
		int i, j;
		Info temp;
		for (i = numOfRecords - 1; i > 0; i--) {
			for (j = 0; j < i; j++) {
				if (rec[j].amount > rec[j + 1].amount) {
					temp = rec[j];
					rec[j] = rec[j + 1];
					rec[j + 1] = temp;
				}
			}
		}
	}

	bool load(const char file[]) {
		bool ok = true;
		int i;
		if (!openFile(file)) {
			cout << "Could not open data file: " << file << endl;
			ok = false;
		}
		numOfRecords = noOfRecords();
		rec = new Info[numOfRecords];

		for (i = 0; i < numOfRecords; i++) {
			read(rec[i].acc);
			read(rec[i].amount);
		}
		if (i < numOfRecords) {
			cout << "Error: incorrect number of records read; the data is possibly corrupted!" << endl;
		}
		closeFile();
		return ok;
	}

	void display() {
		sort();
		cout << "Account#: Balance" << endl;
		for (int i = 0; i < numOfRecords; i++) {
			cout << i + 1 << ": " << rec[i].acc << ":  " << rec[i].amount << endl;
		}
	}

	void deallocateMemory() {
		delete[] rec;
		rec = nullptr;
	}
	

}