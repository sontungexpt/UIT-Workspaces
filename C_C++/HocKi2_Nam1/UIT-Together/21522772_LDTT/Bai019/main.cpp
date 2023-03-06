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
	double x12 = x8 * x4;
	double x13 = x12 * x;

	cout << "x^13 = " << x13;
	return 0;
}
