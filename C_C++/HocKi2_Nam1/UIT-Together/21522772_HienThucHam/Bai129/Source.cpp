#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void Input(double&);
void Swap(double&, double&);
int main()
{
	double a, b,c;
	Input(a);
	Input(b);
	Input(c);
	Swap(a, b);
	Swap(a, c);
	Swap(b, c);

	cout << "3 so sau khi duoc sap xep la: " << a << " " << b<<" "<<c;
	return 0;
}

//method
void Input(double& nn)
{
	cout << "Nhap so nguyen: ";
	cin >> nn;
}
void Swap(double& aa, double& bb)
{
	double temp;
	if (aa > bb)
	{
		temp = aa;
		aa = bb;
		bb = temp;
	}
}