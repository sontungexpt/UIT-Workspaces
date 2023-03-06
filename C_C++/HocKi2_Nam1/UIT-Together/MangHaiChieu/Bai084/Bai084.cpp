#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
#include <math.h>

using namespace std;

#define MAXR 500
#define MAXC 500

void Nhap(string, int[][MAXC], int&, int&);
void Xuat(int[][MAXC], int, int);
bool ktNguyenTo(int);
int NguyenToDau(int[][MAXC], int, int);
int NguyenToLonNhat(int[][MAXC], int, int);
string GetFileLink(string);

int main()
{
	string filename = GetFileLink("int");
	int row = 0;
	int col = 0;
	int a[MAXR][MAXC];

	Nhap(filename, a, row, col);
	Xuat(a, row, col);

	int kq = NguyenToLonNhat(a, row, col);
	cout << "\nSo nguyen to lon nhat trong ma tran la: " << kq;

	return 0;
}

void Nhap(string filename, int a[][MAXC], int& m, int& n)
{
	ifstream fi(filename);
	fi >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			fi >> a[i][j];
}

void Xuat(int a[][MAXC], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(8) << a[i][j];
		cout << endl;
	}
}

bool ktNguyenTo(int k)
{
	int dem = 0;

	for (int i = 1; i <= k; i++)
		if (k % i == 0)
			dem++;

	if (dem == 2)
		return true;
	return false;
}

int NguyenToDau(int a[][MAXC], int m, int n)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (ktNguyenTo(a[i][j]))
				return a[i][j];
}

int NguyenToLonNhat(int a[][MAXC], int m, int n)
{
	int lc = NguyenToDau(a, m, n);

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (ktNguyenTo(a[i][j]) && lc < a[i][j])
				lc = a[i][j];

	return lc;
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