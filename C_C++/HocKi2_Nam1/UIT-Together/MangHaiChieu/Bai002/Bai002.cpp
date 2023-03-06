#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
#include <math.h>
#include <time.h>

using namespace std;

#define MAXR 500
#define MAXC 500

string GetFileLink(string);
void TaoMaTranNgauNhien(int[][MAXC], int&, int&);
void XuatRaManHinh(int[][MAXC], int, int);
void XuatRaFile(string, int[][MAXC], int, int);

int main()
{
	int a[MAXR][MAXC];
	int m;
	int n;
	TaoMaTranNgauNhien(a, m, n);
	XuatRaManHinh(a, m, n);
	XuatRaFile(GetFileLink("int"), a, m, n);
	return 1;
}

string GetFileLink(string dataTypeOfFile)
{
	string folderName = dataTypeOfFile;
	folderName[0] = toupper(folderName[0]);
	folderName += "MatranData";
	string fileLink = "../" + folderName + "/" + dataTypeOfFile + "matrandata";
	int fileIndex;
	cout << "Nhap so thu tu cua file can xuat gia tri: ";
	cin >> fileIndex;
	if (fileIndex < 10)
		fileLink += '0';
	fileLink += to_string(fileIndex);
	string fileLinkOut = fileLink;
	fileLinkOut += ".out";
	return fileLinkOut;
}

void TaoMaTranNgauNhien(int a[][MAXC], int& m, int& n)
{
	srand(time(NULL));
	cout << "Nhap so dong: ";
	cin >> m;
	cout << "Nhap so cot: ";
	cin >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = rand() % (100 + 100 + 1) - 100;
}

void XuatRaManHinh(int a[][MAXC], int m, int n)
{
	cout << "Ma tran vua tao ngau nhien la: " << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(8) << a[i][j];
		cout << endl;
	}
}

void XuatRaFile(string filename, int a[][MAXC], int m, int n)
{
	ofstream fo(filename);
	if (fo.fail() == true)
		cout << "File da nhap khong hop le";
	else
	{
		fo << m << setw(8) << n;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				fo << setw(8) << a[i][j];
			cout << endl;
		}
	}
}
