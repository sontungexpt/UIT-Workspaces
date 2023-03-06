#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double x, f;
	cout << "nhap x: ";
	cin >> x;
	if (x > 0)
		f = -2 * x * x * x + 6 * x + 9;
	else
		if (x <= 1)
			f = 5 * x - 7;
		else
			f = 2 * x * x * x + 5 * x * x - 8 * x + 3;

	cout << "ket qua la: " << f;
	return 0;
}