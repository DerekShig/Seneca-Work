//==============================================
// Name:           Derek Shigetomi
// Student Number: 028-970-135
// Email:          dgshigetomi@myseneca.ca
// Date:           02/06/2021
// Section:        NBB
// Workshop:       3
//==============================================

#ifndef SSDS_SETSUMMABLE_H
#define SSDS_SETSUMMABLE_H

#include "Set.h"

namespace sdds {

	template <size_t N, typename T>
	class SetSummable : public Set<N, T> {
	public:
		T accumulate(const std::string& filter) const {
			T obj(filter);
			for (size_t i = 0u; i < this->size(); i++) {
				if ( (this->get(i)).isCompatibleWith(obj) ) {
					obj += this->get(i);
				} 
			}
			return obj;
		}
	};

}

#endif