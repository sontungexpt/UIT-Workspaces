#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <iomanip>
using namespace std;

#define MAXR 500
#define MAXC 500

void TaoMaTran(int[][MAXC], int&, int&);
void Xuat(int[][MAXC], int, int);
void XuatVaoFile(string, int[][MAXC], int, int);

int main()
{
	string fileName = "intmatrandata01.inp";
	int m;
	int n;
	int a[MAXR][MAXC];
	TaoMaTran(a, m, n);
	Xuat(a, m, n);
	XuatVaoFile(fileName, a, m, n);
	return 0;
}

void TaoMaTran(int a[][MAXC], int& m, int& n)
{
	srand(time(NULL));
	m = rand() % (100 + 1) + 100;
	n = rand() % (100 + 1) + 100;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = rand() % (200 + 1) - 100;
}

void Xuat(int a[][MAXC], int m, int n)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cout << setw(8) << a[i][j];
}

void XuatVaoFile(string filename, int a[][MAXC], int m, int n)
{
	ofstream fo(filename);
	if (fo.fail() == true)
	{
		cout << "Khong mo duoc file";
		exit(0);
	}
	fo << m << setw(8) << n << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			fo << setw(8) << a[i][j];
		fo << endl;
	}
}