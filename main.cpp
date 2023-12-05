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
		cout << "Enter Name: ";
		cin >> name;
		cout << "Enter Father Name: ";
		cin >> fatherName;
		cout << "Enter Date of Birth (DDMMYYYY): ";
		cin >> dob;
		age = calculateAge(dob);
		cout << "Enter Job Type: ";
		cin >> jobType;
		cout << "Enter Employee ID: ";
		cin >> empId;
		cout << "Enter BPS: ";
		cin >> bps;
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
		Employee::setRecord();
		cout << "Enter Education: ";
		cin >> education;
		cout << "Enter Teaching Level: ";
		cin >> teachingLevel;
		cout << "Enter Subject: ";
		cin >> subject;
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
		cout << "Enter the updated Job Type: ";
		cin >> jobType;
		cout << "Enter the updated BPS: ";
		cin >> bps;
		cout << "Enter the updated Education: ";
		cin >> education;
		cout << "Enter the updated Teaching Level: ";
		cin >> teachingLevel;
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
		Employee::setRecord();
		cout << "Enter Doctor Type: ";
		cin >> doctorType;
		cout << "Enter Specialization: ";
		cin >> specialization;
		cout << "Enter Job Level: ";
		cin >> jobLevel;
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
		cout << "Enter the updated Job Type: ";
		cin >> jobType;
		cout << "Enter the updated BPS: ";
		cin >> bps;
		cout << "Enter the updated Job Level: ";
		cin >> jobLevel;
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
	void searchEmployeeByID()
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
	void deleteEmployeeByID()
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
				cout << "Employee with ID " << id << " deleted successfully." << endl;
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
				cout << "Employee with ID " << id << " deleted successfully." << endl;
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
				cout << "Employee with name " << name << " deleted successfully." << endl;
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
				cout << "Employee with name " << name << " deleted successfully." << endl;
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
	Teacher t1;
	t1.setRecord();
	t1.showRecord();
	t1.updateRecord();
	t1.showRecord();

	cout << "\nMenu: "
		 << "\t1. Add Employee" << endl
		 << "\t2. Update Employee Record" << endl
		 << "\t3. Search Employee" << endl
		 << "\t4. Delete Employee" << endl
		 << "\t5. Exit" << endl

		 << "Enter here: ";

	cin >> choice;

	int localChoice;

	switch (choice)
	{
	case 1:
	{
		cout << "Enter the type of employee you want to add: " << endl
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
	}
	break;
	case 2:
	{
		cout << "Enter the type of employee you want to add: " << endl
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
	}
	break;
	case 3:
	{

		cout << "\n Search Employee Menu: "
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
			searchEmployeeByID();
			break;
		case 2:
			searchEmployeeByName();
			break;
		case 3:
			searchYoungestEmployee();
			break;
		case 4:
			searchEldestEmployee();
			break;
		case 5:
			searchDoctorBySpecialization();
			break;
		case 6:
			searchTeacherByTeachingLevel();
			break;
		case 0:
			break;
		}
	case 4:
	{
		cout << "\n Search Employee Menu: "
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
			deleteEmployeeByID();
			break;
		case 2:
			deleteEmployeeByName();
			break;
		case 0:
			break;
		}
	}
	}
		return 0;
	}
