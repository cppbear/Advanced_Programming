#include "Manager.h"

Manager::~Manager()
{
	list<Truck*>::iterator iter;
	for (iter = truckList.begin(); iter != truckList.end(); iter++)
	{
		delete[](*iter);
	}
}

Truck* Manager::transport(int targetDistance, int weight)
{
	list<Truck*>::iterator iter;
	double minPrice = 0.0;
	Truck* res = (*truckList.begin());
	for (iter = truckList.begin(); iter != truckList.end(); iter++)
	{
		if ((*iter)->price(targetDistance) != -1)
		{
			minPrice = (*iter)->price(targetDistance);
			res = (*iter);
			break;
		}
	}
	iter++;
	while (iter != truckList.end())
	{
		if ((*iter)->price(targetDistance) != -1 && (*iter)->price(targetDistance) < minPrice)
		{
			minPrice = (*iter)->price(targetDistance);
			res = (*iter);
		}
		else if ((*iter)->price(targetDistance) != -1 && (*iter)->price(targetDistance) == minPrice)
		{
			if ((*iter)->getTotalIncome() < res->getTotalIncome())
			{
				minPrice = (*iter)->price(targetDistance);
				res = (*iter);
			}
			else if ((*iter)->getTotalIncome() == res->getTotalIncome())
			{
				if ((*iter)->getID() < res->getID())
				{
					minPrice = (*iter)->price(targetDistance);
					res = (*iter);
				}
			}
		}
		iter++;
	}
	res->transport(targetDistance, weight);
	return res;
}

double Manager::getAllIncome()
{
	double sum = 0.0;
	list<Truck*>::iterator iter;
	for (iter = truckList.begin(); iter != truckList.end(); iter++)
		sum += (*iter)->getTotalIncome();
	return sum;
}

double Manager::getAllCost()
{
	double sum = 0.0;
	list<Truck*>::iterator iter;
	for (iter = truckList.begin(); iter != truckList.end(); iter++)
		sum += (*iter)->getTotalCost();
	return sum;
}
