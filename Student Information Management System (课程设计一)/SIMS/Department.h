#pragma once
#include <string>
#include <vector>
#include "Student.h"
using namespace std;

class Department
{
private:
	string name;
	vector<Student*> studentlist;
public:
	Department(string name_) { name = name_; }
	~Department() {};
	string getName() { return name; }
	void addStudent(Student* stu) { studentlist.push_back(stu); }
	void deleteStudent(Student* stu);
	void display();
	void display(string filename);
};


