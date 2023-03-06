#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>

using namespace std;

#define MAX_ROW 100
#define MAX_COL 100
void Nhap(int[][MAX_COL], int, int);
void Xuat(int[][MAX_COL], int, int);
bool IsPrimeNumber(int);
int TongNguyenTo(int[][MAX_COL], int, int);

int main()
{
	int row = 0;
	int col = 0;
	int arr[MAX_ROW][MAX_COL];
	cout << "Nhap hang: ";
	cin >> row;
	cout << "Nhap cot: ";
	cin >> col;
	Nhap(arr, row, col);
	Xuat(arr, row, col);
	cout << endl;
	cout <<"Tong cac so nguyen to la: " << TongNguyenTo(arr, row, col);

	return 0;
}

void Nhap(int a[][MAX_COL], int row, int col)
{
	if (row == 0 || col == 0)
		return;
	Nhap(a, row - 1, col);
	for (int i = 0; i < col; i++)
	{
		cout << "Nhap a[" << row - 1 << "][" << i << "]: ";
		cin >> a[row - 1][i];
	}
}
void Xuat(int a[][MAX_COL], int row, int col)
{
	if (row == 0 || col == 0)
		return;
	Xuat(a, row - 1, col);
	for (int i = 0; i < col; i++)
		cout << setw(8) << a[row - 1][i];
	cout << endl;
}

bool IsPrimeNumber(int x)
{
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0) return false;
	return x > 1;
}

int TongNguyenTo(int a[][MAX_COL], int row, int col)
{
	if (row == 0)
		return 0;
	int sum = TongNguyenTo(a, row - 1, col);
	for (int i = 0; i < col; i++)
		if (IsPrimeNumber(a[row - 1][i]))
			sum += a[row - 1][i];
	return sum;
}