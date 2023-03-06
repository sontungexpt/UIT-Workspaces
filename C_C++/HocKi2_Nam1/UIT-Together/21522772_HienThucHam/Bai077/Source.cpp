#include <iostream>
#include <math.h>

using namespace std;

// initialize method

void Input(int&, int&);

double Sum(double, int);

double Pow(double, int);

int main()
{
	int k;
	int n;
	Input(n, k);
	double result = Sum(n, k);
	cout << "Tong la: " << result;
	return 0;
}

//method

void Input(int& nn, int& kk)
{
	cout << "Nhap n: ";
	cin >> nn;
	cout << "Nhap k: ";
	cin >> kk;
}
double Pow(double xx, int nn)
{
	double product = 1;
	if (nn == 0)
		return 1;
	for (int i = 1; i <= nn; i++)
	{
		product *= xx;
	}
	return product;
}

double Sum(double nn, int kk)
{
	double sum = 1;
	for (int i = 1; i <= nn; i ++)
	{
		double temp = Pow(i, kk);
		sum += temp;
	}
	return sum;
}