#include <iostream>
#include "IOAble.h"

using namespace std;

namespace sdds {

	IOAble::~IOAble() {

	}

	ostream& operator<<(ostream& os, const IOAble& i) {
		i.write(os);
		return os;
	}

	istream& operator>>(istream& is, IOAble& i) {
		i.read(is);
		return is;
	}

}