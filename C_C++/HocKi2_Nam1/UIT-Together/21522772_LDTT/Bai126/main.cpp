#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double a, b;
	cout << "nhap lan luot a,b: ";
	cin >> a >> b;
	double max = b;
	if (a > b)
		max = a;

	cout << "Gia tri lon nhat la: " << max;
	return 0;
}