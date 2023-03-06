#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void Input(double& , double& );
int SolveEquation(double ,double,double&);
int main()
{
	double a,b,x;
	Input(a,b);
	int result = SolveEquation(a, b, x);
	if (result == 1)
		cout << "Nghiem x = " << x;
	else if (result == 0)
		cout << "Vo so nghiem";
	else
		cout << "Vo nghiem";
	return 0;
}

//method
void Input(double& aa,double &bb)
{
	cout << "Nhap a: ";
	cin >> aa;
	cout << "Nhap b: ";
	cin >> bb;
}
int SolveEquation(double aa,double bb, double& xOut) 
{
	if (aa == 0)
	{
		if (bb == 0)
			return 0;
		else
			return -1;
	}
	else
	{
		xOut = -bb / aa;
		return 1;
	}
}
