#include <iostream>
#include <ctime>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

int calculateAge(const string &dob)
{
	istringstream iss(dob);
	tm dob_tm{};
	iss >> get_time(&dob_tm, "%d%m%Y");

	time_t now_time_t = time(nullptr);
	tm *now_tm = localtime(&now_time_t);

	int age = now_tm->tm_year + 1900 - (dob_tm.tm_year + 1900);
	if (now_tm->tm_mon < dob_tm.tm_mon ||
		(now_tm->tm_mon == dob_tm.tm_mon && now_tm->tm_mday < dob_tm.tm_mday))
	{
		age--;
	}
	return age;
}

class Employee
{
public:
	string name, fatherName, dob, jobType;
	int empId, bps, age;

	Employee()
	{
		name = "Ali";
		fatherName = "Ahmed";
		dob = "02012001";
		age = calculateAge(dob);
		jobType = "public";
		empId = 0;
		bps = 17;
	}
	Employee(string name, string fatherName, string dob, string jobType, int empId, int bps)
	{
		this->name = name;
		this->fatherName = fatherName;
		this->dob = dob;
		this->jobType = jobType;
		this->empId = empId;
		this->bps = bps;
	}
	void setRecord()
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
	void showRecord()
	{
		cout << "Name: " << name << endl;
		cout << "Father Name: " << fatherName << endl;
		cout << "Date of Birth: " << dob << endl;
		cout << "Age: " << age << endl;
		cout << "Job Type: " << jobType << endl;
		cout << "Employee ID: " << empId << endl;
		cout << "BPS: " << bps << endl;
	}
};

class Teacher : public Employee
{
public:
	string education, teachingLevel, subject;
	Teacher()
	{
		// parent default constructor is called automatically
		education = "Bachelor";
		teachingLevel = "School";
		subject = "Physics";
	}

	Teacher(string name, string fatherName, string dob, string jobType, int empId, int bps, string education, string teachingLevel, string subject)
		: Employee(name, fatherName, dob, jobType, empId, bps)
	{
		this->education = education;
		this->teachingLevel = teachingLevel;
		this->subject = subject;
	}
	void setRecord()
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

	void showRecord()
	{
		Employee::showRecord();
		cout << "Education: " << education << endl;
		cout << "Teaching Level: " << teachingLevel << endl;
		cout << "Subject: " << subject << endl;
	}
	void updateRecord()
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
};

class Doctor : public Employee
{
public:
	string doctorType, specialization, jobLevel;
	Doctor()
	{
		// parent default constructor is called automatically
		doctorType = "MBBS";
		specialization = "ENT";
		jobLevel = "House Job";
	}

	Doctor(string name, string fatherName, string dob, string jobType, int empId, int bps, string doctorType, string specialization, string jobLevel)
		: Employee(name, fatherName, dob, jobType, empId, bps)
	{
		this->doctorType = doctorType;
		this->specialization = specialization;
		this->jobLevel = jobLevel;
	}
	void setRecord()
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
		cout << "\nSuccessfully added doctor record." << endl;
	}
	void showRecord()
	{
		Employee::showRecord();
		cout << "Doctor Type: " << doctorType << endl;
		cout << "Specialization: " << specialization << endl;
		cout << "Job Level: " << jobLevel << endl;
	}
	void updateRecord()
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
};
class TeacherNode
{
public:
	Teacher teacher; // object
	TeacherNode *next;

	TeacherNode(const Teacher &teacher) : teacher(teacher), next(nullptr) {}
};
class DoctorNode
{
public:
	Doctor doctor;
	DoctorNode *next;

	DoctorNode(const Doctor &doctor) : doctor(doctor), next(nullptr) {}
};

class EmployeeList
{
public:
	TeacherNode *teacherFirstNode;
	DoctorNode *doctorFirstNode;

	EmployeeList() : teacherFirstNode(nullptr), doctorFirstNode(nullptr) {}

	void addTeacher(const Teacher &teacher)
	{
		TeacherNode *newNode = new TeacherNode(teacher);
		newNode->next = teacherFirstNode;
		teacherFirstNode = newNode;
	}

