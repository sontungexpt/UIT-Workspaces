#include <iostream>

using namespace std;

int main()
{
	int n;
	double x;
	cout << "Nhap lan luot x, n: ";
	cin >> x >> n;
	double S = 0;
	double T = x;
	int dau = 1;
	unsigned int i = 1;
	while(i <= 2*n+1)
	{
		S += T * dau;
		T *= x * x;
		dau = -dau;
		i += 2;
	}
	cout << "Ket qua la: " << S;
	return 0;
}