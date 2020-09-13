#pragma once
#include <iostream>
using namespace std;

class Truck
{
private:
	int ID;
	double TotalCost;
	double TotalIncome;
public:
	Truck(int id) { ID = id; TotalCost = 0.0; TotalIncome = 0.0; }
	virtual double cost(int targetDistance, int weight) = 0;
	virtual double price(int targetDistance) = 0;
	void transport(int targetDistance, int weight)
	{
		if (cost(targetDistance, weight) == -1)
			return;
		TotalCost += cost(targetDistance, weight);
		TotalIncome += price(targetDistance);
	}
	double getTotalCost() const { return TotalCost; }
	double getTotalIncome() const { return TotalIncome; }
	int getID() const { return ID; }
};

class NormalTruck : public Truck
{
private:
	int maxDistance;
public:
	NormalTruck(int id, int maxDistance) :Truck(id) { this->maxDistance = maxDistance; }
	double cost(int targetDistance, int weight)
	{
		if (targetDistance > maxDistance)
			return -1;
		else
			return (double)weight * (double)targetDistance;
	}
	double price(int targetDistance)
	{
		if (targetDistance > maxDistance)
			return -1;
		else
		{
			double price = (double)targetDistance * 5.0;
			if (price < 100.0)
				return 100.0;
			else
				return price;
		}
	}
};

class AdvancedTruck : public Truck
{
public:
	AdvancedTruck(int id) :Truck(id) {}
	double cost(int targetDistance, int weight)
	{
			return (double)weight * (double)targetDistance + 50.0;
	}
	double price(int targetDistance)
	{
		double price = (double)targetDistance * 8.0;
		if (price < 150.0)
			return 150.0;
		else
			return price;
	}
};

class LongDistanceTruck : public AdvancedTruck
{
public:
	LongDistanceTruck(int id) :AdvancedTruck(id) {}
	double price(int targetDistance)
	{
		double price;
		double temp = (double)targetDistance * 8.0;
		if (temp < 150.0)
			price = 150.0;
		else
			price = temp;
		if (targetDistance < 30)
			return price * 1.1;
		else
			return price * 0.9;
	}
};
