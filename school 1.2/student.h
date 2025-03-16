#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Student {
private:
    std::string rId;
    std::string fName;
    std::string lName;
    std::string classes;
    std::string mNumber;

public:
    Student();

    void newStudentRegistration();
    void updateStudentInform();
    void deleteStudentInform();
    void listOfStudents();
    static void menu(); // static function to be accessed without an instance
};

#endif
