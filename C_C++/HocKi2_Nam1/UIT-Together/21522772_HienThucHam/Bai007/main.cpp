#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void InputFahrenheit(double&);
double ConvertFToC(double);

int main()
{
	double F;
	InputFahrenheit(F);
	double C = ConvertFToC(F);
	cout << "Do C tim duoc la: " << C;
	return 0;
}

//method
void InputFahrenheit(double& fahrenheit)
{
	cout << "Nhap do F can chuyen sang do C: ";
	cin >> fahrenheit;
}
double ConvertFToC(double fahrenheit)
{
	return 5*(fahrenheit-32)/9;
}