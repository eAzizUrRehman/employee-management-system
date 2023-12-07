#include "./employeeList.h"
#include "./doctor/doctor.h"
#include "./doctor/doctorNode/doctorNode.h"
#include "./teacher/teacher.h"
#include "./teacher/teacherNode/teacherNode.h"
#include <iostream>
using namespace std;

EmployeeList::EmployeeList()
    : teacherFirstNode(nullptr), doctorFirstNode(nullptr) {}

void EmployeeList::addTeacher(const Teacher &teacher) {
  TeacherNode *newNode = new TeacherNode(teacher);
  newNode->next = teacherFirstNode;
  teacherFirstNode = newNode;
}

void EmployeeList::addDoctor(const Doctor &doctor) {
  DoctorNode *newNode = new DoctorNode(doctor);
  newNode->next = doctorFirstNode;
  doctorFirstNode = newNode;
}
void EmployeeList::searchEmployeeById() {
	int id;
	cout << "Enter the ID of the Employee you want to search: ";
	cin >> id;
	TeacherNode *temp1 = teacherFirstNode;
	while (temp1 != nullptr) {
		if (temp1->teacher.empId == id) {
			cout << "The employee with id " << id << " is " << temp1->teacher.name
					 << ". The employee belongs to teacher list." << endl;
			return;
		}
		temp1 = temp1->next;
	}
	DoctorNode *temp2 = doctorFirstNode;
	while (temp2 != nullptr) {
		if (temp2->doctor.empId == id) {
			cout << "The employee with id " << id << " is " << temp2->doctor.name
					 << ". The employee belongs to doctor list." << endl;
			return;
		}
		temp2 = temp2->next;
	}
	cout << "Employee with id " << id << " not found." << endl;
}

void EmployeeList::searchEmployeeByName() {
  string name;
  cout << "Enter the Name of the Employee you want to search: ";
  cin >> name;

  TeacherNode *temp1 = teacherFirstNode;
  while (temp1 != nullptr) {
    if (temp1->teacher.name == name) {
      cout << "The employee with name " << name << " belongs to teacher list."
           << endl;
      return;
    }
    temp1 = temp1->next;
  }
  DoctorNode *temp2 = doctorFirstNode;
  while (temp2 != nullptr) {
    if (temp2->doctor.name == name) {
      cout << "The employee with name " << name << " belongs to doctor list."
           << endl;
      return;
    }
    temp2 = temp2->next;
  }
}
void EmployeeList::updateEmployeeRecord() {
  int id;
  cout << "Enter the ID of the Employee you want to update: ";
  cin >> id;

  TeacherNode *temp1 = teacherFirstNode;
  while (temp1 != nullptr) {
    if (temp1->teacher.empId == id) {
      cout << "Please enter new details." << endl;
      temp1->teacher.setRecord();
      return;
    }
    temp1 = temp1->next;
  }

  DoctorNode *temp2 = doctorFirstNode;
  while (temp2 != nullptr) {
    if (temp2->doctor.empId == id) {
      cout << "Please enter new details." << endl;
      temp2->doctor.setRecord();
      return;
    }
    temp2 = temp2->next;
  }
  cout << "No employee found with the provided ID " << id << "." << endl;
}

void EmployeeList::searchYoungestEmployee() {
  TeacherNode *temp1 = teacherFirstNode;
  DoctorNode *temp2 = doctorFirstNode;
  if (temp1 == nullptr && temp2 == nullptr) {
    cout << "No employees exists in the record." << endl;
    return;
  }
  TeacherNode *youngestTeacher = temp1;
  DoctorNode *youngestDoctor = temp2;
  while (temp1 != nullptr) {
    if (temp1->teacher.age < youngestTeacher->teacher.age) {
      youngestTeacher = temp1;
    }
    temp1 = temp1->next;
  }
  while (temp2 != nullptr) {
    if (temp2->doctor.age < youngestDoctor->doctor.age) {
      youngestDoctor = temp2;
    }
    temp2 = temp2->next;
  }
  if (youngestTeacher->teacher.age < youngestDoctor->doctor.age) {
    cout << "Youngest employee is " << youngestTeacher->teacher.name
         << " whose age is " << youngestTeacher->teacher.age << endl;
  } else {
    cout << "Youngest employee is " << youngestDoctor->doctor.name
         << " whose age is " << youngestDoctor->doctor.age << endl;
  }
}

