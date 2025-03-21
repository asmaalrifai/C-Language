#include <iostream>
#include <cstdlib> // Include cstdlib for exit()
#include "student.h"
#include "staff.h"
#include "result.h"
#include "fee.h"

using namespace std;

int main() {
    int choice;
    Student studentObj; // Create object of Student class
    Staff staffObj;     // Create object of Staff class
    Result resultObj;   // Create object of Result class
    Fee feeObj;         // Create object of Fee class

    for (;;) {
        cout << endl
             << endl;
        cout << "\t\t\t\t!...**WELCOME TO SCHOOL MANAGEMENT SYSTEM**...!" << endl
             << endl;
        cout << "1. Student Information" << endl;
        cout << "2. Staff Information" << endl;
        cout << "3. Result Information" << endl;
        cout << "4. Fee Structure" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice:" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            int studentC;
            cout << endl;
            cout << " **STUDENT** " << endl;
            cout << "1. New Registration" << endl;
            cout << "2. Update student information" << endl;
            cout << "3. Delete student information" << endl;
            cout << "4. List All students" << endl;
            cout << "5. Exit" << endl;
            cout << "Enter your choice:" << endl;
            cin >> studentC;
            switch (studentC) {
            case 1:
                studentObj.newStudentRegistration();
                break;
            case 2:
                studentObj.updateStudentInform();
                break;
            case 3:
                studentObj.deleteStudentInform();
                break;
            case 4:
                studentObj.listOfStudents();
                break;
            case 5:
                exit(0);
                break;
            default:
                cout << "wrong option, please retry";
            }
            break;
        case 2:
            int staffC;

            cout << endl;
            cout << " **STAFF** " << endl;
            cout << "1. New Registration" << endl;
            cout << "2. Update staff information" << endl;
            cout << "3. Delete staff information" << endl;
            cout << "4. List All staffs" << endl;
            cout << "5. Exit" << endl;
            cout << "Enter your choice:" << endl;
            cin >> staffC;
            switch (staffC) {
            case 1:
                staffObj.newStaffRegistration();
                break;
            case 2:
                staffObj.updateStaffInform();
                break;
            case 3:
                staffObj.deleteStaffInform();
                break;
            case 4:
                staffObj.listOfStaffs();
                break;

            case 5:
                exit(0);
                break;
            default:
                cout << "wrong option, please retry";
            }
            break;

        case 3:
            int resultC;
            cout << endl;
            cout << " **RESULT** " << endl;
            cout << "1. Add Result " << endl;
            cout << "2. Update Result" << endl;
            cout << "3. Delete Result" << endl;
            cout << "4. Over All class Result" << endl;
            cout << "5. School Annual Result" << endl;
            cout << "6. Student Result" << endl;
            cout << "7. Exit" << endl;
            cout << "Enter your choice:" << endl;
            cin >> resultC;
            switch (resultC) {
            case 1:
                resultObj.newResultAdd();
                break;
            case 2:
                resultObj.updateResultAdd();
                break;
            case 3:
                resultObj.deleteResult();
                break;
            case 4:
                // Assuming the overAllClassResult requires an argument, modify accordingly
                // resultObj.overAllClassResult();
                break;
            case 5:
                resultObj.schoolResult();
                break;
            case 6:
                // Assuming the studentResult requires an argument, modify accordingly
                // resultObj.studentResult();
                break;
            case 7:
                exit(0);
                break;
            default:
                cout << "wrong option, please retry";
            }
            break;
        case 4:
            int feeC;
            cout << endl;
            cout << " **FEE** " << endl;
            cout << "1. Add New Fee" << endl;
            cout << "2. Update Fee Information" << endl;
            cout << "3. Delete Fee information" << endl;
            cout << "4. List All Fees" << endl;
            cout << "5. Exit" << endl;
            cout << "Enter your choice:" << endl;
            cin >> feeC;
            switch (feeC) {
            case 1:
                feeObj.addFee();
                break;
            case 2:
                feeObj.updateFee();
                break;
            case 3:
                feeObj.deleteFee();
                break;
            case 4:
                feeObj.listAllFees();
                break;
            case 5:
                exit(0);
                break;
            default:
                cout << "wrong option, please retry";
            }
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "wrong entry, please re-try";
        }
    }
    return 0;
}
