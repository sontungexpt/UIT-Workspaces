#include <iostream>

using namespace std;

int main()
{
	int n;
	double x;
	double T = x;
	double S = x;
	cout << "Nhap lan luot x ,n: ";
	cin >> x >> n;
	unsigned int i = 1;
	while(i <= 2 * n+1)
	{
		T *= x * x;
		S += T;
		i += 2;
	}
	cout << "Ket qua la: " << S;
	return 0;
}