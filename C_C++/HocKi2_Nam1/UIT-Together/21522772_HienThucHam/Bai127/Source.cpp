#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void Input(int&);
double Min(double, double);
int main()
{
	int a, b;
	Input(a);
	Input(b);
	double result = Min(a, b);
	cout << "Gia tri nho nhat la: " << result;

	return 0;
}

//method
void Input(int& nn)
{
	cout << "Nhap so nguyen: ";
	cin >> nn;
}
double Min(double aa, double bb)
{
	double max = aa <= bb ? aa : bb;
	return max;
}