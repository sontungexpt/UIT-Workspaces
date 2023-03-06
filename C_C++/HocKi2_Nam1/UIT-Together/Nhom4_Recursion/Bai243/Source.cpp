#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>

using namespace std;

#define MAX_ROW 100
#define MAX_COL 100
void Nhap(int[][MAX_COL], int, int);
void Xuat(int[][MAX_COL], int, int);
int DemChuSoDauChan(int[][MAX_COL], int, int, int);
bool IsEvenFirstDigit(int);

int main()
{
	int row = 0;
	int col = 0;
	int colChoice = 0;
	int arr[MAX_ROW][MAX_COL];
	cout << "Nhap hang: ";
	cin >> row;
	cout << "Nhap cot: ";
	cin >> col;
	Nhap(arr, row, col);
	Xuat(arr, row, col);
	cout << "Nhap cot can tinh tich: ";
	cin >> colChoice;
	cout << endl;
	cout << "So cac chu so co chu so dau tien chan la: " << DemChuSoDauChan(arr, row, col, colChoice);
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

bool IsEvenFirstDigit(int x)
{
	if (x <= 9)
	{
		if (x % 2 == 0)
			return 1;
		return 0;
	}
	return IsEvenFirstDigit(x / 10);
}

int DemChuSoDauChan(int a[][MAX_COL], int row, int col, int colChoice)
{
	if (colChoice >= col || colChoice < 0)
		return 0;
	if (row == 0)
		return 0;
	int count = DemChuSoDauChan(a, row - 1, col, colChoice);
	if (IsEvenFirstDigit(a[row - 1][colChoice]))
		count++;
	return count;
}

