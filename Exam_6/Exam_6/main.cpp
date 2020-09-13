#include <iostream>
#include "CarDatabase.h"
using namespace std;

int main()
{
	CarRecord cr;
	cr.set("A9999", 1, "16:33");
	CarDatabase cd("database"), cd2("database");
	cd.add(cr);
	cd2.read();
	vector<CarRecord> cars = cd2.IndexRecordsByCar("A9999");
	return 0;
}
