#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void InputX(double&);
double CalcX6(float);

int main()
{
	double x;
	InputX(x);
	double result = CalcX6(x);
	cout << "x^6 = " << result;
	return 0;
}

//method
void InputX(double &xx)
{
	cout << "Nhap x: ";
	cin >> xx;
}
double CalcX6(float xx)
{
	float xx2 = xx * xx;
	float xx4 = xx2 * xx2;
	float xx6 = xx4*xx2;
	return xx6;
}