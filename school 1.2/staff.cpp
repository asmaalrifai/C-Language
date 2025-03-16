#include "staff.h"

std::vector<Staff> staffs;  // Define the vector

// Constructors
Staff::Staff() : id(""), fName(""), lName(""), qualification(""), mNumber(""), pay("") {}

Staff::Staff(const std::string& id, const std::string& fName, const std::string& lName, const std::string& qualification, const std::string& mNumber, const std::string& pay)
    : id(id), fName(fName), lName(lName), qualification(qualification), mNumber(mNumber), pay(pay) {}

// Member functions
void Staff::newStaffRegistration() {
    Staff staff;
    std::cout << "Staff Id: ";
    std::cin >> staff.id;
    std::cout << "First Name: ";
    std::cin >> staff.fName;
    std::cout << "Last Name: ";
    std::cin >> staff.lName;
    std::cout << "Qualification: ";
    std::cin >> staff.qualification;
    std::cout << "Mobile Number: ";
    std::cin >> staff.mNumber;
    std::cout << "Pay: ";
    std::cin >> staff.pay;
    staffs.push_back(staff);
    std::cout << "\n**Staff Successfully Added**\n";
}

void Staff::updateStaffInform() {
    std::string sId;
    std::cout << "\nEnter staff Id: ";
    std::cin >> sId;

    for (Staff& staff : staffs) {
        if (staff.id == sId) {
            std::cout << "First Name: ";
            std::cin >> staff.fName;
            std::cout << "Last Name: ";
            std::cin >> staff.lName;
            std::cout << "Qualification: ";
            std::cin >> staff.qualification;
            std::cout << "Mobile Number: ";
            std::cin >> staff.mNumber;
            std::cout << "Pay: ";
            std::cin >> staff.pay;
            std::cout << "\n**Staff Successfully Updated**\n";
            return;
        }
    }

    std::cout << "Staff not found!\n";
}

void Staff::deleteStaffInform() {
    std::string sId;
    std::cout << "\nEnter staff Id: ";
    std::cin >> sId;

    auto it = std::remove_if(staffs.begin(), staffs.end(), [sId](const Staff& staff) {
        return staff.id == sId;
    });

    if (it != staffs.end()) {
        staffs.erase(it, staffs.end());
        std::cout << "\n**Staff Successfully Deleted**\n";
    } else {
        std::cout << "Staff not found!\n";
    }
}

void Staff::listOfStaffs() {
    std::cout << "\n\t\t\t\t !** STAFF LIST **!\t\t\n\n\n";
    std::cout << std::setw(15) << "S.ID" << std::setw(15) << "F.NAME" << std::setw(15) << "L.NAME" << std::setw(15) << "PAY" << std::setw(15) << "QUALIFICATION" << std::setw(15) << "M.NUMBER" << std::endl
              << std::endl;

    for (const Staff& staff : staffs) {
        std::cout << std::setw(15) << staff.id;
        std::cout << std::setw(15) << staff.fName;
        std::cout << std::setw(15) << staff.lName;
        std::cout << std::setw(15) << staff.pay;
        std::cout << std::setw(15) << staff.qualification;
        std::cout << std::setw(15) << staff.mNumber << std::endl;
    }

    std::cout << std::endl;
}

// Operator overloading
std::ostream& operator<<(std::ostream& os, const Staff& staff) {
    os << "S.ID: " << staff.id << "\n";
    os << "F.NAME: " << staff.fName << "\n";
    os << "L.NAME: " << staff.lName << "\n";
    os << "PAY: " << staff.pay << "\n";
    os << "QUALIFICATION: " << staff.qualification << "\n";
    os << "M.NUMBER: " << staff.mNumber << "\n";
    return os;
}

std::istream& operator>>(std::istream& is, Staff& staff) {
    std::cout << "S.ID: ";
    is >> staff.id;
    std::cout << "F.NAME: ";
    is >> staff.fName;
    std::cout << "L.NAME: ";
    is >> staff.lName;
    std::cout << "PAY: ";
    is >> staff.pay;
    std::cout << "QUALIFICATION: ";
    is >> staff.qualification;
    std::cout << "M.NUMBER: ";
    is >> staff.mNumber;
    return is;
}
