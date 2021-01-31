//==============================================
// Name:           Derek Shigetomi
// Student Number: 028-970-135
// Email:          dgshigetomi@myseneca.ca
// Date:           01/31/2021
// Section:        NBB
// Workshop:       2
//==============================================

#ifndef TIMED_EVENTS_H
#define TIMED_EVENTS_H

#include <chrono>
#include <ostream>

namespace sdds {

	struct Event {
		char* event_name = nullptr;
		char* unit = nullptr;
		std::chrono::steady_clock::duration duration;
	};

	class TimedEvents {
		static const int max = 10;
		int records;
		std::chrono::steady_clock::time_point start;
		std::chrono::steady_clock::time_point end;
		Event e [max];
	public:
		TimedEvents();
		~TimedEvents();
		void startClock();
		void stopClock();
		void addEvent(const char* name);
		friend std::ostream& operator<<(std::ostream& os, TimedEvents& t);
	};

}

#endif
