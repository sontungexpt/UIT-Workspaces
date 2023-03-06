#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double x;
	cout << "Nhap x: ";
	cin >> x;
	double S = 1;
	double e = 1;
	unsigned int i = 1;
	int M = 1;

	while (e >= 1 * pow(10, -6))
	{
		M *= i;
		e = 1 / (double)M;
		S += e;
		i++;
	}
	cout <<"Ket qua la: " << S;
	return 0;
}