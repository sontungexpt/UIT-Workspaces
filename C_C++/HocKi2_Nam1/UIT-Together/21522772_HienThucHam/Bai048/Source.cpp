#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void Input(double &,int&);
double Sum(double, int);

int main()
{
	double x;
	int n;
	Input(x,n);
	double sum = Sum(x,n);
	cout << "Tong la: " << sum;
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
double Sum(double xx,int nn)
{
	double sum = 1;
	for (int i = 0; i <= nn; i++)
	{
		sum *= (xx + i);
	}
	return sum;
}
