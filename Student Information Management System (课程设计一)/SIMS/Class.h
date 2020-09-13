#pragma once
#include <string>
#include <vector>
#include "Student.h"
using namespace std;

class Class
{
private:
	int number;
	vector<Student*> studentlist;
public:
	Class(int nu) { number = nu; }
	~Class() {};
	int getNumber() { return number; }
	void addStudent(Student* stu) { studentlist.push_back(stu); }
	void deleteStudent(Student* stu);
	void display();
	void display(string filename);
};

