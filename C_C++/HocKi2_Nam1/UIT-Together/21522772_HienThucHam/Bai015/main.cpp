#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void InputX(double&);
double CalcX64(double);

int main()
{
	double x;
	InputX(x);
	double result = CalcX64(x);
	cout << "x^64 = " << result;
	return 0;
}

//method
void InputX(double& xx)
{
	cout << "Nhap x: ";
	cin >> xx;
}
double CalcX64(double xx)
{
	float xx2 = xx * xx;
	float xx4 = xx2 * xx2;
	float xx8 = xx4 * xx4;
	float xx16 = xx8 * xx8;
	float xx32 = xx16 * xx16;
	float xx64 = xx32 * xx32;
	return xx64;
}