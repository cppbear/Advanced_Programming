#define _CRT_SECURE_NO_WARNINGS
#include "CourseList.h"

void CourseList::addStudent(Student* stu)
{
	vector<course> courses = stu->getCourse();
	for (int i = 0; i < courses.size(); i++)
	{
		int j;
		for (j = 0; j < courselist.size(); j++)
		{
			if (courselist[j].getName() == courses[i].name)
			{
				courselist[j].addStudent(stu);
				break;
			}
		}
		if (j == courselist.size())
		{
			Course newcourse(courses[i].name);
			newcourse.addStudent(stu);
			courselist.push_back(newcourse);
		}
	}
}

void CourseList::deleteStudent(Student* stu)
{
	vector<course> temp = stu->getCourse();
	for (int i = 0; i < courselist.size(); i++)
	{
		for (int j = 0; j < temp.size(); j++)
		{
			if (courselist[i].getName() == temp[j].name)
			{
				courselist[i].deleteStudent(stu);
				temp.erase(temp.begin() + j);
				break;
			}
		}
	}
}

void CourseList::modify(Student* stu, vector<course> cou)
{
	deleteStudent(stu);
	stu->changeCourses(cou);
	addStudent(stu);
}

void CourseList::display(string cou)
{
	int i;
	for (i = 0; i < courselist.size(); i++)
	{
		if (courselist[i].getName() == cou)
		{
			courselist[i].display();
			cout << "\nDo you want to save the result to file[N/y]: ";
			string choice;
			getline(cin, choice);
			if (choice == "y")
			{
				cout << "Please enter the name of the file: ";
				string filename;
				getline(cin, filename);
				courselist[i].display(filename);
				GREEN;
				cout << "Result has been written to the file";
				RESET;
				Sleep(1500);
			}
			return;
		}
	}
	if (i == courselist.size())
	{
		RED;
		cout << "There is no such course!";
		RESET;
		Sleep(1500);
	}
}

void CourseList::printInfor(string name)
{
	int i;
	for (i = 0; i < courselist.size(); i++)
	{
		if (courselist[i].getName() == name)
		{
			cout << "选修人数：" << courselist[i].getNum() << ", 平均成绩：" << courselist[i].averPoints() << endl;
			cout << "\nDo you want to save the result to file[N/y]: ";
			string choice;
			getline(cin, choice);
			if (choice == "y")
			{
				cout << "Please enter the name of the file: ";
				string filename;
				getline(cin, filename);
				ofstream fout;
				fout.open(filename, ios::app);
				auto t = chrono::system_clock::to_time_t(chrono::system_clock::now());
				fout << put_time(localtime(&t), "%Y-%m-%d %X") << endl;
				fout << name << "\t" << "选修人数：" << courselist[i].getNum() << ", 平均成绩：" << courselist[i].averPoints() << endl;
				fout.close();
				GREEN;
				cout << "Result has been written to the file";
				RESET;
				Sleep(1500);
			}
			return;
		}
	}
	if (i == courselist.size())
	{
		RED;
		cout << "There is no such course!";
		RESET;
		Sleep(1500);
	}
}
