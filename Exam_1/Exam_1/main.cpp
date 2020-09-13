#include <iostream>
#include <string>
#include "StringAnalyer.h"
using namespace std;

int main()
{
	string str1, str2;
	while(cin >> str1 >> str2)
	{
		char* s1 = (char*)str1.c_str(), * s2 = (char*)str2.c_str();
		cout << judgeStringType(s1, s2) << endl;
	}
	return 0;
}