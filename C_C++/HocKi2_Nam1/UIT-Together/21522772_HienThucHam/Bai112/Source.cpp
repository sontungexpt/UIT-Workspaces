#include <iostream>
#include <math.h>

using namespace std;

// initialize method

double Sum();
//Luy thua
double Pow(double , int );

int main()
{
	double result = Sum();
	cout << "Tong voi do chinh xac 10^-6 la: " << result;
	return 0;
}

//method

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

double Sum()
{
	double sum = 4-2/4-1/5-1/6;
	double e = 1;
	for (int i = 1; e >= pow(10, -6); i ++)
	{
		e = (4 / (8 * i + 1) - 2 / (8 * i + 4) - 1 / (8 * i + 5) - 1 / (8 * i + 6))/Pow(16,i);
		sum += e;
	}
	return sum;
}
