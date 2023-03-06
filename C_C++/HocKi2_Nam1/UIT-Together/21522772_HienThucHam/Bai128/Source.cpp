#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void Input(double&);
void Swap(double&, double&);
int main()
{
	double a, b;
	Input(a);
	Input(b);
	Swap(a,b);
	cout << "2 so sau khi duoc sap xep la: " << a<<" "<<b;
	return 0;
}

//method
void Input(double& nn)
{
	cout << "Nhap so nguyen: ";
	cin >> nn;
}
void Swap(double &aa, double &bb)
{
	double temp;
	if (aa > bb)
	{
		temp = aa;
		aa = bb;
		bb = temp;
	}
}