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
	int i = 1;
	while(i <= n)
	{
		aCurrent = 5*aBefore+ 6*aBeforeBefore;
		aBeforeBefore = aBefore;
		aBefore = aCurrent;
		i++;
	}
	cout << "Ket qua la: " << aCurrent;
	return 0;
}