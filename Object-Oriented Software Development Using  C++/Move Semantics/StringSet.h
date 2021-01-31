//==============================================
// Name:           Derek Shigetomi
// Student Number: 028-970-135
// Email:          dgshigetomi@myseneca.ca
// Date:           01/31/2021
// Section:        NBB
// Workshop:       2
//==============================================

#ifndef STRING_SET_H
#define STRING_SET_H

#include <string>

namespace sdds {
	class StringSet {
		std::string* strings;
		size_t numStrings;
	public:
		StringSet();
		~StringSet();
		StringSet(const char* name);
		StringSet(const StringSet& s);
		StringSet(StringSet&& src) noexcept;
		StringSet& operator=(StringSet&& src) noexcept;
		StringSet& operator=(const StringSet& s);
		size_t size() const;
		std::string operator[](size_t a) const;
	};
}

#endif
