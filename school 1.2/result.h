#ifndef RESULT_H
#define RESULT_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iterator>
#include <vector>
#include <iomanip>

class Result {
private:
    std::string rId;
    std::string classes;
    int kannada;
    int english;
    int science;
    int maths;
    int sStudy;

public:
    Result();
    Result(const std::string& rId, const std::string& classes, int kannada, int english, int science, int maths, int sStudy);

    // Member functions
    void newResultAdd();
    static void updateResultAdd();
    static void deleteResult();
    static void overAllClassResult(const std::string& classes);
    static void schoolResult();
    static void studentResult(const std::string& rId);

    // Operator overloading
    friend std::ostream& operator<<(std::ostream& os, const Result& result);
    friend std::istream& operator>>(std::istream& is, Result& result);
};

#endif // RESULT_H
