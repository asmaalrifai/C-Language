#ifndef STAFF_H
#define STAFF_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iterator>
#include <vector>
#include <iomanip>

class Staff {
private:
    std::string id;
    std::string fName;
    std::string lName;
    std::string qualification;
    std::string mNumber;
    std::string pay;

public:
    Staff();
    Staff(const std::string& id, const std::string& fName, const std::string& lName, const std::string& qualification, const std::string& mNumber, const std::string& pay);

    // Member functions
    void newStaffRegistration();
    static void updateStaffInform();
    static void deleteStaffInform();
    static void listOfStaffs();
    void displayStudentInfo() const;


    // Operator overloading
    friend std::ostream& operator<<(std::ostream& os, const Staff& staff);
    friend std::istream& operator>>(std::istream& is, Staff& staff);
};

#endif // STAFF_H
