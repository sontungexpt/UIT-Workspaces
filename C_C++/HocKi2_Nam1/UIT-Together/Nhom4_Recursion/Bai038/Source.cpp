#include <iostream>
#include <math.h>

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
	if (n == 1)
		return 0;
	return pow(n+Tinh(n-1),(float)1/n);
}