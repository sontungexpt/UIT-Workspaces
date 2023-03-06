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

void HoanVi(float&, float&);
void HoanViDong(float[][MAXC], int, int, int, int);
float TongDong(float[][MAXC], int, int, int, int);
void SapTang(float[][MAXC], int, int);

string GetFileLink(string);

int main()
{
	float a[MAXR][MAXC];
	int m;
	int n;
	Nhap(GetFileLink("float"), a, m, n);
	Xuat(a, m, n);
	cout << "sap xep cac dong ma tran theo dong: " << endl;
	SapTang(a, m, n);
	Xuat(a, m, n);
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

void HoanVi(float& a, float& b)
{
	float temp = a;
	a = b;
	b = temp;
}

void HoanViDong(float a[][MAXC], int m, int n, int d1, int d2)
{
	for (int j = 0; j < n; j++)
		HoanVi(a[d1][j], a[d2][j]);
}

float TongDong(float a[][MAXC], int m, int n, int d)
{
	float s = 0;
	for (int j = 0; j < n; j++)
		s = s + a[d][j];
	return s;
}

void SapTang(float a[][MAXC], int m, int n)
{
	for (int i = 0; i <= m - 2; i++)
		for (int j = i + 1; j <= m - 1; j++)
			if (TongDong(a, m, n, i) > TongDong(a, m, n, j))
				HoanViDong(a, m, n, i, j);
}