#include "StudentManager.h"


StudentManager::StudentManager()
{
    students = new std::vector<Student>();
    process = new MemoryStudentProcess(students);
}

StudentManager::~StudentManager()
{
    delete process;
    (*students).clear();
    delete students;
}
StudentManager * StudentManager::getInstance()
{
	 
    static StudentManager myInstance;

    return &myInstance;
}

bool StudentManager::insertStudent(Student student)
{
    return process->insertStudent(student);
}
bool StudentManager::deleteStudent(string studentId)
{
    return process->deleteStudent(studentId);
}
bool StudentManager::updateStudent(Student student)
{
    return process->updateStudent(student);
}
std::vector<Student> StudentManager::queryStudent(string studentIdOrName)
{
    return process->queryStudent(studentIdOrName);
}

bool StudentManager::isVaildStudentId(std::string id) const
{
	auto it = students->cbegin();
	while (it != students->cend())
	{
		if (it->studentId == id)
		{
			return true;
		}
		++it;
	}
	return false;
}
