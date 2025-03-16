#include <iostream>
#include <vector>
#include <typeinfo>


class Employee{
    String firstName;
    String lastName;
    int salary;
};

class MAnager : public Employee{
     vector<Employee*>
};

class Factory{
    public:
    vector<Employee*> employee;
    void addEmployee(Employee emp){
        employee.push_back(&emp);
    }

    void printEmployeeTypeNumber(){
        int normal_emp = 0;
        for(Employee* emp : Employee){
            if (instanceof<Manager>(emp)){
                continue;
            }else{
                normal_emp++;
            }
        }
        cout << "normal emp: "<<normal_emp<<endl<<"Manager"<<Employee;
    }
};

void addEmployee(){

}



int main(){
    Employee emp;
    emp.firstName = "Ahmed";
    emp.lastName = "AK";
    Factory fact;
    fact.addEmployee(emp);
    cout <<fact.employee.size()<<endl;
    cout<<
}