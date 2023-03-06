#include <iostream>


using namespace std;

int main()
{
	double x;
	cout << "Nhap x: ";
	cin >> x;
	double x2 = x * x;
	double x3 = x2 * x;
	double x4 = x2 * x2;
	double x7 = x4 * x3;
	cout << "x^7 = " << x7;
	return 0;
}