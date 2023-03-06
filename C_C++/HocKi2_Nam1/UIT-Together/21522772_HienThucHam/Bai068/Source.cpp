#include <iostream>
#include <math.h>

using namespace std;

// initialize method

void Input(int&);

int FactorialOf(int);

int Sum(int);
int main()
{
	int n;
	Input(n);
	double result = Sum(n);
	cout << "Tong la: " << result;
	return 0;
}

//method

void Input(int& nn)
{
	cout << "Nhap so nguyen n: ";
	cin >> nn;
}
int FactorialOf(int nn)
{
	int product = 1;
	if (nn == 0)
		return 1;
	else
		for (int i = 1; i <= nn; i++)
			product *= i;
	return product;
}
int Sum(int nn)
{
	int sum = 0;
	for (int i = 1; i <= nn; i++)
	{
		int factorial = FactorialOf(i);
		sum += factorial;
	}
	return sum;
}