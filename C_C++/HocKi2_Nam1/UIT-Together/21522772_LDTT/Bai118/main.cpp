#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int n;
	double aCurrent = 0;
	cout << "Nhap n: ";
	cin >> n;
	double aBefore = 2;
	int T = 2;
	int i = 1;
	while(i <= n)
	{
		aCurrent = (-9 * aBefore - 24) / (5 * aBefore + 13);
		aBefore = aCurrent;
		i++;
	}
	cout << "Ket qua la: " << aCurrent;
	return 0;
}