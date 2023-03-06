#include <iostream>

using namespace std;

int main()
{
	double x;
	cout << "Nhap x: ";
	cin >> x;
	double x2 = x * x;
	double x4 = x2 * x2;
	double x8 = x4 * x4;
	double x10 = x8 * x2;
	double x11 = x10 * x;

	cout << "x^11 = " << x11;
	return 0;
}
