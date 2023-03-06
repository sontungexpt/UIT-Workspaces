#include <iostream>
using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;

public:
	Date(int day = 1, int month = 1, int year = 1);
	void Input();
	void Print();
	bool IsLeapYear();
	Date GetNextDay();
	Date GetYesterday();
};

int main()
{
	Date date;
	date.Input();
	cout << "\nNgay ban dau: ";
	date.Print();
	cout << "\nNgay ke tiep: ";
	date.GetNextDay().Print();
	cout << "\nNgay hom qua: ";
	date.GetYesterday().Print();
	return 1;
}

Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

bool Date::IsLeapYear()
{
	if (year % 4 == 0 && year % 100 != 0)
		return 1;
	if (year % 400 == 0)
		return 1;
	return 0;
}

void Date::Print()
{
	cout << day<<"/"<<month<<"/"<<year;
}

void Date::Input()
{
	cout << "Nhap ngay: ";
	cin >> day;
	cout << "Nhap thang: ";
	cin >> month;
	cout << "Nhap nam: ";
	cin >> year;
}

Date Date::GetNextDay()
{
	Date nextDay={this->day,this->month,this->year};
	int dayInMonth[12] = { 31,28,31,30,31,31,31,30,31,30,31 };
	if (nextDay.IsLeapYear())
		dayInMonth[1] = 29;
	nextDay.day++;
	if (nextDay.day > dayInMonth[month - 1])
	{
		nextDay.month++;
		if (nextDay.month > 12)
		{
			nextDay.year++;
			nextDay.month = 1;
		}
		nextDay.day = 1;
	}
	return nextDay;
}

Date Date::GetYesterday()
{
	Date yesterday = { this->day,this->month,this->year };
	int dayInMonth[12] = { 31,28,31,30,31,31,31,30,31,30,31 };
	if (yesterday.IsLeapYear())
		dayInMonth[1] = 29;
	if (yesterday.day == 1 && yesterday.month == 1 && yesterday.year == 1)
		return yesterday;
	yesterday.day--;
	if (yesterday.day == 0)
	{
		yesterday.month--;
		if (yesterday.month == 0)
		{
			yesterday.year--;
			yesterday.month = 12;
		}
		yesterday.day = dayInMonth[yesterday.month - 1];
	}
	return yesterday;
}