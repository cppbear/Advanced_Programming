#include "Administrator.h"
#include <cstring>

int Administrator::findAthleteByNationality(const char* nationality, Athlete** resultList, int maxMum) const
{
	int t = 0;
	int res = 0;
	for (int i = 0; i < list.size(); i++)
	{
		//string country = list[i]->getNationality();
		//string nation = nationality;
		if (!strcmp(list[i]->getNationality(), nationality))
		{
			resultList[t] = list[i];
			t++;
			res++;
		}
	}
	return res;
}

int Administrator::findAthleteByVisitedPlace(const char* place, Athlete** resultList, int maxNum) const
{
	int t = 0;
	int res = 0;
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i]->checkVisitedPlace(place))
		{
			resultList[t] = list[i];
			t++;
			res++;
		}
	}
	return res;
}
