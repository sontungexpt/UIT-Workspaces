#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void InputX(double&);
double CalcX7(double);

int main()
{
	double x;
	InputX(x);
	double result = CalcX7(x);
	cout << "x^7 = " << result;
	return 0;
}

//method
void InputX(double& xx)
{
	cout << "Nhap x: ";
	cin >> xx;
}
double CalcX7(double xx)
{
	float xx2 = xx * xx;
	float xx3 = xx2 * xx;
	float xx4 = xx2 * xx2;
	float xx7 = xx4 * xx3;
	return xx7;
}