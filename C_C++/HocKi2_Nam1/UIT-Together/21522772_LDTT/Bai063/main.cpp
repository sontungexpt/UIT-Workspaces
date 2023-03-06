#include <iostream>

using namespace std;

int main()
{
	int n, unit;
	cout << "Nhap n: ";
	cin >> n;
	int T = 1;
	int temp = n;
	while (temp > 0)
	{
		unit = temp % 10;
		if (unit % 2 != 0)
		{
			T *= unit;
		}
		temp /= 10;
	}
	cout << "Ket qua la: " << T;
	return 0;
}