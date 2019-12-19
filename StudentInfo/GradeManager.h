#ifndef GRADE_MANAGER_H_
#define GRADE_MANAGER_H_
#include "stdafx.h"
#include "StudentGrade.h"
#include <memory>
class GradeManager
{
public:
	
	static GradeManager & getInstance();

	void insertGrade(StudentGrade);
	void deleteGrade(std::string studentId);
	void updateGrade(StudentGrade);
	std::vector<StudentGrade> queryGrade(std::string studentIdOrName) const;
	
private:
	
	GradeManager & operator=(const GradeManager &) = delete;
	GradeManager(const GradeManager &) = delete;
	GradeManager();
	~GradeManager();
	std::shared_ptr<std::vector<std::shared_ptr<StudentGrade>>> grades;
};




#endif GRADE_MANAGER_H_
