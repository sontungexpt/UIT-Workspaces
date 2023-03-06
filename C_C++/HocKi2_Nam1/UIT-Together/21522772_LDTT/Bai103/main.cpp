#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double S = 0;
	double e = 1;
	unsigned int i = 1;
	while (e >= 1 * pow(10, -6))
	{
		e = 1 / (double)i;
		S += e;
		i += 2;
	}
	cout <<"Ket qua la: " << S;
	return 0;
}