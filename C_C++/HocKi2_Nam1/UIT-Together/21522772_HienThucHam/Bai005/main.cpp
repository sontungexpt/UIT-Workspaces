#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void InputRadius(double&);
double CalcVolume(double);

int main()
{
	double r;
	InputRadius(r);
	double result = CalcVolume(r);
	cout << "The tich cua hinh cau la: " << result;
	return 0;
}

//method
void InputRadius(double& radius)
{
	cout << "Nhap ban kinh: ";
	cin >> radius;
}
double CalcVolume(double radius)
{
	const float PI = 3.14;
	return 4 * PI * radius * radius /3;
}