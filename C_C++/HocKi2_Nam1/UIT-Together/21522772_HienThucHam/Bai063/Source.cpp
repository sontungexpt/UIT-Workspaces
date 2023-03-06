#include <iostream>
#include <math.h>

using namespace std;

// initialize method

void Input(int&);

int OddDigitProductOf(int nn);

int main()
{
	int n;
	Input(n);
	int result = OddDigitProductOf(n);
	cout << "Tich cac chu le chan cua " << n << ": " << result;
	return 0;
}

//method

void Input(int& nn)
{
	cout << "Nhap so nguyen n: ";
	cin >> nn;
}
int OddDigitProductOf(int nn)
{
	int product = 1;
	int temp = nn;
	int unit;
	for (; temp > 0;)
	{
		unit = temp % 10;
		if (unit % 2 != 0)
		{
			product *= unit;
		}
		temp /= 10;
	}
	return product;
}
