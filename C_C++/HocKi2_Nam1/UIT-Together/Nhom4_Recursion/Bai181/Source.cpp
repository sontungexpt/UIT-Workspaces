#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;


void Nhap(float[], int);
void LietKeToanDuong(float[], int);
void Xuat(float[], int);
bool KiemTraMangDuong(float[], int);
int main()
{
	int n;
	float a[100];
	cout << "Nhap n: ";
	cin >> n;
	Nhap(a, n);
	LietKeToanDuong(a, n);
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

bool KiemTraMangDuong(float a[], int n)
{
	if (n == 0)
		return 1;
	bool flag =  KiemTraMangDuong(a, n - 1);
	if (flag == 0)
		return 0;
	if (a[n-1] < 0)
		return 0;
	else if (a[n-1] > 0)
		return 1;		
}

void LietKeToanDuong(float a[], int n)
{
	if (n ==  0)
		return;
	LietKeToanDuong(a, n - 1);
	for (int i = 2; i <= n; i++)
	{
		float *temp = new float[i];
		for (int j = 0; j < i; j++)
			temp[j] = a[n - i + j];
		if (KiemTraMangDuong(temp, i) == 1)
		{
			Xuat(temp, i);
			cout << endl;
		}
	}
}