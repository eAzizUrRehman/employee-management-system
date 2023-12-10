#ifndef DOCTOR_H
#define DOCTOR_H

#include "../employee/employee.h"
#include <string>
using namespace std;

class Doctor : public Employee
{
public:
    string doctorType, specialization, jobLevel;
    Doctor();
    Doctor(string name, string fatherName, string dob, string jobType, int empId, int bps, string doctorType, string specialization, string jobLevel);

    void setRecord();
    void showRecord();
    void updateRecord();
};

#endif