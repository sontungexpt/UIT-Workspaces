#include <iostream>

using namespace std;


struct Day {
	//fields
	short int day;
	short int month;
	int year;
	
	//constructors
	Day(){};

	Day(short int day, short int month, int year)
	{
		this->day = day;
		this->month = month;
		this->year = year;
	};

};
typedef struct Day Day;


short int GetMaxDaysInMonth(short int month, int year);

bool IsLeapYear(int year);

void InputDay(Day &day);

void PrintDay(Day day);

bool IsInvalidData(Day day);

Day FindNextDay(Day day);

int main()
{
	Day day;
	InputDay(day);
	cout << "Next day: ";
	PrintDay(FindNextDay(day));
}

void PrintDay(Day day)
{
	cout << day.day << "/" << day.month << "/" << day.year;
}

void InputDay(Day &day)
{
	do {
		cout << "Day: ";
		cin >> day.day;
		cout << "Month: ";
		cin >> day.month;
		cout << "Year: ";
		cin >> day.year;
		if (!IsInvalidData(day) )
		{
			cout << "Is not valid Data! Input again"<<endl;
		}
	} while (!IsInvalidData(day));
}

short int GetMaxDaysInMonth(short int month, int year)
{
	switch (month)
	{
		case 2:
		{
			if (IsLeapYear(year))
				return 29;
			else
				return 28;
		}
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
		{
			return 31;
		}
		case 4:
		case 6:
		case 9:
		case 11:
		{
			return 30;
		}
		
	}
}

bool IsLeapYear(int year)
{
	if (year % 400 == 0)
		return 1;
	else if (year % 100 == 0 && year % 4 == 0)
		return 0;
	else if ((year % 100 != 0 && year % 4 == 0))
		return 1;
	else 
		return 0;
}

bool IsInvalidData(Day day)
{
	if (day.year <= 0)
		return 0;
	else if (day.month <= 0 || day.month >12)
		return 0;
	else if (day.day > GetMaxDaysInMonth(day.month, day.year) || day.day <= 0   )
		return 0;
	else
		return 1;
}

Day FindNextDay(Day day) 
{
	day.day ++;
	if (day.day > GetMaxDaysInMonth(day.month, day.year))
	{
		day.day = 1;
		day.month++;
		if (day.month > 12)
		{
			day.month = 1;
			day.year ++;
		}
	}
	return day;
}