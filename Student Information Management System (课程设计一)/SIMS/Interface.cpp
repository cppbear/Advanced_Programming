#include "Interface.h"

void Interface::addStudent(StudentList& stulist, DepartmentList& departlist, ClassList& classlist, CourseList& courselist)
{
	string tempid, name, depart, tempClass;
	cout << "Please enter the student's ID, name, department and class ";
	RED;
	cout << "in a line ";
	RESET;
	cout <<": \n";
	cin >> tempid >> name >> depart >> tempClass;
	cin.ignore(INT_MAX, '\n');
	int id = atoi(tempid.c_str());
	int Class = atoi(tempClass.c_str());
	while (to_string(id) != tempid || to_string(Class) != tempClass )
	{
		RED;
		cout << "Invalid input!\n";
		RESET;
		cout << "Try again:\n";
		cin >> tempid >> name >> depart >> tempClass;
		cin.ignore(INT_MAX, '\n');
		id = atoi(tempid.c_str());
		Class = atoi(tempClass.c_str());
	}
	cout << "The number of the course(s): ";
	string tempnum;
	getline(cin, tempnum);
	int num = atoi(tempnum.c_str());
	while (to_string(num) != tempnum)
	{
		RED;
		cout << "Invalid input!\n";
		RESET;
		cout << "Try again:\n";
		cin >> tempnum;
		getline(cin, tempnum);
		num = atoi(tempnum.c_str());
	}
	cout << "Please enter the course(s) and points(each course one line):\n";
	vector<course> cou;
	for (int i = 0; i < num; i++)
	{
		course temp;
		cin >> temp.name;
		string temppoints;
		cin >> temppoints;
		cin.ignore(INT_MAX, '\n');
		//temp.points = atof(temppoints.c_str());
		temp.points = atoi(temppoints.c_str());
		//string h = to_string(temp.points);
		while (to_string(temp.points) != temppoints)
		{
			RED;
			cout << "Invalid points!\n";
			RESET;
			cout << "Try again: ";
			cin >> temppoints;
			cin.ignore(INT_MAX, '\n');
			//temp.points = atof(temppoints.c_str());
			temp.points = atoi(temppoints.c_str());
		}
		cou.push_back(temp);
	}
	//cin.get();
	list<Student>::iterator iter = stulist.searchIter(id);
	if (iter == stulist.getEnd())
	{
		Student* p = stulist.addStudent(id, name, depart, Class, cou);
		departlist.addStudent(p);
		classlist.addStudent(p);
		courselist.addStudent(p);
		GREEN;
		cout << "The student has been added succesfully!";
		RESET;
	}
	else
	{
		RED;
		cout << "The student has already exist!\nOperation failed!";
		RESET;
	}
}

void Interface::deleteStudent(StudentList& stulist, DepartmentList& departlist, ClassList& classlist, CourseList& courselist)
{
	string tempid;
	int id;
	cout << "Please enter the student's ID: ";
	getline(cin, tempid);
	id = atoi(tempid.c_str());
	while (to_string(id) != tempid)
	{
		RED;
		cout << "Invalid input!\n";
		RESET;
		cout << "Try again: ";
		getline(cin, tempid);
		id = atoi(tempid.c_str());
	}
	list<Student>::iterator iter = stulist.searchIter(id);
	if (iter != stulist.getEnd())
	{
		Student* p = &*iter;
		departlist.deleteStudent(p);
		classlist.deleteStudent(p);
		courselist.deleteStudent(p);
		stulist.deleteStudent(iter);
		GREEN;
		cout << "Delete succesfully!";
		RESET;
	}
	else
	{
		RED;
		cout << "There is no such student!\nOperation failed!";
		RESET;
	}
}

void Interface::searchStudent(StudentList& stulist)
{
	string tempid;
	int id;
	cout << "Please enter the student's ID: ";
	getline(cin, tempid);
	id = atoi(tempid.c_str());
	while (to_string(id) != tempid)
	{
		RED;
		cout << "Invalid input!\n";
		RESET;
		cout << "Try again: ";
		getline(cin, tempid);
		id = atoi(tempid.c_str());
	}
	list<Student>::iterator iter = stulist.searchIter(id);
	if (iter != stulist.getEnd())
	{
		stulist.print(iter);
		cout << "\nDo you want to save the result to file[N/y]: ";
		string choice;
		getline(cin, choice);
		if (choice == "y")
		{
			cout << "Please enter the name of the file: ";
			string filename;
			getline(cin, filename);
			//ofstream fout;
			//fout.open(filename, ios::app);
			stulist.print(iter, filename);
			GREEN;
			cout << "Result has been written to the file";
			RESET;
			Sleep(1500);
		}
	}
	else
	{
		RED;
		cout << "There is no such student!";
		RESET;
		Sleep(1500);
	}
}

