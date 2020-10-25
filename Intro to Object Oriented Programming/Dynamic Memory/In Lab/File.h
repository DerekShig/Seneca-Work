//==============================================
// Name:           Derek Shigetomi
// Student Number: 028-970-135
// Email:          dgshigetomi@myseneca.ca
// Date:           9/30/2020
// Section:        NDD
// Workshop:       2 (Lab)
// I have done all the coding by myself
//==============================================

#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   bool read(char name[]);
   bool read(int& number);
   bool read(double& gpa);
}
#endif // !SDDS_FILE_H_
