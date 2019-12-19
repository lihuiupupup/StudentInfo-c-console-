#include "stdafx.h"
#include "GradeManager.h"

GradeManager & GradeManager::getInstance()
{
	static GradeManager instance;
	return instance;
}

void GradeManager::insertGrade(StudentGrade grade)
{
	grades->push_back(std::shared_ptr<StudentGrade>(new StudentGrade(grade)));
}

void GradeManager::deleteGrade(std::string studentId)
{
	std::vector<std::shared_ptr<StudentGrade>>::iterator begin = grades->begin();
	while (begin != grades->end())
	{
		if ((*begin)->studentId == studentId)
		{
			grades->erase(begin);
			break;
		}
		++begin;
	}
}

void GradeManager::updateGrade(StudentGrade grade)
{
	std::vector<std::shared_ptr<StudentGrade>>::iterator begin = grades->begin();
	while (begin != grades->end())
	{
		if ((*begin)->studentId == grade.studentId)
		{
			grades->insert(grades->erase(begin),std::shared_ptr<StudentGrade>(new StudentGrade(grade)));
			break;
		}
		++begin;
	}
}

std::vector<StudentGrade> GradeManager::queryGrade(std::string studentIdOrName) const
{
	std::vector<StudentGrade> result;
	auto begin = grades->begin();
	while (begin != grades->end())
	{
		if (studentIdOrName == "")
		{
			result.push_back(**begin);
		}
		else
		{
			if ((*begin)->studentName == studentIdOrName)
			{
				result.push_back(**begin);
			}
			if ((*begin)->studentId == studentIdOrName)
			{
				result.clear();
				result.push_back(**begin);
				break;
			}
		}	
		++begin;
	}
	return result;

}

GradeManager::GradeManager()
{
	grades = std::make_shared<std::vector<std::shared_ptr<StudentGrade>>>();

}

GradeManager::~GradeManager()
{
}
