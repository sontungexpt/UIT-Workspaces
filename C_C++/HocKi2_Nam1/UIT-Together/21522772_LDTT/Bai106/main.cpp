#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double x;
	cin >> x;
	x = 3.14 * x / 180;
	double S = x;
	double T = x;
	double e = 1;
	unsigned int i = 3;
	int M = 1;
	int dau = -1;
	while (e >= 1 * pow(10, -6))
	{
		T *= x * x;
		M *= (i - 1) * i;
		e = dau * T / M;
		S += e;
		dau = -dau;
		i += 2;
	}
	cout << "Ket qua la: " << S;
	return 0;
}