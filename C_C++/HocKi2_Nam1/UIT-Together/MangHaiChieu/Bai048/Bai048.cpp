#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
#include <math.h>

using namespace std;

#define MAXR 500
#define MAXC 500

string GetFileLink(string);
void Nhap(string, int[][500], int&, int&);
int TongBien(int[][500], int, int);

int main()
{
	int row = 0;
	int col = 0;
	int a[MAXR][MAXC];
	Nhap(GetFileLink("int"), a, row, col);
	cout << "Tong cac so chinh phuong tren bien ma tran la: ";
	int kq = TongBien(a, row, col);
	cout << kq;
}

void Nhap(string filename, int a[][500], int& m, int& n)
{
	ifstream fi(filename);
	fi >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			fi >> a[i][j];
}

int TongBien(int a[][500], int m, int n)
{
	int s = 0;
	for (int j = 0; j <= n - 2; j++)
		for (int k = 1; (k * k) <= a[0][j]; k++)
			if (k * k == a[0][j])
				s = s + a[0][j];

	for (int i = 0; i <= m - 2; i++)
		for (int k = 1; (k * k) <= a[i][n - 1]; k++)
			if (k * k == a[i][n - 1])
				s = s + a[i][n - 1];

	for (int j = n - 1; j >= 1; j--)
		for (int k = 1; (k * k) <= a[m - 1][j]; k++)
			if (k * k == a[m - 1][j])
				s = s + a[m - 1][j];

	for (int i = m - 1; i >= 1; i--)
		for (int k = 1; (k * k) <= a[i][0]; k++)
			if (k * k == a[i][0])
				s = s + a[i][0];
	return s;
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