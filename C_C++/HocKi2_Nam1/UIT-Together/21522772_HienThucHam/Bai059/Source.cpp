#include <iostream>
#include <math.h>

using namespace std;

// initialize method

void Input(int&);

int CountDigitOf(int);

int main()
{
	int n;
	Input(n);
	int result = CountDigitOf(n);
	cout << "So luong chu so cua " << n << ": " << result;
	return 0;
}

//method

void Input(int& nn)
{
	cout << "Nhap so nguyen n: ";
	cin >> nn;
}
int CountDigitOf(int nn)
{
	int temp = nn;
	int count = 0;
	for (; temp > 0;)
	{
		temp /= 10;
		count++;
	}
			
	return count;
}
