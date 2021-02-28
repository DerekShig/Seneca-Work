//==============================================
// Name:           Derek Shigetomi
// Student Number: 028-970-135
// Email:          dgshigetomi@myseneca.ca
// Date:           02/21/2021
// Section:        NBB
// Workshop:       5
//==============================================

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <string>
#include <iostream>

namespace sdds {

	class Book {
		std::string bookAuthor;
		std::string bookTitle;
		std::string bookCountry;
		std::string bookDesc;
		size_t bookYear;
		double bookPrice;
		size_t max;
	public:
		Book();
		Book(const std::string& strBook);
		std::string trim(const std::string& str);
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		friend std::ostream& operator<<(std::ostream& os, const Book& b);

		template <typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(this->bookDesc);
		}
	};

}

#endif