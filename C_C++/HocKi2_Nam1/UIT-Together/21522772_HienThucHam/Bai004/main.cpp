#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void InputRadius(double&);
double CalcSurfaceArea(double);

int main()
{
	double r;
	InputRadius(r);
	double result = CalcSurfaceArea(r);
	cout << "Dien tich xung quanh cua hinh cau la: " << result;
	return 0;
}

//method
void InputRadius(double& radius)
{
	cout << "Nhap ban kinh: ";
	cin >> radius;
}
double CalcSurfaceArea(double radius)
{
	const float PI = 3.14;
	return 4 * PI * radius*radius;
}