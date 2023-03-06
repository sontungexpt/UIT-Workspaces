#include "CNgay.h"

CNgay::CNgay()
{
	this->day = 1;
	this->month = 1;
	this->year = 1;
}
CNgay::CNgay(const CNgay& x)
{
	day = x.day;
	month = x.month;
	year = x.year;
}

CNgay::CNgay(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

CNgay::~CNgay()
{
	return;
}

bool CNgay::IsLeapYear()
{
	if (year % 4 == 0 && year % 100 != 0)
		return 1;
	if (year % 400 == 0)
		return 1;
	return 0;
}

void CNgay::Print()
{
	cout << day << "/" << month << "/" << year;
}

void CNgay::Input()
{
	cout << "Nhap ngay: ";
	cin >> day;
	cout << "Nhap thang: ";
	cin >> month;
	cout << "Nhap nam: ";
	cin >> year;
}

CNgay CNgay::GetNextDay()
{
	CNgay nextDay = { this->day,this->month,this->year };
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

CNgay CNgay::GetYesterday()
{
	CNgay yesterday = { this->day,this->month,this->year };
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
int CNgay::sttTrongNam()
{
	int ngaythang[12] = { 31,28,31,30,31,
	30,31,31,30,31,30,31 };
	if (IsLeapYear() == 1)
		ngaythang[1] = 29;
	int stt = 0;
	for (int i = 1; i <= month - 1; i++)
		stt = stt + ngaythang[i - 1];
	return (stt + day);
}

long CNgay::SoThuTu()
{
	long stt = 0;
	for (int i = 1; i <= year - 1; i++)
	{
		stt = stt + 365;
		CNgay temp(1, 1, i);
		if (temp.IsLeapYear() == 1)
			stt = stt + 1;
	}
	return (stt + sttTrongNam());
}

CNgay CNgay::TimNgay(int nam, int stt)
{
	int ngaythang[12] = { 31,28,31,30,
	31,30,31,31,30,31,30,31 };
	CNgay temp(1, 1, nam);
	if (temp.IsLeapYear() == 1)
		ngaythang[1] = 29;
	temp.month = 1;
	while (stt - ngaythang[temp.month- 1] > 0)
	{
		stt = stt - ngaythang[temp.month - 1];
		temp.month++;
	}
	temp.month = stt;
	return temp;
}

istream& operator >> (istream& is, CNgay& x)
{
	cout << "Nhap ngay: ";
	is >> x.day;
	cout << "Nhap thang: ";
	is >> x.month;
	cout << "Nhap nam: ";
	is >> x.year;
	return is;
}
ostream& operator << (ostream& os, CNgay& x)
{
	os << x.day << "/" << x.month << "/" << x.year;
	return os;
}

CNgay  CNgay:: operator + (CNgay x)
{

}
CNgay  CNgay:: operator - (CNgay x)
{

}
CNgay  CNgay:: operator * (CNgay x)
{

}
CNgay CNgay:: operator / (CNgay x)
{

}


bool CPhanSo::operator > (CPhanSo x)
{
	float a = (float)this->Tu / this->Mau;
	float b = (float)x.Tu / x.Mau;
	return (a > b);
}
bool CPhanSo::operator < (CPhanSo x)
{
	float a = (float)this->Tu / this->Mau;
	float b = (float)x.Tu / x.Mau;
	return (a < b);
}
bool CPhanSo::operator == (CPhanSo x)
{
	float a = (float)this->Tu / this->Mau;
	float b = (float)x.Tu / x.Mau;
	return (a == b);
}
bool CPhanSo::operator != (CPhanSo x)
{
	float a = (float)this->Tu / this->Mau;
	float b = (float)x.Tu / x.Mau;
	return (a != b);
}
bool CPhanSo::operator >= (CPhanSo x)
{
	float a = (float)this->Tu / this->Mau;
	float b = (float)x.Tu / x.Mau;
	return (a > b || a == b);
}
bool CPhanSo::operator <= (CPhanSo x)
{
	float a = (float)this->Tu / this->Mau;
	float b = (float)x.Tu / x.Mau;
	return (a < b || a == b);
}