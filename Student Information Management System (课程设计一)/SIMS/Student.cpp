#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"

void Student::print()
{
	cout << "学号\t姓名\t院系\t班级\n";
	cout << ID << '\t' << name << '\t' << depart << '\t' << Class << endl;
	cout << "\n课程\t分数\n";
	for (int i = 0; i < courses.size(); i++)
	{
		cout << courses[i].name << "\t" << courses[i].points << endl;
	}
}

void Student::print(string filename)
{
	ofstream fout;
	fout.open(filename, ios::app);
	auto t = chrono::system_clock::to_time_t(chrono::system_clock::now());
	fout << put_time(localtime(&t), "%Y-%m-%d %X") << endl;
	fout << ">----------------------------------------------------<\n";
	fout << "学号\t姓名\t院系\t班级" << endl;
	fout << ID << '\t' << name << '\t' << depart << '\t' << Class << endl;
	fout << "\n课程\t分数" << endl;
	for (int i = 0; i < courses.size(); i++)
	{
		fout << courses[i].name << "\t" << courses[i].points << endl;
	}
	fout.close();
}

void Student::writeToFile(string filename)
{
	ofstream fout;
	fout.open(filename, ios::app);
	fout << "<--------------------------------------------------->\n";
	fout << ID << '\t' << name << '\t' << depart << '\t' << Class << endl;
	for (int i = 0; i < courses.size(); i++)
	{
		fout << courses[i].name << "  " << courses[i].points << endl;
	}
	//fout << "<--------------------------------------------------->\n";
	fout.close();
}

void Student::displayDepart()
{
	cout << ID << '\t' << name << '\t' << Class << endl;
}

void Student::displayClass()
{
	cout << ID << '\t' << name << '\t' << depart << endl;
}

void Student::displayCourse(string cou)
{
	cout << ID << '\t' << name << '\t' << depart << '\t' << Class << '\t';
	for (int i = 0; i < courses.size(); i++)
	{
		if (courses[i].name == cou)
		{
			cout << courses[i].points << endl;
			break;
		}
	}
}

void Student::displayDepart(string filename)
{
	ofstream fout;
	fout.open(filename, ios::app);
	fout << ID << '\t' << name << '\t' << Class << endl;
	fout.close();
}

void Student::displayClass(string filename)
{
	ofstream fout;
	fout.open(filename, ios::app);
	fout << ID << '\t' << name << '\t' << depart << endl;
	fout.close();
}

void Student::displayCourse(string cou, string filename)
{
	ofstream fout;
	fout.open(filename, ios::app);
	fout << ID << '\t' << name << '\t' << depart << '\t' << Class << '\t';
	for (int i = 0; i < courses.size(); i++)
	{
		if (courses[i].name == cou)
		{
			fout << courses[i].points << endl;
			break;
		}
	}
	fout.close();
}

double Student::getPoints(string couname)
{
	for (int i = 0; i < courses.size(); i++)
		if (courses[i].name == couname)
			return (double)courses[i].points;
}
