#include "CTime.h"

CTime::CTime()
{
	this->hour = 0;
	this->minute = 0;
	this->second = 0;
}
CTime::CTime(int hour, int minute, int second)
{
	this->hour = hour;
	this->minute = minute;
	this->second = second;
}

//destructor
CTime:: ~CTime()
{
	return;
}
istream& operator >> (istream& is, CTime& newEle)
{
	do
	{
		cout << "Input hour (0<= hour <24): ";
		is >> newEle.hour;
	} while (newEle.hour < 0 || newEle.hour >= 24);
	do
	{
		cout << "Input minute(0<= minute <60): ";
		is >> newEle.minute;
	} while (newEle.minute < 0 || newEle.minute >= 60);
	do
	{
		cout << "Input second(0<= second <60): ";
		is >> newEle.second;
	} while (newEle.second < 0 || newEle.second >= 60);
	return is;

}
ostream& operator << (ostream& os, CTime& newElement)
{
	os << newElement.hour << ":" << newElement.minute << ":" << newElement.second;
	return os;
}
CTime CTime::operator + (int& second)
{
	int time = this->ConvertToSecond();
	time += second;
	return CTime::ConvertSecondToTime(time);
}
CTime CTime::operator - (int& second)
{
	int time = this->ConvertToSecond();
	time -= second;
	return CTime::ConvertSecondToTime(time);
}
CTime CTime::operator + (CTimeSpan& ele)
{
	int newSecondElement = this->ConvertToSecond() + ele.ConvertToSecond();
	return CTime::ConvertSecondToTime(newSecondElement);

}
CTimeSpan CTime::operator - (CTime& ele)
{
	int newSecondElement = this->ConvertToSecond() - ele.ConvertToSecond();
	return CTimeSpan::ConvertSecondToTime(newSecondElement);
}

CTime CTime::operator = (const CTime& x)
{
	this->hour = x.hour;
	this->minute = x.minute;
	this->second = x.second;
	return *this;
}

CTime& CTime::operator ++ ()
{
	this->second++;
	if (this->second == 60)
	{
		this->minute++;
		if (this->minute == 60)
		{
			this->hour++;
			if (this->hour == 24)
				this->hour == 0;
			this->minute == 0;
		}
		this->second = 0;
	}
	return *this;
}
CTime CTime::operator ++ (int noValue)
{
	CTime temp = *this;
	++* this;
	return temp;
}
CTime& CTime::operator --()
{
	this->second--;
	if (this->second < 0)
	{
		this->minute--;
		if (this->minute < 0)
		{
			this->hour--;
			if (this->hour < 0)
				this->hour == 23;
			this->minute == 59;
		}
		this->second = 59;
	}
	return *this;
}
CTime CTime::operator -- (int noValue)
{
	CTime temp = *this;
	--* this;
	return temp;
}

void CTime::SetHour(int hh)
{
	hour = hh;
}

void CTime::SetMinute(int mm)
{
	minute = mm;
}

void CTime::SetSecond(int ss)
{
	second = ss;
}

int CTime::GetHour()
{
	return hour;
}

int CTime::GetMinute()
{
	return minute;
}

int CTime::GetSecond()
{
	return second;
}

CTime CTime::ConvertSecondToTime(int second)
{
	CTime temp;
	temp.SetHour((second / 3600) % 24);
	temp.SetMinute((second % 3600) / 60);
	temp.SetSecond((second % 3600) % 60);
	return temp;
}

int CTime::ConvertToSecond()
{
	return hour * 3600 + minute * 60 + second;
}
#pragma endregion
