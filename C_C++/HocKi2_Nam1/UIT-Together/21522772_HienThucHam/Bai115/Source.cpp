#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void Input(int&);
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

int GetNumberAt(int nn)
{
	int aPreviousOfPrevious=-1;
	int aPrevious = 3;
	int aCurrent = 0;
	for (int i = 1; i <= nn; i++)
	{
		aCurrent = 5 * aPrevious + 6 * aPreviousOfPrevious;
		aPrevious = aCurrent;
		aPreviousOfPrevious = aPrevious;
	}
	return aCurrent;

}