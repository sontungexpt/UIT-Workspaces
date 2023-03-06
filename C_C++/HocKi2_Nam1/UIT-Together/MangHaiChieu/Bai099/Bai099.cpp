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
void Nhap(string, int[][MAXC], int&, int&);
void Xuat(int[][MAXC], int, int);

void TachChuSo(int, int[][MAXC]);
void ChuSoXuatHienNhieuNhat(int[][MAXC], int, int);


string GetFileLink(string);

int main()
{
	int a[MAXR][MAXC];
	int m;
	int n;
	Nhap(GetFileLink("int"), a, m, n);
	Xuat(a, m, n);
	cout << "chu so xuat hien nhieu nhat : ";
	ChuSoXuatHienNhieuNhat(a, m, n);
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
			cout << setw(8) << setprecision(3) << a[i][j];
		cout << endl;
	}
}

void TachChuSo(int n, int b[])
{
	int ChuSo;
	n = abs(n);
	while (n > 0)
	{
		ChuSo = n % 10;
		b[ChuSo]++;
		n /= 10;
	}
}

void ChuSoXuatHienNhieuNhat(int a[][MAXC], int m, int n)
{
	int b[10] = { 0 };
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			TachChuSo(a[i][j], b);
	int temp = 0;
	for (int i = 0; i < 10; i++)
		if (b[temp] == b[i])
			cout << "\n" << i;
}
