#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double a, b;
	cout << "nhap a,b: ";
	cin >> a >> b;
	double min = a;
	if (a > b)
		min = b;
	cout << "Gia tri nho nhat la: " << min;
	return 0;
}