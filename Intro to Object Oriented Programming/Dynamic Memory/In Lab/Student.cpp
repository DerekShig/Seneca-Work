//==============================================
// Name:           Derek Shigetomi
// Student Number: 028-970-135
// Email:          dgshigetomi@myseneca.ca
// Date:           9/30/2020
// Section:        NDD
// Workshop:       2 (Lab)
// I have done all the coding by myself
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Student.h"
#include "File.h"
using namespace std;
namespace sdds {
   int noOfStudents;
   Student* students;


   void sort() {
      int i, j;
      Student temp;
      for (i = noOfStudents - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (students[j].m_gpa > students[j + 1].m_gpa) {
               temp = students[j];
               students[j] = students[j + 1];
               students[j + 1] = temp;
            }
         }
      }
   }

   // TODO: Finish the implementation of the 1 arg load function which
   // reads one student record from the file and loads it into the student reference
   // argument
   bool load(Student &student) {
      bool ok = false;
      char name[128];
      // if reading of name is successful
      if (read(name)) {
         // allocate memory to the size of the name + 1
         // and keep its address in the name of the Student Reference
          int sz = strlen(name) + 1;
         // copy the name into the newly allocated memroy
          student.m_name = new char[sz];
          strcpy(student.m_name, name);

         // read student number and gpa from the file into the corresponding
         // variables in the Student Referenct
          read(student.m_studentNumber);
          read(student.m_gpa);

         // make sure the "ok" flag is set to true, if all is good
          ok = true;
      }
      return ok;
   }
   // TODO: Finish the implementation of the 0 arg load function 
   bool load() {
      bool ok = true;
      int i;
      if (openFile(DATAFILE)) {
         // set the noOfStudents to the number of recoreds in the file.
          noOfStudents = noOfRecords();
         // dyanamically allocated an array of students into the global
         // Student pointer; "students" to the size of the noOfStudents.
          students = new Student[noOfStudents];
         // in a loop load the student records from the file into 
         // the dynamic array.
          for (i = 0; i < noOfStudents; i++) {
              load(students[i]);
          }
         // if th number of the records does not match the number of reads
         // print an error message
         if (!ok){
             cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
         }
         else {
            ok = true;
         }
         closeFile();
      }
      else {
         cout << "Could not open data file: " << DATAFILE<< endl;
      }
      return ok;
   }

   // TODO: Implementation for the display functions go here
   void display(Student &student) {
       cout << student.m_name << ", " << student.m_studentNumber << ": " << student.m_gpa << endl;
   }

   void display() {
       sort();
       for (int i = 0; i < noOfStudents; i++) {
           cout << i + 1 << ": ";
           display(students[i]);
       }
   }

   // TODO: Implementation for the deallocateMemory function goes here
   void deallocateMemory() {
       for (int i = 0; i < noOfStudents; i++) {
           delete [] students[i].m_name;
       }
       delete [] students;
       students = nullptr;
   }

}