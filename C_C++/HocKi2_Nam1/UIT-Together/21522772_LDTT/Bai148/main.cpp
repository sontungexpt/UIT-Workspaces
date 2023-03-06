#include <iostream>

using namespace std;

int main()
{
	int n, unit;
	cout << "Nhap n: ";
	cin >> n;
	int flag = 1;
	int temp = n;
	while (temp > 0)
	{
		unit = temp % 10;
		if (unit % 2 != 0)
		{
			flag = 0;
		}
		temp /= 10;
	}
	if (flag == 1)
		cout << n << "Toan chan";
	else
		cout << n << "Khong toan chan";
	return 0;
}