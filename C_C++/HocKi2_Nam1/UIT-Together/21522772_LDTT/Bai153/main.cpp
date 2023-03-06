#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int n;
	cout << "nhap n: ";
	cin >> n;
	bool flag = 1;
	int temp = n;
	int du = 0;

	while (temp > 1)
	{
		du = temp % 5;
		if (du != 0)
			flag = 0;
		temp /= 5;
	}
	if (flag == 1)
		cout << n << " co dang 5^m";
	else
		cout << n << " khong co dang 5^m";

	return 0;
}