#pragma once
#include <string>
#include <vector>
#include "Class.h"
#include "Student.h"
using namespace std;

class ClassList
{
private:
	vector<Class> classlist;
public:
	ClassList() {};
	~ClassList() {};
	void addStudent(Student* stu);
	void deleteStudent(Student* stu);
	void modify(Student* stu, int num);
	void display(int num);
};

