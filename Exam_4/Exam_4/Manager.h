#pragma once
#include "Transport.h"
#include <vector>
#include <list>
using namespace std;

class Manager
{
private:
	list<Truck*> truckList;
public:
	Manager() {}
	~Manager();
	void addTruck(Truck* t) { truckList.push_back(t); }
	Truck* transport(int targetDistance, int weight);
	double getAllIncome();
	double getAllCost();
};
