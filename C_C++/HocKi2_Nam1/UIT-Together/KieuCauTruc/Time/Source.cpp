#include <iostream>
#include <math.h>

using namespace std;

struct time
{
	int hour;
	int minute;
	int second;
};
typedef struct time TIME;

void Input(TIME&);
void Print(TIME);
bool IsInvalidTime(TIME);
TIME FindNextTime(TIME);
TIME FindPreviousTime(TIME);
int NumberOfSecond(TIME);
int Distance(TIME, TIME);
int Compare(TIME, TIME);

int main()
{
	TIME a;
	TIME b;
	cout << "Nhap thoi gian 1:\n";
	Input(a);
	cout << "\nThoi gian 1 hien tai la: ";
	Print(a);
	cout << "\nNhap thoi gian 2:\n";
	Input(b);
	cout << "\nThoi gian 2 hien tai la: ";
	Print(b);
	if (IsInvalidTime(a) == true)
		cout << "\nGio a hop le";
	else
		cout << "\nGio a khong hop le";
	cout << "\nThoi gian cua a o giay ke tiep la: ";
	Print(FindNextTime(a));
	cout << "\nThoi gian cua a o giay truoc la: ";
	Print(FindPreviousTime(a));
	cout << "\nSo giay la: " << NumberOfSecond(a);
	cout << "\nKhoang cach giua hai thoi gian a va b la: " << Distance(a, b);
	if (Compare(a, b) == 1)
		cout << "\na > b";
	else if (Compare(a, b) == 0)
		cout << "\na = b";
	else
		cout << "\n a < b";
	return 0;
}

void Input(TIME& x)
{
	cout << "Input hour: ";
	cin >> x.hour;
	cout << "Input minute: ";
	cin >> x.minute;
	cout << "Input second: ";
	cin >> x.second;
}

void Print(TIME x)
{
	cout << x.hour << ":" << x.minute << ":" << x.second;
}

bool IsInvalidTime(TIME x)
{
	if (x.hour < 0 || x.hour > 23)
		return 0;
	if (x.minute < 0 || x.minute >59)
		return 0;
	if (x.second < 0 || x.second > 59)
		return 0;
	return 1;
}

TIME FindNextTime(TIME x)
{
	x.second++;
	if (x.second > 59)
	{
		x.minute++;
		if (x.minute > 59)
		{
			x.hour++;
			if (x.hour > 23)
				x.hour = 0;
			x.minute = 0;
		}
		x.second = 0;
	}
	return x;
}

TIME FindPreviousTime(TIME x)
{
	x.second--;
	if (x.second < 0)
	{
		x.minute--;
		if (x.minute < 0)
		{
			x.hour--;
			if (x.hour < 0)
				x.hour = 23;
			x.minute = 59;
		}
		x.second = 59;
	}
	return x;
}

int NumberOfSecond(TIME x)
{
	return x.hour * 3600 + x.minute * 60 + x.second;
}
int Distance(TIME x, TIME y)
{
	int a = NumberOfSecond(x);
	int b = NumberOfSecond(y);
	return abs(a - b);
}

int Compare(TIME x, TIME y)
{
	if (x.hour > x.hour)
		return 1;
	else if (x.hour < y.hour)
		return -1;
	else if (x.minute > y.minute)
		return 1;
	else if (x.minute < y.minute)
		return -1;
	else if (x.second > y.second)
		return 1;
	else if (x.second < y.second)
		return -1;
	return 0;
}