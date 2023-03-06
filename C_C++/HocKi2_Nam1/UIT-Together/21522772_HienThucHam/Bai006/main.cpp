#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void InputCelsius(double&);
double ConvertCToF(double);

int main()
{
	double C;
	InputCelsius(C);
	double F = ConvertCToF(C);
	cout << "Do F tim duoc la: " << F;
	return 0;
}

//method
void InputCelsius(double& celsius)
{
	cout << "Nhap do C can chuyen sang do F: ";
	cin >> celsius;
}
double ConvertCToF(double celsius)
{
	return 9 * celsius / 5 + 32;
}