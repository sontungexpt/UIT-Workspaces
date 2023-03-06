#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "Nhap n: ";
	cin >> n;
	int count = 0;
	unsigned int i = 1;
	while(i <= n)
	{
		if (n % i == 0)
		{
			count ++;
		}
		i++;
	}
	cout << "Dem duoc: " << count;
	return 0;
}