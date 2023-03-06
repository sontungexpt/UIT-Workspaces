#include <iostream>

using namespace std;

int main()
{
	int n, unit;
	cout << "Nhap n: ";
	cin >> n;
	int count = 0;
	int temp = n;
	while (temp > 0)
	{
		unit = temp % 10;
		if (unit % 2 != 0)
		{
			count++;
		}
		temp /= 10;
	}
	cout << "So chu so le: " << count;
	return 0;
}