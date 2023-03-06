#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "Nhap n: ";
	cin >> n;
	int S = 0;
	unsigned int i = 1;
	while(i <= n)
	{
		S += i;
		i++;
	}
	cout << "Ket qua la: " << S;
	return 0;
}
