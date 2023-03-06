#include <iostream>
#include <math.h>

using namespace std;

// initialize method

void Input(int&);

int DigitProductOf(int);

int main()
{
	int n;
	Input(n);
	int result = DigitProductOf(n);
	cout << "Tich tat ca cac chu so cua " << n << ": " << result;
	return 0;
}

//method

void Input(int& nn)
{
	cout << "Nhap so nguyen n: ";
	cin >> nn;
}
int DigitProductOf(int nn)
{
	int product = 1;
	int temp = nn;
	int unit;
	for (; temp > 0;)
	{
		unit = temp % 10;
		product *= unit;
		temp /= 10;
	}
	return product;
}
