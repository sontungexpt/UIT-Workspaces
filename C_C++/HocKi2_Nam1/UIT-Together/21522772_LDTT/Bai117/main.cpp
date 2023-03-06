#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int n;
	int aCurrent = 0;
	cout << "Nhap n: ";
	cin >> n;
	int aBeforeBefore = -1;
	int aBefore = 3;
	int T = 2;
	int i = 1;
	while(i <= n)
	{
		T *= 2;
		aCurrent = 5 * T + 5*aBefore - aBeforeBefore;
		aBeforeBefore = aBefore;
		aBefore = aCurrent;
		i++;
	}
	cout << "Ket qua la: " << aCurrent;
	return 0;
}