#define _CRT_SECURE_NO_WARNINGS

#ifndef SDDS_TIME_H
#define SDDS_TIME_H
#include <iostream>
#include <ostream>
using namespace std;
namespace sdds {
    class Time {
        unsigned int m_min;
    public:
        Time& reset();
        Time(unsigned int min = 0);
        ostream& write(ostream& ostr) const;
        istream& read(istream& istr);
        operator int()const;
        Time& operator *= (int val);
        Time& operator-=(const Time& D);
        Time& operator-(const Time& ROperand);
    };
    ostream& operator<<(ostream& os, const Time& t);
    istream& operator>>(istream& is, Time& t);


}

#endif // !SDDS_TIME_H

