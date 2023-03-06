#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int n;
	int aCurrent = 0;
	cout << "Nhap n: ";
	cin >> n;
	int aBefore = -2;
	int P = 3;
	int T = 7;
	int i = 2;
	while(i <= n)
	{
		P *= 3;
		T *= 7;

		aCurrent = 5*aBefore + 2 * P - 6*T +12;
		aBefore = aCurrent;
		i++;
	}
	cout << "ket qua la: " << aCurrent;
	return 0;
}