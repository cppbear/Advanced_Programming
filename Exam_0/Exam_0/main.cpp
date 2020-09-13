#include <iostream>
#include <string>
#include "GoodsList.h"
using namespace std;

int main()
{
	GoodsList list;
	Goods* good1 = new Goods("apple", 500);
	Goods* good2 = new Goods("pear", 100);
	Goods* good3 = new Goods("peach", 150);
	Goods* good4 = new Goods("peach", 222);
	list.insert(good1);
	list.sort();
	list.show();
	list.insert(good2);
	list.insert(good3);
	list.show();
	list.sort();
	list.show();
	list.remove("apple", 100);
	list.show();
	list.remove("pear", 100);
	list.show();
	cout << list.count() << endl;
	list.insert(good4);
	list.show();
	list.remove("apple", 400);
	list.show();
	cout << list.count() << endl;
	list.sort();
	list.show();
	cout << list.count() << endl;
	list.remove("peach", 150);
	list.show();
	cout << list.count() << endl;
	list.remove("peach", 150);
	cout << list.count() << endl;
	list.clear();
	cout << list.count() << endl;
	//system("pause");
	return 0;
}