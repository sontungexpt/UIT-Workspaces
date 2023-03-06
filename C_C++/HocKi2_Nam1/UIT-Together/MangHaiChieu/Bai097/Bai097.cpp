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
void Nhap(string, float[][MAXC], int&, int&);
void Xuat(float[][MAXC], int, int);


int demDiemHoangHau(float[][MAXC], int, int);
bool laDiemHoangHau(float[][MAXC], int, int, int, int);
bool maxDong(float[][MAXC], int, int, int);
bool maxCot(float[][MAXC], int, int, int);
bool maxCheoPhai(float[][MAXC], int, int, int, int);
bool maxCheoTrai(float[][MAXC], int, int, int, int);


string GetFileLink(string);

int main()
{
	float a[MAXR][MAXC];
	int m;
	int n;
	Nhap(GetFileLink("float"), a, m, n);
	Xuat(a, m, n);
	cout << "so Hoang Hau: " << demDiemHoangHau(a, m, n);
	return 0;
}
//function
string GetFileLink(string dataTypeOfFile)
{
	string folderName = dataTypeOfFile;
	folderName[0] = toupper(folderName[0]);
	folderName += "MatranData";
	string fileLink = "../" + folderName + "/" + dataTypeOfFile + "matrandata";
	int fileIndex;
	cout << "Nhap so thu tu cua file can lay gia tri: ";
	cin >> fileIndex;
	if (fileIndex < 10)
		fileLink += '0';
	fileLink += to_string(fileIndex);
	string fileLinkInp = fileLink;
	fileLinkInp += ".inp";
	return fileLinkInp;
}

void Nhap(string filename, float a[][MAXC], int& m, int& n)
{
	ifstream fi(filename);
	fi >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			fi >> a[i][j];
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

int demDiemHoangHau(float a[][MAXC], int m, int n)
{
	int dem = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (laDiemHoangHau(a, m, n, i, j))
				dem++;
	return dem;
}

bool laDiemHoangHau(float a[][MAXC], int m, int n, int x, int y)
{
	if (maxDong(a, n, x, y) && maxCot(a, m, x, y) && maxCheoPhai(a, m, n, x, y) && maxCheoTrai(a, m, n, x, y))
		return true;
	return false;
}

bool maxDong(float a[][MAXC], int n, int x, int y)
{
	for (int j = 0; j < n; j++)
		if (a[x][j] > a[x][y])
			return false;
	return true;
}

bool maxCot(float a[][MAXC], int m, int x, int y)
{
	for (int i = 0; i < m; i++)
		if (a[i][y] < a[x][y])
			return false;
	return true;
}

bool maxCheoPhai(float a[][MAXC], int m, int n, int x, int y)
{
	for (int i = x + 1; i < m; i++)
		for (int j = y + 1; j < n; j++)
			if (a[i][j] > a[x][y])
				return false;
	return true;
}

bool maxCheoTrai(float a[][MAXC], int m, int n, int x, int y)
{
	for (int i = x + 1; i < m; i++)
		for (int j = y - 1; j >= 0; j--)
			if (a[i][j] > a[x][y])
				return false;
	return true;
}