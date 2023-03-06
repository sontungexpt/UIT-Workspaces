#include <iostream>

using namespace std;

int main()
{
	int n;
	double x;
	cin >> x >> n;
	double M = x;
	double S = 1;
	
	for (unsigned int i = 1; i <= n; i++)
	{
		S += 1 / M;
		M *= x + 1;
	}
	cout << S;
	return 0;
}