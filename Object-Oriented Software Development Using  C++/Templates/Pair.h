//==============================================
// Name:           Derek Shigetomi
// Student Number: 028-970-135
// Email:          dgshigetomi@myseneca.ca
// Date:           02/06/2021
// Section:        NBB
// Workshop:       3
//==============================================

#ifndef SSDS_PAIR_H
#define SSDS_PAIR_H

#include <iostream>

namespace sdds {
	template <typename V, typename K>
	class Pair {
		V pvalue;
		K pkey;
	public:
		Pair() : pvalue{}, pkey{} {}
		Pair(const V& value, const K& key) {
			pkey = key;
			pvalue = value;
		}
		const V& value() const {
			return pvalue;
		}
		const K& key() const {
			return pkey;
		}
		virtual void display(std::ostream& os) const {
			os << pkey << " : " << pvalue << std::endl;
		}
	};

	template <typename V, typename K>
	std::ostream& operator<<(std::ostream& os, const Pair<V, K>& pair) {
		pair.display(os);
		return os;
	}

}

#endif