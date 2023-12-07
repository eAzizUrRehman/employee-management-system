#ifndef TEACHER_NODE_H
#define TEACHER_NODE_H

#include "../teacher.h"

class TeacherNode
{
public:
	Teacher teacher;
	TeacherNode *next;

	TeacherNode(const Teacher &teacher);
};

#endif