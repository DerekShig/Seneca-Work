#define _CRT_SECURE_NO_WARNINGS

#include "Time.h"
#include "utils.h"
#include <iomanip>

using namespace std;
namespace sdds {

	Time& Time::reset() {
		m_min = getTime();
		return *this;
	}

	Time::Time(unsigned int min) {
		m_min = min;
	}

	std::ostream& Time::write(std::ostream& ostr) const {
		ostr << setw(2) << setfill('0') << m_min / 60 << ':' << setw(2) << setfill('0') << m_min - (m_min / 60) * 60;
		return ostr;
	}

	std::istream& Time::read(std::istream& istr) {
		int hours = 0, minutes = 0;
		char colon = '\0';
		istr >> hours >> colon >> minutes;

		if (colon != ':') {
			istr.setstate(std::ios::failbit);
		}
		else {
			m_min = hours * 60 + minutes;
		}
		return istr;
	}

	Time::operator int() const {
		return m_min;
	}

	Time& Time::operator*=(int val) {
		m_min *= val;
		return *this;
	}

	Time& Time::operator-=(const Time& D) {
		if (m_min < unsigned((int)D)) {
			m_min = (m_min + 1440) - (int)D;
		}
		else {
			m_min -= (int)D;
		}
		return *this;
	}

	ostream& operator<<(ostream& os, const Time& t) {
		t.write(os);
		return os;
	}

	istream& operator>>(istream& is, Time& t) {
		t.read(is);
		return is;
	}

	Time& Time::operator-(const Time& ROperand) {
		Time LOperand = *this;
		LOperand -= ROperand;
		*this = LOperand;
		return *this;
	}

}