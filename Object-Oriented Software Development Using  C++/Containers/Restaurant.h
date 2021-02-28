//==============================================
// Name:           Derek Shigetomi
// Student Number: 028-970-135
// Email:          dgshigetomi@myseneca.ca
// Date:           02/13/2021
// Section:        NBB
// Workshop:       4
//==============================================

#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H

#include "Reservation.h"

namespace sdds {

	class Restaurant {
		Reservation* res{};
		size_t count = 0;
	public:
		Restaurant(const Reservation* reservations[], size_t cnt);
		Restaurant(const Restaurant& r);
		~Restaurant();
		Restaurant& operator=(const Restaurant& s);
		Restaurant(Restaurant&& src) noexcept;
		Restaurant& operator=(Restaurant&& src) noexcept;
		size_t size() const;
		friend std::ostream& operator<<(std::ostream& os, const Restaurant& r);
	};

}

#endif