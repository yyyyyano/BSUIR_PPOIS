#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <string>
using namespace std;

class Date {
    int day;
    int month;
    int year;

    bool IsLeapYear(int year) const;

    int MaxDays(int year, int month) const;

public:
    Date(int day, int month, int year) ;

    void ShowDate();

    bool IsValidDate() const;

    int GetDay();
};


#endif
