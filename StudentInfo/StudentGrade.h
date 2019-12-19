#ifndef STUDENT_GRADE_H_
#define STUDENT_GRADE_H_
#include <string>
using std::string;
class StudentGrade
{
    public:
    
    string studentId;
    string studentName;
    double china;
    double math;
    double eng;
    
	StudentGrade() = default;
    StudentGrade(string studentId,string studentName,double china,double math,double eng,double pe)
        :studentId(studentId),studentName(studentName),china(china),math(math),eng(eng){}
    
};
#endif