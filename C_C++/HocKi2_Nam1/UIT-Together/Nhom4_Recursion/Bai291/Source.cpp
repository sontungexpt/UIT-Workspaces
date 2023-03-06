#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>

using namespace std;

#define MAX_ROW 100
#define MAX_COL 100
void Nhap(float[][MAX_COL], int, int);
void Xuat(float[][MAX_COL], int, int);
void BienDoiMaTran(float[][MAX_COL], int, int);
int main()
{
	int row = 0;
	int col = 0;
	float arr[MAX_ROW][MAX_COL];
	cout << "Nhap hang: ";
	cin >> row;
	cout << "Nhap cot: ";
	cin >> col;
	Nhap(arr, row, col);
	Xuat(arr, row, col);
	BienDoiMaTran(arr, row, col);
	cout << "Ma tran sau khi bi bien doi la: \n";
	Xuat(arr, row, col);
	return 0;
}

void Nhap(float a[][MAX_COL], int row, int col)
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
void Xuat(float a[][MAX_COL], int row, int col)
{
	if (row == 0 || col == 0)
		return;
	Xuat(a, row - 1, col);
	for (int i = 0; i < col; i++)
		cout << setw(8) << a[row - 1][i];
	cout << endl;
}

void BienDoiMaTran(float a[][MAX_COL], int row, int col)
{
	if (row == 0 || col == 0)
		return;
	BienDoiMaTran(a, row - 1, col);
	for (int i = 0; i < col; i++)
		a[row - 1][i] = abs(a[row - 1][i]);
}

