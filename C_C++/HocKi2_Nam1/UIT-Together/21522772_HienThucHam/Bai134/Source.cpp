#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void Input(double&);

int main()
{
	double x, y, z;
	Input(x);
	Input(y);
	Input(z);
	if (x<=y&&y<=z)
		cout << "Bat dang thuc dung";
	else
		cout << "Bat dang thuc Sai";
	return 0;
}

//method
void Input(double& nn)
{
	cout << "Nhap so: ";
	cin >> nn;
}

