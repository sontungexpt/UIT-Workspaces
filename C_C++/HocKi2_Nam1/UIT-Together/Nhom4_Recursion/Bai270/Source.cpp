#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>

using namespace std;

#define MAX_ROW 100
#define MAX_COL 100
void Nhap(int[][MAX_COL], int, int);
void Xuat(int[][MAX_COL], int, int);
bool KtCot(int[][MAX_COL], int, int, int);
void LietKe(int[][MAX_COL], int, int);
bool IsSquareNumber(int);
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
	cout << endl << "Cac cot co ton tai so chinh phuong la: \n";
	LietKe(arr, row, col);
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
bool IsSquareNumber(int x)
{
	if (x < 1)
		return 0;
	for (int i = 1; i * i <= x; i++)
		if (i * i == x)
			return 1;
	return 0;
}

bool KtCot(int a[][MAX_COL], int row, int col, int colCheck)
{
	if (row == 0 || col == 0)
		return 0;
	bool flag = KtCot(a, row - 1, col, colCheck);
	if (IsSquareNumber(a[row - 1][colCheck]))
		flag = 1;
	return flag;
}

void LietKe(int a[][MAX_COL], int row, int col)
{
	if (col == 0)
		return;
	LietKe(a, row , col-1);
	if (KtCot(a, row, col, col - 1) == true)
		for (int i = 0; i < row; i++)
			cout << setw(8) << a[i][col-1];
	cout << endl;
}

