#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int n;
	double aCurrent = 0;
	double bCurrent = 0;
	cout << "Nhap n: ";
	cin >> n;
	double aBefore = 1;
	double bBefore = 1;
	int i = 2;
	while(i <= n)
	{
		aCurrent = 3*bBefore + 2*aBefore;
		bBefore = aBefore + 3 * bBefore;
		aBefore = aCurrent;
		bBefore = bCurrent;
		i++;
	}
	cout << "Ket qua la: " << aCurrent;
	return 0;
}