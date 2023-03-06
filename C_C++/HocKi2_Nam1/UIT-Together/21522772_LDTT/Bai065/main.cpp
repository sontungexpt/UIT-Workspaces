#include <iostream>

using namespace std;

int main()
{
	int n, unit;
	cout << "Nhap n: ";
	cin >> n;
	int min = n%10;
	int temp = n/10;
	while (temp > 0)
	{
		unit = temp % 10;
		if (min > unit)
		{
			min = unit;
		}
		temp /= 10;
	}
	cout << "Chu so nho nhat la: " << min;
	return 0;
}