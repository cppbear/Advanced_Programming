#pragma once
#include <string>
#include <vector>
#include "Course.h"
#include "Student.h"
using namespace std;

class CourseList
{
private:
	//vector<Student> studentlist;
	vector<Course> courselist;
public:
	CourseList() {};
	~CourseList() {};
	void addStudent(Student* stu);
	void deleteStudent(Student* stu);
	void modify(Student* stu, vector<course> cou);
	void display(string cou);
	void printInfor(string name);
};

