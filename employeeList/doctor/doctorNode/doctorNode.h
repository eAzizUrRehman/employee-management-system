#ifndef DOCTOR_NODE_H
#define DOCTOR_NODE_H

#include "../doctor.h"

class DoctorNode
{
public:
    Doctor doctor;
    DoctorNode *next;

    DoctorNode(const Doctor &doctor);
};

#endif