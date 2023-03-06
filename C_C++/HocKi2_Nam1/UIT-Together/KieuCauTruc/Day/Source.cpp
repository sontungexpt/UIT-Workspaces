#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

struct date
{
	int day;
	int month;
	int year;
};
typedef struct date DATE;

void Input(DATE&);
void Print(DATE);
bool IsLeapYear(DATE);
int MaxDayInMonth(DATE);
int MaxDayInYear(DATE);
bool IsInvalidDate(DATE);
int Compare(DATE,DATE);
int IndexDateInCurrentYear(DATE);
int IndexDateInFrom010101(DATE);
void PrintWeekDay(DATE);
int Distance(DATE, DATE);
DATE FindDate(int, int);
DATE FindDate(int);
DATE FindNextDate(DATE);
DATE FindNextDate(DATE, int&);
DATE FindPreviousDate(DATE);
DATE FindPreviousDate(DATE, int&);

int main()
{
	DATE date1;
	DATE date2;
	int k;
	cout << "Nhap ngay 1: \n";
	Input(date1);
	cout << "\nNgay 1 vua nhap la: \n";
	Print(date1);
	cout << "\nNhap ngay 2: \n";
	Input(date2);
	cout << "\nNgay 2 vua nhap la: \n";
	Print(date2);
	if (IsLeapYear(date1) == true)
		cout << "Ngay 1 la nam nhuan\n";
	else
		cout << "Ngay 1 khong la nam nhuan\n";
	cout << "Ngay toi da trong thang cua ngay 1 vua nhap la: " << MaxDayInMonth(date1)<<endl;
	cout << "Ngay toi da trong nam cua ngay 1 vua nhap la: " << MaxDayInYear(date1)<<endl;
	if (IsInvalidDate(date1) == true)
		cout << "Ngay 1 nhap vao la hop le\n";
	else 
		cout << "Ngay 1 nhap vao khong hop le\n";
	if (Compare(date1, date2) == 1)
		cout << "Ngay 1 la tuong lai cua ngay 2\n";
	else if (Compare(date1, date2) == 0)
		cout << "Ngay 1 trung ngay 2\n";
	else
		cout << "Ngay 1 la qua khu cua ngay 2\n";
	cout << "Thu cua ngay 1 la: \n";
	PrintWeekDay(date1) ;
	cout << "\nNgay ke tiep cua ngay 1 la: \n"; 
	Print(FindNextDate(date1));
	cout << "\nNgay truoc cua ngay 1 la: ";
	Print(FindPreviousDate(date1));
	cout << "\nNgay ke tiep sau khoang thoi gian k cua ngay 1 la: \n";
	Print(FindNextDate(date1,k));
	cout << "\nNgay truoc sau khoang thoi gian k cua ngay 1 la: ";
	Print(FindPreviousDate(date1,k));
	return 0;
}

void Input(DATE& x)
{
	cout << "Nhap ngay: ";
	cin >> x.day;
	cout << "Nhap thang: ";
	cin >> x.month;
	cout << "Nhap nam: ";
	cin >> x.year;
}

void Print(DATE x)
{
	cout << x.day << "/" << x.month << "/" << x.year;
}


bool IsLeapYear(DATE x) 
{
	if (x.year % 4 == 0 && x.year % 100 != 0)
		return 1;
	else if (x.year % 400 == 0)
		return 1;
	return 0;
}

int MaxDayInMonth(DATE x) 
{
	int dayInMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if(IsLeapYear(x)==true)
		dayInMonth[1] = 29;
	return dayInMonth[x.month - 1];
}

int MaxDayInYear(DATE x)
{
	if (IsLeapYear(x) == true)
		return 366;
	return 365;

}

bool IsInvalidDate(DATE x)
{
	if (x.year < 1)
		return 0;
	else if (x.month > 12 || x.month < 1)
		return 0;
	else if (x.day > MaxDayInMonth(x) || x.day < 1)
		return 0;
	return 1;
}

int Compare(DATE x, DATE y)
{
	if (x.year > x.year)
		return 1;
	else if (x.year < y.year)
		return -1;
	else if (x.month > y.month)
		return 1;
	else if (x.month < y.month)
		return -1;
	else if (x.day > y.day)
		return 1;
	else if (x.day < y.day)
		return -1;
	return 0;

}

int IndexDateInCurrentYear(DATE x)
{
	int index = 0;
	for (int i = 1; i <= x.month -1; i++)
	{
		DATE temp = { 1,i,x.year };
		index += MaxDayInMonth(temp);
	}
	return (index + x.day);
}
 
int IndexDateInFrom010101(DATE x)
{
	int index = 0;
	for (int i = 1; i < x.year; i++)
	{
		DATE temp = { 1,1,i };
		index += MaxDayInYear(temp);
	}
	return (index + IndexDateInCurrentYear(x));
}

void PrintWeekDay(DATE x)
{
	int index = IndexDateInFrom010101(x);
	switch (index % 7)
	{
	case 0:
		cout << "On Sunday";
		break;
	case 1:
		cout << "On Monday";
		break;
	case2:
		cout << "On Tuesday";
		break;
	case3:
		cout << "On Wednesday";
		break;
	case 4:
		cout << "On Thursday";
		break;
	case 5:
		cout << "On Friday";
		break;
	case 6:
		cout << "On Saturday";
		break;
	}
}

int Distance(DATE x, DATE y)
{
	int a = IndexDateInCurrentYear(x);
	int b = IndexDateInCurrentYear(y);
	return abs(a - b);
}

DATE FindDate(int yyear, int index)
{
	DATE temp = { 1,1,yyear };
	temp.month = 1;
	while (index - MaxDayInMonth(temp) > 0)
	{
		index = index - MaxDayInMonth(temp);
		temp.month++;
	}
	temp.day = index;
	return temp;
}

DATE FindDate(int index)
{
	int year = 1;
	int numberOfDay = 365;
	while (index - numberOfDay > 0)
	{
		index -= numberOfDay;
		year++;
		DATE temp = { 1,1,year };
		numberOfDay = MaxDayInMonth(temp);
	}
	return FindDate(year, index);
}

DATE FindNextDate(DATE x)
{
	int index = IndexDateInFrom010101(x);
	index += 1;
	return FindDate(index);
}

DATE FindPreviousDate(DATE x)
{
	if (x.day == 1 && x.month == 1 && x.year == 1)
		return x;
	int index = IndexDateInFrom010101(x);
	index -= 1;
	return FindDate(index);
}

DATE FindNextDate(DATE x, int &k)
{
	cout << "Nhap khoang cach sau do can tim ngay: ";
	cin >> k;
	int index = IndexDateInFrom010101(x);
	index += k;
	return FindDate(index);
}

DATE FindPreviousDate(DATE x, int &k)
{
	cout << "Nhap khoang cach truoc do can tim ngay: ";
	cin >> k;
	if (x.day == 1 && x.month == 1 && x.year == 1)
		return x;
	int index = IndexDateInFrom010101(x);
	index -= k;
	return FindDate(index);
}