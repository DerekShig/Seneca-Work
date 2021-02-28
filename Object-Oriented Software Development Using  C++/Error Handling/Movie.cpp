//==============================================
// Name:           Derek Shigetomi
// Student Number: 028-970-135
// Email:          dgshigetomi@myseneca.ca
// Date:           02/21/2021
// Section:        NBB
// Workshop:       5
//==============================================

#include <iostream>
#include <iomanip>
#include <string>
#include "Movie.h"

using namespace std;

namespace sdds {

	Movie::Movie() {
		movieYear = 0;
	}

	const string& Movie::title() const {
		return movieTitle;
	}

    Movie::Movie(const std::string& str) {
        string tmp = str;
        movieTitle = trim(tmp.substr(0, tmp.find(',')));
        tmp.erase(0, tmp.find(',') + 1);
        movieYear = stoi(trim(tmp.substr(0, tmp.find(','))));
        tmp.erase(0, tmp.find(',') + 1);
        movieDesc = trim(tmp.substr(0, tmp.find('.') + 1));
    }

    string Movie::trim(const std::string& str) {
        const string space = " \t\v\r\n";
        size_t start = str.find_first_not_of(space);
        size_t end = str.find_last_not_of(space);
        return str.substr(start, end - start + 1);
    }

    std::ostream& operator<<(std::ostream& os, const Movie& m) {
        os << setw(40) << setfill(' ') << m.movieTitle << " | ";
        os << setw(4) << setfill(' ') << m.movieYear << " | " << m.movieDesc << endl;
        return os;
    }


}