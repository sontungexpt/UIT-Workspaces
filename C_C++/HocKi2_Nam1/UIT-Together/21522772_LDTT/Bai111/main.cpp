#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double x;
	cout << "Nhap x: ";
	cin >> x;
	double S = 3;
	double e = 1;
	unsigned int i = 2;
	int dau = 1;

	while (e >= 1 * pow(10, -6))
	{
		e = dau * 4 / (double)(i*(i+1)*(i+2));
		S += e;
		i ++;
		dau = -dau;
	}
	cout << "Ket qua la: " << S;
	return 0;
}