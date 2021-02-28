#include "strTrim.h"

namespace sdds {
	std::string trim(const std::string& str) {
		const std::string space = " \t\v\r\n";
		size_t start = str.find_first_not_of(space);
		size_t end = str.find_last_not_of(space);
		return str.substr(start, end - start + 1);
	}
}