void Interface::modifyStudent(StudentList& stulist, DepartmentList& departlist, ClassList& classlist, CourseList& courselist)
{
	string tempid;
	int id;
	cout << "Please enter the student's ID: ";
	getline(cin, tempid);
	id = atoi(tempid.c_str());
	while (to_string(id) != tempid)
	{
		RED;
		cout << "Invalid ID!\n";
		RESET;
		cout << "Try again: ";
		getline(cin, tempid);
		id = atoi(tempid.c_str());
	}
	list<Student>::iterator iter = stulist.searchIter(id);
	if (iter != stulist.getEnd())
	{
		Student* p = &*iter;
		stulist.print(iter);
		RED;
		cout << "Do you really want to change the information?[NO/yes] ";
		RESET;
		string flag;
		getline(cin, flag);
		if (flag == "yes")
		{
			//cin.get();
			bool run = true;
			while (run)
			{
				system("cls");
				cout << "\t\t\t    Student Information Management System--Modify\n";
				cout << "\t\t\t_____________________________________________________\n";
				cout << "\t\t\t|                1. 修改学号                        |\n";
				cout << "\t\t\t|                2. 修改姓名                        |\n";
				cout << "\t\t\t|                3. 修改院系                        |\n";
				cout << "\t\t\t|                4. 修改班级                        |\n";
				cout << "\t\t\t|                5. 修改课程                        |\n";
				cout << "\t\t\t|                0. 退出功能                        |\n";
				cout << "\t\t\t-----------------------------------------------------\n";
				cout << "Please choose the iterm you want to change, one each time: ";
				string temp;
				getline(cin, temp);
				int choice = atoi(temp.c_str());
				while (to_string(choice) != temp || (to_string(choice) == temp && (choice < 0 || choice > 5)))
				{
					RED;
					cout << "Invalid input!\n";
					RESET;
					cout << "Try again: ";
					getline(cin, temp);
					choice = atoi(temp.c_str());
				}
				// modify according to the choice
				switch (choice)
				{
				case 1:
				{
					cout << "Please enter the new ID for this student: ";
					string tempnewid;
					getline(cin, tempnewid);
					int newid = atoi(tempnewid.c_str());
					while (to_string(newid) != tempnewid)
					{
						RED;
						cout << "Invalid ID!\n";
						RESET;
						cout << "Try again: ";
						getline(cin, tempnewid);
						newid = atoi(tempnewid.c_str());
					}
					iter->changeID(newid);
					GREEN;
					cout << "Modify successfully!";
					RESET;
					Sleep(1000);
					break;
				}
				case 2:
				{
					cout << "Please enter the new name for this student: ";
					string newname;
					getline(cin, newname);
					iter->changeName(newname);
					GREEN;
					cout << "Modify successfully!";
					RESET;
					Sleep(1000);
					break;
				}
				case 3:
				{
					cout << "Please enter the new department for this student: ";
					string newdepartment;
					getline(cin, newdepartment);
					departlist.modify(p, newdepartment);
					GREEN;
					cout << "Modify successfully!";
					RESET;
					Sleep(1000);
					break;
				}
				case 4:
				{
					cout << "Please enter the new class for this student: ";
					string tempnewclass;
					getline(cin, tempnewclass);
					int newclass = atoi(tempnewclass.c_str());
					while (to_string(newclass) != tempnewclass)
					{
						RED;
						cout << "Invalid class!\n";
						RESET;
						cout << "Try again: ";
						getline(cin, tempnewclass);
						newclass = atoi(tempnewclass.c_str());
					}
					classlist.modify(p, newclass);
					GREEN;
					cout << "Modify successfully!";
					RESET;
					Sleep(1000);
					break;
				}
				case 5:
				{
					cout << "Please enter the number of the course(s): ";
					string tempnum;
					getline(cin, tempnum);
					int num = atoi(tempnum.c_str());
					while (to_string(num) != tempnum)
					{
						RED;
						cout << "Invalid input!\n";
						RESET;
						cout << "Try again:\n";
						cin >> tempnum;
						getline(cin, tempnum);
						num = atoi(tempnum.c_str());
					}
					cout << "Please enter the course(s) and points(each course one line):\n";
					vector<course> newcou;
					for (int i = 0; i < num; i++)
					{
						course temp;
						cin >> temp.name;
						string temppoints;
						cin >> temppoints;
						cin.ignore(INT_MAX, '\n');
						//temp.points = atof(temppoints.c_str());
						temp.points = atoi(temppoints.c_str());
						while (to_string(temp.points) != temppoints)
						{
							RED;
							cout << "Invalid points!\n";
							RESET;
							cout << "Try again: ";
							cin >> temppoints;
							cin.ignore(INT_MAX, '\n');
							//temp.points = atof(temppoints.c_str());
							temp.points = atoi(temppoints.c_str());
						}
						newcou.push_back(temp);
					}
					courselist.modify(p, newcou);
					GREEN;
					cout << "Modify successfully!";
					RESET;
					Sleep(1000);
					break;
				}
				case 0: run = false; break;
				default:
					break;
				}
			}
		}
		else
		{
			cout << "You have cancel the modification.";
			cin.get();
			Sleep(2000);
		}
	}
	else
	{
		RED;
		cout << "There is no such student!";
		RESET;
		Sleep(2000);
	}
}

