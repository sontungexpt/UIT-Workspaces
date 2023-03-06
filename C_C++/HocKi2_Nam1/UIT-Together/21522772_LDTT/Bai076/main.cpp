#include <iostream>

using namespace std;

int main()
{
	int n;
	double x;
	cout << "Nhap lan luot x,n: ";
	cin >> x >> n;
	int M = 1;
	double S = 1+x;
	double T = x;
	unsigned int i = 3;
	while(i <= 2*n+1)
	{
		M *= i*(i-1);
		T *= x*x;
		S += T / M;
		i += 2;
	}
	cout << "ket qua la: " << S;
	return 0;
}