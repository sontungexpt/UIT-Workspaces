#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void InputX(double&);
double CalcX9(double);

int main()
{
	double x;
	InputX(x);
	double result = CalcX9(x);
	cout << "x^9 = " << result;
	return 0;
}

//method
void InputX(double& xx)
{
	cout << "Nhap x: ";
	cin >> xx;
}
double CalcX9(double xx)
{
	float xx2 = xx * xx;
	float xx4 = xx2 * xx2;
	float xx8 = xx4 * xx4;
	float xx9 = xx8 * xx;
	return xx9;
}