void Interface::display(DepartmentList& departlist, ClassList& classlist, CourseList& courselist, int choice)
{
	switch (choice)
	{
	case 1:
	{
		cout << "Please enter the name: ";
		string name;
		getline(cin, name);
		departlist.display(name);
		break;
	}
	case 2:
	{
		cout << "Please enter the name: ";
		string tempname;
		getline(cin, tempname);
		int name = atoi(tempname.c_str());
		while (to_string(name) != tempname)
		{
			RED;
			cout << "Invalid input!\n";
			RESET;
			cout << "Try again: ";
			getline(cin, tempname);
			name = atoi(tempname.c_str());
		}
		classlist.display(name); break;
	}
	case 3:
	{
		bool run = true;
		while (run)
		{
			system("cls");
			cout << "\t\t\t    Student Information Management System--Display\n";
			cout << "\t\t\t_____________________________________________________\n";
			cout << "\t\t\t|                1. 平均成绩、选修人数              |\n";
			cout << "\t\t\t|                2. 所有学生                        |\n";
			cout << "\t\t\t|                0. 退出功能                        |\n";
			cout << "\t\t\t-----------------------------------------------------\n";
			cout << "Please enter your choice: ";
			string temp;
			getline(cin, temp);
			int choice = atoi(temp.c_str());
			while (to_string(choice) != temp || (to_string(choice) == temp && (choice < 0 || choice > 2)))
			{
				RED;
				cout << "Invalid input!\n";
				RESET;
				cout << "Try again: ";
				getline(cin, temp);
				choice = atoi(temp.c_str());
			}
			if (choice == 0)
				run = false;
			else if (choice == 2)
			{
				cout << "Please enter the name: ";
				string name;
				getline(cin, name);
				courselist.display(name);
				//Sleep(2000);
			}
			else
			{
				cout << "Please enter the name: ";
				string name;
				getline(cin, name);
				courselist.printInfor(name);
				//Sleep(2000);
			}
		}
		break;
	}
	default:
		break;
	}
}

void Interface::writeToFile(StudentList& stulist)
{
	string filename = "StudentInformation.txt";
	cout << "Please enter the name of the file: ";
	getline(cin, filename);
	ofstream fout;
	fout.open(filename);
	fout.close();
	stulist.writeAllToFile(filename);
}

int* Interface::readFromFile(StudentList& stulist, DepartmentList& departlist, ClassList& classlist, CourseList& courselist)
{
	int *res = new int[4]();
	string filename = "StudentInformation.txt";
	cout << "Please enter the name of the file: ";
	getline(cin, filename);
	ifstream fin;
	fin.open(filename);
	if (!fin.is_open())
	{
		RED;
		cout << "File does not exist!";
		RESET;
		return res;
	}
	res[0] = 1;
	int stuid, Class;
	string name, depart;
	string temp;
	getline(fin, temp);
	while (fin.good())
	{
		fin >> stuid >> name >> depart >> Class;
		vector<course> cou;
		string couname;
		//double points;
		fin >> couname;
		while (fin.good() && couname[0] != '<')
		{
			course temp;
			temp.name = couname;
			fin >> temp.points;
			cou.push_back(temp);
			fin >> couname;
		}
		if (stulist.searchIter(stuid) == stulist.getEnd())
		{
			Student* p = stulist.addStudent(stuid, name, depart, Class, cou);
			departlist.addStudent(p);
			classlist.addStudent(p);
			courselist.addStudent(p);
			res[1]++;
		}
		else
			res[2]++;
	}
	fin.close();
	return res;
}

