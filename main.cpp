#include "./employeeList/employee/employee.h"
#include "./employeeList/doctor/doctor.h"
#include "./employeeList/doctor/doctorNode/doctorNode.h"
#include "./employeeList/teacher/teacher.h"
#include "./employeeList/teacher/teacherNode/teacherNode.h"
#include "./employeeList/employeeList.h"
#include <iostream>
#include <ctime>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	int choice, localChoice;
	EmployeeList employeeList;

	do
	{
		cout << "\nMenu: " << endl
			 << "\t1. Add Employee" << endl
			 << "\t2. Update Employee Record" << endl
			 << "\t3. Search Employee" << endl
			 << "\t4. Delete Employee" << endl
			 << "\t5. Show Employees" << endl
			 << "\t0. Exit the program" << endl
			 << "Enter here: ";

		cin >> choice;
		while (choice < 0 || choice > 5)
		{
			cout << "Invalid choice, Enter again: ";
			cin >> choice;
		}
		switch (choice)
		{
		case 0:
		{
			break;
		}
		case 1:
		{
			cout << "\nWhich type of employee you want to add?" << endl
				 << "\t1. Doctor" << endl
				 << "\t2. Teacher" << endl
				 << "Enter here: ";
			cin >> localChoice;
			while (localChoice != 1 && localChoice != 2)
			{
				cout << "Invalid choice, Enter again: ";
				cin >> localChoice;
			}
			if (localChoice == 1)
			{
				Doctor tempDoctor;
				tempDoctor.setRecord();
				employeeList.addDoctor(tempDoctor);
			}
			else
			{
				Teacher tempTeacher;
				tempTeacher.setRecord();
				employeeList.addTeacher(tempTeacher);
			}
			break;
		}
		case 2:
		{
			cout << "What type of employee's record you want to update?" << endl
				 << "\t1. Doctor" << endl
				 << "\t2. Teacher" << endl
				 << "Enter here: ";
			cin >> localChoice;
			while (localChoice != 1 && localChoice != 2)
			{
				cout << "Invalid choice, Enter again: ";
				cin >> localChoice;
			}
			if (localChoice == 1)
			{
				Doctor tempDoctor;
				tempDoctor.updateRecord();
			}
			else
			{
				Teacher tempTeacher;
				tempTeacher.updateRecord();
			}
			break;
		}
		case 3:
		{
			cout << "\nSearch Employee Menu: " << endl
				 << "\t1. Search Employee By ID" << endl
				 << "\t2. Search Employee By Name" << endl
				 << "\t3. Search Youngest Employee" << endl
				 << "\t4. Search Eldest Employee" << endl
				 << "\t5. Search Doctor By Specialization" << endl
				 << "\t6. Search Teacher By Teaching Level" << endl
				 << "\t0. Exit" << endl
				 << "Enter here: ";

			cin >> localChoice;
			while (localChoice < 0 || localChoice > 6)
			{
				cout << "Invalid choice, Enter again: ";
				cin >> localChoice;
			}

			switch (localChoice)
			{
			case 1:
				employeeList.searchEmployeeById();
				break;
			case 2:
				employeeList.searchEmployeeByName();
				break;
			case 3:
				employeeList.searchYoungestEmployee();
				break;
			case 4:
				employeeList.searchEldestEmployee();
				break;
			case 5:
				employeeList.searchDoctorBySpecialization();
				break;
			case 6:
				employeeList.searchTeacherByTeachingLevel();
				break;
			case 0:
				break;
			}
			break;
		}

		case 4:
		{
			cout << "\nDelete Employee Menu: " << endl
				 << "\t1. Delete Employee By ID" << endl
				 << "\t2. Delete Employee By Name" << endl
				 << "\t0. Exit" << endl
				 << "Enter here: ";

			cin >> localChoice;
			while (localChoice < 0 || localChoice > 2)
			{
				cout << "Invalid choice, Enter again: ";
				cin >> localChoice;
			}

			switch (localChoice)
			{
			case 1:
				employeeList.deleteEmployeeById();
				break;
			case 2:
				employeeList.deleteEmployeeByName();
				break;
			case 0:
				break;
			}
			break;
		}
		case 5:
		{
			employeeList.showEmployees();
			break;
		}
		}
		if (choice != 0)
		{
			cout << "\nEnter 9 to show Menu again or 0 to terminate the "
					"program: ";
			cin >> choice;
			while (choice != 0 && choice != 9)
			{
				cout << "Invalid input. Enter again: ";
				cin >> choice;
			}
		}

	} while (choice != 0);

	cout << "\n***Thank You For Using This Program.***" << endl;
	return 0;
}
