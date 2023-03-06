#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void InputYear(int&);
bool IsLeapYear(int);
int main()
{
	int year;
	InputYear(year);
	bool result = IsLeapYear(year);
	if (result == 1)
		cout << "La nam nhuan";
	else 
		cout << "Khong la nham nhuan";
	return 0;
}

//method
void InputYear(int& yearToInput)
{
	cout << "Nhap nam: ";
	cin >> yearToInput;
}
bool IsLeapYear(int yearToCheck)
{
	if ((yearToCheck % 4 == 0 && yearToCheck % 100 != 0) || (yearToCheck % 400 == 0))
		return 1;
	else return 0;
}
