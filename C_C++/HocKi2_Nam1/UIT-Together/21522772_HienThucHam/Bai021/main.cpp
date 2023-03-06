#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void InputX(double&);
double CalcX15(double);

int main()
{
	double x;
	InputX(x);
	double result = CalcX15(x);
	cout << "x^15 = " << result;
	return 0;
}

//method
void InputX(double& xx)
{
	cout << "Nhap x: ";
	cin >> xx;
}
double CalcX15(double xx)
{
	float xx2 = xx * xx;
	float xx4 = xx2 * xx2;
	float xx5 = xx4 * xx;
	float xx10 = xx5 * xx5;
	float xx15 = xx10 * xx5;
	return xx15;
}