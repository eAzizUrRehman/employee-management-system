#ifndef TEACHER_H
#define TEACHER_H

#include "../employee/employee.h"
#include <string>
using namespace std;

class Teacher : public Employee {
public:
  string education, teachingLevel, subject;

  Teacher();

  Teacher(string name, string fatherName, string dob, string jobType, int empId,
          int bps, string education, string teachingLevel, string subject);

  void setRecord();
  void showRecord();
  void updateRecord();
};

#endif