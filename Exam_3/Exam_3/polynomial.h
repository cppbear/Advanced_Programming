#pragma once
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Polynomial
{
private:
	vector<double> coe;

public:
	Polynomial() {};
	Polynomial(const Polynomial& p);
	Polynomial(const double w[], const int n);
	Polynomial operator+(const Polynomial& p)const;
	Polynomial operator*(const Polynomial& p)const;
	Polynomial operator()(const Polynomial& p)const;
	double operator()(double x) const;
	double derivative(double x) const;
	void print();
};
