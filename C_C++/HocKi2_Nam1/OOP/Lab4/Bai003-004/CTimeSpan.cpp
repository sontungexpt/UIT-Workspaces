#include "CTimeSpan.h"

CTimeSpan::CTimeSpan()
{
	this->hour = 0;
	this->minute = 0;
	this->second = 0;
}
CTimeSpan::CTimeSpan(int hour, int minute, int second)
{
	this->hour = hour;
	this->minute = minute;
	this->second = second;
}

CTimeSpan::~CTimeSpan()
{
	return;
}

istream& operator >> (istream& is, CTimeSpan& newElement)
{
	cout << "Input hour: ";
	is >> newElement.hour;
	cout << "Input minute: ";
	is >> newElement.minute;
	cout << "Input second: ";
	is >> newElement.second;
	return is;
}

ostream& operator << (ostream& os, CTimeSpan& newElement)
{
	os << newElement.hour << ":" << newElement.minute << ":" << newElement.second;
	return os;
}
CTimeSpan CTimeSpan::operator + (const CTimeSpan& x)
{
	CTimeSpan temp;
	temp.hour = this->hour + x.hour;
	temp.minute = this->minute + x.minute;
	temp.second = this->second + x.second;
	return temp;
	
}
CTimeSpan CTimeSpan::operator - (const CTimeSpan& x)
{
	CTimeSpan temp;
	temp.hour = this->hour - x.hour;
	temp.minute = this->minute - x.minute;
	temp.second = this->second - x.second;
	return temp;
}
bool CTimeSpan::operator == (CTimeSpan& x)
{
	int thisAtSecond = this->ConvertToSecond();
	int xAtSecond = x.ConvertToSecond();
	if (thisAtSecond == xAtSecond)
		return 1;
	return 0;
}
bool CTimeSpan::operator != (CTimeSpan& x)
{
	int thisAtSecond = this->ConvertToSecond();
	int xAtSecond = x.ConvertToSecond();
	if (thisAtSecond != xAtSecond)
		return 1;
	return 0;
}
bool CTimeSpan::operator > (CTimeSpan& x)
{
	int thisAtSecond = this->ConvertToSecond();
	int xAtSecond = x.ConvertToSecond();
	if (thisAtSecond > xAtSecond)
		return 1;
	return 0;
}
bool CTimeSpan::operator < (CTimeSpan& x)
{
	int thisAtSecond = this->ConvertToSecond();
	int xAtSecond = x.ConvertToSecond();
	if (thisAtSecond < xAtSecond)
		return 1;
	return 0;
}
bool CTimeSpan::operator >= (CTimeSpan& x)
{
	int thisAtSecond = this->ConvertToSecond();
	int xAtSecond = x.ConvertToSecond();
	if (thisAtSecond >= xAtSecond)
		return 1;
	return 0;
}
bool CTimeSpan::operator <= (CTimeSpan& x )
{
	int thisAtSecond = this->ConvertToSecond();
	int xAtSecond = x.ConvertToSecond();
	if (thisAtSecond <= xAtSecond)
		return 1;
	return 0;
}

CTimeSpan CTimeSpan::operator = (const CTimeSpan& x)
{
	this->hour = x.hour;
	this->minute = x.minute;
	this->second = x.second;
	return *this;
}
CTimeSpan CTimeSpan::ConvertSecondToTime(int second)
{
	CTimeSpan temp;
	temp.SetHour(second / 3600);
	temp.SetMinute((second % 3600) / 60);
	temp.SetSecond((second % 3600) % 60);
	return temp;
}
int CTimeSpan::ConvertToSecond()
{
	return hour * 3600 + minute * 60 + second;
}

void CTimeSpan::SetHour(int hh)
{
	hour = hh;
}

void CTimeSpan::SetMinute(int mm)
{
	minute = mm;
}

void CTimeSpan::SetSecond(int ss)
{
	second = ss;
}

int CTimeSpan::GetHour()
{
	return hour;
}

int CTimeSpan::GetMinute()
{
	return minute;
}

int CTimeSpan::GetSecond()
{
	return second;
}