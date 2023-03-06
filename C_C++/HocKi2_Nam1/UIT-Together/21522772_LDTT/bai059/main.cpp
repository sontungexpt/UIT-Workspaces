#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "Nhap n: ";
	cin >> n;
	int count = 0;
	int temp = n;
	while (temp > 0)
	{
		temp /= 10;
		count ++;
	}
	cout << "Dem duoc: " << count;
	return 0;
}