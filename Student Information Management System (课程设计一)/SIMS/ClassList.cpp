#include "ClassList.h"

void ClassList::addStudent(Student* stu)
{
	int number = stu->getClass();
	int i;
	for (i = 0; i < classlist.size(); i++)
	{
		if (classlist[i].getNumber() == number)
		{
			classlist[i].addStudent(stu);
			break;
		}
	}
	if (i == classlist.size())
	{
		Class newclass(number);
		newclass.addStudent(stu);
		classlist.push_back(newclass);
	}
}

void ClassList::deleteStudent(Student* stu)
{
	for (int i = 0; i < classlist.size(); i++)
	{
		if (classlist[i].getNumber() == stu->getClass())
		{
			classlist[i].deleteStudent(stu);
			return;
		}
	}
}

void ClassList::modify(Student* stu, int num)
{
	deleteStudent(stu);
	stu->changeClass(num);
	addStudent(stu);
}

void ClassList::display(int num)
{
	int i;
	for (i = 0; i < classlist.size(); i++)
	{
		if (classlist[i].getNumber() == num)
		{
			classlist[i].display();
			cout << "\nDo you want to save the result to file[N/y]: ";
			string choice;
			getline(cin, choice);
			if (choice == "y")
			{
				cout << "Please enter the name of the file: ";
				string filename;
				getline(cin, filename);
				classlist[i].display(filename);
				GREEN;
				cout << "Result has been written to the file";
				RESET;
				Sleep(1500);
			}
			return;
		}
	}
	if (i == classlist.size())
	{
		RED;
		cout << "There is no such class!\n";
		RESET;
		Sleep(1500);
	}
}
