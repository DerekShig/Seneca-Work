//==============================================
// Name:           Derek Shigetomi
// Student Number: 028-970-135
// Email:          dgshigetomi@myseneca.ca
// Date:           02/13/2021
// Section:        NBB
// Workshop:       4
//==============================================

#include <iostream>
#include "Reservation.h"
#include "Restaurant.h"

using namespace std;

namespace sdds {

	Restaurant::Restaurant(const Reservation* reservations[], size_t cnt) {
		count = cnt;
		delete[] res;
		res = new Reservation[cnt];
		for (size_t i = 0; i < cnt; i++) {
			res[i] = *reservations[i];
		}
	}

	Restaurant::Restaurant(const Restaurant& r) {
		*this = r;
	}

	Restaurant::~Restaurant() {
		delete[] res;
	}

	Restaurant::Restaurant(Restaurant&& src) noexcept {
		*this = move(src);
	}

	Restaurant& Restaurant::operator=(const Restaurant& s) {
		if (this != &s) {
			count = s.count;
			delete[] res;
			res = new Reservation[count];
			for (size_t i = 0; i < count; i++) {
				res[i] = s.res[i];
			}
		}
		return *this;
	}

	Restaurant& Restaurant::operator=(Restaurant&& src) noexcept{
		if (this != &src) {
			delete[] res;
			count = src.count;
			res = src.res;
			src.res = nullptr;
			src.count = 0;
		}
		return *this;
	}
	
	size_t Restaurant::size() const {
		return count;
	}

	std::ostream& operator<<(std::ostream& os, const Restaurant& r) {
		static size_t tick = 0;
		tick++;
		os << "--------------------------" << endl;
		os << "Fancy Restaurant (" << tick  << ')'<< endl;
		os << "--------------------------" << endl;
		if (r.size() > 0) {
			for (size_t i = 0; i < r.size(); i++) {
				os << r.res[i];
			}
		}
		else {
			os << "This restaurant is empty!" << endl;
		}

		os << "--------------------------" << endl;
		return os;
	}

}