	void addDoctor(const Doctor &doctor)
	{
		DoctorNode *newNode = new DoctorNode(doctor);
		newNode->next = doctorFirstNode;
		doctorFirstNode = newNode;
	}
	void searchEmployeeById()
	{
		int id;
		cout << "Enter the ID of the Employee you want to search: ";
		cin >> id;
		TeacherNode *temp1 = teacherFirstNode;
		while (temp1 != nullptr)
		{
			if (temp1->teacher.empId == id)
			{
				cout << "The employee with id " << id << " is " << temp1->teacher.name << ". The employee belongs to teacher list." << endl;
				return;
			}
			temp1 = temp1->next;
		}
		DoctorNode *temp2 = doctorFirstNode;
		while (temp2 != nullptr)
		{
			if (temp2->doctor.empId == id)
			{
				cout << "The employee with id " << id << " is " << temp2->doctor.name << ". The employee belongs to doctor list." << endl;
				return;
			}
			temp2 = temp2->next;
		}
	}

	void searchEmployeeByName()
	{
		string name;
		cout << "Enter the Name of the Employee you want to search: ";
		cin >> name;

		TeacherNode *temp1 = teacherFirstNode;
		while (temp1 != nullptr)
		{
			if (temp1->teacher.name == name)
			{
				cout << "The employee with name " << name << " belongs to teacher list." << endl;
				return;
			}
			temp1 = temp1->next;
		}
		DoctorNode *temp2 = doctorFirstNode;
		while (temp2 != nullptr)
		{
			if (temp2->doctor.name == name)
			{
				cout << "The employee with name " << name << " belongs to doctor list." << endl;
				return;
			}
			temp2 = temp2->next;
		}
	}
	void updateEmployeeRecord()
	{
		int id;
		cout << "Enter the ID of the Employee you want to update: ";
		cin >> id;

		TeacherNode *temp1 = teacherFirstNode;
		while (temp1 != nullptr)
		{
			if (temp1->teacher.empId == id)
			{
				cout << "Please enter new details." << endl;
				temp1->teacher.setRecord();
				return;
			}
			temp1 = temp1->next;
		}

		DoctorNode *temp2 = doctorFirstNode;
		while (temp2 != nullptr)
		{
			if (temp2->doctor.empId == id)
			{
				cout << "Please enter new details." << endl;
				temp2->doctor.setRecord();
				return;
			}
			temp2 = temp2->next;
		}
		cout << "No employee found with the provided ID " << id << "." << endl;
	}

	void searchYoungestEmployee()
	{
		TeacherNode *temp1 = teacherFirstNode;
		DoctorNode *temp2 = doctorFirstNode;
		if (temp1 == nullptr && temp2 == nullptr)
		{
			cout << "No employees exists in the record." << endl;
			return;
		}
		TeacherNode *youngestTeacher = temp1;
		DoctorNode *youngestDoctor = temp2;
		while (temp1 != nullptr)
		{
			if (temp1->teacher.age < youngestTeacher->teacher.age)
			{
				youngestTeacher = temp1;
			}
			temp1 = temp1->next;
		}
		while (temp2 != nullptr)
		{
			if (temp2->doctor.age < youngestDoctor->doctor.age)
			{
				youngestDoctor = temp2;
			}
			temp2 = temp2->next;
		}
		if (youngestTeacher->teacher.age < youngestDoctor->doctor.age)
		{
			cout << "Youngest employee is " << youngestTeacher->teacher.name
				 << " whose age is " << youngestTeacher->teacher.age << endl;
		}
		else
		{
			cout << "Youngest employee is " << youngestDoctor->doctor.name
				 << " whose age is " << youngestDoctor->doctor.age << endl;
		}
	}

