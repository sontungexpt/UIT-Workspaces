#include <iostream>
#include <math.h>

using namespace std;

// initialize method

void Input(int&);

int GetMaxDigitOf(int nn);

int main()
{
	int n;
	Input(n);
	int result = GetMaxDigitOf(n);
	cout << "Chu so lon nhat cua " << n << ": " << result;
	return 0;
}

//method

void Input(int& nn)
{
	cout << "Nhap so nguyen n: ";
	cin >> nn;
}
int GetMaxDigitOf(int nn)
{
	int max = 0;
	int temp = nn;
	int unit;
	for (; temp > 0;)
	{
		unit = temp % 10;
		if (max < unit)
		{
			max = unit;
		}
		temp /= 10;
	}
	return max;
}
