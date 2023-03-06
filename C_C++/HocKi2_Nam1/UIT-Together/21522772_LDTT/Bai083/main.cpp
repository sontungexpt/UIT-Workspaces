#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int n;
	double x;
	cout << "Nhap lan luot x,n: ";
	cin >> x >> n;
	double S = 0;
	int T = 1;
	unsigned int i = 1;
	while(i <= n)
	{
		T *= x;
		S += sin(T);
		i++
	}
	cout << "Ket qua la: " << S;
	return 0;
}