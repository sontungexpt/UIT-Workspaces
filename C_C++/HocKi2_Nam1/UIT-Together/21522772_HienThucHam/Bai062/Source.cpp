#include <iostream>
#include <math.h>

using namespace std;

// initialize method

void Input(int&);

int EvenDigitSumOf(int nn);

int main()
{
	int n;
	Input(n);
	int result = EvenDigitSumOf(n);
	cout << "Tong cac chu so chan cua " << n << ": " << result;
	return 0;
}

//method

void Input(int& nn)
{
	cout << "Nhap so nguyen n: ";
	cin >> nn;
}
int EvenDigitSumOf(int nn)
{
	int sum = 0;
	int temp = nn;
	int unit;
	for (; temp > 0;)
	{
		unit = temp % 10;
		if (unit % 2 == 0)
		{
			sum += unit;
		}
		temp /= 10;
	}
	return sum;
}
