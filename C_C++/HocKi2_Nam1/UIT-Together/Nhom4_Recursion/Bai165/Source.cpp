#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;


void Nhap(int[], int);
void ChanTangLeTang(int[], int);
void Xuat(int[], int);
int main()
{
	int n;
	int a[100];
	cout << "Nhap n: ";
	cin >> n;
	Nhap(a, n);
	ChanTangLeTang(a, n);
	Xuat(a, n);
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
void Xuat(int a[], int n)
{
	if (n == 0)
		return;
	Xuat(a, n - 1);
	cout <<setw(8)<< a[n - 1];
}

void ChanTangLeTang(int a[], int n)
{
	if (n == 1)
		return;
	for (int i = 0; i <= n - 2; i++)
	{
		if (a[i] % 2 == 0 && a[n - 1] % 2 == 0 && a[i] > a[n - 1])
			swap(a[i], a[n - 1]);
		if (a[i] % 2 != 0 && a[n - 1] % 2 != 0 && a[i] > a[n - 1])
			swap(a[i], a[n - 1]);
	}
	ChanTangLeTang(a, n - 1);
}