int Interface::menuForAdd(StudentList& stulist, DepartmentList& departlist, ClassList& classlist, CourseList& courselist)
{
	bool run = true;
	while (run)
	{
		system("cls");
		cout << "\t\t\t    Student Information Management System--Add\n";
		cout << "\t\t\t_____________________________________________________\n";
		cout << "\t\t\t|                1. 添加学生                        |\n";
		cout << "\t\t\t|                0. 退出功能                        |\n";
		cout << "\t\t\t-----------------------------------------------------\n";
		cout << "Please enter your choice: ";
		string temp;
		getline(cin, temp);
		int choice = atoi(temp.c_str());
		while (to_string(choice) != temp || (to_string(choice) == temp && (choice < 0 || choice > 1)))
		{
			RED;
			cout << "Invalid input!\n";
			RESET;
			cout << "Try again: ";
			getline(cin, temp);
			choice = atoi(temp.c_str());
		}
		if (choice == 0)
			run = false;
		else if (choice == 1)
		{
			addStudent(stulist, departlist, classlist, courselist);
			Sleep(2000);
		}
	}
	return 0;
}

int Interface::menuForDelete(StudentList& stulist, DepartmentList& departlist, ClassList& classlist, CourseList& courselist)
{
	bool run = true;
	while (run)
	{
		system("cls");
		cout << "\t\t\t    Student Information Management System--Delete\n";
		cout << "\t\t\t_____________________________________________________\n";
		cout << "\t\t\t|                1. 删除学生                        |\n";
		cout << "\t\t\t|                0. 退出功能                        |\n";
		cout << "\t\t\t-----------------------------------------------------\n";
		cout << "Please enter your choice: ";
		string temp;
		getline(cin, temp);
		int choice = atoi(temp.c_str());
		while (to_string(choice) != temp || (to_string(choice) == temp && (choice < 0 || choice > 1)))
		{
			RED;
			cout << "Invalid input!\n";
			RESET;
			cout << "Try again: ";
			getline(cin, temp);
			choice = atoi(temp.c_str());
		}
		if (choice == 0)
			run = false;
		else if (choice == 1)
		{
			deleteStudent(stulist, departlist, classlist, courselist);
			Sleep(2000);
		}
	}
	return 0;
}

int Interface::menuForSearch(StudentList& stulist)
{
	bool run = true;
	while (run)
	{
		system("cls");
		cout << "\t\t\t    Student Information Management System--Search\n";
		cout << "\t\t\t_____________________________________________________\n";
		cout << "\t\t\t|                1. 查询学生                        |\n";
		cout << "\t\t\t|                0. 退出功能                        |\n";
		cout << "\t\t\t-----------------------------------------------------\n";
		cout << "Please enter your choice: ";
		string temp;
		getline(cin, temp);
		int choice = atoi(temp.c_str());
		while (to_string(choice) != temp || (to_string(choice) == temp && (choice < 0 || choice > 1)))
		{
			RED;
			cout << "Invalid input!\n";
			RESET;
			cout << "Try again: ";
			getline(cin, temp);
			choice = atoi(temp.c_str());
		}
		if (choice == 0)
			run = false;
		else if (choice == 1)
		{
			searchStudent(stulist);
			//Sleep(2000);
		}
	}
	return 0;
}

int Interface::menuForModify(StudentList& stulist, DepartmentList& departlist, ClassList& classlist, CourseList& courselist)
{
	bool run = true;
	while (run)
	{
		system("cls");
		cout << "\t\t\t    Student Information Management System--Modify\n";
		cout << "\t\t\t_____________________________________________________\n";
		cout << "\t\t\t|                1. 修改信息                        |\n";
		cout << "\t\t\t|                0. 退出功能                        |\n";
		cout << "\t\t\t-----------------------------------------------------\n";
		cout << "Please enter your choice: ";
		string temp;
		getline(cin, temp);
		int choice = atoi(temp.c_str());
		while (to_string(choice) != temp || (to_string(choice) == temp && (choice < 0 || choice > 1)))
		{
			RED;
			cout << "Invalid input!\n";
			RESET;
			cout << "Try again: ";
			getline(cin, temp);
			choice = atoi(temp.c_str());
		}
		if (choice == 0)
			run = false;
		else if (choice == 1)
		{
			modifyStudent(stulist, departlist, classlist, courselist);
			//Sleep(2000);
		}
	}
	return 0;
}

