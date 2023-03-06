#include <iostream>
#include <iomanip>

using namespace std;


void Nhap(int[], int);
int ChanDau(int[], int);

int main()
{
	int n;
	int a[100];
	cout << "Nhap n: ";
	cin >> n;
	Nhap(a, n);
	cout << "Chan dau: " << ChanDau(a, n);
	return 0;
}
void Nhap(int a[], int n)
{
	if (n == 0)
		return;
	Nhap(a, n - 1);
	cout << "Nhap a[" << n - 1 << "]: ";
	cin >> a[n - 1];
}

int ChanDau(int a[], int n)
{
	if (n == 0)
		return -1;
	int lc = ChanDau(a, n - 1);
	if (lc != -1)
		return lc;
	if (a[n - 1] % 2 == 0)
		return a[n - 1];
	return -1;
}