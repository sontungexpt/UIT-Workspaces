#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double a, b, c;
	cout < "Nhap lan luot a,b,c: ";
	cin >> a >> b>>c;
	double temp;
	if (a > b)
	{
		temp = a;
		a = b;
		b = temp;
	}
	if (a > c)
	{
		temp = a;
		a = c;
		c = temp;
	}
	if (b > c)
	{
		temp = b;
		b = c;
		c = temp;
	}
	cout<<"Gia tri sau khi xap sep: " << a << " " << b << " " << c;
	return 0;
}