#include <iostream>
#include <iomanip>

using namespace std;


void Nhap(int[], int);

int ChanCuoi(int[], int);

int main()
{
	int n;
	int x;
	int y;
	int a[100];
	cout << "Nhap n: ";
	cin >> n;
	Nhap(a, n);
	cout << "Chan cuoi: " << ChanCuoi(a, n);
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

int ChanCuoi(int a[], int n)
{
	if (n == 0)
		return -1;
	if (a[n - 1] % 2 == 0)
		return a[n - 1];
	return ChanCuoi(a, n - 1);
}