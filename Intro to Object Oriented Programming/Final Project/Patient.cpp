#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Patient.h"
#include "utils.h"

using namespace std;

namespace sdds {

	Patient::Patient(int ticketNum, bool flag) : p(ticketNum) {
		p_flag = flag;
		p_name = nullptr;
		p_number = 0;
	}

	Patient::~Patient() {
		delete[] p_name;
	}

	bool Patient::fileIO() const {
		return p_flag;
	}

	void Patient::fileIO(bool b) {
		p_flag = b;
	}

	bool Patient::operator==(char c) const {
		return c == type();
	}

	bool Patient::operator==(const Patient& p) const {
		return this->type() == p.type();
	}

	void Patient::setArrivalTime() {
		p.resetTime();
	}

	Patient::operator Time() const {
		return Time(p);
	}

	int Patient::number() const {
		return p.number();
	}

	ostream& Patient::csvWrite(ostream& os) const {
		os << type() << ',' << p_name << ',' << p_number << ',';
		p.csvWrite(os);
		return os;
	}

	istream& Patient::csvRead(istream& is) {
		char temp[51];
		is.get(temp, 51, ',');
		delete[] p_name;
		p_name = new char[strlen(temp) + 1];
		strcpy(p_name, temp);
		is.ignore(1000, ',');
		is >> p_number;
		is.ignore(1000, ',');
		p.csvRead(is);
		return is;
	}

	ostream& Patient::write(ostream& os) const {
		os << p << endl;
		os << p_name << ", " << "OHIP: " << p_number;
		return os;
	}

	istream& Patient::read(istream& is) {
		char temp[51];
		bool flag = true;
		cout << "Name: ";
		is.get(temp, 51, '\n');
		delete[] p_name;
		p_name = new char[strlen(temp) + 1];
		strcpy(p_name, temp);
		is.ignore(1000, '\n');
		cout << "OHIP: ";
		do {
			p_number = getInt();
			if (p_number >= 100000000 && p_number <= 999999999) {
				flag = false;
			}
			else {
				cout << "Invalid value enterd, retry[100000000 <= value <= 999999999]: ";
			}
		} while (flag);
		return is;
	}

}