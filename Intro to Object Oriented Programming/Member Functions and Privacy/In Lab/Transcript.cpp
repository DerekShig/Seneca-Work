//==============================================
// Name:           Derek Shigetomi
// Student Number: 028-970-135
// Email:          dgshigetomi@myseneca.ca
// Date:           10/5/2020
// Section:        NDD
// Workshop:       3 (LAB)
// I have done all the coding by myself
//==============================================

#include "Transcript.h"
#include <iostream>
#include <string.h>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
namespace sdds {
	void Transcript::setEmpty() {
		m_studentName = nullptr;
		m_subjects = nullptr;
	}

	bool Transcript::isValid()const {
		bool valid = true;
		if (m_studentName != NULL && m_subjects != NULL) {
			for (int i = 0; i < m_noOfSubjects && valid == true; i++) {
				if (!m_subjects[i].isValid()) {
					valid = false;
				}
			}
		}
		return valid;
	}

	void Transcript::Title()const {
		cout << m_studentName << endl;
		cout.width(30);
		cout.fill('-');
		cout << '\n';
	}

	float Transcript::gpa()const {
		float sum = 0.0;
		for (int i = 0; i < m_subjectsAdded; i++) {
			sum += m_subjects[i].scale4();
		}
		return sum / m_subjectsAdded;
	}

	void Transcript::footer()const {
		cout.fill('-');
		cout.width(30);
		cout << '\n';
		cout.fill(' ');
		cout.width(26);
		cout << "GPA: " << gpa() << endl;
	}

	void Transcript::init(const char* studentName, int noOfSubjects) {
		if (studentName == NULL || noOfSubjects < 1) {
			setEmpty();
		}
		else {
			m_noOfSubjects = noOfSubjects;
			m_subjectsAdded = 0;
			m_studentName = new char[strlen(studentName) + 1];
			strcpy(m_studentName, studentName);
			m_subjects = new Subject[m_noOfSubjects];
		}
	}

	bool Transcript::add(const char* subject_code, int mark) {
		bool add = true;
		if (m_subjectsAdded < m_noOfSubjects) {
			m_subjects[m_subjectsAdded].set(subject_code, mark);
			m_subjectsAdded += 1;
		}
		else {
			add = false;
		}
		return add;
	}

	void Transcript::display()const {
		if (isValid()) {
			Title();
			for (int i = 0; i < m_noOfSubjects; i++) {
				m_subjects[i].display();
			}
			footer();
		}
		else {
			cout << "Invalid Transcript!" << endl;
		}
	}

	void Transcript::deallocate() {
		delete[] m_studentName;
		delete[] m_subjects;
	}


}