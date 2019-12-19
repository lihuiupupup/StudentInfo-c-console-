#ifndef STUDENT_MANAGER_H_
#define STUDENT_MANAGER_H_
#include "stdafx.h"
#include "student.h"
#include "logger.h"
#include "Student.h"
#include "StudentProcess.h"
#include "MemoryStudentProcess.h"

class StudentManager
{
private:
    /* data */
    StudentProcess *process;
    std::vector<Student> *students;
    StudentManager();
    StudentManager(const StudentManager &) = delete;
    StudentManager &operator=(const StudentManager &) = delete;
    

public:
    static StudentManager *getInstance();
    bool insertStudent(Student student);
    bool deleteStudent(string studentId);
    bool updateStudent(Student student);
    std::vector<Student> queryStudent(string studentIdOrName);
	bool isVaildStudentId(std::string id) const;
    ~StudentManager();
};

#endif