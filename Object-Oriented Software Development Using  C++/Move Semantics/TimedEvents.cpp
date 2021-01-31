//==============================================
// Name:           Derek Shigetomi
// Student Number: 028-970-135
// Email:          dgshigetomi@myseneca.ca
// Date:           01/31/2021
// Section:        NBB
// Workshop:       2
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <iomanip>

#include "TimedEvents.h"

using namespace std;

namespace sdds {

	TimedEvents::TimedEvents() {
		records = 0;
	}

	TimedEvents::~TimedEvents() {
		for (int i = 0; i < records; i++) {
			delete[] e[i].event_name;
			delete[] e[i].unit;
		}
	}

	void TimedEvents::startClock() {
		start = std::chrono::steady_clock::now();
	}

	void TimedEvents::stopClock() {
		end = std::chrono::steady_clock::now();
	}

	void TimedEvents::addEvent(const char* name) {
		delete[] e[records].unit;
		e[records].unit = new char[strlen("nanoseconds") + 1];
		strcpy(e[records].unit, "nanoseconds");
		delete[] e[records].event_name;
		e[records].event_name = new char[strlen(name) + 1];
		strcpy(e[records].event_name, name);
		e[records].duration = end - start;
		records++;
	}

	std::ostream& operator<<(std::ostream& os, TimedEvents& t) {
		os << "--------------------------" << endl;
		os << "Execution Times:" << endl;
		os << "--------------------------" << endl;
		for (int i = 0; i < t.records; i++) {
			os << setw(21) << left << t.e[i].event_name << ' '  << setw(13) << right << t.e[i].duration.count() << ' ' << t.e[i].unit << endl;
		}
		os << "--------------------------" << endl;
		return os;
	}

}