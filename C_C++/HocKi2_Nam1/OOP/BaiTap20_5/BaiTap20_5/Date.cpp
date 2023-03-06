#include "Date.h"

Date::Date()
{
	this->day = 1;
	this->month = 1;
	this->year = 1;
}
Date::Date(const Date& x)
{
	day = x.day;
	month = x.month;
	year = x.year;
}

Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

Date::~Date()
{
	return;
}



istream& operator >> (istream& is, Date& x)
{
	cout << "\nInput day: ";
	is >> x.day;
	cout << "Input month: ";
	is >> x.month;
	cout << "Input year: ";
	is >> x.year;
	return is;
}
ostream& operator << (ostream& os, Date& x)
{
	os << x.day << "/" << x.month << "/" << x.year;
	return os;
}

