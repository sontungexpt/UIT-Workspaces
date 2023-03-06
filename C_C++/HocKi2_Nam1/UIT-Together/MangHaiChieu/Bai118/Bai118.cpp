#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
#include <math.h>

using namespace std;

#define MAXR 100
#define MAXC 100

void Nhap(string, float[][100], int&, int&);
void Xuat(float[][100], int, int);
string GetFileLink(string);
void XayDung(float[][100], int, int, float[][100], int&, int&);

int main()
{
	int row = 0;
	int col = 0;
	float a[MAXR][MAXC];
	int m = 0;
	int n = 0;
	float b[MAXR][MAXC];
	Nhap(GetFileLink("int"), a, row, col);
	cout << "Ma tran A: \n";
	Xuat(a, row, col);
	XayDung(a, row, col, b, m, n);
	cout << "Ma tran B: \n";
	Xuat(b, m, n);
	return 1;
}

void Nhap(string filename, float a[][100], int& m, int& n)
{
	ifstream fi(filename);
	fi >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			fi >> a[i][j];
}

void Xuat(float a[][100], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(11) << a[i][j];
		cout << endl;
	}
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

void XayDung(float a[][100], int m, int n, float b[][100], int& k, int& l)
{
	k = m;
	l = n;
	for (int i = 0; i < k; i++)
		for (int j = 0; j < l; j++)
			b[i][j] = abs(a[i][j]);
}
