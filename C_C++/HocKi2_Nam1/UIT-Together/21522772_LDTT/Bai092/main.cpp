#include <iostream>

using namespace std;

int main()
{
	int n;
	double x;
	cout << "Nhap lan luot x,n: ";
	cin >> x >> n;
	double S = 1-x;
	int M = 1;
	double T = x;
	int dau = 1;
	unsigned int i = 3;
	while(i <= 2*n+1)
	{
		T *= x * x;
		M += (i - 1) * i;
		S += dau * T / M;
		dau = -dau;
		i += 2;
	}
	cout << "Ket qua la: " << S;
	return 0;
}