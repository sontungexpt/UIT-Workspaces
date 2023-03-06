#include <iostream>
#include <math.h>

using namespace std;

// initialize method

void Input(int&);

int CountOddDigitOf(int nn);

int main()
{
	int n;
	Input(n);
	int result = CountOddDigitOf(n);
	cout << "So luong chu so le cua " << n << ": " << result;
	return 0;
}

//method

void Input(int& nn)
{
	cout << "Nhap so nguyen n: ";
	cin >> nn;
}
int CountOddDigitOf(int nn)
{
	int count = 0;
	int temp = nn;
	int unit;
	for (; temp>0;)
	{
		unit = temp % 10;
		if (unit % 2 != 0)
		{
			count++;
		}
		temp /= 10;
	}
	return count;
}
