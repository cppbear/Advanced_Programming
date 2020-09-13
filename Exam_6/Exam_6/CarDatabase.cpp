#include "CarDatabase.h"

bool CarDatabase::cmp_date_time(CarRecord a, CarRecord b)
{
	if (a.getDate() < b.getDate())
		return true;
	else if (a.getDate() > b.getDate())
		return false;
	else
	{
		return a.getTime() < b.getTime();
	}
}

bool CarDatabase::cmp_time(CarRecord a, CarRecord b)
{
	if (a.getTime() < b.getTime())
		return true;
	else if (a.getTime() > b.getTime())
		return false;
	else
	{
		return a.getCar() < b.getCar();
	}
}

void CarDatabase::read()
{
	list.clear();
	ifstream fin;
	fin.open(file);
	string car, time;
	int date;
	while (fin)
	{
		CarRecord newcar;
		fin >> car >> date >> time;
		if (fin)
		{
			newcar.set(car, date, time);
			list.push_back(newcar);
		}
	}
	fin.close();
}

void CarDatabase::add(CarRecord cr)
{
	bool exist = false;
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i].getCar() == cr.getCar() && list[i].getDate() == cr.getDate() && list[i].getTime() == cr.getTime())
		{
			exist = true;
			break;
		}
	}
	if (!exist)
	{
		list.push_back(cr);
		ofstream fout;
		fout.open(file, ios::app);
		fout << cr.getCar() << ' ' << cr.getDate() << ' ' << cr.getTime() << endl;
		fout.close();
	}
}

void CarDatabase::del(string car)
{
	vector<CarRecord>::iterator iter = list.begin();
	while (iter != list.end())
	{
		if (iter->getCar() == car)
		{
			iter = list.erase(iter);
		}
		else
		{
			iter++;
		}
	}
	ofstream fout;
	fout.open(file);
	for (int i = 0; i < list.size(); i++)
	{
		fout << list[i].getCar() << ' ' << list[i].getDate() << ' ' << list[i].getTime() << endl;
	}
	fout.close();
}

void CarDatabase::del(int date)
{
	vector<CarRecord>::iterator iter = list.begin();
	while (iter != list.end())
	{
		if (iter->getDate() == date)
		{
			iter = list.erase(iter);
		}
		else
		{
			iter++;
		}
	}
	ofstream fout;
	fout.open(file);
	for (int i = 0; i < list.size(); i++)
	{
		fout << list[i].getCar() << ' ' << list[i].getDate() << ' ' << list[i].getTime() << endl;
	}
	fout.close();
}

void CarDatabase::del(string car, int date)
{
	vector<CarRecord>::iterator iter = list.begin();
	while (iter != list.end())
	{
		if (iter->getCar() == car && iter->getDate() == date)
		{
			iter = list.erase(iter);
		}
		else
		{
			iter++;
		}
	}
	ofstream fout;
	fout.open(file);
	for (int i = 0; i < list.size(); i++)
	{
		fout << list[i].getCar() << ' ' << list[i].getDate() << ' ' << list[i].getTime() << endl;
	}
	fout.close();
}

void CarDatabase::del(string car, int date, string time)
{
	vector<CarRecord>::iterator iter = list.begin();
	while (iter != list.end())
	{
		if (iter->getCar() == car && iter->getDate() == date && iter->getTime() == time)
		{
			iter = list.erase(iter);
		}
		else
		{
			iter++;
		}
	}
	ofstream fout;
	fout.open(file);
	for (int i = 0; i < list.size(); i++)
	{
		fout << list[i].getCar() << ' ' << list[i].getDate() << ' ' << list[i].getTime() << endl;
	}
	fout.close();
}

void CarDatabase::del(int date, string time_start, string time_end)
{
	vector<CarRecord>::iterator iter = list.begin();
	while (iter != list.end())
	{
		if (iter->getDate() == date && iter->getTime() >= time_start && iter->getTime() <= time_end)
		{
			iter = list.erase(iter);
		}
		else
		{
			iter++;
		}
	}
	ofstream fout;
	fout.open(file);
	for (int i = 0; i < list.size(); i++)
	{
		fout << list[i].getCar() << ' ' << list[i].getDate() << ' ' << list[i].getTime() << endl;
	}
	fout.close();
}

vector<CarRecord> CarDatabase::IndexRecordsByCar(string car)
{
	vector<CarRecord> res;
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i].getCar() == car)
			res.push_back(list[i]);
	}
	sort(res.begin(), res.end(), cmp_date_time);
	return res;
}

vector<CarRecord> CarDatabase::IndexRecordsByDate(int date)
{
	vector<CarRecord> res;
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i].getDate() == date)
		{
			bool same = false;
			for (int j = 0; j < res.size(); j++)
			{
				if (res[j].getCar() == list[i].getCar())
				{
					if (list[i].getTime() > res[j].getTime())
					{
						res.erase(res.begin() + j);
						res.push_back(list[i]);
					}
					same = true;
					break;
				}
			}
			if (!same)
			{
				res.push_back(list[i]);
			}
		}
	}
	sort(res.begin(), res.end(), cmp_time);
	return res;
}
