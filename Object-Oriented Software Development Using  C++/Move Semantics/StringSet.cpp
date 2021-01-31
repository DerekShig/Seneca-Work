//==============================================
// Name:           Derek Shigetomi
// Student Number: 028-970-135
// Email:          dgshigetomi@myseneca.ca
// Date:           01/31/2021
// Section:        NBB
// Workshop:       2
//==============================================

#include <iostream>
#include <fstream>

#include "StringSet.h"

using namespace std;

namespace sdds {

	StringSet::StringSet() {
		numStrings = 0u;
		strings = nullptr;
	}

	StringSet::~StringSet() {
		delete[] strings;
	}

	StringSet::StringSet(const char* name) : StringSet() {
		int counter = 0;
		ifstream Text(name);
		string myText;
		while (getline(Text, myText, ' ')) {
			numStrings++;
		}
		strings = new string[numStrings + 1];
		Text.clear();
		Text.seekg(0);
		while (getline(Text, strings[counter], ' ')) {
			counter++;
		}
		Text.close();
	}

	StringSet::StringSet(const StringSet& s) {
		strings = nullptr;
		*this = s;
	}

	StringSet::StringSet(StringSet&& src) noexcept {
		*this = move(src);
	}

	StringSet& StringSet::operator=(StringSet&& src) noexcept {
		if (this != &src) {
			strings = src.strings;
			numStrings = src.numStrings;
			src.strings = nullptr;
			src.numStrings = 0u;
		}
		return *this;
	}

	StringSet& StringSet::operator=(const StringSet& s) {
		if (this != &s) {
			delete[] strings;
			numStrings = s.numStrings;
			strings = new string[numStrings + 1];
			for (size_t i = 0; i < numStrings; i++) {
				strings[i] = s.strings[i];
			}
		}
		return *this;
	}

	size_t StringSet::size() const {
		return size_t(numStrings);
	}

	string StringSet::operator[](size_t a) const {
		string tmp;
		if (a < numStrings) {
			tmp = strings[a];
		}
		return string(tmp);
	}

}