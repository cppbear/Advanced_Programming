#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "ClassList.h"
#include "CourseList.h"
#include "DepartmentList.h"
#include "StudentList.h"
using namespace std;

class Interface
{
private:
	void addStudent(StudentList& stulist, DepartmentList& departlist, ClassList& classlist, CourseList& courselist);
	void deleteStudent(StudentList& stulist, DepartmentList& departlist, ClassList& classlist, CourseList& courselist);
	void searchStudent(StudentList& stulist);
	void modifyStudent(StudentList& stulist, DepartmentList& departlist, ClassList& classlist, CourseList& courselist);
	void display(DepartmentList& departlist, ClassList& classlist, CourseList& courselist,int choice);
	void writeToFile(StudentList& stulist);
	int* readFromFile(StudentList& stulist, DepartmentList& departlist, ClassList& classlist, CourseList& courselist);
	int menuForAdd(StudentList& stulist, DepartmentList& departlist, ClassList& classlist, CourseList& courselist);
	int menuForDelete(StudentList& stulist, DepartmentList& departlist, ClassList& classlist, CourseList& courselist);
	int menuForSearch(StudentList& stulist);
	int menuForModify(StudentList& stulist, DepartmentList& departlist, ClassList& classlist, CourseList& courselist);
	int menuForDisplay(DepartmentList& departlist, ClassList& classlist, CourseList& courselist);
	int menuForWTF(StudentList& stulist);
	int menuForRFF(StudentList& stulist, DepartmentList& departlist, ClassList& classlist, CourseList& courselist);
	int mainMenu(StudentList& stulist, DepartmentList& departlist, ClassList& classlist, CourseList& courselist);
public:
	Interface() {}
	~Interface() {}
	int run();
};
