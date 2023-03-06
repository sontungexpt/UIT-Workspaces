#include <iostream>
#include <iomanip>

using namespace std;


void Nhap(int[], int);
int TimGiaTri(int[], int);
int ktToanLe(int);

int main()
{
	int n;
	int a[100];
	cout << "Nhap n: ";
	cin >> n;
	Nhap(a, n);
	cout << "Chan cuoi: " << TimGiaTri(a, n);
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

int TimGiaTri(int a[], int n)
{
	if (n == 0)
		return 0;
	int lc = TimGiaTri(a, n - 1);
	if (!ktToanLe(a[n - 1]))
		return lc;
	if (lc == 0)
		return a[n - 1];
	if (a[n - 1] > lc)
		lc = a[n - 1];
	return lc;
}

int ktToanLe(int n)
{
	n = abs(n);
	if (n <= 9)
	{
		if (n % 2 != 0)
			return 1;
		return 0;
	}
	int dv = n % 10;
	if (ktToanLe(n / 10) == 1 && dv % 2 != 0)
		return 1;
	return 0;
}