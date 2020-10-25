//==============================================
// Name:           Derek Shigetomi
// Student Number: 028-970-135
// Email:          dgshigetomi@myseneca.ca
// Date:           10/15/2020
// Section:        NDD
// Workshop:       4 (Lab)
// I have done all the coding by myself
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Box.h"
#include <iostream>
#include <iomanip>

namespace sdds {

	Box::Box() {
		m_height = 12;
		m_length = 12;
		m_width = 12;
		m_contentName = nullptr;
		m_contentVolume = 0;
	}

	Box::Box(int sideLength, const char* contentName) {
		m_contentName = nullptr;
		if (sideLength < 5 || sideLength > 36) {
			setUnusable();
		}
		else {
			m_height = sideLength;
			m_length = sideLength;
			m_width = sideLength;
			m_contentVolume = 0;
			setName(contentName);
		}
	}

	Box::Box(int width, int height, int length, const char* contentName) {
		m_contentName = nullptr;
		if ((width < 5 || width > 36) || (height < 5 || height > 36) || (length < 5 || length > 36)) {
			setUnusable();
		}
		else {
			m_height = height;
			m_length = length;
			m_width = width;
			m_contentVolume = 0;
			setName(contentName);
		}
	}

	Box::~Box() {
		delete[] m_contentName;
	}

	void Box::setName(const char* Cstr) {
		if (Cstr != nullptr) {
			delete[] m_contentName;
			m_contentName = nullptr;
			m_contentName = new char[strlen(Cstr) + 1];
			strcpy(m_contentName, Cstr);
		}
	}

	void Box::setUnusable() {
		delete[] m_contentName;
		m_contentName = nullptr;
		m_height = -1;
		m_length = -1;
		m_width = -1;
		m_contentVolume = -1;
	}

	bool Box::isUnusable() const {
		return m_height == -1;
	}

	bool Box::hasContent() const {
		return m_contentVolume > 0 || quantity() > 0;
	}

	int Box::capacity() const {
		return m_height * m_length * m_width;
	}

	int Box::quantity() const {
		return m_contentVolume;
	}

	Box& Box::setContent(const char* contentName) {
		if (hasContent() && m_contentName != nullptr) {
			setUnusable();
		}
		else {
			setName(contentName);
		}
		return *this;
	}

	ostream& Box::display() const {
		if (isUnusable()) {
			cout << "Unusable box, discard the content, and recycle.";
		}
		else if (m_contentName == nullptr) {
			cout.width(30);
			cout.fill('.');
			cout << left << "Empty box";

		}
		else {
			cout.width(30);
			cout.fill('.');
			cout << left << m_contentName;
		}
		if (!isUnusable()) {
			cout.fill(' ');
			cout.fill('0');
			cout << "  " << setw(2) << right << m_width << 'x' << setw(2) << right << m_height << 'x' << setw(2) << right << m_length;
			cout.width(8);
			cout.fill(' ');
			cout << right << quantity() << '/' << capacity() << " C.I.";
		}
		return cout;
	}

	Box& Box::add(int quantity) {
		if (quantity > 0 && quantity < capacity()) {
			m_contentVolume += quantity;
		}
		else {
			setUnusable();
		}
		return *this;
	}

	Box& Box::add(Box& B) {
		if (m_contentName == nullptr || quantity() == 0) {
			setContent(B.m_contentName);
		}
		if (strcmp(m_contentName, B.m_contentName) == 0) {
			if (quantity() + B.quantity() <= capacity()) {
				add(B.quantity());
				B.m_contentVolume = 0;
			}
			else {
				B.m_contentVolume -= (capacity() - quantity());
				m_contentVolume = capacity();
			}
		}
		else {
			if (quantity() + B.quantity() <= capacity()) {
				B.m_contentVolume = 0;
			}
			else {
				B.m_contentVolume -= (capacity() - quantity());
			}
			setUnusable();
		}
		return *this;
	}

}

