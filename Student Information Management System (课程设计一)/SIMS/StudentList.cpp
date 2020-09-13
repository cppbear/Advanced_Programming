#include "StudentList.h"

Student* StudentList::addStudent(int id, string name_, string dep, int cla, vector<course> cou)
{
	Student newstu(id, name_, dep, cla, cou);
	studentlist.push_back(newstu);
	return &studentlist.back();
}

list<Student>::iterator StudentList::searchIter(int stuid)
{
	list<Student>::iterator iter = studentlist.begin();
	while (iter != studentlist.end())
	{
		if (iter->getID() == stuid)
		{
			return iter;
		}
		else
			iter++;
	}
	if (iter == studentlist.end())
	{
		return studentlist.end();
	}
}


void StudentList::deleteStudent(list<Student>::iterator iter)
{
	//list<Student>::iterator iter = searchIter(stuid);
	if (iter != studentlist.end())
	{
		studentlist.erase(iter);
		GREEN;
		cout << "This student has been deleted successfully!\n";
		RESET;
	}
	else
	{
		RED;
		cout << "Delete falied!\n";
		RESET;
	}
}

void StudentList::print(list<Student>::iterator iter)
{
	//list<Student>::iterator iter = searchIter(stuid);
	if (iter != studentlist.end())
	{
		//cout << GREEN << "The student has been found successfully!\n" << RESET;
		iter->print();
	}
}

void StudentList::print(list<Student>::iterator iter, string filename)
{
	//list<Student>::iterator iter = searchIter(stuid);
	if (iter != studentlist.end())
	{
		//cout << GREEN << "The student has been found successfully!\n" << RESET;
		iter->print(filename);
	}
}

void StudentList::writeAllToFile(string filename)
{
	list<Student>::iterator iter;
	for (iter = studentlist.begin(); iter != studentlist.end(); iter++)
		iter->writeToFile(filename);
}

/*
void StudentList::modify(list<Student>::iterator iter, int sw)
{
	//list<Student>::iterator iter = searchIter(stuid);
	if (iter != studentlist.end())
	{
		//cout << GREEN << "This student has been found successfully!\n" << RESET;
		//iter->print();
		//TODO: choose the iterm(s) and modify
		
	}
	else
		cout << RED << "Modify falied!\n" << RESET;
}
*/

void StudentList::changeID(list<Student>::iterator iter, int id)
{
	iter->changeID(id);
	GREEN;
	cout << "Change ID successfully!\n";
	RESET;
}

void StudentList::changeName(list<Student>::iterator iter, string na)
{
	iter->changeName(na);
	GREEN;
	cout << "Change name successfully!\n";
	RESET;
}
