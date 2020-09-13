#pragma once
#include <string>
#include <vector>
#include "Student.h"
using namespace std;

class Course
{
private:
	string name;
	vector<Student*> studentlist;
public:
	Course(string name_) { name = name_; }
	~Course() {};
	string getName() { return name; }
	void addStudent(Student* stu) { studentlist.push_back(stu); }
	int getNum() { return studentlist.size(); }
	double averPoints();
	void deleteStudent(Student* stu);
	void display();
	void display(string filename);
};


