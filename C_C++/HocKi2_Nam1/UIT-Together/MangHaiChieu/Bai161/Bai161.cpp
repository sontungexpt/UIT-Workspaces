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
void DichTrai(float[], int);
void DichPhaiBien(float[][MAXC], int, int);
void Xuat(float[][MAXC], int, int);

int main()
{
	int m;
	int n;
	float a[MAXR][MAXC];
	NhapMaTran(GetFileLink("float"), a, m, n);
	DichPhaiBien(a, m, n);
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

void DichTrai(float a[], int n)
{
	float temp = a[0];
	for (int i = 0; i < n - 1; i++)
		a[i] = a[i + 1];
	a[n - 1] = temp;
}

void DichPhaiBien(float a[][MAXC], int m, int n)
{
	float b[100];
	int k;
	int i, j;
	k = 0;
	for (j = 0; j < n - 1; j++)
		b[k++] = a[0][j];
	for (i = 0; i < m - 1; i++)
		b[k++] = a[i][n - 1];
	for (j = n - 1; j >= 1; j--)
		b[k++] = a[m - 1][j];
	for (i = m - 1; i >= 1; i--)
		b[k++] = a[i][0];
	DichTrai(b, k);
	k = 0;
	for (j = 0; j < n - 1; j++)
		a[0][j] = b[k++];
	for (i = 0; i < m - 1; i++)
		a[i][n - 1] = b[k++];
	for (j = n - 1; j >= 1; j--)
		a[m - 1][j] = b[k++];
	for (i = m - 1; i >= 1; i--)
		a[i][0] = b[k++];
}

void Xuat(float a[][MAXC], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << fixed << setprecision(4) << setw(8) << a[i][j];
		cout << endl;
	}
}