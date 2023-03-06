#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "Nhap n: ";
	cin >> n;
	int S = 0;
	unsigned int i = 2;
	while(i <= n)
	{
		if (n % i == 0)
		{
			S = S + i;
		}
		i += 2;
	}
	cout <<"Ket qua la: " << S;
	return 0;
}