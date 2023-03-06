#include <iostream>

using namespace std;

float Tong(float, int);

int main()
{
	int n;
	int x;
	cout << "Nhap x: ";
	cin >> x;
	cout << "Nhap n: ";
	cin >> n;
	cout << "Tong la: " << Tong(x, n);
	return 0;
}

float Tong(float x, int n)
{
	if (n == 0)
		return x;
	float T = Tong(x,n - 1);
	return (T * (x+n));
}