#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
#include <math.h>

using namespace std;

#define MAXR 500
#define MAXC 500

void Nhap(string, float[][MAXC], int&, int&);
void Xuat(float[][MAXC], int, int);
int ktCucTieu(float[][MAXC], int, int, int, int);
int DemCucTieu(float[][MAXC], int, int);
int ktCucDai(float[][MAXC], int, int, int, int);
int DemCucDai(float[][MAXC], int, int);
int DemCucTri(float[][MAXC], int, int);
string GetFileLink(string);

int main()
{
	string filename = GetFileLink("float");
	int row = 0;
	int col = 0;
	float a[MAXR][MAXC];

	Nhap(filename, a, row, col);
	Xuat(a, row, col);

	int kq = DemCucTri(a, row, col);
	cout << "\nSo luong cuc tri trong ma tran la: " << kq;

	return 0;
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
			cout << setw(8) << a[i][j];
		cout << endl;
	}
}

int ktCucTieu(float a[][MAXC], int m, int n, int vtd, int vtc)
{
	int i = vtd;
	int j = vtc;

	if (a[i][j] < a[i + 1][j] && a[i][j] < a[i - 1][j] && a[i][j] < a[i][j + 1] && a[i][j] < a[i][j - 1])
		return 1;
	return 0;
}

int DemCucTieu(float a[][MAXC], int m, int n)
{
	int dem = 0;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (ktCucTieu(a, m, n, i, j) == 1)
				dem++;

	return dem;
}

int ktCucDai(float a[][MAXC], int m, int n, int vtd, int vtc)
{
	int i = vtd;
	int j = vtc;
	if (a[i][j] > a[i + 1][j] && a[i][j] > a[i - 1][j] && a[i][j] > a[i][j + 1] && a[i][j] > a[i][j - 1])
		return 1;
	return 0;
}

int DemCucDai(float a[][MAXC], int m, int n)
{
	int dem = 0;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (ktCucDai(a, m, n, i, j) == 1)
				dem++;

	return dem;
}


int DemCucTri(float a[][MAXC], int m, int n)
{
	return DemCucDai(a, m, n) + DemCucTieu(a, m, n);
}

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