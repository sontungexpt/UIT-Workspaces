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
	while(i <= n)
	{
		aCurrent = (aBefore*aBefore+2)/(2*aBefore);
		aBefore = aCurrent;
		i++;
	}
	cout << "Ket qua la: " << aCurrent;
	return 0;
}