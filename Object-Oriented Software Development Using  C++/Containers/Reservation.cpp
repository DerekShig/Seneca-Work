//==============================================
// Name:           Derek Shigetomi
// Student Number: 028-970-135
// Email:          dgshigetomi@myseneca.ca
// Date:           02/13/2021
// Section:        NBB
// Workshop:       4
//==============================================

#include <iostream>
#include <string>
#include <iomanip>
#include "Reservation.h"

using namespace std;

namespace sdds {

	Reservation::Reservation() {
		numPeople = 0;
		day = 0;
		hour = 0;
		reservationID = "";
		name = "";
		email = "";
	}

	Reservation::Reservation(const string& res) {
		string str = res;
		reservationID = trim(str.substr(0, str.find(':')));
		str.erase(0, str.find(':') + 1);
		name = trim(str.substr(0, str.find(',')));
		str.erase(0, str.find(',') + 1);
		email = trim(str.substr(0, str.find(',')));
		str.erase(0, str.find(',') + 1);
		numPeople = stoi(trim(str.substr(0, str.find(','))));
		str.erase(0, str.find(',') + 1);
		day = stoi(trim(str.substr(0, str.find(','))));
		str.erase(0, str.find(',') + 1);
		hour = stoi(trim(str.substr(0, str.find(','))));
		str.erase(0, str.length());
	}

	string Reservation::trim(const std::string& str) {
		const string space = " \t\v\r\n";
		size_t start = str.find_first_not_of(space);
		size_t end = str.find_last_not_of(space);
		return str.substr(start, end - start + 1);
	}


	ostream& operator<<(ostream& os, const Reservation& r) {
		string time;
		if (r.hour >= 6 && r.hour <= 9) {
			time = "Breakfast";
		}
		else if (r.hour >= 11 && r.hour <= 15) {
			time = "Lunch";
		}
		else if (r.hour >= 17 && r.hour <= 21) {
			time = "Dinner";
		}
		else {
			time = "Drinks";
		}
		os << "Reservation " << setw(10) << setfill(' ') << right << r.reservationID << ':';
		os << setw(21) << setfill(' ') << right << r.name;
		os << "  <" << r.email << "> ";
		os << setw(21 - (r.email.length())) << left << ' ' << time;
		os << " on day " << r.day << " @ ";
		os << r.hour << ":00 for " << r.numPeople;
		if (r.numPeople == 1) {
			os << " person.";
		}
		else {
			os << " people.";
		}
		os << endl;
		return os;
	}

}