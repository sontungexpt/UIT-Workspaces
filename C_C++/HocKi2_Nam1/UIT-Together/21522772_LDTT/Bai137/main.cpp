#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double x,f;
	cout << "Nhap x: ";
	cin >> x;
	if (x >= 5)
		f = 2 * x * x + 5 * x + 9;
	else
		f = -2 * x * x + 4 * x - 9;

	cout << "ket qua la: " << f;
	return 0;
}