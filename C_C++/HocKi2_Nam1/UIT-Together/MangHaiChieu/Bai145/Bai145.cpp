#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

#define MAXR 500
#define MAXC 500

string GetFileLink(string);
void NhapMaTran(string, float[][MAXC], int&, int&);
bool ktCot(float[][MAXC], int, int);
void XoaCot(float[][MAXC], int, int&, int);
void XoaCot(float[][MAXC], int, int&);
void Xuat(float[][MAXC], int, int);

int main()
{
	int m;
	int n;
	float a[MAXR][MAXC];
	NhapMaTran(GetFileLink("float"), a, m, n);
	XoaCot(a, m, n);
	Xuat(a, m, n);
	return 0;
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

void NhapMaTran(string filename, float a[][MAXC], int& m, int& n)
{
	ifstream fi(filename);
	if (fi.fail() == true)
	{
		cout << "Khong mo duoc file";
		exit(0);
	}
	fi >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			fi >> a[i][j];
}

bool ktCot(float a[][MAXC], int m, int j)
{
	int demDuong = 0;
	int demAm = 0;
	for (int i = 0; i < m; i++)
		if (a[i][j] >= 0)
			demDuong++;
		else
			demAm++;
	if (demDuong == m || demAm == m) // Toan am hoac toan duong
		return false;
	return true;
}

void XoaCot(float a[][MAXC], int m, int& n, int k)
{
	for (int i = 0; i < m; i++)
		for (int j = k; j < n - 1; j++)
			a[i][j] = a[i][j + 1];
	n--;
}

void XoaCot(float a[][MAXC], int m, int& n)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (ktCot(a, m, j) == true)
				XoaCot(a, m, n, j);
}

void Xuat(float a[][MAXC], int m, int n)
{
	if (n == 0) return;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << fixed << setprecision(4) << setw(8) << a[i][j];
		cout << endl;
	}
}