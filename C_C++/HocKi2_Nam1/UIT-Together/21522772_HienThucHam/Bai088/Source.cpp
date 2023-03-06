#include <iostream>
#include <math.h>

using namespace std;

// initialize method

void Input(double&, int&);
int ArithmeticProgressionOf(int);
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
	int flag = 1;
	for (int i = 1; i <=nn; i ++)
	{
		double denominator = ArithmeticProgressionOf(i);
		sum += flag * 1 / denominator;
		flag = -flag;
	}
	return sum;
}