#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void Input(double&);
double CalculateF(double);
int main()
{
	double x;
	Input(x);
	int result = CalculateF(x);
	cout << "Ket qua cua ham la: " << result;
	return 0;
}

//method
void Input(double& nn)
{
	cout << "Nhap so: ";
	cin >> nn;
}
double CalculateF(double xx)
{
	if (xx >= 5)
		return 2 * xx * xx + 5 * xx + 9;
	else
		return -2 * x * x + 4 * x - 9;
}
