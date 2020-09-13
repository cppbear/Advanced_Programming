#pragma once
#include <iostream>
#include <string>
using namespace std;

class CarRecord
{
private:
    string carnumber;
    int date;
    string time;
public:
    CarRecord() {}
    void set(string car,int date,string time);
    string getCar();
    int getDate();
    string getTime();
};
