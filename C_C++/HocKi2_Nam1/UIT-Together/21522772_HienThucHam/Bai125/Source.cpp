#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void Input(int&);
double Abs(double);
int main()
{
	int a, b;
	Input(a);
	Input(b);
	a = Abs(a);
	b = Abs(b);
	cout << "Ket qua a,b lan luot la: " << a << ", " << b;
	
	return 0;
}

//method
void Input(int& nn)
{
	cout << "Nhap so nguyen: ";
	cin >> nn;
}
double Abs(double nn)
{
	if (nn < 0)
		return 0-nn;
	else 
		return nn;
}