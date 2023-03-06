#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "nhap n: ";
	cin >> n;
	if (n <= 1)
		cout << "Khong la so nguyen to";
	for (int i = 2; i <= n/2; i++)
	{
		if (n % i == 0)
		{
			cout << "Khong la so nguyen to";
			exit(0);
		}
	}
	cout << "La so nguyen to";

	return 0;
}