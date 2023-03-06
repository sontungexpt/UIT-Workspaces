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
void NhapTuFile(string, int[][MAXC], int&, int&);
int ktToanChan(int[][MAXC], int, int, int);
void XoaDong(int[][MAXC], int&, int, int);
void XoaDongToanToanChan(int[][MAXC], int&, int);
void Xuat(int[][MAXC], int, int);


int main()
{
	int a[MAXR][MAXC];
	int m;
	int n;
	NhapTuFile(GetFileLink("int"), a, m, n);
	Xuat(a, m, n);
	return 1;
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

void NhapTuFile(string filename, int a[][MAXC], int& m, int& n)
{
	ifstream fi(filename);
	if (fi.fail() == true)
		cout << "Khong mo duoc file";
	fi >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			fi >> a[i][j];
}

int ktToanChan(int a[][MAXC], int m, int n, int d)
{
	for (int j = 0; j < n; j++)
		if (a[d][j] % 2 != 0)
			return 0;
	return 1;
}

void XoaDong(int a[][MAXC], int& m, int n, int d)
{
	for (int j = 0; j < n; j++)
		a[d][j] = a[d + 1][j];
	m--;
}

void XoaDongToanToanChan(int a[][MAXC], int& m, int n)
{
	for (int i = 0; i < m; i++)
		if (ktToanChan(a, m, n, i) == 1)
			XoaDong(a, m, n, i);
}

void Xuat(int a[][MAXC], int m, int n)
{
	cout << "Ma tran sau khi xoa cac dong toan chan la: " << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(8) << a[i][j];
		cout << endl;
	}
}