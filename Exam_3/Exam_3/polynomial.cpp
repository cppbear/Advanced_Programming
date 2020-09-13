#include "polynomial.h"

Polynomial::Polynomial(const Polynomial& p)
{
	coe = p.coe;
}
//�����������w�������ʽ��nΪw�ĳ��ȣ�������ߴ���+1��w[i]��x��i���ݵĲ���
//��f(x)=1+x+x^2+x^3ʱ��w={1,1,1,1},n=4
Polynomial::Polynomial(const double w[], const int n)
{
	for (int i = 0; i < n; i++)
		coe.push_back(w[i]);
}
//����+�����
Polynomial Polynomial::operator+(const Polynomial& p)const
{
	Polynomial temp;
	int a = coe.size();
	int b = p.coe.size();
	if (a < b)
	{
		int i;
		for (i = 0; i < a; i++)
			temp.coe.push_back(coe[i] + p.coe[i]);
		while (i < b)
		{
			temp.coe.push_back(p.coe[i]);
			i++;
		}
	}
	else
	{
		int i;
		for (i = 0; i < b; i++)
			temp.coe.push_back(coe[i] + p.coe[i]);
		while (i < a)
		{
			temp.coe.push_back(coe[i]);
			i++;
		}
	}
	return temp;
}
//����*�����
Polynomial Polynomial::operator*(const Polynomial& p)const
{
	Polynomial temp;
	int a = coe.size();
	int b = p.coe.size();
	int n = a + b - 1;
	for (int i = 0; i < n; i++)
		temp.coe.push_back(0.0);
	for (int i = 0; i < a; i++)
		for (int j = 0; j < b; j++)
			temp.coe[i + j] += coe[i] * p.coe[j];
	return temp;
}
//����()�������ʵ�ֺ�������
Polynomial Polynomial::operator()(const Polynomial& p)const
{
	Polynomial res;
	int a = coe.size();
	int b = p.coe.size();
	int n = (a - 1) * (b - 1) + 1;
	for (int i = 0; i < n; i++)
		res.coe.push_back(0.0);
	for (int i = 1; i < a; i++)
	{
		Polynomial temp = p;
		for (int j = 1; j < i; j++)
			temp = temp * p;
		for (int k = 0; k < temp.coe.size(); k++)
			res.coe[k] += temp.coe[k] * coe[i];
	}
	res.coe[0] += coe[0];
	return res;
}
//����()�������ʵ�ֺ���ֵ����
double Polynomial::operator()(double x) const
{
	double res = 0.0;
	int n = coe.size();
	for (int i = 0; i < n; i++)
	{
		double temp = pow(x, i);
		res += temp * coe[i];
	}
	return res;
}
//������x���ĵ���
double Polynomial::derivative(double x) const
{
	double res = 0.0;
	int n = coe.size();
	for (int i = 1; i < n; i++)
	{
		double temp = pow(x, i - 1);
		res += temp * coe[i] * (double)i;
	}
	return res;
}

void Polynomial::print()
{
	for (int i = 0; i < coe.size() - 1; i++)
		cout << coe[i] << "x^" << i << "+";
	cout << coe[coe.size() - 1] << "x^" << coe.size() - 1 << endl;
}
