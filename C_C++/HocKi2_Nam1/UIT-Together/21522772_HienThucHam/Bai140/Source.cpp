#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

// initialize method
void Input(double&, double&,double&);
void PrintResult(double, double);
bool SolveEquation(double, double,double, double&,double&);

int main()
{
	double a, b, c,x1,x2;
	Input(a, b,c);
	int result = SolveEquation(a,b,c, x1,x2);
	if (result == 1)
	{
		PrintResult(x1, x2);
	}
	else
		cout << "Vo nghiem";
	return 0;
}

//method
void Input(double& aa, double& bb,double &cc)
{
	cout << "Nhap a: ";
	cin >> aa;
	cout << "Nhap b: ";
	cin >> bb;
	cout << "Nhap c:";
	cin >> cc;
}
void PrintResult(double xx1, double xx2)
{
	if (xx1 == xx2)
	{
		cout << "Phuong trinh co mot nghiem x = " << xx1;
	}
	else
	{
		cout << "x1 = " << xx1 << endl;
		cout << "x2 = " << xx2 << endl;
	}
}
bool SolveEquation(double aa, double bb,double cc, double& x1Out,double &x2Out)
{
	double delta = bb * bb - 4 * aa * cc;
	if (delta != 0)
	{
		if (delta > 0)
		{
			x1Out = (-bb + sqrt(delta)) / (2 * aa);
			x2Out = (-bb - sqrt(delta)) / (2 * aa);
			return 1;
		}
		else
			return 0;
	}
	else
	{
		x1Out = -bb / 2 * aa;
		x2Out = -bb / 2 * aa;
		return 1;
	}
}
