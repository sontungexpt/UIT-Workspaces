#include <iostream>

using namespace std;

int main()
{
	int n, unit;
	cout << "Nhap n: ";
	cin >> n;
	int max = 0;
	int temp = n;
	while (temp > 0)
	{
		unit = temp % 10;
		if (max < unit)
		{
			max = unit;
		}
		temp /= 10;
	}
	cout << "Chu so lon nhat la: " << max;
	return 0;
}