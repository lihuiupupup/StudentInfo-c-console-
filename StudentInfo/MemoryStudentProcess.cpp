#include "MemoryStudentProcess.h"
#include "stdafx.h"
 
MemoryStudentProcess::MemoryStudentProcess(std::vector<Student> *list)
{
    studentList = list;
}

bool MemoryStudentProcess::insertStudent(Student student) 
{
    studentList->push_back(student);
    return true;
}
bool MemoryStudentProcess::deleteStudent(string studentId) 
{
    auto it = studentList->begin();
    while (it != studentList->end())
    {
        if (it->studentId == studentId)
        {
            studentList->erase(it);
            return true;
        }
        ++it;
    }
    

    return false;
    
}
bool MemoryStudentProcess::updateStudent(Student student) 
{
    std::vector<Student>::iterator currentPtr;
	bool isErase = false;
    auto it = studentList->begin();
    while (it != studentList->end())
    {
        if (it->studentId == student.studentId)
        {
            currentPtr = studentList->erase(it);
			isErase = true;
            break;
        }
        ++it;
    }
    if (isErase)
    {
        studentList->insert(currentPtr,student);
        return true;
    }
    return false;
    
}
std::vector<Student> MemoryStudentProcess::queryStudent(string studentIdOrName) 
{
    if (studentIdOrName == "" )
    {
        return *studentList;
    }
    
    std::vector<Student> temp;
    auto it = studentList->begin();
    while (it != studentList->end())
    {
        if (it->studentId == studentIdOrName || it->studentName == studentIdOrName)
        {
            temp.push_back(*it);
            if (it->studentId == studentIdOrName)
            {
                temp.clear();
                temp.push_back(*it);
                return temp;
            }           
        }
        ++it;
    }
    return temp;

}