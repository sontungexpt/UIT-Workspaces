#include "Date.h"

#pragma region Constructor
Date::Date()
{
	this->day = 1;
	this->month = 1;
	this->year = 1;
}
Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

Date::Date(const Date& dateCopy)
{
	this->day = dateCopy.day;
	this->month = dateCopy.month;
	this->year = dateCopy.year;
}

#pragma endregion

#pragma region Properties
int Date::GetDay()
{
	return this->day;
}
void Date::SetDay(int value)
{
	this->day = value;
}
int Date::GetMonth()
{
	return this->month;
}
void Date::SetMonth(int value)
{
	this->month = value;
}
int Date::GetYear()
{
	return this->year;
}
void Date::SetYear(int value)
{
	this->year = value;
}
#pragma endregion

#pragma region Method
istream& operator >> (istream& is, Date& date)
{
	cout << "\nInput day: ";
	is >> date.day;
	cout << "Input month: ";
	is >> date.month;
	cout << "Input year: ";
	is >> date.year;
	return is;
}

ostream& operator << (ostream& os, Date& date)
{
	os << date.day << "/" << date.month << "/" << date.year;
	return os;
}

#pragma endregion
