#include <iostream>

using namespace std;

float Tinh(int);

int main()
{
	int n;
	cout << "Nhap n: ";
	cin >> n;
	cout << "Tong la: " << Tinh(n);
	return 0;
}

float Tinh(int n)
{
	if (n == 0)
		return 0;
	return sqrt(n+Tinh(n-1));
}