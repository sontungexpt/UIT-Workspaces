#include <iostream>
#include <math.h>

using namespace std;

// initialize method

void Input(double& , int& );

double Pow(double, int);

int Sum(double,int);

int main()
{
	double x;
	int n;
	Input(x,n);
	double result = Sum(x,n);
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
int Sum(double xx, int nn)
{
	int sum = 0;
	for (int i = 1; i <= nn; i++)
	{
		int temp = Pow(xx,i);
		sum += temp;
	}
	return sum;
}