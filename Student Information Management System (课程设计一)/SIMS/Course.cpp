#define _CRT_SECURE_NO_WARNINGS
#include "Course.h"

double Course::averPoints()
{
	double sum = 0.0;
	int n = studentlist.size();
	for (int i = 0; i < n; i++)
	{
		sum += studentlist[i]->getPoints(name);
	}
	return sum / (double)n;
}

void Course::deleteStudent(Student* stu)
{
	for (int i = 0; i < studentlist.size(); i++)
	{
		if (studentlist[i] == stu)
		{
			studentlist.erase(studentlist.begin() + i);
			return;
		}
	}
}

void Course::display()
{
	for (int i = 0; i < studentlist.size(); i++)
	{
		studentlist[i]->displayCourse(name);
	}
}

void Course::display(string filename)
{
	ofstream fout;
	fout.open(filename, ios::app);
	auto t = chrono::system_clock::to_time_t(chrono::system_clock::now());
	fout << put_time(localtime(&t), "%Y-%m-%d %X") << endl;
	fout << "学号\t姓名\t院系\t班级\t分数\n";
	fout.close();
	for (int i = 0; i < studentlist.size(); i++)
	{
		studentlist[i]->displayCourse(name, filename);
	}
}
