#define _CRT_SECURE_NO_WARNINGS

#include "utils.h"
#include "Menu.h"
#include <cstring>
using namespace std;
namespace sdds {

	Menu::Menu(const char* text, int NoOfSelections) {
		m_text = new char[strlen(text) + 1];
		strcpy(m_text, text);
		m_noOfSel = NoOfSelections;
	}

	Menu::~Menu() {
		delete[] m_text;
	}

	ostream& Menu::display(ostream& ostr) const {
		ostr << m_text << endl;
		ostr << "0- Exit" << endl;
		ostr << "> ";
		return ostr;
	}

	int& Menu::operator>>(int& Selection) {
		display();
		bool valid = true;
		do {
			Selection = getInt();
			if (Selection < 0 || Selection > m_noOfSel) {
				cout << "Invalid value enterd, retry[0 <= value <= " << m_noOfSel << "]: ";
			}
			else {
				valid = false;
			}
		} while (valid);
		return Selection;
	}

}