#define _CRT_SECURE_NO_WARNINGS
#include "Department.h"

void Department::deleteStudent(Student* stu)
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

void Department::display()
{
	cout << "学号\t姓名\t班级\n";
	for (int i = 0; i < studentlist.size(); i++)
	{
		studentlist[i]->displayDepart();
	}
}

void Department::display(string filename)
{
	ofstream fout;
	fout.open(filename, ios::app);
	auto t = chrono::system_clock::to_time_t(chrono::system_clock::now());
	fout << put_time(localtime(&t), "%Y-%m-%d %X") << endl;
	fout << "学号\t姓名\t班级\n";
	fout.close();
	for (int i = 0; i < studentlist.size(); i++)
	{
		studentlist[i]->displayDepart(filename);
	}
}
