#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
using namespace std;
namespace sdds {
    class Numbers {
        double* m_numbers; // dynamic array of doubles
        char* m_filename;  // name of file
        bool m_isOriginal;
        int m_numCount;
        bool isEmpty()const;
        void setEmpty();
        void setFilename(const char* filename);
        void sort();
        int numberCount()const;
        bool load();
        void save();
    public:
        Numbers();
        Numbers(const char* filename);
        Numbers(Numbers& n);
        Numbers& operator=(Numbers& n);
        double average()const;
        double max()const;
        double min()const;
        Numbers& operator+=(double d);
        ostream& display(ostream& ostr)const;
        ~Numbers();
    };
   ostream& operator<<(ostream& os, const Numbers& N);
   istream& operator>>(istream& istr, Numbers& N);
}
#endif // !SDDS_NUMBERS_H_

