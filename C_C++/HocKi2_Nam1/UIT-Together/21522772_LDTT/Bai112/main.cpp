#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double S = 4-2/4-1/5-1/6;
	double e = 1;
	double i = 1;
	long int T = 1;

	while (e >= 1 * pow(10, -6))
	{
		T *= 16;
		e = (4 / (8 * i + 1) - 2 / (8 * i + 4) - 1 / (8 * i + 5) - 1 / (8 * i + 6))/T;
		S += e;
		i++;
	}
	cout <<"Ket qua la: " << S;
	return 0;
}