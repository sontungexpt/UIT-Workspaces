#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>

using namespace std;

#define MAX_ROW 100
#define MAX_COL 100
void Nhap(int[][MAX_COL], int, int);
void Xuat(int[][MAX_COL], int, int);
bool KtDong(int[][MAX_COL], int, int, int);
void LietKe(int[][MAX_COL], int, int);

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
	cout << endl<<"Cac dong toan gia tri chan la: \n";
	LietKe(arr,row, col);
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

bool KtDong(int a[][MAX_COL], int row, int col, int rowCheck)
{
	if (col == 0)
		return 1;
	bool flag = KtDong(a, row, col - 1,rowCheck);
	if (a[rowCheck][col - 1] % 2 != 0)
		flag = 0;
	return flag;
}


void LietKe(int a[][MAX_COL], int row, int col)
{
	if (row == 0)
		return;
	LietKe(a, row - 1, col);
	if (KtDong(a,row,col,row-1) == true)
		for (int i = 0; i < col; i++)
			cout << setw(8) << a[row - 1][i];
	cout << endl;
}

