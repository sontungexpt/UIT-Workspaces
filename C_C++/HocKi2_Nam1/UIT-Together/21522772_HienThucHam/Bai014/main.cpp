#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void InputX(double&);
double CalcX32(double);

int main()
{
	double x;
	InputX(x);
	double result = CalcX32(x);
	cout << "x^32 = " << result;
	return 0;
}

//method
void InputX(double& xx)
{
	cout << "Nhap x: ";
	cin >> xx;
}
double CalcX32(double xx)
{
	float xx2 = xx * xx;
	float xx4 = xx2 * xx2;
	float xx8 = xx4 * xx4;
	float xx16 = xx8 * xx8;
	float xx32 = xx16 * xx16;
	return xx32;
}