#include <iostream>


using namespace std;

int main()
{
	double x;
	cout << "Nhap x: ";
	cin >> x;
	double x2 = x * x;
	double x4 = x2 * x2;
	double x6 = x4 * x2;
	cout << "x^6 = " << x6;
	return 0;
}