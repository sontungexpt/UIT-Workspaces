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
void Nhap(string, float[][MAXC], int&, int&);
void Xuat(float[][MAXC], int, int);

bool ktCucDai(float[][MAXC], int, int, int, int);
bool ktCucTieu(float[][MAXC], int, int, int, int);
float TongCucDai(float[][MAXC], int, int);
float TongCucTieu(float[][MAXC], int, int);
float TongCucTri(float[][MAXC], int, int);

string GetFileLink(string);

int main()
{
	float a[MAXR][MAXC];
	int m;
	int n;
	Nhap(GetFileLink("float"), a, m, n);
	Xuat(a, m, n);
	cout << "tong cac cuc tri: " << TongCucTri(a, m, n);
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
			cout << setw(8) << setprecision(3) << a[i][j];
		cout << endl;
	}
}

bool ktCucTieu(float a[][MAXC], int m, int n, int i, int j)
{
	if (i == 0 & j == 0)
	{
		if ((a[i][j] > a[i][j + 1] && a[i][j] > a[i + 1][j]) || (a[i][j] < a[i][j + 1] && a[i][j] < a[i + 1][j]))
			return true;
	}

	if (i == m - 1 && j == 0)
	{
		if ((a[i][j] > a[i - 1][j] && a[i][j] > a[i][j + 1]) || (a[i][j] < a[i - 1][j] && a[i][j] < a[i][j + 1]))
			return true;
	}

	if (i == 0 && j == n - 1)
	{
		if ((a[i][j] > a[i + 1][j] && a[i][j] > a[i][j - 1]) || (a[i][j] < a[i + 1][j] && a[i][j] < a[i][j - 1]))
			return true;
	}

	if (i == m - 1 && j == n - 1)
	{
		if ((a[i][j] > a[i - 1][j] && a[i][j] > a[i][j - 1]) || (a[i][j] < a[i - 1][j] && a[i][j] < a[i][j - 1]))
			return true;
	}

	if (i == 0)
	{
		if ((a[i][j] > a[i][j + 1] && a[i][j] > a[i][j - 1] && a[i][j] > a[i + 1][j]) || (a[i][j] < a[i][j + 1] && a[i][j] < a[i][j - 1] && a[i][j] < a[i + 1][j]))
			return true;
	}

	if (j == 0)
	{
		if ((a[i][j] > a[i][j + 1] && a[i][j] > a[i + 1][j] && a[i][j] > a[i - 1][j]) || (a[i][j] < a[i][j + 1] && a[i][j] < a[i + 1][j] && a[i][j] < a[i - 1][j]))
			return true;
	}

	if (i == m - 1)
	{
		if ((a[i][j] > a[i][j + 1] && a[i][j] > a[i][j - 1] && a[i][j] > a[i - 1][j]) || (a[i][j] < a[i][j + 1] && a[i][j] < a[i][j - 1] && a[i][j] < a[i - 1][j]))
			return true;
	}

	if (j == n - 1)
		if ((a[i][j] > a[i - 1][j] && a[i][j] > a[i][j - 1] && a[i][j] > a[i + 1][j]) || (a[i][j] < a[i - 1][j] && a[i][j] < a[i][j - 1] && a[i][j] < a[i + 1][j]))
			return true;

	if ((a[i][j] > a[i][j + 1] && a[i][j] > a[i + 1][j] && a[i][j] > a[i][j - 1] && a[i][j] > a[i - 1][j]) || (a[i][j] < a[i][j + 1] && a[i][j] < a[i + 1][j]) && a[i][j] < a[i][j - 1] && a[i][j] < a[i - 1][j])
		return true;
	return false;
}

bool ktCucDai(float a[][MAXC], int m, int n, int i, int j) // cai nay em k nghi ra thuat toan nen lay tren mang :D mong thay tha thu
{
	if (i == 0 & j == 0)
	{
		if ((a[i][j] < a[i][j + 1] && a[i][j] < a[i + 1][j]) || (a[i][j] > a[i][j + 1] && a[i][j] > a[i + 1][j]))
			return true;
	}

	if (i == m - 1 && j == 0)
	{
		if ((a[i][j] < a[i - 1][j] && a[i][j] < a[i][j + 1]) || (a[i][j] > a[i - 1][j] && a[i][j] > a[i][j + 1]))
			return true;
	}

	if (i == 0 && j == n - 1)
	{
		if ((a[i][j] < a[i + 1][j] && a[i][j] < a[i][j - 1]) || (a[i][j] > a[i + 1][j] && a[i][j] > a[i][j - 1]))
			return true;
	}

	if (i == m - 1 && j == n - 1)
	{
		if ((a[i][j] < a[i - 1][j] && a[i][j] < a[i][j - 1]) || (a[i][j] > a[i - 1][j] && a[i][j] > a[i][j - 1]))
			return true;
	}

	if (i == 0)
	{
		if ((a[i][j] < a[i][j + 1] && a[i][j] < a[i][j - 1] && a[i][j] < a[i + 1][j]) || (a[i][j] > a[i][j + 1] && a[i][j] < a[i][j - 1] && a[i][j] > a[i + 1][j]))
			return true;
	}

	if (j == 0)
	{
		if ((a[i][j] < a[i][j + 1] && a[i][j] < a[i + 1][j] && a[i][j] < a[i - 1][j]) || (a[i][j] < a[i][j + 1] && a[i][j] > a[i + 1][j] && a[i][j] > a[i - 1][j]))
			return true;
	}

	if (i == m - 1)
	{
		if ((a[i][j] < a[i][j + 1] && a[i][j] < a[i][j - 1] && a[i][j] < a[i - 1][j]) || (a[i][j] > a[i][j + 1] && a[i][j] > a[i][j - 1] && a[i][j] > a[i - 1][j]))
			return true;
	}

	if (j == n - 1)
		if ((a[i][j] < a[i - 1][j] && a[i][j] < a[i][j - 1] && a[i][j] < a[i + 1][j]) || (a[i][j] > a[i - 1][j] && a[i][j] > a[i][j - 1] && a[i][j] > a[i + 1][j]))
			return true;

	if ((a[i][j] < a[i][j + 1] && a[i][j] < a[i + 1][j] && a[i][j] < a[i][j - 1] && a[i][j] < a[i - 1][j]) || (a[i][j] > a[i][j + 1] && a[i][j] > a[i + 1][j]) && a[i][j] > a[i][j - 1] && a[i][j] > a[i - 1][j])
		return true;
	return false;
}

float TongCucDai(float a[][MAXC], int m, int n)
{
	float s = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (ktCucDai(a, m, n, i, j))
				s += a[i][j];
	return s;
}

float TongCucTieu(float a[][MAXC], int m, int n)
{
	float s = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (ktCucTieu(a, m, n, i, j))
				s += a[i][j];
	return s;
}

float TongCucTri(float a[][MAXC], int m, int n)
{
	return TongCucDai(a, m, n) + TongCucTieu(a, m, n);
}