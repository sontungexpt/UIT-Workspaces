#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double a, b;
	cout << "nhap a,b: ";
	cin >> a >> b;
	double temp;
	if (a > b)	
	{
		temp = a;
		a = b;
		b = temp;
	}
	cout <<"a va b sau khi sap xep la: " << a << " " << b;
	return 0;
}