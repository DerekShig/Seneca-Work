//==============================================
// Name:           Derek Shigetomi
// Student Number: 028-970-135
// Email:          dgshigetomi@myseneca.ca
// Date:           10/15/2020
// Section:        NDD
// Workshop:       4 (Lab)
// I have done all the coding by myself
//==============================================

#include <ostream>
#ifndef _BOX_H_
#define _BOX_H_
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
namespace sdds {
	class Box {
		char* m_contentName;
		int m_width;
		int m_height;
		int m_length;
		int m_contentVolume;
		void setName(const char* Cstr);
		void setUnusable();
		bool isUnusable()const;
		bool hasContent()const;
	public:
		Box();
		Box(int sideLength, const char* contentName = nullptr);
		Box(int width, int height, int length, const char* contentName = nullptr);
		~Box();
		int capacity()const;
		int quantity()const;
		Box& setContent(const char* contentName);
		ostream& display()const;
		Box& add(int quantity);
		Box& add(Box& B);
	};
}




#endif