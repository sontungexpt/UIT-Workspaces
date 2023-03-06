#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void InputRadius(double&);
double CalcCircleArea(double);

int main()
{
	double r;
	InputRadius(r);
	double result = CalcCircleArea(r);
	cout <<"Dien tich cua duong tron la: " << result;
	return 0;
}

//method
void InputRadius(double &radius)
{
	cout << "Nhap ban kinh: ";
	cin >> radius;
}
double CalcCircleArea(double radius)
{
	const float PI = 3.14;
	return PI * radius*radius;
}