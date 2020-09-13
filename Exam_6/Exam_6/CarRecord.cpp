#include "CarRecord.h"

void CarRecord::set(string car, int date, string time)
{
	carnumber = car;
	this->date = date;
	this->time = time;
}

string CarRecord::getCar()
{
	return carnumber;
}

int CarRecord::getDate()
{
	return date;
}

string CarRecord::getTime()
{
	return time;
}
