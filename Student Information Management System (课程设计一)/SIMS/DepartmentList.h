#pragma once
#include <string>
#include <vector>
#include "Department.h"
#include "Student.h"
using namespace std;

class DepartmentList
{
private:
	//vector<Student> studentlist;
	vector<Department> departlist;
public:
	DepartmentList() {};
	~DepartmentList() {};
	void addStudent(Student* stu);
	void deleteStudent(Student* stu);
	void modify(Student* stu, string dep);
	void display(string depart);
};

