#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int n;
	cout << "Nhap n: ";
	cin >> n;
	bool flag = 1;
	int temp = n;
	int du = 0;

	while (temp > 1)
	{
		du = temp % 2;
		if (du != 0)
			flag = 0;
		temp /= 2;
	}
	if (flag == 1)
		cout << n << " co dang 2^m";
	else 
		cout << n << " khong co dang 2^m";

	return 0;
}