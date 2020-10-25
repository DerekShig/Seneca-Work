//==============================================
// Name:           Derek Shigetomi
// Student Number: 028-970-135
// Email:          dgshigetomi@myseneca.ca
// Date:           10/5/2020
// Section:        NDD
// Workshop:       3 (LAB)
// I have done all the coding by myself
//==============================================

#ifndef _TRANSCRIPT_H_
#define _TRANSCRIPT_H_
#define _CRT_SECURE_NO_WARNINGS

#include "Subject.h"

namespace sdds {
	class Transcript {
		char* m_studentName; 
		Subject* m_subjects; 
		int m_noOfSubjects;  
		int m_subjectsAdded;
		void setEmpty();
		bool isValid()const;
		void Title()const;
		float gpa()const;
		void footer()const;
	public:
		void init(const char* studentName, int noOfSubjects);
		bool add(const char* subject_code, int mark);
		void display()const;
		void deallocate();
	};
}

#endif
