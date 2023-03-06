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
	int i = 2;
	while(i <= n )
	{
		aCurrent = 5*aBefore  +sqrt(24*aBefore*aBefore-8);
		aBefore = aCurrent;
		i++;
	}
	cout << "Ket qua la: " << aCurrent;
	return 0;
}