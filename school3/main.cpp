// This is a group project submission for Computer Programming Lab.

// Project Name: School Management System
// Class: BS-IT 1A
// Team Members: Salman Abid, Ahsan, Zain

#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;


// Function Prototypes
void student_data();
void new_student();
void fee_calculator();
void check_grade();

// Structure to store New Student's Details
struct student_details
{
    string first_name, last_name, enrollment;
};

int main()
{
    int choice;
    // Main Menu of the Program
    while(choice != 5)
    {
        cout << "\t\t\tWelcome to Bahria University IT Department\n";
        cout << "\nMenu:\n\n";
        cout << "1. Show Records\n2. Add a New Student\n3. Fee Calculator\n4. Check Grades\n5. Exit\n";
        cout << "Enter your choice\n";
        cin >> choice;
        
        switch(choice)
        {
            case 1:
            {
                student_data();
                
                break;
            }

            case 2:
            {
                new_student();

                break;
            }

            case 3:
            {
                fee_calculator();

                break;
            }

            case 4:
            {
                check_grade();

                break;
            }

            case 5:
            {
                break;
            }

            default:
            {
                cout << "Invalid Input\n";

                break;
            }
        }
    }

    system("pause");
    return 0;
}

// Function Declaration
void fee_calculator()
{
    system("cls");
    int fee_per_credit_hour = 4200;
    int credit_hour, total_fee;
    
    cout << "How many credit hours do you have to study in this semester?\n";
    cin >> credit_hour;

    total_fee = fee_per_credit_hour * credit_hour;

    cout << "Your fee for this semester would be = " << total_fee << "\n";
    
    cout << "Press any key to jump to main menu\n";
    getch();
    system("cls");
}

void check_grade()
{
    system("cls");
    int marks;
    cout << "Enter your marks\n";
    cin >> marks;

    if (marks >= 85 && marks <= 100)
    {
        cout << "Congratulations!!! You scored an A+\n";
    }
    else if (marks >= 75 && marks <= 84)
    {
        cout << "You scored a B+\n";
    }
    else if (marks >= 65 && marks <= 74)
    {
        cout << "You scored a B\n";
    }
    else if (marks >= 55 && marks <= 64)
    {
        cout << "You Scored a C, Please focus on your studies\n";
    }
    else if(marks < 55)
    {
        cout << "It's an F, Better luck next time\n";
    }
    else
    {
        cout << "Invalid Input\n";
    }

    cout << "Press any key to jump to main menu\n";
    getch();
    system("cls");
}

void new_student()
{
    system("cls");
    char add_another;

    // Details is structure variable
    student_details details;
    ofstream writeData("studentdata.txt", ios::in | ios::out | ios::app);
    char choice;

    // Asking for New Student's Details and appending it to the file
    while(add_another != 'n' && add_another != 'N')
    {
    cout << "Enter Student's First Name\n";
    cin >> details.first_name;
    cout << "Enter Student's Last Name\n";
    cin >> details.last_name;
    cout << "Assign an enrollment id\n";
    cin >> details.enrollment;

    writeData << "\n" << details.enrollment << "           |       " << details.first_name << " " << details.last_name;
    cout << "Do you want to add another student?(y/n)\n";
    cin >> add_another;
    cin.ignore();
    }
    writeData.close();

    cout << "Press any key to jump to main menu\n";
    getch();
    system("cls");

}

void student_data()
{
    system("cls");
    string studentData;
    ifstream read_student_data("studentdata.txt");
    
    // Displaying Data line by line
    while(getline(read_student_data, studentData))
    {
        cout << studentData << endl;

    }

    read_student_data.close();

    cout << "Press any key to jump to main menu\n";
    getch();
    system("cls");

}