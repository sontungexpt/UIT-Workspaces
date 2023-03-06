#include <iostream>
#include <iomanip>

using namespace std;


void Nhap(int[], int);
int DauTien(int[], int, int, int);

int main()
{
	int n;
	int x;
	int y;
	int a[100];
	cout << "Nhap n: ";
	cin >> n;
	Nhap(a, n);
	cout << "Nhap x: ";
	cin >> x;
	cout << "Nhap y: ";
	cin >> y;
	cout << "Chan dau: " << DauTien(a, n, x, y);
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

int DauTien(int a[], int n, int x, int y)
{
	if (n == 0)
		return x;
	int lc = DauTien(a, n - 1, x, y);
	if (lc != x)
		return lc;
	if (a[n - 1] > x && a[n - 1] < y)
		return a[n - 1];
	return x;
}