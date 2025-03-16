#include "result.h"

std::vector<Result> results;  // Define the vector

// Constructors
Result::Result() : rId(""), classes(""), kannada(0), english(0), science(0), maths(0), sStudy(0) {}

Result::Result(const std::string& rId, const std::string& classes, int kannada, int english, int science, int maths, int sStudy)
    : rId(rId), classes(classes), kannada(kannada), english(english), science(science), maths(maths), sStudy(sStudy) {}

// Member functions
void Result::newResultAdd() {
    Result result;
    std::cout << "Registration Id: ";
    std::cin >> result.rId;
    std::cout << "Class: ";
    std::cin >> result.classes;
    std::cout << "Kannada: ";
    std::cin >> result.kannada;
    std::cout << "English: ";
    std::cin >> result.english;
    std::cout << "Maths: ";
    std::cin >> result.maths;
    std::cout << "Science: ";
    std::cin >> result.science;
    std::cout << "Social Study: ";
    std::cin >> result.sStudy;
    results.push_back(result);
    std::cout << "\n**Result Added Successfully**\n";
}

void Result::updateResultAdd() {
    std::string rId, classes;
    std::cout << "\nEnter student registration Id: ";
    std::cin >> rId;
    std::cout << "\nEnter student Class: ";
    std::cin >> classes;

    for (Result& result : results) {
        if (result.rId == rId && result.classes == classes) {
            std::cout << "Kannada: ";
            std::cin >> result.kannada;
            std::cout << "English: ";
            std::cin >> result.english;
            std::cout << "Maths: ";
            std::cin >> result.maths;
            std::cout << "Science: ";
            std::cin >> result.science;
            std::cout << "Social Study: ";
            std::cin >> result.sStudy;
            std::cout << "\n**Result Updated Successfully**\n";
            return;
        }
    }

    std::cout << "Result not found!\n";
}

void Result::deleteResult() {
    std::string rId, classes;
    std::cout << "\nEnter student registration Id: ";
    std::cin >> rId;
    std::cout << "\nEnter student Class: ";
    std::cin >> classes;

    auto it = std::remove_if(results.begin(), results.end(), [rId, classes](const Result& result) {
        return result.rId == rId && result.classes == classes;
    });

    if (it != results.end()) {
        results.erase(it, results.end());
        std::cout << "\n**Result Deleted Successfully**\n";
    } else {
        std::cout << "Result not found!\n";
    }
}

void Result::overAllClassResult(const std::string& classes) {
    int failCount = 0, passCount = 0, totalCount = 0;

    for (const Result& result : results) {
        if (result.classes == classes) {
            totalCount++;
            if (result.kannada < 35 || result.english < 35 || result.maths < 35 || result.science < 35 || result.sStudy < 35) {
                failCount++;
            } else {
                passCount++;
            }
        }
    }

    std::cout << "\n\t\t\t\t !** CLASS " << classes << " RESULT**!\t\t\n\n\n";
    std::cout << "Total No. of Failed Students: " << failCount << std::endl;
    std::cout << "Total No. of Passed Students: " << passCount << std::endl;
    std::cout << "Total No. of Students: " << totalCount << std::endl;
    std::cout << "School Annual Result(%): " << (double)(100 * passCount) / totalCount << "%" << std::endl;
    std::cout << std::endl;
}

void Result::schoolResult() {
    int failCount = 0, passCount = 0, totalCount = 0;

    for (const Result& result : results) {
        totalCount++;
        if (result.kannada < 35 || result.english < 35 || result.maths < 35 || result.science < 35 || result.sStudy < 35) {
            failCount++;
        } else {
            passCount++;
        }
    }

    std::cout << "Total No. of Failed Students: " << failCount << std::endl;
    std::cout << "Total No. of Passed Students: " << passCount << std::endl;
    std::cout << "Total No. of Students: " << totalCount << std::endl;
    std::cout << "School Annual Result(%): " << (double)(100 * passCount) / totalCount << "%" << std::endl;
    std::cout << std::endl;
}

void Result::studentResult(const std::string& rId) {
    int total = 0;
    bool s_result = true;
    std::string resultStr;

    for (const Result& result : results) {
        if (result.rId == rId) {
            total += result.kannada + result.english + result.maths + result.science + result.sStudy;
            if (result.kannada < 35 || result.english < 35 || result.maths < 35 || result.science < 35 || result.sStudy < 35) {
                s_result = false;
            }

            std::ostringstream oss;
            oss << std::setw(10) << result.rId;
            oss << std::setw(10) << result.classes;
            oss << std::setw(10) << result.kannada;
            oss << std::setw(10) << result.english;
            oss << std::setw(10) << result.maths;
            oss << std::setw(10) << result.science;
            oss << std::setw(10) << result.sStudy;
            resultStr = oss.str();
        }
    }

    std::cout << "\n\t\t\t\t !** STUDENT RESULT **!\t\t\n\n\n";
    std::cout << std::setw(10) << "Reg ID" << std::setw(10) << "Class" << std::setw(10) << "Kannada" << std::setw(10) << "English" << std::setw(10) << "Maths" << std::setw(10) << "Science" << std::setw(10) << "S. Study" << std::endl << std::endl;
    std::cout << resultStr << std::endl << std::endl;
    std::cout << "Total Marks: " << total << std::endl;
    if (s_result) {
        std::cout << "Result: PASS\n\n";
    } else {
        std::cout << "Result: FAIL\n\n";
    }
}

// Operator overloading
std::ostream& operator<<(std::ostream& os, const Result& result) {
    os << "Reg ID: " << result.rId << "\n";
    os << "Class: " << result.classes << "\n";
    os << "Kannada: " << result.kannada << "\n";
    os << "English: " << result.english << "\n";
    os << "Maths: " << result.maths << "\n";
    os << "Science: " << result.science << "\n";
    os << "Social Study: " << result.sStudy << "\n";
    return os;
}

std::istream& operator>>(std::istream& is, Result& result) {
    std::cout << "Reg ID: ";
    is >> result.rId;
    std::cout << "Class: ";
    is >> result.classes;
    std::cout << "Kannada: ";
    is >> result.kannada;
    std::cout << "English: ";
    is >> result.english;
    std::cout << "Maths: ";
    is >> result.maths;
    std::cout << "Science: ";
    is >> result.science;
    std::cout << "Social Study: ";
    is >> result.sStudy;
    return is;
}
