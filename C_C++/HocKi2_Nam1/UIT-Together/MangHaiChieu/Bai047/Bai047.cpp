#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
#include <math.h>

using namespace std;

#define MAXR 500
#define MAXC 500

void Nhap(string, float[][500], int&, int&);
void Xuat(float[][500], int, int);
string GetFileLink(string);
int ktToanDuong(float[][500], int, int, int);
void ThemDong(float[][500], int&, int);
void ThemDongAm(float[][500], int&, int, int);

int main()
{
	int row = 0;
	int col = 0;
	float a[MAXR][MAXC];
	Nhap(GetFileLink("int"), a, row, col);
	cout << "Ma tran: \n";
	Xuat(a, row, col);
	ThemDong(a, row, col);
	return 1;
}

void Nhap(string filename, float a[][500], int& m, int& n)
{
	ifstream fi(filename);
	fi >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			fi >> a[i][j];
}

void Xuat(float a[][500], int m, int n)
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

int ktCucDai(float a[][500], int m, int n, int d, int c)
{
	int di[8] = { -1,-1,-1,0,+1,+1,+1,0 };
	int dj[8] = { -1,0,+1,+1,+1,0,-1,-1 };
	int flag = 1;
	for (int k = 0; k < 8; k++)
		if ((d + di[k]) >= 0 && (d + di[k]) < m && (c + dj[k]) >= 0 && (c + dj[k]) < n && a[(d + di[k])][(c + dj[k])] > a[d][c])
			flag = 0;
	return flag;

}

int ktToanDuong(float a[][500], int m, int n, int d)
{
	int flag = 1;
	for (int j = 0; j < n; j++)
		if (a[d][j] <= 0)
			flag = 0;
	return flag;
}

void ThemDong(float a[][500], int& m, int n)
{
	for (int i = m - 1; i >= 0; i--)
		if (ktToanDuong(a, m, n, i) == 1)
			ThemDongAm(a, m, n, i);

}

void ThemDongAm(float a[][500], int& m, int n, int d)
{
	for (int j = 0; j < n; j++)
	{
		for (int i = m; i >= d + 1; i--)
			a[i][j] = a[i - 1][j];
		a[d][j] = -1;
	}
	m++;
}