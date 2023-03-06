#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
#include <math.h>

using namespace std;

#define MAXR 500
#define MAXC 500

//initalize function
void Nhap(float[][MAXC], int&, int&);
void Xuat(float[][MAXC], int, int);


string GetFileLink(string);

int main()
{
	float a[MAXR][MAXC];
	int m;
	int n;
	Nhap(a, m, n);
	Xuat(a, m, n);

	return 0;
}
//function

void Nhap(float a[][MAXC], int& m, int& n)
{
	cout << "nhap m";
	cin >> m;
	cout << "nhap n";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "nhap phan tu: ";
			cin >> a[i][j];
		}
	}
}

void Xuat(float a[][MAXC], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(8) << setprecision(3) << a[i][j];
		cout << endl;
	}
}

