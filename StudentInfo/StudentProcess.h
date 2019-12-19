#ifndef STUDENT_PROCESS_H
#define STUDENT_PROCESS_H
#include "stdafx.h"
#include "student.h"


struct StudentProcess
{
    
    virtual bool insertStudent(Student student) =0;
    virtual bool deleteStudent(string studentId) =0;
    virtual bool updateStudent(Student student) = 0;
    virtual std::vector<Student> queryStudent(string studentIdOrName) =0;
    
};



#endif