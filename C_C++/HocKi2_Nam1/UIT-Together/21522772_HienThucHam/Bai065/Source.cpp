#include <iostream>
#include <math.h>

using namespace std;

// initialize method

void Input(int&);

int GetMinDigitOf(int nn);

int main()
{
	int n;
	Input(n);
	int result = GetMinDigitOf(n);
	cout << "Chu so nho nhat cua " << n << ": " << result;
	return 0;
}

//method

void Input(int& nn)
{
	cout << "Nhap so nguyen n: ";
	cin >> nn;
}
int GetMinDigitOf(int nn)
{
	int min = 0;
	int temp = nn;
	int unit;
	for (; temp > 0;)
	{
		unit = temp % 10;
		if (min > unit)
		{
			min = unit;
		}
		temp /= 10;
	}
	return min;
}
