//==============================================
// Name:           Derek Shigetomi
// Student Number: 028-970-135
// Email:          dgshigetomi@myseneca.ca
// Date:           02/21/2021
// Section:        NBB
// Workshop:       5
//==============================================

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

#include <string>
#include <iostream>

namespace sdds {

	class Movie {
		std::string movieTitle;
		std::string movieDesc;
		size_t movieYear;
	public:
		Movie();
		const std::string& title() const;
		std::string trim(const std::string& str);
		Movie(const std::string& str);
		friend std::ostream& operator<<(std::ostream& os, const Movie& b);
		template <typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(this->movieDesc);
			spellChecker(this->movieTitle);
		}
	};

}


#endif