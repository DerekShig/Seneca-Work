//==============================================
// Name:           Derek Shigetomi
// Student Number: 028-970-135
// Email:          dgshigetomi@myseneca.ca
// Date:           02/06/2021
// Section:        NBB
// Workshop:       3
//==============================================

#ifndef SSDS_SET_H
#define SSDS_SET_H

namespace sdds {

	template <size_t N, typename T>
	class Set {
		size_t elements;
		T arr[N];
	public:
		Set() : arr{} {
			elements = 0u;
		}		
		size_t size() const {
			return elements;
		}
		const T& get(size_t idx) const {
			return arr[idx];
		}
		void operator+=(const T& item) {
			if (elements < N) {
				arr[elements] = item;
				elements++;
			}
		}
	};



}

#endif
