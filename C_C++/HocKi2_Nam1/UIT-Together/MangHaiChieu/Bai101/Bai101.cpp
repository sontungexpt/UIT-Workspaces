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
void XuatCon(float[][MAXC], int, int);
float TongCon(float[][MAXC], int, int, int, int);
void TongLonNhat(float[][MAXC], int, int);
string GetFileLink(string);

int main()
{
	string filename = GetFileLink("float");
	int row = 0;
	int col = 0;
	float a[MAXR][MAXC];

	Nhap(filename, a, row, col);
	Xuat(a, row, col);

	cout << "\nCac chu so xuat hien it nhat trong ma tran la:\n";
	TongLonNhat(a, row, col);

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

void XuatCon(float a[][MAXC], int vtd, int vtc)
{
	for (int i = vtd; i < vtd + 3; i++)
	{
		for (int j = vtc; j < vtc + 3; j++)
			cout << setw(8) << a[i][j];
		cout << endl;
	}
}

float TongCon(float a[][MAXC], int m, int n, int vtd, int vtc)
{
	float s = 0;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			s += a[vtd + i][vtc + j];

	return s;
}

void TongLonNhat(float a[][MAXC], int m, int n)
{
	float lc = TongCon(a, m, n, 0, 0);
	int vtd = 0;
	int vtc = 0;

	for (int i = 0; i <= m - 3; i++)
		for (int j = 0; j < n - 3; j++)
		{
			float s = TongCon(a, m, n, i, j);
			if (lc < s)
			{
				lc = s;
				vtd = i;
				vtc = j;
			}
		}

	XuatCon(a, vtd, vtc);
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