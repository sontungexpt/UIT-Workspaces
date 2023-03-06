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
	double x9 = x8 * x;

	cout << "x^9 = " << x9;
	return 0;
}
