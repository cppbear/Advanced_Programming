#pragma once
#include <string>
#include <vector>
using namespace std;

class Athlete
{
private:
	string name, nationality;
	vector<string> places;

public:
	Athlete(const char* na, const char* nation);
	~Athlete() {}
	void addVisitedPlace(const char* place) { places.push_back(place); }
	bool checkVisitedPlace(const char* place) const;
	const char* getName() const { return name.c_str(); }
	const char* getNationality() const { return nationality.c_str(); }
};

inline Athlete::Athlete(const char* na, const char* nation)
{
	name = na;
	nationality = nation;
}
