#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;


void Nhap(int[], int);
void DuongTangAmGiam(float[], int);
void Xuat(int[], int);
int main()
{
	int n;
	float a[100];
	cout << "Nhap n: ";
	cin >> n;
	Nhap(a, n);
	DuongTangAmGiam(a, n);
	Xuat(a, n);
	return 0;
}
void Nhap(float a[], int n)
{
	if (n == 0)
		return;
	Nhap(a, n - 1);
	cout << "Nhap a[" << n - 1 << "]: ";
	cin >> a[n - 1];
}
void Xuat(float a[], int n)
{
	if (n == 0)
		return;
	Xuat(a, n - 1);
	cout << setw(8) << a[n - 1];
}

void DuongTangAmGiam(float a[], int n)
{
	if (n == 1)
		return;
	for (int i = 0; i <= n - 2; i++)
	{
		if (a[i] > 0 && a[n - 1] > 0 && a[i] > a[n - 1])
			swap(a[i], a[n - 1]);
		if (a[i] < 0 && a[n - 1] < 0 && a[i] < a[n - 1])
			swap(a[i], a[n - 1]);
	}
	DuongTangAmGiam(a, n - 1);
}