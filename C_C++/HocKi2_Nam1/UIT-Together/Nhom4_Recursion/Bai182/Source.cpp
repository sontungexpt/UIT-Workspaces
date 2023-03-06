#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;


void Nhap(float[], int);
int DemConTang(float[], int);
void Xuat(float[], int);
bool KiemTraMangTang(float[], int);
int main()
{
	int n;
	float a[100];
	cout << "Nhap n: ";
	cin >> n;
	Nhap(a, n);
	cout << DemConTang(a, n);
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

bool KiemTraMangTang(float a[], int n)
{
	if (n == 1)
		return 1;
	bool flag = KiemTraMangTang(a, n - 1);
	if (flag == 0)
		return 0;
	if (a[n - 2] > a[n-1])
		return 0;
	else 
		return 1;
}

int DemConTang(float a[], int n)
{
	if (n == 0)
		return  0;
	int dem = DemConTang(a, n - 1);
	for (int i = 2; i <= n; i++)
	{
		float* temp = new float[i];
		for (int j = 0; j < i; j++)
			temp[j] = a[n - i + j];
		if (KiemTraMangTang(temp, i) == 1)
		{
			dem++;
		}
	}
	return dem;
}