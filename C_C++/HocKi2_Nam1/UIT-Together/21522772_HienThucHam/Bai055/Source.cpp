#include <iostream>
#include <math.h>

using namespace std;

// initialize method

void Input(int&);

int ProductOddDivisorOf(int);

int main()
{
	int n;
	Input(n);
	int result = ProductOddDivisorOf(n);
	cout << "Tich tat ca cac uoc so le cua " << n << ": " << result;
	return 0;
}

//method

void Input(int& nn)
{
	cout << "Nhap so nguyen n: ";
	cin >> nn;
}
int ProductOddDivisorOf(int nn)
{
	int product = 1;
	for (int i = 1; i <= nn; i+=2)
		if (nn % i == 0)
			product *= i;
	return product;
}
