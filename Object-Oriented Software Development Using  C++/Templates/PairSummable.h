//==============================================
// Name:           Derek Shigetomi
// Student Number: 028-970-135
// Email:          dgshigetomi@myseneca.ca
// Date:           02/06/2021
// Section:        NBB
// Workshop:       3
//==============================================

#ifndef SSDS_PAIRSUMMABLE_H
#define SSDS_PAIRSUMMABLE_H

#include <iomanip>
#include "Pair.h"

namespace sdds {

	template <typename V, typename K>
	class PairSummable : public Pair<V, K> {
		static V initial;
		static size_t minWidth;
	public:
		PairSummable() {}
		PairSummable(const K& key, const V& value = initial) : Pair<V, K>(value, key) {
			if (minWidth < key.size()) {
				minWidth = key.size();
			}
		}
		bool isCompatibleWith(const PairSummable<V, K>& b) const {
			return this->key() == b.key();
		}
		PairSummable<V, K>& operator+=(const PairSummable<V, K>& b) {
			*this = PairSummable(this->key(), this->value() + b.value());
			return *this;
		}
		void display(std::ostream& os) const override{
			os << std::left << std::setw(minWidth);
			Pair<V, K>::display(os);
			os << std::right;
		}
	};

	template<>
	PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator+=(const PairSummable<std::string, std::string>& b) {
		// Only add comma where there is a value
		std::string comma = (this->value() != "") ? ", " : "";
		*this = PairSummable<std::string, std::string>(this->key(), this->value() + comma + b.value());
		return *this;
	}

	template <typename V, typename K>
	V PairSummable<V, K>::initial{};

	template <typename V, typename K>
	size_t PairSummable<V, K>::minWidth = 0u;
}

#endif