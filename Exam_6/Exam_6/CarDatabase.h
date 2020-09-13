#pragma once
#include <vector>
#include <fstream>
#include <algorithm>
#include "CarRecord.h"
using namespace std;

class CarDatabase
{
private:
    string file;
    vector<CarRecord> list;
    static bool cmp_date_time(CarRecord a, CarRecord b);
    static bool cmp_time(CarRecord a, CarRecord b);
public:
    CarDatabase(string filename);
    void read();
    void add(CarRecord cr);
    void del(string car);
    void del(int date);

    void del(string car,int date);

    void del(string car,int date,string time);
    void del(int date,string time_start,string time_end);
    vector<CarRecord> IndexRecordsByCar(string car);
    vector<CarRecord> IndexRecordsByDate(int date);
};

inline CarDatabase::CarDatabase(string filename)
{
    file = filename;
}
