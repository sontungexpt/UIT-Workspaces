#include <iostream>

using namespace std;

int main()
{
	double x, n;
	cin >> x >> n;
	double S = 0;
	double T = 1;
	for (unsigned int i = 1; i <= n; i++)
	{
		T *= i;
		S += i*T ;
	}
	cout << S;
	return 0;
}