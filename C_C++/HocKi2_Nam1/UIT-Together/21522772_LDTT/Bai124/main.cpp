#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int n;
	double aCurrent = 0;
	double bCurrent = 0;
	cout << "nhap n: ";
	cin >> n;
	double aBefore = 2;
	double bBefore = 1;
	int i = 2;
	while(i <= n)
	{
		aCurrent = aBefore*aBefore + 2*bBefore*bBefore;
		bBefore = 2*aBefore* bBefore;
		aBefore = aCurrent;
		bBefore = bCurrent;
		i++;
	}
	cout << "Ket qua la: " << aCurrent;
	return 0;
}