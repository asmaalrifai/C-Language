#include "student.h"
#include <algorithm>
#include <iomanip>


std::vector<Student> students;  // Define the vector

// Constructors
Student::Student(const std::string& rId, const std::string& fName, const std::string& lName, const std::string& classes, const std::string& mNumber)
    : rId(rId), fName(fName), lName(lName), classes(classes), mNumber(mNumber) {}

// Member functions
void Student::newStudentRegistration() {
    Student s1;
    std::cout << "Registration Id:";
    std::cin >> s1.rId;
    std::cout << "FirstName:";
    std::cin >> s1.fName;
    std::cout << "LastName:";
    std::cin >> s1.lName;
    std::cout << "Class:";
    std::cin >> s1.classes;
    std::cout << "Mobile Number:";
    std::cin >> s1.mNumber;
    students.push_back(s1);
    std::cout << "\n**Successfully Added**\n";
}

void Student::updateStudentInform() {
    std::string rId;
    std::cout << "\nEnter student registration Id:";
    std::cin >> rId;

    for (Student& student : students) {
        if (student.rId == rId) {
            std::cout << "FirstName:";
            std::cin >> student.fName;
            std::cout << "LastName:";
            std::cin >> student.lName;
            std::cout << "Class:";
            std::cin >> student.classes;
            std::cout << "Mobile Number:";
            std::cin >> student.mNumber;
            std::cout << "\n**Successfully updated**\n";
            return;
        }
    }

    std::cout << "Student not found!\n";
}

void Student::deleteStudentInform() {
    std::string rId;
    std::cout << "\nEnter student registration Id:";
    std::cin >> rId;

    auto it = std::remove_if(students.begin(), students.end(), [rId](const Student& student) { return student.rId == rId; });
    
    if (it != students.end()) {
        students.erase(it, students.end());
        std::cout << "\n**Deleted successfully**\n";
    } else {
        std::cout << "Student not found!\n";
    }
}

void Student::displayStudentInfo() const {
    // Implementation to display student information
}

// Static member function
void Student::listOfStudents() {
    if (students.empty()) {
        std::cout << "No students available.\n";
        return;
    }

    std::cout << std::setw(15) << "REG.ID:" << std::setw(15) << "F.NAME" << std::setw(15) << "L.NAME"
              << std::setw(15) << "CLASS" << std::setw(15) << "M.NUMBER" << std::endl << std::endl;

    for (const Student& student : students) {
        std::cout << std::setw(15) << student.rId << std::setw(15) << student.fName << std::setw(15) << student.lName
                  << std::setw(15) << student.classes << std::setw(15) << student.mNumber << std::endl;
    }
}

// Operator overloading
std::ostream& operator<<(std::ostream& os, const Student& student) {
    // Implementation to output student information
    os << "Registration ID: " << student.rId << "\n";
    os << "First Name: " << student.fName << "\n";
    os << "Last Name: " << student.lName << "\n";
    os << "Class: " << student.classes << "\n";
    os << "Mobile Number: " << student.mNumber << "\n";
    return os;
}

std::istream& operator>>(std::istream& is, Student& student) {
    // Implementation to input student information
    std::cout << "Registration ID: ";
    is >> student.rId;
    std::cout << "First Name: ";
    is >> student.fName;
    std::cout << "Last Name: ";
    is >> student.lName;
    std::cout << "Class: ";
    is >> student.classes;
    std::cout << "Mobile Number: ";
    is >> student.mNumber;
    return is;
}
