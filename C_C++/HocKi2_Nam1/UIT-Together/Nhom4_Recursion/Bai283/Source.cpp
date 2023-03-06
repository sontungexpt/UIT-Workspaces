#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>

using namespace std;

#define MAX_ROW 100
#define MAX_COL 100
void Nhap(int[][MAX_COL], int, int);
void Xuat(int[][MAX_COL], int, int);
void DeleteRow(int[][MAX_COL], int&, int, int);

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
	cout << endl << "Nhap hang can xoa: ";
	int rowDelete;
	cin >> rowDelete;
	DeleteRow(arr, row, col, rowDelete);
	cout << "Ma tran sau khi bi xoa hang " << rowDelete << " la: \n";
	Xuat(arr, row, col);
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

void DeleteRow(int a[][MAX_COL], int &row, int col, int rowDelete )
{
	if (col == 0)
	{
		row--;
		return;
	}
		
	DeleteRow(a, row, col - 1, rowDelete);
	for (int i = rowDelete; i < row; i++)
		a[i][col - 1] = a[i + 1][col - 1];
}

