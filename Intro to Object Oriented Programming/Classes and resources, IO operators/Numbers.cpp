#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip> 
#include "Numbers.h"
using namespace std;
namespace sdds {
  
   Numbers::Numbers() { 
      setEmpty();
      m_isOriginal = false;
   }

   Numbers::Numbers(const char* filename) { 
      setEmpty();
      m_isOriginal = true;
      setFilename(filename);
      m_numCount = numberCount();
      if (m_numCount == 0 || !load()) {
         delete[] m_numbers;
         delete[] m_filename;
         setEmpty();
         m_isOriginal = false; 
      }
      else {
         sort();
      }
   }

   Numbers::Numbers(Numbers& n) {
       setEmpty();
       m_isOriginal = false;
       *this = n;
   }

   Numbers& Numbers::operator=(Numbers& n) {
       delete[] m_numbers;
       m_numbers = new double[n.m_numCount];
       for (int i = 0; i < n.m_numCount; i++) {
           m_numbers[i] = n.m_numbers[i];
       }
       m_numCount = n.m_numCount;
       return *this;
   }

   Numbers::~Numbers() {
      save();
      delete[] m_numbers;
      delete[] m_filename;
   }
   
   bool Numbers::isEmpty() const { 
      return m_numbers == nullptr;
   }

   void Numbers::setEmpty() { 
      m_numbers = nullptr;
      m_filename = nullptr;
      m_numCount = 0;
   }
   void Numbers::setFilename(const char* filename) { 
      delete[] m_filename;
      m_filename = new char[strlen(filename) + 1];
      strcpy(m_filename, filename);
   }
   void Numbers::sort() {
      int i, j;
      double temp;
      for (i = m_numCount - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (m_numbers[j] > m_numbers[j + 1]) {
               temp = m_numbers[j];
               m_numbers[j] = m_numbers[j + 1];
               m_numbers[j + 1] = temp;
            }
         }
      }
   }

   double Numbers::average() const {
      double aver = 0.0;
      if (!isEmpty()) {
         for (int i = 0; i < m_numCount; i++)
            aver += m_numbers[i];
         aver = aver / m_numCount;
      }
      return aver;
   }
   double Numbers::min() const {
      double minVal = 0.0;
      if (!isEmpty()) {
         minVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (minVal > m_numbers[i]) minVal = m_numbers[i];
      }
      return minVal;
   }
   double Numbers::max() const {
      double maxVal = 0.0;
      if (!isEmpty()) {
         maxVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
      }
      return maxVal;
   }

   int Numbers::numberCount()const {
       int newline = 0;
       ifstream f(m_filename);
       char b;
       while (f.get(b)) {
           if (b == '\n') {
               newline++;
           }
       }
       return newline;
   }

   bool Numbers::load() {
       int count = numberCount();
       int index = 0;
       double num = 0.0;
       if (count > 0) {
           delete[] m_numbers;
           m_numbers = new double[count];
           ifstream f(m_filename);
           while (f >> num) {
               m_numbers[index] = num;
               index++;
           }
       }
       return count == index;
   }

   void Numbers::save() {
       if (m_isOriginal && !isEmpty()) {
           ofstream f(m_filename, ofstream::trunc);
           for (int i = 0; i < m_numCount; i++) {
               f << m_numbers[i] << endl;
           }
           f.close();
       }
   }

   Numbers& Numbers::operator+=(double d) {
       if (!isEmpty()) {
           int i;
           double* temp;
           temp = new double[m_numCount + 1];
           for (i = 0; i < m_numCount; i++) {
               temp[i] = m_numbers[i];
           }
           m_numCount++;
           temp[i] = d;
           delete[] m_numbers;
           m_numbers = temp;
           sort();
       }
       return *this;
   }

   ostream& Numbers::display(ostream& ostr) const {
       if (isEmpty()) {
           cout << "Empty list";
       }
       else {
           ostr << "=========================" << '\n';
           if (m_isOriginal) {
               ostr << m_filename << '\n';
           }
           else {
               ostr << "*** COPY ***" << '\n';
           }
           for (int i = 0; i < m_numCount; i++) {
               ostr << m_numbers[i];
               if (i < m_numCount - 1) {
                   ostr << ", ";
               }
           }
           ostr << '\n';
           ostr << "-------------------------" << '\n';
           ostr << "Total of " << m_numCount << " number(s)" << '\n';
           ostr << "Largest number: " << " " << right << max() << '\n';
           ostr << "Smallest number: " << right << min() << '\n';
           ostr << "Average : " << "       " << right << average() << '\n';
           ostr << "=========================";
       }
       return ostr;
   }

   ostream& operator<<(ostream& os, const Numbers& N) {
       return N.display(os);
   }

   istream& operator>>(istream& istr, Numbers& N) {
       double temp = 0.0;
       istr >> temp;
       N += temp;
       return istr;
   }
   
}
