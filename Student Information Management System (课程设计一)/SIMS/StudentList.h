#pragma once
#include "Student.h"

class StudentList
{
private:
	list<Student> studentlist;
	
public:
	StudentList() {};
	~StudentList() {};
	Student* addStudent(int id, string name_, string dep, int cla, vector<course> cou);
	list<Student>::iterator searchIter(int stuid);
	//Student* searchPointer(int stuid);
	void deleteStudent(list<Student>::iterator iter);
	void print(list<Student>::iterator iter);
	void print(list<Student>::iterator iter, string filename);
	void writeAllToFile(string filename);
	//void modify(list<Student>::iterator iter, int sw);
	void changeID(list<Student>::iterator iter, int id);
	void changeName(list<Student>::iterator iter, string na);
	list<Student>::iterator getEnd() { return studentlist.end(); }
};

/*
StudentList::StudentList()
{
}
*/