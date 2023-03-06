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
bool ktChan(int);
void HoanVi(int&, int&);
void ChanGiamPhu(int[][MAXC], int, int);
void ChanGiamKhongPhu(int[][MAXC], int, int);
string GetFileLink(string);

int main()
{
	string filename = GetFileLink("int");
	int row = 0;
	int col = 0;
	int a[MAXR][MAXC];

	Nhap(filename, a, row, col);
	Xuat(a, row, col);

	cout << "\nMa tran sau khi sap xep la:\n";
	ChanGiamPhu(a, row, col);
	Xuat(a, row, col);

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

bool ktChan(int k)
{
	if (k % 2 == 0)
		return true;
	return false;
}

void HoanVi(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void ChanGiamPhu(int a[][MAXC], int m, int n)
{
	int b[100];
	int k;
	int i, j;

	k = 0;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			if (a[i][j] % 2 == 0)
				b[k++] = a[i][j];

	for (i = 0; i <= k - 2; i++)
		for (j = i + 1; j <= k - 1; j++)
			if (b[i] < b[j])
				HoanVi(b[i], b[j]);

	k = 0;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			if (a[i][j] % 2 == 0)
				a[i][j] = b[k++];
}

void ChanGiamKhongPhu(int a[][MAXC], int m, int n)
{
	int i, j;

	for (i = 0; i < m; i++)
		for (j = 0; j < n - 1; j++)
			for (int j1 = j + 1; j1 < n; j1++)
				if (ktChan(a[i][j]) && ktChan(a[i][j1]) && a[i][j] < a[i][j1])
					HoanVi(a[i][j], a[i][j1]);

	for (j = 0; j < m; j++)
		for (i = 0; i < n - 1; i++)
			for (int i1 = i + 1; i1 < n; i1++)
				if (ktChan(a[i][j]) && ktChan(a[i1][j]) && a[i][j] < a[i1][j])
					HoanVi(a[i][j], a[i1][j]);
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