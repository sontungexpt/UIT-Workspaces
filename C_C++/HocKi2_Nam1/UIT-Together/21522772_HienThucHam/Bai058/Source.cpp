#include <iostream>
#include <math.h>

using namespace std;

// initialize method

void Input(int&);

int DigitSumOf(int);

int main()
{
	int n;
	Input(n);
	int result = DigitSumOf(n);
	cout << "Tong tat ca cac chu so cua " << n << ": " << result;
	return 0;
}

//method

void Input(int& nn)
{
	cout << "Nhap so nguyen n: ";
	cin >> nn;
}
int DigitSumOf(int nn)
{
	int sum = 0;
	int temp = nn;
	int unit;
	for (; temp>0; )
	{
		unit = temp % 10;
		sum+=unit;
		temp / 10;
	}
	return sum;
}
