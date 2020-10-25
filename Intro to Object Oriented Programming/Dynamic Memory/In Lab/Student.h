//==============================================
// Name:           Derek Shigetomi
// Student Number: 028-970-135
// Email:          dgshigetomi@myseneca.ca
// Date:           9/30/2020
// Section:        NDD
// Workshop:       2 (Lab)
// I have done all the coding by myself
//==============================================

#ifndef SDDS_STUDENT_H_
#define SDDS_STUDENT_H_

#define DATAFILE "students.csv"

namespace sdds {
    struct Student {
        char* m_name;
        int m_studentNumber;
        double m_gpa;
    };
    //sorts the dynamic array of students based on the GPA of the students.
    void sort();
    // loads a student structue with its values from the file
    bool load(Student& student);
    // allocates the dyanmic array of students and loads all the file
    // recoreds into the array
    bool load();

    // TODO: Declare the prototype for the display function that
    // displays a student record on the screen:
    void display(Student& student);
    // TODO: Declare the prototype for the display function that 
    // first sorts the students then displays all the students on the screen
    void display();
    // TODO: Declare the prototype for the deallocateMemory function that
    // first will deallocate all the names in the student elements
    // then it will deallocate the student array 
    void deallocateMemory();

}
#endif // SDDS_STUDENT_H_