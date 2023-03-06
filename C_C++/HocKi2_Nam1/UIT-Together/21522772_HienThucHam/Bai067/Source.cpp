#include <iostream>
#include <math.h>

using namespace std;

// initialize method

void Input(int&);

bool HasOddDigit(int);

int main()
{
	int n;
	Input(n);
	bool result = HasOddDigit(n);
	if (result == 1)
		cout << "Ton tai chu so le";
	else
		cout << "Khong ton tai chu so le";
	return 0;
}

//method

void Input(int& nn)
{
	cout << "Nhap so nguyen n: ";
	cin >> nn;
}
bool HasOddDigit(int nn)
{
	int temp = nn;
	int unit;
	for (; temp > 0;)
	{
		unit = temp % 10;
		if (unit % 2 != 0)
		{
			return 1;
		}
		temp /= 10;
	}
	return 0;
}
