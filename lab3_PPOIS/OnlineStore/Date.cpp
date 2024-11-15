#include "Date.h"

bool Date::IsLeapYear(int year) const {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int  Date::MaxDays(int year, int month) const {
	switch (month) {
	case 2:
		return IsLeapYear(year) ? 29 : 28;
	case 4: case 6: case 9: case 11:
		return 30;
	default:
		return 31;
	}
}

Date::Date(int day, int month, int year)
	:day(day), month(month), year(year) {
	allInDays = day + ((month - 1) * 30) + ((year - 1899) * 365);
}

void  Date::ShowDate() const {
	cout << day << "." << month << "." << year << endl;
}

bool  Date::IsValidDate() const {
	if (year < 1899 || year > 2024) return false;
	if (month < 1 || month > 12) return false;
	if (day < 1 || day > MaxDays(year, month)) return false;
	return true;
}