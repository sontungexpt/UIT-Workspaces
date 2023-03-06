#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "Nhap n: ";
	cin >> n;
	int T = 1;
	unsigned int i = 1;
	while(i <= n)
	{
		T *= i;
		i++;
	}
	cout <<"Ket qua la: " << T;
	return 0;
}