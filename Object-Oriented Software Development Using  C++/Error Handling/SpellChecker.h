//==============================================
// Name:           Derek Shigetomi
// Student Number: 028-970-135
// Email:          dgshigetomi@myseneca.ca
// Date:           02/21/2021
// Section:        NBB
// Workshop:       5
//==============================================

#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

#include <string>

namespace sdds {

	class SpellChecker {
		std::string m_badWords[6];
		std::string m_goodWords[6];
		size_t replaceCnt[6] = {0};
	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};

}


#endif