#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int n;
	double aCurrent = 0;
	cout << "Nhap n: ";
	cin >> n;
	double aBeforeBefore = 1;
	double aBefore = 1;
	int i = 2;
	while (i <= n)
	{
		aCurrent = aBeforeBefore + aBefore;
		aBeforeBefore = aBefore;
		aBefore = aCurrent;
		i++;
	}
	cout << "Ket qua la: " << aCurrent;
	return 0;
}