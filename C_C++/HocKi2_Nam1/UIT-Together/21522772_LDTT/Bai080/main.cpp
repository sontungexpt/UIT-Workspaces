#include <iostream>

using namespace std;

int main()
{
	int n;
	float x;
	cin >> x >> n;
	double S = 1;
	double T = 1;
	for (unsigned int i = 1; i <= n; i++)
	{
		T *= x;
		S += (i+1)*T;
	}
	cout << S;
	return 0;
}