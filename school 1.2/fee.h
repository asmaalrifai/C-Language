#ifndef FEE_H
#define FEE_H

#include <iostream>
#include <iomanip>
#include <vector>

class Fee {
private:
    std::string studentId;
    std::string feeType;
    double amount;

public:
    Fee();
    Fee(const std::string& studentId, const std::string& feeType, double amount);

    // Member functions
    void addFee();
    static void updateFee();
    static void deleteFee();
    static void listAllFees();

    // Operator overloading
    friend std::ostream& operator<<(std::ostream& os, const Fee& fee);
    friend std::istream& operator>>(std::istream& is, Fee& fee);
};

#endif // FEE_H
