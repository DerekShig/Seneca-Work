//==============================================
// Name:           Derek Shigetomi
// Student Number: 028-970-135
// Email:          dgshigetomi@myseneca.ca
// Date:           10/5/2020
// Section:        NDD
// Workshop:       3 (LAB)
// I have done all the coding by myself
//==============================================

#include "Subject.h"
#include <iostream>
#include <string.h>
#include <cstring>
#include <iomanip>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
namespace sdds {
	char Subject::grade() const {
		char grade = {'\0'};
		if (m_mark >= 0 && m_mark < 50) {
			grade = 'F';
		}
		else if (m_mark >= 50 && m_mark < 60) {
			grade = 'D';
		}
		else if (m_mark >= 60 && m_mark < 70) {
			grade = 'C';
		}
		else if (m_mark >= 70 && m_mark < 80) {
			grade = 'B';
		}
		else if (m_mark >= 80 && m_mark <= 100) {
			grade = 'A';
		}
		return grade;
	}

	void Subject::setEmpty() {
		m_mark = -1;
		m_code[0] = {'\0'};
	}

	void Subject::set(const char* code, int mark) {
		if (mark < 0 || mark > 100) {
			setEmpty();
		}
		else {
			m_mark = mark;
			strcpy(m_code, code);
		}
	}

	float Subject::scale4()const {
		float grade = 0.0;
		if (m_mark >= 0 && m_mark < 50) {
			grade = 0.0;
		}
		else if (m_mark >= 50 && m_mark < 60) {
			grade = 1.0;
		}
		else if (m_mark >= 60 && m_mark < 70) {
			grade = 2.0;
		}
		else if (m_mark >= 70 && m_mark < 80) {
			grade = 3.0;
		}
		else if (m_mark >= 80 && m_mark <= 100) {
			grade = 4.0;
		}
		return grade;
	}

	bool Subject::isValid()const {
		return m_mark >= 0;
	}

	void Subject::display()const {
		if (isValid()) {
			cout << m_code;
			cout.width(12);
			cout.fill(' ');
			cout << std::fixed;
			cout << std::setprecision(1);
			cout << m_mark;
			cout.width(10);
			cout << grade() << endl;
		}
	}
}