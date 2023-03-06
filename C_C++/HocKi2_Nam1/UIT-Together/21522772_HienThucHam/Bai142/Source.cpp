#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void Input(int&);
int GetReverseNumberOf(int);

int main()
{
	int n;
	Input(n);
	int result = GetReverseNumberOf(n);
	cout << "So dao nguoc cua " << n << " la: " << result;
	return 0;
}

//method
void Input(int& nn)
{
	cout << "Nhap so nguyen n: ";
	cin >> nn;
}
int GetReverseNumberOf(int nn)
{
	int reverseNumber = 0;
	int unit = 0;
	for (;nn > 0;)
	{
		unit = nn % 10;
		reverseNumber = reverseNumber * 10 + unit;
		nn /= 10;
	}
	return reverseNumber;
}
