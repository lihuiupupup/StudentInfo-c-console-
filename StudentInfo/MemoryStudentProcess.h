#ifndef MEMOEY_STUDENT_PROCESS_H
#define MEMOEY_STUDENT_PROCESS_H
#include "StudentProcess.h"
#include <vector>
#include <string>

struct MemoryStudentProcess : public StudentProcess
{
    MemoryStudentProcess(std::vector<Student> *);
    bool insertStudent(Student student) ;
    bool deleteStudent(string studentId) ;
    bool updateStudent(Student student) ;
    std::vector<Student> queryStudent(string studentIdOrName) ;
    std::vector<Student> * studentList;
};

#endif