void EmployeeList::searchEldestEmployee() {
  TeacherNode *temp1 = teacherFirstNode;
  DoctorNode *temp2 = doctorFirstNode;
  if (temp1 == nullptr && temp2 == nullptr) {
    cout << "No employees exists in the record." << endl;
    return;
  }
  TeacherNode *eldestTeacher = temp1;
  DoctorNode *eldestDoctor = temp2;
  while (temp1 != nullptr) {
    if (temp1->teacher.age > eldestTeacher->teacher.age) {
      eldestTeacher = temp1;
    }
    temp1 = temp1->next;
  }
  while (temp2 != nullptr) {
    if (temp2->doctor.age > eldestDoctor->doctor.age) {
      eldestDoctor = temp2;
    }
    temp2 = temp2->next;
  }
  if (eldestTeacher->teacher.age > eldestDoctor->doctor.age) {
    cout << "Eldest employee is " << eldestTeacher->teacher.name
         << " whose age is " << eldestTeacher->teacher.age
         << " who belongs to teacher list" << endl;
  } else {
    cout << "Eldest employee is " << eldestDoctor->doctor.name
         << " whose age is " << eldestDoctor->doctor.age
         << " who belongs to doctor list" << endl;
  }
}
void EmployeeList::searchDoctorBySpecialization() {
  string specialization;
  cout << "Enter the specialization of the doctor you want to search: ";
  cin >> specialization;
  DoctorNode *temp = doctorFirstNode;
  while (temp != nullptr) {
    if (temp->doctor.specialization == specialization) {
      cout << "The doctor with specialization " << specialization << " is "
           << temp->doctor.name << "." << endl;
      return;
    }
    temp = temp->next;
  }
  cout << "No doctor found with the provided specialization " << specialization
       << "." << endl;
}
void EmployeeList::searchTeacherByTeachingLevel() {
  string teachingLevel;
  cout << "Enter the teaching level of the teacher you want to search: ";
  cin >> teachingLevel;
  TeacherNode *temp = teacherFirstNode;
  while (temp != nullptr) {
    if (temp->teacher.teachingLevel == teachingLevel) {
      cout << "The teacher with teaching level " << teachingLevel << " is "
           << temp->teacher.name << "." << endl;
      return;
    }
    temp = temp->next;
  }
  cout << "No teacher found with the provided teaching level " << teachingLevel
       << "." << endl;
}
void EmployeeList::deleteEmployeeById() {
  int id;
  cout << "Enter the ID of the Employee you want to delete: ";
  cin >> id;
  TeacherNode *temp1 = teacherFirstNode;
  TeacherNode *prev1 = nullptr;
  while (temp1 != nullptr) {
    if (temp1->teacher.empId == id) {
      if (prev1 == nullptr) {
        teacherFirstNode = temp1->next;
      } else {
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
  while (temp2 != nullptr) {
    if (temp2->doctor.empId == id) {
      if (prev2 == nullptr) {
        doctorFirstNode = temp2->next;
      } else {
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
void EmployeeList::deleteEmployeeByName() {
  string name;
  cout << "Enter the Name of the Employee you want to delete: ";
  cin >> name;
  TeacherNode *temp1 = teacherFirstNode;
  TeacherNode *prev1 = nullptr;
  while (temp1 != nullptr) {
    if (temp1->teacher.name == name) {
      if (prev1 == nullptr) {
        teacherFirstNode = temp1->next;
      } else {
        prev1->next = temp1->next;
      }
      delete temp1;
      cout << "Employee with name " << name << " deleted \nsuccessfully."
           << endl;
      return;
    }
    prev1 = temp1;
    temp1 = temp1->next;
  }
  DoctorNode *temp2 = doctorFirstNode;
  DoctorNode *prev2 = nullptr;
  while (temp2 != nullptr) {
    if (temp2->doctor.name == name) {
      if (prev2 == nullptr) {
        doctorFirstNode = temp2->next;
      } else {
        prev2->next = temp2->next;
      }
      delete temp2;
      cout << "Employee with name " << name << " deleted \nsuccessfully."
           << endl;
      return;
    }
    prev2 = temp2;
    temp2 = temp2->next;
  }
  cout << "No employee found with the provided name " << name << "." << endl;
}