int Interface::menuForDisplay(DepartmentList& departlist, ClassList& classlist, CourseList& courselist)
{
	bool run = true;
	while (run)
	{
		system("cls");
		cout << "\t\t\t    Student Information Management System--Display\n";
		cout << "\t\t\t_____________________________________________________\n";
		cout << "\t\t\t|                1. 显示院系                        |\n";
		cout << "\t\t\t|                2. 显示班级                        |\n";
		cout << "\t\t\t|                3. 显示课程                        |\n";
		cout << "\t\t\t|                0. 退出功能                        |\n";
		cout << "\t\t\t-----------------------------------------------------\n";
		cout << "Please enter your choice: ";
		string temp;
		getline(cin, temp);
		int choice = atoi(temp.c_str());
		while (to_string(choice) != temp || (to_string(choice) == temp && (choice < 0 || choice > 3)))
		{
			RED;
			cout << "Invalid input!\n";
			RESET;
			cout << "Try again: ";
			getline(cin, temp);
			choice = atoi(temp.c_str());
		}
		if (choice == 0)
			run = false;
		else
		{
			display(departlist, classlist, courselist, choice);
			//Sleep(2000);
		}
	}
	return 0;
}

int Interface::menuForWTF(StudentList& stulist)
{
	writeToFile(stulist);
	GREEN;
	cout << "All students' information has been written to the file";
	RESET;
	Sleep(2000);
	return 0;
}

int Interface::menuForRFF(StudentList& stulist, DepartmentList& departlist, ClassList& classlist, CourseList& courselist)
{
	int* succ = readFromFile(stulist, departlist, classlist, courselist);
	if (succ[0] == 1)
	{
		GREEN;
		cout << "All students' information has been read from the file\n";
		cout << succ[1] << " successfully, " << succ[2] << " repeatly";
		RESET;
	}
	Sleep(2000);
	return 0;
}

int Interface::mainMenu(StudentList& stulist, DepartmentList& departlist, ClassList& classlist, CourseList& courselist)
{
	CYAN;
	cout << "\t\t\t\t欢迎使用本学生信息管理系统！";
	RESET;
	Sleep(2 * 1000);
	bool run = true;
	string temp;
	while (run)
	{
		system("cls");
		cout << "\t\t\t\tStudent Information Management System\n";
		cout << "\t\t\t_____________________________________________________\n";
		cout << "\t\t\t|                1. 添加学生                        |\n";
		cout << "\t\t\t|                2. 删除学生                        |\n";
		cout << "\t\t\t|                3. 查找学生                        |\n";
		cout << "\t\t\t|                4. 修改学生信息                    |\n";
		cout << "\t\t\t|                5. 显示院系/班级/课程              |\n";
		cout << "\t\t\t|                6. 保存学生信息至文件              |\n";
		cout << "\t\t\t|                7. 从文件读取学生信息              |\n";
		cout << "\t\t\t|                0. 退出系统                        |\n";
		cout << "\t\t\t-----------------------------------------------------\n";
		cout << "Please enter your choice: ";
		//string temp;
		getline(cin, temp);
		int choice = atoi(temp.c_str());
		while (to_string(choice) != temp || (to_string(choice) == temp && (choice < 0 || choice > 7)))
		{
			RED;
			cout << "Invalid input!\n";
			RESET;
			cout << "Try again: ";
			getline(cin, temp);
			choice = atoi(temp.c_str());
		}
		//cout << choice;
		switch (choice)
		{
		case 1: menuForAdd(stulist, departlist, classlist, courselist); break;
		case 2: menuForDelete(stulist, departlist, classlist, courselist); break;
		case 3: menuForSearch(stulist); break;
		case 4: menuForModify(stulist, departlist, classlist, courselist); break;
		case 5: menuForDisplay(departlist, classlist, courselist); break;
		case 6: menuForWTF(stulist); break;
		case 7: menuForRFF(stulist, departlist, classlist, courselist); break;
		case 0: run = false; break;
		default:
			break;
		}
	}
	return 0;
}

int Interface::run()
{
	StudentList stulist;
	ClassList classlist;
	DepartmentList departlist;
	CourseList courselist;
	int res = mainMenu(stulist, departlist, classlist, courselist);
	return res;
}
