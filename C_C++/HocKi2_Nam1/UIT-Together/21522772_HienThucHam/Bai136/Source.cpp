#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void InputZone(int&, int&);
bool IsLeapYear(int);
void ListLeapYear(int, int);
int main()
{
	int x, y;
	InputZone(x, y);
	ListLeapYear(x, y);
	return 0;
}

//method
void InputZone(int& xx, int& yy)
{
	cout << "Nhap x: ";
	cin >> xx;
	do {
		cout << "Nhap y(y>x): ";
		cin >> yy;
	} while (yy < xx);
}
bool IsLeapYear(int yearToCheck)
{
	if ((yearToCheck % 4 == 0 && yearToCheck % 100 != 0) || (yearToCheck % 400 == 0))
		return 1;
	else return 0;
}
void ListLeapYear(int xx, int yy)
{
	cout << "Cac nam nhuan tu " << xx << " den " << y << ": ";
	for (int i = xx; i <= yy; i++)
	{
		if (IsLeapYear(i) == true)
			cout << i << " ";
	}
}