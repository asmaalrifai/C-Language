#include "fee.h"

std::vector<Fee> fees;  // Define the vector

// Constructors
Fee::Fee() : studentId(""), feeType(""), amount(0.0) {}

Fee::Fee(const std::string& studentId, const std::string& feeType, double amount)
    : studentId(studentId), feeType(feeType), amount(amount) {}

// Member functions
void Fee::addFee() {
    Fee fee;
    std::cout << "Student Id: ";
    std::cin >> fee.studentId;
    std::cout << "Fee Type: ";
    std::cin >> fee.feeType;
    std::cout << "Amount: ";
    std::cin >> fee.amount;
    fees.push_back(fee);
    std::cout << "\n**Fee Added Successfully**\n";
}

void Fee::updateFee() {
    std::string studentId;
    std::cout << "Enter Student Id: ";
    std::cin >> studentId;

    for (Fee& fee : fees) {
        if (fee.studentId == studentId) {
            std::cout << "Enter new Fee Type: ";
            std::cin >> fee.feeType;
            std::cout << "Enter new Amount: ";
            std::cin >> fee.amount;
            std::cout << "\n**Fee Updated Successfully**\n";
            return;
        }
    }

    std::cout << "Fee not found!\n";
}

void Fee::deleteFee() {
    std::string studentId;
    std::cout << "Enter Student Id: ";
    std::cin >> studentId;

    auto it = std::remove_if(fees.begin(), fees.end(), [studentId](const Fee& fee) { return fee.studentId == studentId; });

    if (it != fees.end()) {
        fees.erase(it, fees.end());
        std::cout << "\n**Fee Deleted Successfully**\n";
    } else {
        std::cout << "Fee not found!\n";
    }
}

void Fee::listAllFees() {
    if (fees.empty()) {
        std::cout << "No fees available.\n";
        return;
    }

    std::cout << std::setw(15) << "Student ID:" << std::setw(15) << "Fee Type" << std::setw(15) << "Amount" << std::endl << std::endl;

    for (const Fee& fee : fees) {
        std::cout << std::setw(15) << fee.studentId << std::setw(15) << fee.feeType << std::setw(15) << fee.amount << std::endl;
    }
}

// Operator overloading
std::ostream& operator<<(std::ostream& os, const Fee& fee) {
    os << "Student ID: " << fee.studentId << "\n";
    os << "Fee Type: " << fee.feeType << "\n";
    os << "Amount: " << fee.amount << "\n";
    return os;
}

std::istream& operator>>(std::istream& is, Fee& fee) {
    std::cout << "Student ID: ";
    is >> fee.studentId;
    std::cout << "Fee Type: ";
    is >> fee.feeType;
    std::cout << "Amount: ";
    is >> fee.amount;
    return is;
}
