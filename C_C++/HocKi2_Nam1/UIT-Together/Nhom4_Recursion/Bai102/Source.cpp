#include <iostream>
#include <iomanip>

using namespace std;


void Nhap(int[], int);
int DemGiaTri(int[], int);

int main()
{
	int n;
	int a[100];
	cout << "Nhap n: ";
	cin >> n;
	Nhap(a, n);
	cout << "so luong so chan: " << DemGiaTri(a, n);
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

int DemGiaTri(int a[], int n)
{
	if (n == 0)
		return 0;
	int dem = DemGiaTri(a, n - 1);
	if (a[n - 1] > 0 && a[n - 1] % 7 == 0)
		dem++;
	return dem;
}