	void searchEldestEmployee()
	{
		TeacherNode *temp1 = teacherFirstNode;
		DoctorNode *temp2 = doctorFirstNode;
		if (temp1 == nullptr && temp2 == nullptr)
		{
			cout << "No employees exists in the record." << endl;
			return;
		}
		TeacherNode *eldestTeacher = temp1;
		DoctorNode *eldestDoctor = temp2;
		while (temp1 != nullptr)
		{
			if (temp1->teacher.age > eldestTeacher->teacher.age)
			{
				eldestTeacher = temp1;
			}
			temp1 = temp1->next;
		}
		while (temp2 != nullptr)
		{
			if (temp2->doctor.age > eldestDoctor->doctor.age)
			{
				eldestDoctor = temp2;
			}
			temp2 = temp2->next;
		}
		if (eldestTeacher->teacher.age > eldestDoctor->doctor.age)
		{
			cout << "Eldest employee is " << eldestTeacher->teacher.name
				 << " whose age is " << eldestTeacher->teacher.age << " who belongs to teacher list" << endl;
		}
		else
		{
			cout << "Eldest employee is " << eldestDoctor->doctor.name
				 << " whose age is " << eldestDoctor->doctor.age << " who belongs to doctor list" << endl;
		}
	}
	void searchDoctorBySpecialization()
	{
		string specialization;
		cout << "Enter the specialization of the doctor you want to search: ";
		cin >> specialization;
		DoctorNode *temp = doctorFirstNode;
		while (temp != nullptr)
		{
			if (temp->doctor.specialization == specialization)
			{
				cout << "The doctor with specialization " << specialization << " is " << temp->doctor.name << "." << endl;
				return;
			}
			temp = temp->next;
		}
		cout << "No doctor found with the provided specialization " << specialization << "." << endl;
	}
	void searchTeacherByTeachingLevel()
	{
		string teachingLevel;
		cout << "Enter the teaching level of the teacher you want to search: ";
		cin >> teachingLevel;
		TeacherNode *temp = teacherFirstNode;
		while (temp != nullptr)
		{
			if (temp->teacher.teachingLevel == teachingLevel)
			{
				cout << "The teacher with teaching level " << teachingLevel << " is " << temp->teacher.name << "." << endl;
				return;
			}
			temp = temp->next;
		}
		cout << "No teacher found with the provided teaching level " << teachingLevel << "." << endl;
	}
	void deleteEmployeeById()
	{
		int id;
		cout << "Enter the ID of the Employee you want to delete: ";
		cin >> id;
		TeacherNode *temp1 = teacherFirstNode;
		TeacherNode *prev1 = nullptr;
		while (temp1 != nullptr)
		{
			if (temp1->teacher.empId == id)
			{
				if (prev1 == nullptr)
				{
					teacherFirstNode = temp1->next;
				}
				else
				{
					prev1->next = temp1->next;
				}
				delete temp1;
				cout << "Employee with ID " << id << " deleted \nsuccessfully." << endl;
				return;
			}
			prev1 = temp1;
			temp1 = temp1->next;
		}
		DoctorNode *temp2 = doctorFirstNode;
		DoctorNode *prev2 = nullptr;
		while (temp2 != nullptr)
		{
			if (temp2->doctor.empId == id)
			{
				if (prev2 == nullptr)
				{
					doctorFirstNode = temp2->next;
				}
				else
				{
					prev2->next = temp2->next;
				}
				delete temp2;
				cout << "Employee with ID " << id << " deleted \nsuccessfully." << endl;
				return;
			}
			prev2 = temp2;
			temp2 = temp2->next;
		}
		cout << "No employee found with the provided ID " << id << "." << endl;
	}
	void deleteEmployeeByName()
	{
		string name;
		cout << "Enter the Name of the Employee you want to delete: ";
		cin >> name;
		TeacherNode *temp1 = teacherFirstNode;
		TeacherNode *prev1 = nullptr;
		while (temp1 != nullptr)
		{
			if (temp1->teacher.name == name)
			{
				if (prev1 == nullptr)
				{
					teacherFirstNode = temp1->next;
				}
				else
				{
					prev1->next = temp1->next;
				}
				delete temp1;
				cout << "Employee with name " << name << " deleted \nsuccessfully." << endl;
				return;
			}
			prev1 = temp1;
			temp1 = temp1->next;
		}
		DoctorNode *temp2 = doctorFirstNode;
		DoctorNode *prev2 = nullptr;
		while (temp2 != nullptr)
		{
			if (temp2->doctor.name == name)
			{
				if (prev2 == nullptr)
				{
					doctorFirstNode = temp2->next;
				}
				else
				{
					prev2->next = temp2->next;
				}
				delete temp2;
				cout << "Employee with name " << name << " deleted \nsuccessfully." << endl;
				return;
			}
			prev2 = temp2;
			temp2 = temp2->next;
		}
		cout << "No employee found with the provided name " << name << "." << endl;
	}
};

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
			 << "\t0. Exit the program" << endl
			 << "Enter here: ";

		cin >> choice;
		while (choice < 0 || choice > 4)
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
				Doctor d;
				d.setRecord();
			}
			else
			{
				Teacher t;
				t.setRecord();
			}
			break;
		}
		case 2:
		{
			cout << "What type of employee you want to add: " << endl
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
				Doctor d;
				d.updateRecord();
			}
			else
			{
				Teacher t;
				t.updateRecord();
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
				 << "\t6. Search Teacher By TeachingLevel" << endl
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
		}
		}

		if (choice != 0)
		{
			cout << "\nEnter 9 to show 'Teams Menu' again or 0 to terminate the "
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
