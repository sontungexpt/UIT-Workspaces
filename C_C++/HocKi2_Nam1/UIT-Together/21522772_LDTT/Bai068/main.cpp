#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "Nhap n: ";
	cin >> n;
	int S = 0;
	int T = 1;
	unsigned int i = 1;
	while(i <= n)
	{
		T *= i;
		S += T;
		i++;
	}
	cout << "Ket qua la: "<< S;
	return 0;
}