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
	if (xx > 0)
		if (xx <= 1)
			return 5 * xx - 7;
		else
			return 2 * xx * xx * xx + 5 * xx * xx - 8 * xx + 3;
	else
		return -2 * xx * xx * xx + 6 * xx + 9;
}
