#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void Input(int&);
int GetReverseNumberOf(int);
bool IsSymetricalNumber(int);


int main()
{
	int n;
	Input(n);
	bool result = IsSymetricalNumber(n);
	if (result == 1)
		cout << "La so doi xung";
	else
		cout << "Khong la so doi xung";
	return 0;
}

//method
void Input(int& nn)
{
	cout << "Nhap so nguyen n: ";
	cin >> nn;
}
int GetReverseNumberOf(int nn)
{
	int reverseNumber = 0;
	int unit = 0;
	for (;nn > 0;)
	{
		unit = nn % 10;
		reverseNumber = reverseNumber * 10 + unit;
		nn /= 10;
	}
	return reverseNumber;
}
bool IsSymetricalNumber(int nn)
{
	int reverseNumber = GetReverseNumberOf(nn);
	if (nn == reverseNumber)
		return 1;
	else
		return 0;
}