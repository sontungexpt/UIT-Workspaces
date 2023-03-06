#include <iostream>

using namespace std;

int main()
{
	int n, unit;
	cout << "Nhap n: ";
	cin >> n;
	int S = 0;
	int temp = n;
	while (temp > 0)
	{
		unit = temp % 10;
		if (unit % 2 == 0)
		{
			S += unit;
		}
		temp /= 10;
	}
	cout <<"Tong cac chu so chan la: " << S;
	return 0;
}