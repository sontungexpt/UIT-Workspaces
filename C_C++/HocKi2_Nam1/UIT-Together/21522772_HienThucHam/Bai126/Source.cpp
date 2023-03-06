#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void Input(int&);
double Max(double, double);
int main()
{
	int a, b;
	Input(a);
	Input(b);
	double result = Max(a, b);
	cout << "Gia tri lon nhat la: " << result;

	return 0;
}

//method
void Input(int& nn)
{
	cout << "Nhap so nguyen: ";
	cin >> nn;
}
double Max(double aa, double bb)
{
	double max = aa >= bb ? aa : bb;
	return max;
}