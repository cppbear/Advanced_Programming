#include "DepartmentList.h"

void DepartmentList::addStudent(Student* stu)
{
	string depart = stu->getDepart();
	int i;
	for (i = 0; i < departlist.size(); i++)
	{
		if (departlist[i].getName() == depart)
		{
			departlist[i].addStudent(stu);
			break;
		}
	}
	if (i == departlist.size())
	{
		Department newdepart(depart);
		newdepart.addStudent(stu);
		departlist.push_back(newdepart);
	}
}

void DepartmentList::deleteStudent(Student* stu)
{
	for (int i = 0; i < departlist.size(); i++)
	{
		if (departlist[i].getName() == stu->getDepart())
		{
			departlist[i].deleteStudent(stu);
			return;
		}
	}
}

void DepartmentList::modify(Student* stu, string dep)
{
	deleteStudent(stu);
	stu->changeDepart(dep);
	addStudent(stu);
}

void DepartmentList::display(string depart)
{
	int i;
	for (i = 0; i < departlist.size(); i++)
	{
		if (departlist[i].getName() == depart)
		{
			departlist[i].display();
			cout << "\nDo you want to save the result to file[N/y]: ";
			string choice;
			getline(cin, choice);
			if (choice == "y")
			{
				cout << "Please enter the name of the file: ";
				string filename;
				getline(cin, filename);
				departlist[i].display(filename);
				GREEN;
				cout << "Result has been written to the file";
				RESET;
				Sleep(1500);
			}
			return;
		}
	}
	if (i == departlist.size())
	{
		RED;
		cout << "There is no such department!\n";
		RESET;
		Sleep(1500);
	}
}
