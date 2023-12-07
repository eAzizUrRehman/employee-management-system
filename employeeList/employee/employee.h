#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

class Employee
{
public:
    string name, fatherName, dob, jobType;
    int empId, bps, age;

    Employee();
    Employee(string name, string fatherName, string dob, string jobType, int empId, int bps);

    void setRecord();
    void showRecord();
    
};

#endif
