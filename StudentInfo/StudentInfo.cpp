#include "stdafx.h"
#include "StudentManager.h"
#include "Util.h"
#include "ClearStackException.h"
#include "GradeManager.h"

void printMainMenu()
{
	std::cout << "<<------------------------------------->>" << std::endl;
	std::cout << std::endl
		<< std::endl;
	std::cout << "                学生信息系统        " << std::endl;
	std::cout << "           输入'i'可进行添加相关操使       " << std::endl;
	std::cout << "           输入'd'可进行删除相关操使       " << std::endl;
	std::cout << "           输入'u'可进行更新相关操使       " << std::endl;
	std::cout << "           输入'q'可进行查询相关操使       " << std::endl;
	std::cout << "           输入'quit'可退出程序       " << std::endl;
	std::cout << std::endl
		<< std::endl;
	std::cout << "<<------------------------------------->>" << std::endl;
}

bool getStudentfromLine(Student &student, std::string line)
{
	std::vector<std::string> studentInfos;

	int pos;
	while ((pos = line.find(" ", 0)) != -1)
	{
		string tmp = line.substr(0, pos);
		line = line.substr(pos + 1, line.length() - pos - 1);
		studentInfos.push_back(tmp);
	}
	studentInfos.push_back(line);
	if (studentInfos.size() == 5 && Util::isVaildSexInput(studentInfos[2]))
	{

		student.studentId = studentInfos[0];
		student.studentName = studentInfos[1];
		if (studentInfos[2] == "男")
		{
			student.sex = '1';
		}
		else if (studentInfos[2] == "女")
		{
			student.sex = '0';
		}

		student.age = std::stoi(studentInfos[3], 0);
		student.className = studentInfos[4];
		return true;
	}
	return false;
}

