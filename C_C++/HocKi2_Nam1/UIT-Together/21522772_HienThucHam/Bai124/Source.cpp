#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void Input(int&);
void GetNumberAt(int nn, int&, int&);
double GetNumberAt(int);
int main()
{
	int n, a, b;
	Input(n);
	GetNumberAt(n, a, b);
	cout << "So hang thu" << n << " cua day la (a,b) = (" << a << "," << b << ")";
	return 0;
}

//method
void Input(int& nn)
{
	cout << "Nhap so nguyen n: ";
	cin >> nn;
}

void GetNumberAt(int nn, int& aOut, int& bOut)
{
	double aPrevious = 1;
	double aCurrent = 0;
	double bPrevious = 1;
	double bCurrent = 0;
	for (int i = 2; i <= nn; i++)
	{
		aCurrent = aPrevious* aPrevious + 2 * bPrevious*bPrevious;
		bCurrent = 2*aPrevious* bPrevious;
		aPrevious = aCurrent;
		bPrevious = bCurrent;
	}
}