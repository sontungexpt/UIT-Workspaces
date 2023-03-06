#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void Input(double&);
bool IsTriangle(double, double, double);
int main()
{
	double x, y, z;
	Input(x);
	Input(y);
	Input(z);
	bool result = IsTriangle(x, y, z);
	if (result == 1)
		cout << "Ton tai tam giac";
	else
		cout << "Khong ton tai tam giac";
	return 0;
}

//method
void Input(double& nn)
{
	cout << "Nhap so nguyen: ";
	cin >> nn;
}
bool IsTriangle(double xx, double yy, double zz)
{
	if (abs(yy - zz) < xx && xx < yy + zz)
		return 1;
	else
		return 0;
}
