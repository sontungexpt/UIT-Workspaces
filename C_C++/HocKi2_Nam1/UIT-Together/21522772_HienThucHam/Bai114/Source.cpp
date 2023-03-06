#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void Input(int&);
double Pow(double, int );
int GetNumberAt(int);
int main()
{
	int n;
	Input(n);
	int result = GetNumberAt(n);
	cout << "So hang thu" << n << " cua day la: " << result;
	return 0;
}

//method
void Input(int& nn)
{
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
int GetNumberAt(int nn)
{
	int aPrevious = -2;
	int aCurrent = 0;
	for (int i = 2; i <= nn; i++)
	{
		aCurrent = 5*aPrevious + 2 *Pow(3,i) - 6*Pow(7,i) +12;
		aPrevious = aCurrent;
	}
	return aCurrent;
}