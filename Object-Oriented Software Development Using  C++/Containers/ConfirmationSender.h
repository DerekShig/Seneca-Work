//==============================================
// Name:           Derek Shigetomi
// Student Number: 028-970-135
// Email:          dgshigetomi@myseneca.ca
// Date:           02/13/2021
// Section:        NBB
// Workshop:       4
//==============================================

#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H

#include "Reservation.h"

namespace sdds {

	class ConfirmationSender {
		const Reservation** r{};
		size_t counter = 0;
	public:
		ConfirmationSender() {}
		ConfirmationSender(const ConfirmationSender& c);
		ConfirmationSender(ConfirmationSender&& c);
		~ConfirmationSender();
		size_t size() const;
		ConfirmationSender& operator=(const ConfirmationSender& c);
		ConfirmationSender& operator=(ConfirmationSender&& c);
		ConfirmationSender& operator+=(const Reservation& r);
		ConfirmationSender& operator-=(const Reservation& r);
		friend std::ostream& operator<<(std::ostream& os, ConfirmationSender& c);
	};

}

#endif
