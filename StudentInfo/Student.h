#ifndef STUDENT_H_
#define STUDENT_H_
#include <string>
using std::string;
 struct Student
{
    
    string studentId;
    string studentName;
    char sex;
    unsigned int age;
    string className;
    Student() =default;
    Student(string id,string name,char s,unsigned int a,string cN)
        :studentId(id),studentName(name),sex(s),age(a),className(cN){}
    ~Student() =default;
};

#endif