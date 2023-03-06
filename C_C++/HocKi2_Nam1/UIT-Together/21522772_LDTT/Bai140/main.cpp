#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double a, b,c, x1,x2,x,delta;
	cout << "Nhap lan luot a,b,c: ";
	cin >> a >> b>>c;
	if (delta == 0)
	{
		if (delta > 0)
		{
			x1 = (-b + sqrt(delta)) / (2 * a);
			x1 = (-b - sqrt(delta)) / (2 * a);
			cout << x1 << " " << x2;
		}
		else
		{
			cout << "Vo nghiem";
		}
	}
	else
	{
		x = -b / (2 * a);
		cout << x;
	}
	return 0;
}