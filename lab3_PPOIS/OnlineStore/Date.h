#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date {
	int day; 
	int month; 
	int year; 
	int allInDays; 

	bool IsLeapYear(int year) const;

	int  MaxDays(int year, int month) const;

public:
	Date(int day, int month, int year);

	void  ShowDate() const;

	bool  IsValidDate() const;
};

#endif
