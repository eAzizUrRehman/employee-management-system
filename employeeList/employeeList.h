#ifndef EMPLOYEE_LIST_H
#define EMPLOYEE_LIST_H

#include "./doctor/doctor.h"
#include "./doctor/doctorNode/doctorNode.h"
#include "./teacher/teacher.h"
#include "./teacher/teacherNode/teacherNode.h"

class EmployeeList
{
public:
	TeacherNode *teacherFirstNode;
	DoctorNode *doctorFirstNode;
	EmployeeList();

	void addTeacher(const Teacher &teacher);
	void addDoctor(const Doctor &doctor);
	void showEmployees();
	void searchEmployeeById();
	void searchEmployeeByName();
	void updateEmployeeRecord();
	void searchYoungestEmployee();
	void searchEldestEmployee();
	void searchDoctorBySpecialization();
	void searchTeacherByTeachingLevel();
	void deleteEmployeeById();
	void deleteEmployeeByName();
};

#endif