#include "CThoiGian.h"

CThoiGian::CThoiGian()
{
	this->hour = 0;
	this->minute = 0;
	this->second = 0;
}
CThoiGian::CThoiGian(int hour, int minute, int second)
{
	this->hour = hour;
	this->minute = minute;
	this->second = second;
}
CThoiGian::CThoiGian(const CThoiGian& x)
{
	this->hour = x.hour;
	this->minute = x.minute;
	this->second = x.second;
}
CThoiGian::~CThoiGian()
{
	return;
}

void CThoiGian::Input()
{
	cout << "Input hour: ";
	cin >> hour;
	cout << "Input minute: ";
	cin >> minute;
	cout << "Input second: ";
	cin >> second;
}

void CThoiGian::Print()
{
	cout << hour << ":" << minute << ":" << second;
}

bool CThoiGian::IsInvalidTime()
{
	if (hour < 0 || hour > 23)
		return 0;
	if (minute < 0 || minute >59)
		return 0;
	if (second < 0 || second > 59)
		return 0;
	return 1;
}

CThoiGian CThoiGian::FindNextTime()
{
	CThoiGian nextTime = { hour,minute,second };
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

CThoiGian CThoiGian::FindPreviousTime()
{
	CThoiGian prevTime = { hour,minute,second };
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

int CThoiGian::NumberOfSecond()
{
	return hour * 3600 + minute * 60 + second;
}
int CThoiGian::Distance(CThoiGian y)
{
	int b = y.NumberOfSecond();
	return abs(NumberOfSecond() - b);
}

int CThoiGian::Compare(CThoiGian y)
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

istream& operator >> (istream& is, CThoiGian& x)
{
	cout << "Input hour: ";
	is >> x.hour;
	cout << "Input minute: ";
	is >> x.minute;
	cout << "Input second: ";
	is >> x.second;
	return is;
}
ostream& operator << (ostream& os, CThoiGian& x)
{
	os << x.hour << ":" << x.minute << ":" << x.second;
	return os;
}