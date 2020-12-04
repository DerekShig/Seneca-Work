#ifndef SDDS_IOABLE_H_
#define SDDS_IOABLE_H_

#include <iostream>
#include <ostream>

using namespace std;

namespace sdds {

	class IOAble {
	public:
		virtual ostream& csvWrite(ostream& os)const = 0;
		virtual istream& csvRead(istream& is) = 0;
		virtual ostream& write(ostream& os)const = 0;
		virtual istream& read(istream& is) = 0;
		virtual ~IOAble();
	};
	ostream& operator<<(ostream& os, const IOAble& i);
	istream& operator>>(istream& is, IOAble& i);

}

#endif // !SDDS_IOABLE_H_
