#include <iostream>
#include <math.h>

using namespace std;

// initialize method

void Input(double&, int&);
int ArithmeticProgressionOf(int);
double Pow(double, int);
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

int ArithmeticProgressionOf(int nn)
{
	int sum = 0;
	for (int i = 1; i <= nn; i++)
	{
		sum += i;
	}
	return sum;
}
double Sum(double xx, int nn)
{
	double sum = 0;
	int flag = -1;
	for (int i = 1; i <=nn; i ++)
	{
		double numerator = Pow(xx, i);
		double denominator = ArithmeticProgressionOf(i);
		sum += flag *numerator / denominator;
		flag = -flag;
	}
	return sum;
}