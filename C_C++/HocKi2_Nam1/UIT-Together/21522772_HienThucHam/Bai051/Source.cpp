#include <iostream>
#include <math.h>

using namespace std;

// initialize method

void Input(int&);

//hàm tinh tích tất cả các ước số
int ProductDivisorOf(int);

int main()
{
	int n;
	Input(n);
	int result = ProductDivisorOf(n);
	cout << "Tich tat ca cac uoc so cua " << n << ": " << result;
	return 0;
}

//method

void Input(int& nn)
{
	cout << "Nhap so nguyen n: ";
	cin >> nn;
}

int ProductDivisorOf(int nn)
{
	int product = 1;
	for (int i = 1; i <= nn; i++)
		if (nn % i == 0)
			product *= i;
	return product;
}

