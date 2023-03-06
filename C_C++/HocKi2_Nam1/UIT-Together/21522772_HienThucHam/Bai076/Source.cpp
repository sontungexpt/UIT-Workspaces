#include <iostream>
#include <math.h>

using namespace std;

// initialize method

void Input(double&, int&);

double Sum(double, int);

int FactorialOf(int);

double Pow(double, int);

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

double Sum(double xx, int nn)
{
	double sum = 1;
	for (int i = 1; i <= 2 * nn+1; i += 2)
	{
		//tử số
		double numerator = Pow(xx, i);
		//mẩu số
		int denomiator = FactorialOf(i);
		sum += numerator / (double)denomiator;
	}
	return sum;
}