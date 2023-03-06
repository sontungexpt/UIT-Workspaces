#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void InputX(double&);
double CalcX11(double);

int main()
{
	double x;
	InputX(x);
	double result = CalcX11(x);
	cout << "x^11 = " << result;
	return 0;
}

//method
void InputX(double& xx)
{
	cout << "Nhap x: ";
	cin >> xx;
}
double CalcX11(double xx)
{
	float xx2 = xx * xx;
	float xx4 = xx2 * xx2;
	float xx8 = xx4 * xx4;
	float xx10 = xx8 * xx2;
	float xx11 = xx10 * xx;
	return xx11;
}