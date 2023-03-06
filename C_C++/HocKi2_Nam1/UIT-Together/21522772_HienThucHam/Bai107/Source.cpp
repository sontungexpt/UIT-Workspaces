#include <iostream>
#include <math.h>

using namespace std;

// initialize method

void Input(double&);
//Luy thua
double Pow(double, int);
//Giai thua
int FactorialOf(int);
double Sum(double);


int main()
{
	double x;
	Input(x);
	double result = Sum(x);
	cout << "Tong voi do chinh xac 10^-6 la: " << result;
	return 0;
}

//method

void Input(double& xx)
{
	cout << "Nhap x: ";
	cin >> xx;
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
double Sum(double xx)
{
	const float PI = 3.14;
	xx = PI * xx / 180;
	double sum = 0;
	double e = 1;
	int flag = 1;
	for (int i = 0; e >= pow(10, -6); i += 2)
	{
		double numerator = Pow(xx, i);
		double denomiator = FactorialOf(i);
		e = numerator / denomiator;
		sum += flag * e;
		flag = -flag;
	}
	return sum;
}
