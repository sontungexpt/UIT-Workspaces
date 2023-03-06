#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "Nhap n: ";
	cin >> n;
	int count = 0;
	unsigned int i = 2;
	while(i <= n)
	{
		if (n % i == 0)
		{
			count ++;
		}
		i += 2;
	}
	cout <<"Dem duoc: " <<count;
	return 0;
}