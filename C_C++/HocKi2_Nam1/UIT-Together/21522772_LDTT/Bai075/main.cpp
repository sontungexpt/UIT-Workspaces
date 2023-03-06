#include <iostream>

using namespace std;

int main()
{
	int n;
	double x;
	int M = 1;
	double S = 1;
	double T = 1;
	cout << "Nhap lan luot x,n: ";
	cin >> x >> n;
	unsigned int i = 2;
	while(i <= 2*n)
	{
		M *= (i-1)*i;
		T *= x*x;
		S += T / M;
		i += 2;
	}
	cout << "Ket qua la: " << S;
	return 0;
}