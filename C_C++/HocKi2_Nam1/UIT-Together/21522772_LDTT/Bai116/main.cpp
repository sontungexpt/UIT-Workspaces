#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int n;
	int aCurrent = 0;
	cout << "Nhap n: ";
	cin >> n;
	int aBeforeBefore = 1;
	int aBefore = 2;
	int i = 1;
	while(i <= n)
	{
		aCurrent = 4 * aBefore + aBeforeBefore;
		aBeforeBefore = aBefore;
		aBefore = aCurrent;
		i++;
	}
	cout << "Ket qua la: " << aCurrent;
	return 0;
}