#include "teacher.h"
#include <string>
#include <iostream>
using namespace std;

Teacher:: Teacher()
	{
		// parent default constructor is called automatically
		education = "Bachelor";
		teachingLevel = "School";
		subject = "Physics";
	}

Teacher:: Teacher(string name, string fatherName, string dob, string jobType, int empId, int bps, string education, string teachingLevel, string subject)
		: Employee(name, fatherName, dob, jobType, empId, bps)
	{
		this->education = education;
		this->teachingLevel = teachingLevel;
		this->subject = subject;
	}
	void Teacher:: setRecord()
	{
		int localChoice;

		Employee::setRecord();
		cout << "What is the Education?" << endl
			 << "\t1. Bachelor" << endl
			 << "\t2. Masters" << endl
			 << "\t3. PhD" << endl
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
			education = "Bachelor";
			break;
		case 2:
			education = "Masters";
			break;
		case 3:
			education = "PhD";
		}

		cout << "What is the Teaching Level?" << endl
			 << "\t1. School" << endl
			 << "\t2. College" << endl
			 << "\t3. University" << endl
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
			teachingLevel = "School";
			break;
		case 2:

			teachingLevel = "College";
			break;
		case 3:
			teachingLevel = "University";
		}

		cout << "What is the Subject?" << endl
			 << "\t1. Physics" << endl
			 << "\t2. Chemistry" << endl
			 << "\t3. Maths" << endl
			 << "\t4. CS" << endl
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
			subject = "Physics";
			break;
		case 2:

			subject = "Chemistry";
			break;
		case 3:
			subject = "Maths";
			break;
		case 4:
			subject = "CS";
		}
		cout << "\n***Successfully added " << name << "'s record.***" << endl;
	}

	void Teacher:: showRecord()
	{
		Employee::showRecord();
		cout << "Education: " << education << endl;
		cout << "Teaching Level: " << teachingLevel << endl;
		cout << "Subject: " << subject << endl;
	}
	void Teacher:: updateRecord()
	{
		int localChoice;
		cout << "What is the updated Job Type?" << endl
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

		cout << "What is the updated Education?" << endl
			 << "\t1. Bachelor" << endl
			 << "\t2. Masters" << endl
			 << "\t3. PhD" << endl
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
			education = "Bachelor";
			break;
		case 2:
			education = "Masters";
			break;
		case 3:
			education = "PhD";
		}
		cout << "What is the updated Teaching Level?" << endl
			 << "\t1. School" << endl
			 << "\t2. College" << endl
			 << "\t3. University" << endl
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
			teachingLevel = "School";
			break;
		case 2:

			teachingLevel = "College";
			break;
		case 3:
			teachingLevel = "University";
		}
	}
 