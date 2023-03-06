#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int n;
	int aCurrent = 0;
	cout << "Nhap n: ";
	cin >> n;
	int aBefore = 2;
	for (int i = 2; i <= n; i++)
	{
		aCurrent = aBefore + 2 * i + 1;
		aBefore = aCurrent;
	}
	cout << "Ket qua la: " << aCurrent;
	return 0;
}