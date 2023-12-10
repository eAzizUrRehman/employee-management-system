#include "doctor.h"
#include "../employee/employee.h"
#include <iostream>
#include <string>
using namespace std;

Doctor::Doctor()
{
    // parent default constructor is called automatically
    doctorType = "MBBS";
    specialization = "ENT";
    jobLevel = "House Job";
}

Doctor::Doctor(string name, string fatherName, string dob, string jobType, int empId, int bps, string doctorType, string specialization, string jobLevel)
    : Employee(name, fatherName, dob, jobType, empId, bps)
{
    this->doctorType = doctorType;
    this->specialization = specialization;
    this->jobLevel = jobLevel;
}
void Doctor::setRecord()
{
    int localChoice;
    Employee::setRecord();
    cout << "What is the Doctor Type?" << endl
         << "\t1. MBBS" << endl
         << "\t2. BDS" << endl
         << "\t3. Vetnery" << endl
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
        doctorType = "MBBS";
        break;
    case 2:

        doctorType = "BDS";
        break;
    case 3:
        doctorType = "Vetnery";
    }

    cout << "What is the Specialization?" << endl
         << "\t1. ENT" << endl
         << "\t2. Heart" << endl
         << "\t3. Stomach" << endl
         << "\t4. Gyne" << endl
         << "Enter here: ";
    cin >> localChoice;

    while (localChoice < 1 || localChoice > 4)
    {
        cout << "Please select valid option from 1 to 4 only, Enter again: ";
        cin >> localChoice;
    }
    switch (localChoice)
    {
    case 1:
        specialization = "ENT";
        break;
    case 2:

        specialization = "Heart";
        break;
    case 3:
        specialization = "Stomach";
        break;
    case 4:
        specialization = "Gyne";
    }

    cout << "What is the Job Level?" << endl
         << "\t1. House Job" << endl
         << "\t2. Medical Officer" << endl
         << "\t3. Senior Medical Officer" << endl
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
        jobLevel = "House Job";
        break;
    case 2:

        jobLevel = "Medical Officer";
        break;
    case 3:
        jobLevel = "Senior Medical Officer";
    }
    cout << "\n***Successfully added " << name << "'s record.***" << endl;
}
void Doctor::showRecord()
{
    Employee::showRecord();
    cout << "Doctor Type: " << doctorType << endl;
    cout << "Specialization: " << specialization << endl;
    cout << "Job Level: " << jobLevel << endl;
}
void Doctor::updateRecord()
{
    int localChoice;
    cout
        << "What is the updated Job Type?" << endl
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

    cout << "Enter the updated BPS: ";
    cin >> bps;
    while (bps < 1 || bps > 22)
    {
        cout << "BPS can be from 1 to 22 only, Enter again: ";
        cin >> bps;
    }
    cout << "What is the updated Job Level?" << endl
         << "\t1. House Job" << endl
         << "\t2. Medical Officer" << endl
         << "\t3. Senior Medical Officer" << endl
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
        jobLevel = "House Job";
        break;
    case 2:

        jobLevel = "Medical Officer";
        break;
    case 3:
        jobLevel = "Senior Medical Officer";
    }
}
