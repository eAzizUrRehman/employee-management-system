#include "employee.h"
#include "./functions/calculateAge/calculateAge.h"

#include <iostream>
#include <string>
using namespace std;

Employee::Employee()
{
    name = "Ali";
    fatherName = "Ahmed";
    dob = "02012001";
    age = calculateAge(dob);
    jobType = "public";
    empId = 0;
    bps = 17;
}
Employee::Employee(string name, string fatherName, string dob, string jobType, int empId, int bps)
{
    this->name = name;
    this->fatherName = fatherName;
    this->dob = dob;
    this->jobType = jobType;
    this->empId = empId;
    this->bps = bps;
}
void Employee::setRecord()
{
    int localChoice;
    cout << "\nEnter Name: ";
    cin >> name;
    cout << "Enter Father Name: ";
    cin >> fatherName;
    cout << "Enter Date of Birth (DDMMYYYY): ";
    cin >> dob;
    age = calculateAge(dob);
    cout << "What is the Job Type?" << endl
         << "\t1. Private" << endl
         << "\t2. Public" << endl
         << "\t3. Autonomous" << endl
         << "Enter here: ";
    cin >> localChoice;

    while (localChoice < 1 || localChoice > 3)
    {
        cout << "Please select valid option from 1 to 3 only, Enter again: ";
        cin >> localChoice;
    }
    switch (localChoice)
    {
    case 1:
        jobType = "Private";
        break;
    case 2:
        jobType = "Public";
        break;
    case 3:
        jobType = "Autonomous";
    }

    cout << "Enter Employee ID: ";
    cin >> empId;
    cout << "Enter BPS: ";
    cin >> bps;
    while (bps < 1 || bps > 22)
    {
        cout << "BPS can be from 1 to 22 only, Enter again: ";
        cin >> bps;
    }
}
void Employee::showRecord()
{
    cout << "Name: " << name << endl;
    cout << "Father Name: " << fatherName << endl;
    cout << "Date of Birth: " << dob << endl;
    cout << "Age: " << age << endl;
    cout << "Job Type: " << jobType << endl;
    cout << "Employee ID: " << empId << endl;
    cout << "BPS: " << bps << endl;
}