//==============================================
// Name:           Derek Shigetomi
// Student Number: 028-970-135
// Email:          dgshigetomi@myseneca.ca
// Date:           10/5/2020
// Section:        NDD
// Workshop:       3 (LAB)
// I have done all the coding by myself
//==============================================

#ifndef _SUBJECT_H_
#define _SUBJECT_H_
#define _CRT_SECURE_NO_WARNINGS

namespace sdds {
	class Subject {
		char m_code[7];
		int m_mark = -1;
		char grade()const;
	public:
		void setEmpty();
		void set(const char* code, int mark);
		float scale4()const;
		bool isValid()const;
		void display()const;
	};
}

#endif