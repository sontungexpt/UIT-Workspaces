#include <iostream>

using namespace std;

int main()
{
	int n;
	double x;
	cout << "Nhap lan luot x, n: ";
	cin >> x >> n;
	double S = 0;
	double T = 1;
	int dau = 1;
	unsigned int i = 1;
	while(i <= n)
	{
		T *= x;
		S += dau * T;
		dau = -dau;
		i++;
	}
	cout <<"Ket qua la: " << S;
	return 0;
}