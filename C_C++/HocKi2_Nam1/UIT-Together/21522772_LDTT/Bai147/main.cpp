#include <iostream>

using namespace std;

int main()
{
	int n,unit;
	cout << "nhap n: ";
	cin >> n;
	int flag =1;
	int temp = n;
	while (temp > 0)
	{
		unit = temp % 10;
		if (unit % 2 == 0)
		{
			flag = 0;
		}
		temp /= 10;
	}
	if (flag ==1)
		cout << n<<"Toan le";
	else
		cout << n<<"Khong toan le";
	return 0;
}