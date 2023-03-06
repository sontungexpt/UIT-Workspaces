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
bool ktChinhPhuong(int);
int ktCot(int[][MAXC], int, int, int);
void LietKe(int[][MAXC], int, int);
string GetFileLink(string);

int main()
{
	string filename = GetFileLink("int");
	int row = 0;
	int col = 0;
	int a[MAXR][MAXC];

	Nhap(filename, a, row, col);
	Xuat(a, row, col);

	cout << "\nCac cot co chua so chinh phuong trong ma tran la:\n";
	LietKe(a, row, col);

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

bool ktChinhPhuong(int k)
{
	bool flag = false;

	for (int i = 1; i <= k; i++)
		if (i * i == k)
			flag = true;

	return flag;
}

int ktCot(int a[][MAXC], int m, int c)
{
	int flag = 0;
	int j = c;

	for (int i = 0; i < m; i++)
		if (ktChinhPhuong(a[i][j]))
			flag = 1;

	return flag;
}

void LietKe(int a[][MAXC], int m, int n)
{
	for (int j = 0; j < n; j++)
		for (int i = 0; i < m; i++)
			if (ktCot(a, m, j) == 1)
			{
				cout << setw(8) << j;
				break;
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