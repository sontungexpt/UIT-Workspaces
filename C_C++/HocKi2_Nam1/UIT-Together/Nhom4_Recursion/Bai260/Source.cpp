#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>

using namespace std;

#define MAX_ROW 100
#define MAX_COL 100
void Nhap(int[][MAX_COL], int, int);
void Xuat(int[][MAX_COL], int, int);
bool IsPerfectNumber(int);
bool TonTaiHoanThien(int[][MAX_COL], int, int);

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
	if (TonTaiHoanThien(arr, row, col) == 1)
		cout << "Ma tran co ton tai so hoan thien.";
	else
		cout << "Ma tran ko ton tai so hoan thien";
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

bool IsPerfectNumber(int x)
{
	if (x < 6)
		return 0;
	int sum = 0;
	for (int i = 1; i <= x / 2; i++)
		if (x % i == 0)
			sum += i;
	if (sum == x)
		return 1;
	return 0;
}


bool TonTaiHoanThien(int a[][MAX_COL], int row, int col)
{
	if (row == 0)
		return 0;
	int flag = TonTaiHoanThien(a, row - 1, col);
	for (int i = 0; i < col; i++)
		if (IsPerfectNumber(a[row-1][i]))
			flag = 1;
	return flag;
}

