#include <iostream>
#include <iomanip>

using namespace std;

int ChuSoDau(int);
void LietKe(int[], int);
void Nhap(int[], int);
int main()
{
	int n;
	int a[100];
	cout << "Nhap n: ";
	cin >> n;
	Nhap(a, n);
	LietKe(a, n);
	return 0;
}
void Nhap(int a[], int n)
{
	if (n == 0)
		return;
	Nhap(a, n-1);
	cout << "Nhap a[" << n-1 << "]: ";
	cin >> a[n-1];
}

int ChuSoDau(int n)
{
	if (n < 10)
		return n;
	ChuSoDau(n / 10);
}

void LietKe(int a[], int n)
{
	if (n == 0)
		return;
	LietKe(a, n - 1);
	if (ChuSoDau(a[n - 1]) % 2 != 0)
		cout << setw(6) << a[n - 1];
}