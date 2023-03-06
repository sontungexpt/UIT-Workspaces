#include<iostream>

using namespace std;

int main()
{
	int n,unit;
	cout << "Nhap n:";
	cin >> n;
	int S = 0;
	int temp = n;
	while (temp > 0)
	{
		unit = temp % 10;
		S = S * 10 + unit;
		temp /= 10;
	}
	if (S == n)
		cout << "La So Doi Xung";
	else
		cout << "Khong La So Doi Xung";
	return 0;
}