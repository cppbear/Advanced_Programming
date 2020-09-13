#include <iostream>
#include "polynomial.h"
using namespace std;

int main()
{
	double w1[3] = { 5,3,1, };
	double w2[2] = { 1,1 };
	Polynomial p1(w1, 3);
	cout << "p1 = ";
	p1.print();
	Polynomial p2(w2, 2);
	cout << "p2 = ";
	p2.print();
	Polynomial p3 = p1(p2);
	cout << "p3 = ";
	p3.print();
	return 0;
}