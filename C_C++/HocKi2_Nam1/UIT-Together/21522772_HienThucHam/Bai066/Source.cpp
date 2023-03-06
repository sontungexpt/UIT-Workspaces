#include <iostream>
#include <math.h>

using namespace std;

// initialize method

void Input(int&);

bool HasEvenDigit(int);

int main()
{
	int n;
	Input(n);
	bool result = HasEvenDigit(n);
	if (result == 1)
		cout << "Ton tai chu so chan";
	else
		cout << "Khong ton tai chu so chan";
	return 0;
}

//method

void Input(int& nn)
{
	cout << "Nhap so nguyen n: ";
	cin >> nn;
}
bool HasEvenDigit(int nn)
{
	int temp = nn;
	int unit;
	for (; temp > 0;)
	{
		unit = temp % 10;
		if (unit % 2 == 0)
		{
			return 1;
		}
		temp /= 10;
	}
	return 0;
}
