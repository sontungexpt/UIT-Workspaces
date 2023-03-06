#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void InputX(double&);
double CalcX12(double);

int main()
{
	double x;
	InputX(x);
	double result = CalcX12(x);
	cout << "x^12 = " << result;
	return 0;
}

//method
void InputX(double& xx)
{
	cout << "Nhap x: ";
	cin >> xx;
}
double CalcX12(double xx)
{
	float xx2 = xx * xx;
	float xx4 = xx2 * xx2;
	float xx8 = xx4 * xx4;
	float xx12 = xx8 * xx4;
	return xx12;
}