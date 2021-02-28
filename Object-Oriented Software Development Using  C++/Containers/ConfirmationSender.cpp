//==============================================
// Name:           Derek Shigetomi
// Student Number: 028-970-135
// Email:          dgshigetomi@myseneca.ca
// Date:           02/13/2021
// Section:        NBB
// Workshop:       4
//==============================================

#include <iomanip>
#include "ConfirmationSender.h"

using namespace std;

namespace sdds {

	ConfirmationSender::ConfirmationSender(const ConfirmationSender& c) {
		*this = c;
	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender&& c) {
		*this = move(c);
	}

	ConfirmationSender::~ConfirmationSender() {
		delete[] r;
	}

	size_t ConfirmationSender::size() const {
		return counter;
	}

	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& c) {
		if (this != &c) {
			counter = c.counter;
			delete[] r;
			r = new const Reservation* [counter];
			for (auto i = 0u; i < counter; i++) {
				r[i] = c.r[i];
			}
		}
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& c) {
		if (this != &c) {
			r = c.r;
			counter = c.counter;
			c.counter = 0;
			c.r = nullptr;
		}
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
		bool existing = false;
		// Check if element is already in array
		for (size_t i = 0; i < counter; i++) {
			if (r[i] == &res) {
				existing = true;
			}
		}
		// If not in array, add
		if (!existing) {
			// Temp obkect, sized 1 bigger
			const Reservation** temp = new const Reservation* [counter + 1];
			// Add old elements, then add the new one
			for (size_t i = 0; i < counter; i++) {
				temp[i] = r[i];
			}
			temp[counter] = &res;
			
			// Resize and copy all elements including new one
			delete[] r;
			r = new const Reservation * [counter + 1];
			counter++;
			for (size_t i = 0; i < counter; i++) {
				r[i] = temp[i];
			}
			delete[] temp;
		}
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
		for (size_t i = 0; i < counter; i++) {
			if (r[i] == &res) {
				r[i] = nullptr;
			}
		}
		return *this;
	}
	ostream& operator<<(ostream& os, ConfirmationSender& c) {
		os << "--------------------------" << endl;
		os << "Confirmations to Send" << endl;
		os << "--------------------------" << endl;
		if (c.r == nullptr) {
			os << "There are no confirmations to send!" << endl;
		}
		else {
			for (size_t i = 0; i < c.size(); i++) {
				if (c.r[i] != nullptr)
					os << *c.r[i];
			}
		}
		os << "--------------------------" << endl;
		return os;
	}

}