#include <iostream>
#include <math.h>

using namespace std;

float TinhAn(int);
float TinhBn(int);


int main()
{
	int k;
	cout << "Nhap k: ";
	cin >> k;
	cout << "\nSo hang thu k cua a la: " << TinhAn(k);
	cout << "\nSo hang thu k cua b la: " << TinhBn(k);
	return 0;
}

float Tinh(int n)
{
	if (n == 1)
		return 2;
	int x = TinhAn(n - 1);
	int y = TinhBn(n - 1);
	return (3 * y + 2 * x);
}

float TinhBn(int n)
{
	if (n == 1)
		return 1;
	int x = TinhAn(n - 1);
	int y = TinhBn(n - 1);
	return (x + 3 * y);
}