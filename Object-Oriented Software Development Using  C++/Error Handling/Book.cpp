//==============================================
// Name:           Derek Shigetomi
// Student Number: 028-970-135
// Email:          dgshigetomi@myseneca.ca
// Date:           02/21/2021
// Section:        NBB
// Workshop:       5
//==============================================

#include <iomanip>
#include "strTrim.h"
#include "Book.h"

using namespace std;

namespace sdds {

	Book::Book() {
		bookYear = 0;
		bookPrice = 0.00;
		max = 0;
	}

	Book::Book(const std::string& strBook) {
		string str = strBook;
		bookAuthor = trim(str.substr(0, str.find(',')));
		str.erase(0, str.find(',') + 1);
		bookTitle = trim(str.substr(0, str.find(',')));
		str.erase(0, str.find(',') + 1);
		bookCountry = trim(str.substr(0, str.find(',')));
		str.erase(0, str.find(',') + 1);
		bookPrice = stod(trim(str.substr(0, str.find(','))).c_str());
		str.erase(0, str.find(',') + 1);
		bookYear = stoi(trim(str.substr(0, str.find(','))));
		str.erase(0, str.find(',') + 1);
		bookDesc = trim(str);
	}

	string Book::trim(const std::string& str) {
		const string space = " \t\v\r\n";
		size_t start = str.find_first_not_of(space);
		size_t end = str.find_last_not_of(space);
		return str.substr(start, end - start + 1);
	}

	const std::string& Book::title() const {
		return bookTitle;
	}

	const std::string& Book::country() const {
		return bookCountry;
	}

	const size_t& Book::year() const {
		return bookYear;
	}

	double& Book::price() {
		return bookPrice;
	}

	std::ostream& operator<<(std::ostream& os, const Book& b) {
		os << setw(20) << setfill(' ') << right << b.bookAuthor << " | " << setw(22) << setfill(' ') << right << b.bookTitle << " | ";
		os << setw(5) << setfill(' ') << right << b.bookCountry << " | " << setw(4) << setfill(' ') << b.bookYear << " | ";
		os << setw(6) << setfill(' ') << right  << setprecision(2) << fixed << b.bookPrice << " | ";
		os << b.bookDesc << endl;
		return os;
	}

}