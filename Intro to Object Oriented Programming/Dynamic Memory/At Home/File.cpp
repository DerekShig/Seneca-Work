//==============================================
// Name:           Derek Shigetomi
//==============================================
// Name:           Derek Shigetomi
// Student Number: 028-970-135
// Email:          dgshigetomi@myseneca.ca
// Date:           10/4/2020
// Section:        NDD
// Workshop:       2 (DIY)
// I have done all the coding by myself
//==============================================
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {

   FILE* fptr;

   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }

   void read(int &number) {
       fscanf(fptr, "%d,", &number);
   }

   void read(double &balance) {
       fscanf(fptr, "%lf\n", &balance);
   }

}