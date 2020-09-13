#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <chrono>
#include <ctime>
#include <iomanip>
#include "color.h"
using namespace std;

struct course
{
	string name;
	//double points;
	int points;
};

class Student
{
private:
	int ID;
	string name;
	string depart;
	int Class;
	vector<course> courses;

public:
	//Student() {}
	Student(int id, string name_, string dep, int cla, vector<course> cou);
	~Student() {};
	int getID() { return ID; }
	string getName() { return name; }
	string getDepart() { return depart; }
	int getClass() { return Class; }
	vector<course>& getCourse() { return courses; }
	void changeClass(int num) { Class = num; }
	void changeDepart(string dep) { depart = dep; }
	void changeID(int id) { ID = id; }
	void changeName(string na) { name = na; }
	void changeCourses(vector<course> cou) { courses = cou; }
	void print();
	void print(string filename);
	void writeToFile(string filename);
	void displayDepart();
	void displayClass();
	void displayCourse(string cou);
	void displayDepart(string filename);
	void displayClass(string filename);
	void displayCourse(string cou, string filename);
	double getPoints(string couname);
};

inline Student::Student(int id, string name_, string dep, int cla, vector<course> cou)
{
	ID = id;
	name = name_;
	depart = dep;
	Class = cla;
	courses = cou;
}
