#include <iostream>

using namespace std;

int main()
{
	int n;
	double x;
	cout << "Nhap lan luot x, n: ";
	cin >> x >> n;
	int M = 1;
	double S = 0;
	double T = 1;
	unsigned int i = 1;
	while(i <= n)
	{
		M *= i;
		T *= x;
		S += T / M;
		i++;
	}
	cout <<"Ket qua la:" << S;
	return 0;
}