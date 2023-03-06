#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void Input(int&);

double GetNumberAt(int);
int main()
{
	int n;
	Input(n);
	double result = GetNumberAt(n);
	cout << "So hang thu" << n << " cua day la: " << result;
	return 0;
}

//method
void Input(int& nn)
{
	cout << "Nhap so nguyen n: ";
	cin >> nn;
}

double GetNumberAt(int nn)
{
	double aPrevious = 2;
	double aCurrent = 0;
	for (int i = 2; i <= nn; i++)
	{
		aCurrent = (-9 * aPrevious - 24) / (5 * aPrevious + 13);
		aPrevious = aCurrent;
	}
	return aCurrent;

}