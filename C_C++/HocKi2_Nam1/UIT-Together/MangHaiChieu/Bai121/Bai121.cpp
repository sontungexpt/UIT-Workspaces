#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

#define MAXR 500
#define MAXC 500

string GetFileLink(string);
void NhapMaTran(string, float[][MAXC], int&, int&);
void Nhap(int&, int&);
void HoanVi(float&, float&);
void HoanViDong(float[][MAXC], int, int, int, int);
void Xuat(float[][MAXC], int, int);

int main()
{
	int m;
	int n;
	float a[MAXR][MAXC];
	NhapMaTran(GetFileLink("float"), a, m, n);
	int d1;
	int d2;
	Nhap(d1, d2);
	HoanViDong(a, m, n, d1, d2);
	Xuat(a, m, n);
	return 0;
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

void Nhap(int& d1, int& d2)
{
	cout << "Nhap vao dong thu nhat: ";
	cin >> d1;
	cout << "Nhap vao dong thu hai: ";
	cin >> d2;
}

void NhapMaTran(string filename, float a[][MAXC], int& m, int& n)
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

void Xuat(float a[][MAXC], int m, int n)
{
	cout << "Sau khi hoan vi" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(8) << a[i][j];
		cout << endl;
	}
}