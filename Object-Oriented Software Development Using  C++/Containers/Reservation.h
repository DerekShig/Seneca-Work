//==============================================
// Name:           Derek Shigetomi
// Student Number: 028-970-135
// Email:          dgshigetomi@myseneca.ca
// Date:           02/13/2021
// Section:        NBB
// Workshop:       4
//==============================================

#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

#include <string>
#include <iostream>

namespace sdds {
	class Reservation {
		std::string reservationID;
		std::string name;
		std::string email;
		size_t numPeople;
		size_t day;
		size_t hour;
	public:
		Reservation();
		Reservation(const std::string& res);
		std::string trim(const std::string& str);
		friend std::ostream& operator<<(std::ostream& os, const Reservation& r);
	};
	
}

#endif