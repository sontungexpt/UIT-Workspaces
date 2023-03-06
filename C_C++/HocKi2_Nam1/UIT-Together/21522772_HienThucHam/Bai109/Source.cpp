#include <iostream>
#include <math.h>

using namespace std;

// initialize method

//Giai thua
int FactorialOf(int);
double Sum();


int main()
{
	double result = Sum();
	cout << "Tong voi do chinh xac 10^-6 la: " << result;
	return 0;
}

//method

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
double Sum()
{
	double sum = 0;
	double e = 1;
	for (int i = 0; e >= pow(10, -6); i ++)
	{
		double denomiator = FactorialOf(i);
		e = 1 / denomiator;
		sum += e;
	}
	return sum;
}
