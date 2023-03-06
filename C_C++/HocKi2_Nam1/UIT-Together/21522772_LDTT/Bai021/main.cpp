#include <iostream>

using namespace std;

int main()
{
	double x;
	cout << "Nhap x: ";
	cin >> x;
	double x2 = x * x;
	double x4 = x2 * x2;
	double x5 = x4 * x;
	double x10 = x5 * x5;
	double x15 = x10 * x5;

	cout << "x^15 = " << x15;
	return 0;
}
