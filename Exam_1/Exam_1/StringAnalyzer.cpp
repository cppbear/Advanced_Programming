#include <string>
#include <iostream>
using namespace std;

int judgeStringType(char *s1,char *s2)
{
    string str1 = s1;
    string str2 = s2;
    if (str1.length() != str2.length())
        return 1;
    else if (str1 == str2)
        return 2;
    else
    {
        string temp1 = str1, temp2 = str2;
        for (int i = 0; i < str1.length(); i++)
        {
            if (temp1[i] < 0x5b)
                temp1[i] += 0x20;
            if (temp2[i] < 0x5b)
                temp2[i] += 0x20;
        }
        if (temp1 == temp2)
            return 3;
        else
        {
            if (str1[0] < 0x5b && str2[0] < 0x5b || str1[0] > 0x60 && str2[0] > 0x60)
            {
                int offset = (str2[0] - str1[0] + 26) % 26;
                temp1 = str1;
                for (int i = 0; i < str1.length(); i++)
                {
                    if (temp1[i] < 0x5b && temp1[i] + offset > 0x5a || temp1[i] > 0x60 && temp1[i] + offset > 0x7a)
                        temp1[i] += offset - 26;
                    else
                        temp1[i] += offset;
                }
                if (temp1 == str2)
                    return 4;
                else
                    return 5;
            }
            else
                return 5;
        }
    }
}