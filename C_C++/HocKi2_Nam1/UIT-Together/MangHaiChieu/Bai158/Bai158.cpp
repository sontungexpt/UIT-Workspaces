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
void DichTraiDong(float[][MAXC], int, int, int);
void DichTrai(float[][MAXC], int, int);
string GetFileLink(string);

int main()
{
	string filename = GetFileLink("float");
	int row = 0;
	int col = 0;
	float a[MAXR][MAXC];

	Nhap(filename, a, row, col);
	Xuat(a, row, col);

	cout << "\nMa tran sau khi dich trai la:\n";
	DichTrai(a, row, col);
	Xuat(a, row, col);

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

void DichTraiDong(float a[][MAXC], int m, int n, int d)
{
	float temp = a[d][0];

	for (int j = 0; j <= n - 2; j++)
		a[d][j] = a[d][j + 1];

	a[d][n - 1] = temp;
}

void DichTrai(float a[][MAXC], int m, int n)
{
	for (int i = 0; i < m; i++)
		DichTraiDong(a, m, n, i);
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