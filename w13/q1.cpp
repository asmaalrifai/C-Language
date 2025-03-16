#include <iostream>
#include <vector>

class Employee {
public:
    int id;
    std::string name;

    Employee() : id(0), name("") {}

    Employee(int _id, const std::string& _name) : id(_id), name(_name) {}

    bool operator==(const Employee& other) const {
        return id == other.id && name == other.name;
    }
};
std::ostream& operator<<(std::ostream& os, const Employee& employee) {
    os << "Name: " << employee.firstName << " " << employee.lastName
       << ", Salary: " << employee.salary << ", Type: " << employee.type;
    return os;
}

class Manager : public Employee {
public:
    Manager(const std::string& firstName, const std::string& lastName, double salary)
        : Employee(firstName, lastName, salary, "Manager") {}
};

class Department {
public:
    std::vector<Employee> employees;
    int departmentNumber;
    bool operator==(const Department& other) const {
        return employees == other.employees;
    }
};





class Factory {
public:
    std::vector<Employee> employees;

    // Other members of the Factory class...

    // Overloaded subtraction operator
    Factory operator-(const Employee& employee) const {
        Factory newFactory = *this;
        auto it = std::find(newFactory.employees.begin(), newFactory.employees.end(), employee);

        if (it != newFactory.employees.end()) {
            newFactory.employees.erase(it);
        }

        return newFactory;
    }
};

int main() {
    // Test the implementation
    Employee emp1("John", "Doe", 50000, "Worker");
    Employee emp2("Jane", "Smith", 60000, "Worker");

    Manager manager1("Mike", "Johnson", 80000);

    Department department1;
    department1.employees = {emp1, emp2};
    department1.departmentNumber = 1;

    // Create a Factory
    Factory factory;
    factory = factory + emp1 + manager1; // Add employee and manager
    factory = factory + department1;     // Add department

    // Display Factory information
    std::cout << "Factory Employees:\n";
    for (const auto& employee : factory.employees) {
        std::cout << employee << "\n";
    }

    std::cout << "\nFactory Departments:\n";
    for (const auto& department : factory.departments) {
        std::cout << "Department " << department.departmentNumber << ": ";
        for (const auto& emp : department.employees) {
            std::cout << emp.firstName << " " << emp.lastName << ", ";
        }
        std::cout << "\n";
    }

    // Test the + operator for Employee class
    Employee emp3 = emp1 + 10000;
    std::cout << "\nIncreased Salary: " << emp3 << "\n";

    // Test the == operator for Department class
    Department department2;
    department2.employees = {emp1, emp2};
    department2.departmentNumber = 2;

    if (department1 == department2) {
        std::cout << "\nDepartments have the same employees.\n";
    } else {
        std::cout << "\nDepartments do not have the same employees.\n";
    }

    return 0;
}