bool getGradefromLine(StudentGrade & grade,std::string line)
{
	std::vector<std::string> studentInfos;

	int pos;
	while ((pos = line.find(" ", 0)) != -1)
	{
		string tmp = line.substr(0, pos);
		line = line.substr(pos + 1, line.length() - pos - 1);
		studentInfos.push_back(tmp);
	}
	studentInfos.push_back(line);
	if (studentInfos.size() == 5 && StudentManager::getInstance()->isVaildStudentId(studentInfos[0]))
	{
		grade.studentId = studentInfos[0];
		grade.studentName = studentInfos[1]; 
		grade.china = std::stod(studentInfos[2]);
		grade.math = std::stod(studentInfos[3]);
		grade.eng = std::stod(studentInfos[4]);
		return true;
	}
	return false;
}
int waitIDUQCmd(const char *cmdName)
{
	char flag = std::getchar();
	std::getchar();
	if (flag == '0')
	{
		throw ClearStackException("toMain");
	}
	if (flag == '1')
	{
		if (std::strcmp("插入", cmdName) == 0)
		{
			Student student;
			std::cout << "请依次输入学生id、姓名、性别(男/女)、年龄、班级按空格分隔" << std::endl;
			bool isCorrectInput = false;
			while (!isCorrectInput)
			{
				try
				{
					std::cout << "请按格式输入" << std::endl;
					string line;
					std::getline(std::cin, line);
					isCorrectInput = getStudentfromLine(student, line);
				}
				catch (const std::exception &e)
				{
					std::cerr << e.what() << '\n';
				}
			}

			bool success = StudentManager::getInstance()->insertStudent(student);
			if (success)
			{
				Log("插入成功\n");
				throw ClearStackException("toMain");
			}
			else
			{
				Log("插入失败\n");
				throw ClearStackException("toMain");
			}
		}
		else if (std::strcmp("删除", cmdName) == 0)
		{
			std::cout << "请输入学生id" << std::endl;
			string studentId;
			std::getline(std::cin, studentId);
			GradeManager::getInstance().deleteGrade(studentId);
			bool success = StudentManager::getInstance()->deleteStudent(studentId);
			if (success)
			{
				Log("删除成功\n");
				throw ClearStackException("toDelete");
			}
			else
			{
				Log("删除成功\n");
				throw ClearStackException("toMain");
			}
		}
		else if (std::strcmp("更新", cmdName) == 0)
		{
			Student student;
			std::cout << "请依次输入学生id、姓名、性别(男/女)、年龄、班级按空格分隔" << std::endl;
			bool isCorrectInput = false;
			while (!isCorrectInput)
			{
				try
				{
					std::cout << "请按格式输入" << std::endl;
					string line;
					std::getline(std::cin, line);
					isCorrectInput = getStudentfromLine(student, line);
				}
				catch (const std::exception &e)
				{
					std::cerr << e.what() << '\n';
				}
			}

			bool success = StudentManager::getInstance()->updateStudent(student);
			if (success)
			{
				Log("更新成功\n");
				throw ClearStackException("toMain");
			}
			else
			{
				Log("更新失败\n");
				throw ClearStackException("toMain");
			}
		}
		else if (std::strcmp("查询", cmdName) == 0)
		{
			std::cout << "请输入id或者姓名（'all'查询所有）" << std::endl;
			string query;
			std::getline(std::cin, query);
			std::vector<Student> result;
			if (query == "all")
			{
				result = StudentManager::getInstance()->queryStudent("");
			}
			else
			{
				result = StudentManager::getInstance()->queryStudent(query);
			}
			for (auto & student : result)
			{
				std::cout << student.studentId << std::ends << student.studentName << std::ends
					<< Util::sexTrans(student.sex) << std::ends << student.age << std::ends << student.className << std::endl;
			}
			throw ClearStackException("toMain");

		}
	}
	else if (flag == '2')
	{
		if (std::strcmp("插入", cmdName) == 0)
		{
			StudentGrade grade;
			std::cout << "请依次输入学生id、姓名、语文、数学、英语按空格分隔" << std::endl;
			bool isCorrectInput = false;
			while (!isCorrectInput)
			{
				try
				{
					std::cout << "请按格式输入" << std::endl;
					string line;
					std::getline(std::cin, line);
					isCorrectInput = getGradefromLine(grade, line);
				}
				catch (const std::exception &e)
				{
					std::cerr << e.what() << '\n';
				}
			}
			GradeManager::getInstance().insertGrade(grade);

			Log("插入成功\n");
			throw ClearStackException("toMain");


		}
		else if (std::strcmp("删除", cmdName) == 0)
		{
			std::cout << "请输入学生id" << std::endl;
			string studentId;
			std::getline(std::cin, studentId);
			GradeManager::getInstance().deleteGrade(studentId);
			Log("删除成功");
			throw ClearStackException("toMain");
		}
		else if (std::strcmp("更新", cmdName) == 0)
		{
			StudentGrade grade;
			std::cout << "请依次输入学生id、姓名、语文、数学、英语按空格分隔" << std::endl;
			bool isCorrectInput = false;
			while (!isCorrectInput)
			{
				try
				{
					std::cout << "请按格式输入" << std::endl;
					string line;
					std::getline(std::cin, line);
					isCorrectInput = getGradefromLine(grade, line);
				}
				catch (const std::exception &e)
				{
					std::cerr << e.what() << '\n';
				}
			}
			GradeManager::getInstance().updateGrade(grade);

			Log("更新成功\n");
			throw ClearStackException("toMain");
		}
		else if (std::strcmp("查询", cmdName) == 0)
		{
			std::cout << "请输入id或者姓名（'all'查询所有）" << std::endl;
			string query;
			std::getline(std::cin, query);
			std::vector<StudentGrade> result;
			if (query == "all")
			{
				result = GradeManager::getInstance().queryGrade("");
			}
			else
			{
				result = GradeManager::getInstance().queryGrade(query);
			}
			for (auto & student : result)
			{
				std::cout << student.studentId << std::ends << student.studentName << std::ends
					<< student.china << std::ends << student.math << std::ends << student.eng << std::endl;
			}
			throw ClearStackException("toMain");
		}
	}
	else
	{
		std::cout << "请输入正确的指令" << std::endl;
		return 1;
	}

	return 0;
}
void showIDUQMenu(const char *cmdName)
{
	std::cout << "<<------------------------------------->>" << std::endl;
	std::cout << std::endl
		<< std::endl;
	std::cout << "                " << cmdName << "菜单        " << std::endl;
	std::cout << "           输入'1'可" << cmdName << "学生信息       " << std::endl;
	std::cout << "           输入'2'可" << cmdName << "成绩       " << std::endl;
	std::cout << "           输入'0'可返回主菜单       " << std::endl;
	std::cout << std::endl
		<< std::endl;
	std::cout << "<<------------------------------------->>" << std::endl;
	while (waitIDUQCmd(cmdName))
	{
	}
}
bool isQuit = false;
int waitMainCmd()
{
	static char mainCmd[5];
	std::cin.getline(mainCmd, 5);
	if (std::strcmp("i", mainCmd) == 0)
	{
		showIDUQMenu("插入");
	}
	else if (std::strcmp("d", mainCmd) == 0)
	{
		showIDUQMenu("删除");
	}
	else if (std::strcmp("u", mainCmd) == 0)
	{
		showIDUQMenu("更新");
	}
	else if (std::strcmp("q", mainCmd) == 0)
	{
		showIDUQMenu("查询");
	}
	else if (std::strcmp("quit", mainCmd) == 0)
	{
		isQuit = true;
	}
	else
	{
		std::cout << "请输入正确的指令" << std::endl;
		return 1;
	}
	return 0;
}
void init()
{
	printMainMenu();
	while (waitMainCmd())
	{
	}
}

int main(int args, char *argv[])
{

	while (!isQuit)
	{
		try
		{
			init();
		}
		catch (const std::exception &e)
		{
			if (e.what() == std::string("toMain"))
			{
				isQuit = false;
			}
		}
	}


	return 0;
}

