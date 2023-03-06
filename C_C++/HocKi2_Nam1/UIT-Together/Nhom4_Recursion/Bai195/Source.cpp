#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;


void Nhap(float[], int);
void Xuat(float[], int);
bool KiemTraLanCan(float[], int, int);
bool IsEven(int);
int LietKe(float[], const int, int);
int main()
{
	int n;
	float a[100];
	cout << "Nhap n: ";
	cin >> n;
	Nhap(a, n);
	if (LietKe(a, n, n) == 0)
		cout << "Khong co so hop le.";
	//Xuat(a, n);
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

bool KiemTraLanCan(float a[], int n, int pos)
{
	if (pos == 0 && IsEven(a[pos]) && IsEven(a[pos + 1]))
		return 1;
	else if (pos == n - 1 && IsEven(a[pos]) && IsEven(a[pos - 1]))
		return 1;
	else if (pos > 0 && pos < n - 1)
		if ((IsEven(a[pos]) && IsEven(a[pos - 1])) || (IsEven(a[pos]) && IsEven(a[pos + 1])))
			return 1;
	return 0;
}
bool IsEven(int x)
{
	return x % 2 == 0 ? true : false;
}
int LietKe(float a[], const int length, int n)
{
	if (n == 0)
		return 0;
	int success = LietKe(a, length, n - 1);
	if (KiemTraLanCan(a, length, n - 1) == true)
	{
		cout << a[n - 1] << setw(8);
		success = 1;
	}
	return success;

}