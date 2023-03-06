#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int n;
	double x;
	cin >> x >> n;
	double S = 0;
	double T = 1;
	for (unsigned int i = 1; i <= n; i++)
	{
		T *= sin(x);
		S += T;
	}
	cout << S;
	return 0;
}