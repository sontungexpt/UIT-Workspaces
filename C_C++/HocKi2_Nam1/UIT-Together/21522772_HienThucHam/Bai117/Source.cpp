#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void Input(int&);
double Pow(double, int);
int GetNumberAt(int);
int main()
{
	int n;
	Input(n);
	int result = GetNumberAt(n);
	cout << "So hang thu" << n << " cua day la: " << result;
	return 0;
}

//method
void Input(int& nn)
{
	cout << "Nhap so nguyen n: ";
	cin >> nn;
}
double Pow(double xx, int nn)
{
	double product = 1;
	if (nn == 0)
		return 1;
	for (int i = 1; i <= nn; i++)
	{
		product *= xx;
	}
	return product;
}
int GetNumberAt(int nn)
{
	int aPreviousOfPrevious = -1;
	int aPrevious = 3;
	int aCurrent = 0;
	for (int i = 2; i <= nn; i++)
	{
		aCurrent = 5*Pow(2,i)+5 * aPrevious - aPreviousOfPrevious;
		aPrevious = aCurrent;
		aPreviousOfPrevious = aPrevious;
	}
	return aCurrent;

}