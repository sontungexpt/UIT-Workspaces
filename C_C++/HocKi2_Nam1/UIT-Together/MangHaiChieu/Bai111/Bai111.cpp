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
string GetFileLink(string);
void Xuat(int[][MAXC], int, int);
void Nhap(string, int[][MAXC], int&, int&);
bool KtDong(int[][MAXC], int, int, int);
void LietKe(int[][MAXC], int, int);
bool KtSoNguyenTo(int);


int main()
{
	int k = 0;
	int l = 0;
	int a[MAXR][MAXC];
	Nhap(GetFileLink("int"), a, k, l);
	Xuat(a, k, l);
	LietKe(a, k, l);
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
	if (fi.fail() == true)
	{
		cout << "Khong mo duoc file";
		exit(0);
	}
	fi >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			fi >> a[i][j];
}

void Xuat(int a[][MAXC], int m, int n)
{
	cout << "Ma tran la:\n";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(8) << a[i][j];
		cout << endl;
	}
}

bool KtSoNguyenTo(int n)
{
	if (n <= 1)
		return false;
	int count = 0;
	for (int i = 2; i <= n / 2; i++)
		if (n % i == 0)
			return false;
	return true;
}

bool KtDong(int a[][MAXC], int m, int n, int vtDong)
{
	for (int i = 0; i < n; i++)
		if (KtSoNguyenTo(a[vtDong][i]) == true)
			return true;
	return false;
}


void LietKe(int a[][MAXC], int m, int n)
{
	cout << "Cac dong co chua gia tri am la\n";
	for (int i = 0; i < m; i++)
	{
		if (KtDong(a, m, n, i) == true)
		{
			cout << "Dong " << i << ": ";
			for (int j = 0; j < n; j++)
				cout << setw(8) << a[i][j];
			cout << endl;
		}
	}
}

