#include <iostream>
#include <math.h>

using namespace std;

// initialize method

void Input(double&, int&);

double Sum(double, int);

int main()
{
	double x;
	int n;
	Input(x, n);
	double result = Sum(x, n);
	cout << "Tong la: " << result;
	return 0;
}

//method

void Input(double& xx, int& nn)
{
	cout << "Nhap x: ";
	cin >> xx;
	cout << "Nhap so nguyen n: ";
	cin >> nn;
}

double Sum(double xx, int nn)
{
	double sum = 0;
	double product = 1;
	for (int i = 0; i <= nn; i++)
	{
		product *= xx + i;
		sum += product;
	}
	return sum;
}