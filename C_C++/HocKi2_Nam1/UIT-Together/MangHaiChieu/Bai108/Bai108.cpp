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
int ktGiamDanTheoHang(int[][MAXC], int, int);
int ktGiamDanTheoCot(int[][MAXC], int, int);
void ktGiamDanTheoHangVaCot(int[][MAXC], int, int);

int main()
{
	int a[MAXR][MAXC];
	int m;
	int n;
	NhapTuFile(GetFileLink("int"), a, m, n);
	ktGiamDanTheoHangVaCot(a, m, n);
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

int ktGiamDanTheoHang(int a[][MAXC], int m, int d)
{
	for (int i = 0; i < m; i++)
		for (int j = i + 1; i < m; i++)
			if (a[d][i] < a[d][j])
				return 0;
	return 1;
}

int ktGiamDanTheoCot(int a[][MAXC], int n, int c)
{
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (a[j][c] < a[j][c])
				return 0;
	return 1;
}

void ktGiamDanTheoHangVaCot(int a[][MAXC], int m, int n)
{
	int flag = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (ktGiamDanTheoCot(a, n, j) == 0 || ktGiamDanTheoHang(a, n, i) == 0)
				flag = 0;
	if (flag == 1)
		cout << "Ma tran giam dan theo hang va cot";
	else
		cout << "Ma tran khong giam dan theo hang va cot";
}
