#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double a,b,x;
	cout << "Nhap lan luot a,b: ";
	cin >> a>>b;
	if (a == 0)
		if (b == 0)
			cout << "Vo so nghiem";
		else
			cout << "Vo nghiem";
	else
		x = -b / a;

	cout << "Ket qua la: " << x;
	return 0;
}