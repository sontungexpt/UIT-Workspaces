#include <iostream>

using namespace std;

int main()
{
	int n, unit;
	cin >> n;
	int T = 1;
	int temp = n;
	while (temp > 0)
	{
		unit = temp % 10;
		T *= unit;
		temp /= 10;
	}
	cout << T;
	return 0;
}