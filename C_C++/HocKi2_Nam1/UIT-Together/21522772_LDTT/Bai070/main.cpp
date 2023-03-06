#include <iostream>

using namespace std;

int main()
{
	int n;
	double x;
	double S = 0;
	double T = 1;
	cout << "Nhap lan luot x, n: ";
	cin >>x>> n;
	unsigned int i = 2;
	while(i <= 2*n)
	{
		T *= x*x;
		S += T;
		i += 2;
	}
	cout << S;
	return 0;
}