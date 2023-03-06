#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double a, b;
	cout << "nhap lan luot a,b: ";
	cin >> a >> b;
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	cout<<"a va b moi la:" << a << " " << b;
	return 0;
}