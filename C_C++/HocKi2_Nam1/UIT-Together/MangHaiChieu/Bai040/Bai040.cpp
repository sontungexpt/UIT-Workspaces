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
int TongCot(int[][500], int, int, int);

int main()
{
	int row = 0;
	int col = 0;
	int c;
	cout << "Hay lua chon cot: ";
	cin >> c;
	int a[MAXR][MAXC];
	Nhap(GetFileLink("int"), a, row, col);
	cout << "Tich cac so le tren mot cot ma tran la: ";
	int kq = TongCot(a, row, col, c);
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

int TongCot(int a[][500], int m, int n, int c)
{
	int S = 0;
	for (int i = 0; i < m; i++)
		if (abs(a[i][c]) % 2 == 1)
			S = S + a[i][c];
	return S;
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