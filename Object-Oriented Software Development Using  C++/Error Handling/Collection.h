//==============================================
// Name:           Derek Shigetomi
// Student Number: 028-970-135
// Email:          dgshigetomi@myseneca.ca
// Date:           02/21/2021
// Section:        NBB
// Workshop:       5
//==============================================

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <iostream>
#include <string>

namespace sdds {

	template <class T>
	class Collection {
		std::string objectName;
		T* arr;
		size_t objectSize = 0;
		void (*obs)(const Collection<T>&, const T&){};
	public:
		Collection(const std::string& name) {
			objectName = name;
			arr = nullptr;
			objectSize = 0;
		}
		Collection(Collection&) = delete;
		Collection& operator=(const Collection&) = delete;
		~Collection() {
			delete[] arr;
		}
		const std::string& name() const {
			return objectName;
		}
		size_t size() const {
			return objectSize;
		}
		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			obs = observer;
		}
		Collection<T>& operator+=(const T& item) {
			bool found = false;
			// check if item already in array
			for (size_t i = 0; i < objectSize; i++) {
				if (arr[i].title() == item.title()) {
					found = true;
				}
			}
			if (!found) {
				T* temp = new T[objectSize + 1];
				for (size_t i = 0; i < objectSize; i++) {
					temp[i] = arr[i];
				}
				temp[objectSize] = item;
				delete[] arr;
				arr = new T[objectSize + 1];
				objectSize++;
				for (size_t i = 0; i < objectSize; i++) {
					arr[i] = temp[i];
				}
				delete[] temp;
				if (obs != nullptr) {
					(*obs)(*this, item);
				}
			}
			return *this;
		}

		T& operator[](size_t idx) const {

			if (idx < 0 || idx >= objectSize) {
				throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(objectSize) + "] items.");
			}
			else {
				return arr[idx];
			}

		}

		T* operator[](const std::string& title) const {
			for (size_t i = 0; i < objectSize; i++) {
				if (arr[i].title() == title) {
					return &arr[i];
				}
			}
			return nullptr;
		}

	};

	template <typename T>
	std::ostream& operator<<(std::ostream& os, Collection<T>& t) {
		for (size_t i = 0; i < t.size(); i++) {
			os << t[i];
		}
		return os;
	}

}


#endif