#include <iostream>

using namespace std;

int main()
{
	int n, unit;
	cout << "Nhap n: ";
	cin >> n;
	bool flag = 0;
	int temp = n;
	while (temp > 0)
	{
		unit = temp % 10;
		if (unit % 2 != 0)
		{
			flag = 1;
			break;
		}
		temp /= 10;
	}
	if (flag == 1)
		cout << "Ton tai chu so le";
	else
		cout << "Khong ton tai chu so le";
	return 0;
}