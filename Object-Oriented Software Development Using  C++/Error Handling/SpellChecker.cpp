//==============================================
// Name:           Derek Shigetomi
// Student Number: 028-970-135
// Email:          dgshigetomi@myseneca.ca
// Date:           02/21/2021
// Section:        NBB
// Workshop:       5
//==============================================

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "SpellChecker.h"

using namespace std;

namespace sdds {

	SpellChecker::SpellChecker(const char* filename){
		const string space = " \t\v\r\n";
		string line;
		size_t counter = 0;
		string bad, good;
		ifstream file;
		file.open(filename);
		if (!file.is_open()) {
			throw "Bad file name!";
		}
		while (!file.eof()) {
			if (file.peek() != EOF) {
				getline(file, line);
				m_badWords[counter] = line.substr(0, line.find_first_of(space));
				line.erase(0, line.find_first_of(space));
				m_goodWords[counter] = line.substr(line.find_first_not_of(space), line.find_last_not_of(space));
				counter++;
			}
		}
		file.close();
	}

	void SpellChecker::operator()(std::string& text) {
		for (size_t i = 0; i < sizeof(m_badWords) / sizeof(m_badWords[0]); i++) {
			size_t pos = 0;
			while (pos != string::npos) {
				pos = text.find(m_badWords[i]);
				if (pos != string::npos) {
					text.replace(pos, m_badWords[i].length(), m_goodWords[i]);
					replaceCnt[i]++;
				}
			}
		}
	}

	void SpellChecker::showStatistics(std::ostream& out) const {
		out << "Spellchecker Statistics" << endl;
		for (size_t i = 0; i < sizeof(m_badWords) / sizeof(m_badWords[0]); i++) {
			out << setw(15) << setfill(' ') << right << m_badWords[i] << ": " << replaceCnt[i] << " replacements" << endl;
		}
	}

}