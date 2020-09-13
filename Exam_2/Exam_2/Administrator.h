#pragma once
#include <string>
#include <vector>
#include "Athlete.h"
using namespace std;

class Administrator
{
private:
	vector<Athlete*> list;
public:
	Administrator() {};
	~Administrator() {};
	void addAthlete(Athlete* athlete) { list.push_back(athlete); }
	int findAthleteByNationality(const char* nationality, Athlete** resultList, int maxMum) const;
	int findAthleteByVisitedPlace(const char* place, Athlete** resultList, int maxNum) const;
};
