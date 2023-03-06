#include "Time.h"

#pragma region Properties
int Time::GetHour()
{
	return hour;
}
void Time::SetHour(int value)
{
	this->hour = value;
}
int Time::GetMinute()
{
	return minute;
}
void Time::SetMinute(int value)
{
	this->minute = value;
}
int Time::GetSecond()
{
	return second;
}
void Time::SetSecond(int value)
{
	this->second = value;
}
#pragma endregion

#pragma region Constructor
Time::Time()
{
	this->hour = 0;
	this->minute = 0;
	this->second = 0;
}
Time::Time(int hour, int minute, int second)
{
	this->hour = hour;
	this->minute = minute;
	this->second = second;
}
Time::Time(const Time& x)
{
	this->hour = x.hour;
	this->minute = x.minute;
	this->second = x.second;
}
#pragma endregion

#pragma region Destructor
Time::~Time()
{
	return;
}
#pragma endregion

#pragma region Method
void Time::Input()
{
	cout << "Input hour: ";
	cin >> hour;
	cout << "Input minute: ";
	cin >> minute;
	cout << "Input second: ";
	cin >> second;
}

istream& operator >> (istream& is, Time& x)
{
	cout << "Input hour: ";
	is >> x.hour;
	cout << "Input minute: ";
	is >> x.minute;
	cout << "Input second: ";
	is >> x.second;
	return is;
}

void Time::Print()
{
	cout << hour << ":" << minute << ":" << second;
}
ostream& operator << (ostream& os, Time& x)
{
	os << x.hour << ":" << x.minute << ":" << x.second;
	return os;
}
bool Time::IsInvalidTime()
{
	if (hour < 0 || hour > 23)
		return 0;
	if (minute < 0 || minute >59)
		return 0;
	if (second < 0 || second > 59)
		return 0;
	return 1;
}

Time Time::FindNextTime()
{
	Time nextTime = { hour,minute,second };
	nextTime.second++;
	if (nextTime.second > 59)
	{
		nextTime.minute++;
		if (nextTime.minute > 59)
		{
			nextTime.hour++;
			if (nextTime.hour > 23)
				nextTime.hour = 0;
			nextTime.minute = 0;
		}
		nextTime.second = 0;
	}
	return nextTime;
}

Time Time::FindPreviousTime()
{
	Time prevTime = { hour,minute,second };
	prevTime.second--;
	if (prevTime.second < 0)
	{
		prevTime.minute--;
		if (prevTime.minute < 0)
		{
			prevTime.hour--;
			if (prevTime.hour < 0)
				prevTime.hour = 23;
			prevTime.minute = 59;
		}
		prevTime.second = 59;
	}
	return prevTime;
}

int Time::NumberOfSecond()
{
	return hour * 3600 + minute * 60 + second;
}
int Time::Distance(Time y)
{
	int b = y.NumberOfSecond();
	return abs(NumberOfSecond() - b);
}

int Time::Compare(Time y)
{
	if (hour > hour)
		return 1;
	else if (hour < y.hour)
		return -1;
	else if (minute > y.minute)
		return 1;
	else if (minute < y.minute)
		return -1;
	else if (second > y.second)
		return 1;
	else if (second < y.second)
		return -1;
	return 0;
}

#pragma endregion

