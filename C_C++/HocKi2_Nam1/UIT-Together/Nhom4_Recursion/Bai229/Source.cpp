#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>

using namespace std;

#define MAX_ROW 100
#define MAX_COL 100
void Nhap(float[][MAX_COL], int, int);
void Xuat(float[][MAX_COL], int, int);
float TichDuongCot(float[][MAX_COL], int, int , int);

int main()
{
	int row = 0;
	int col = 0;
	int colChoice = 0;
	float arr[MAX_ROW][MAX_COL];
	cout << "Nhap hang: ";
	cin >> row;
	cout << "Nhap cot: ";
	cin >> col;
	Nhap(arr, row, col);
	Xuat(arr, row, col);
	cout << "Nhap cot can tinh tich: ";
	cin >> colChoice;
	cout << endl;
	cout << "Tich cac so duong o cot thu: "<<colChoice <<"la: " << TichDuongCot(arr, row, col, colChoice);
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


float TichDuongCot(float a[][MAX_COL], int row, int col, int colChoice)
{
	if (colChoice >= col || colChoice < 0)
		return 0;
	if (row == 0)
		return 1;
	float product = TichDuongCot(a, row - 1, col, colChoice);
	if (a[row - 1][colChoice] > 0)
		product *= a[row - 1][colChoice];
	return product;
}