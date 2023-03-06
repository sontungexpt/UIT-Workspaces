#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void InputRadius(double&);
double CalcCirclePerimeter(double);

int main()
{
	double r;
	InputRadius(r);
	double result = CalcCirclePerimeter(r);
	cout << "Chu vi cua duong tron la: " << result;
	return 0;
}

//method
void InputRadius(double& radius)
{
	cout << "Nhap ban kinh: ";
	cin >> radius;
}
double CalcCirclePerimeter(double radius)
{
	const float PI = 3.14;
	return 2 * PI * radius;
}