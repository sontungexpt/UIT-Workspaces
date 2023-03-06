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
void Xuat(float[][MAXC], int, int);
void Nhap(string, float[][MAXC], int&, int&);
void Swap(float&, float&);
int FindParticipate(float[], int, int, int);
void DoQuickSortDescending(float[], int, int, int);
void CreateNewArr(float[][MAXC], int, int, float[], int&);
void SapXepBien(float[][MAXC], int, int);

int main()
{
	int k = 0;
	int l = 0;
	float a[MAXR][MAXC];
	Nhap(GetFileLink("float"), a, k, l);
	SapXepBien(a, k, l);
	cout << "Ma tran sau khi sap xep cac bien la\n";
	Xuat(a, k, l);
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

void Xuat(float a[][MAXC], int m, int n)
{
	cout << "Ma tran la:\n";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(8) << a[i][j];
		cout << endl;
	}
}
void Swap(float& a, float& b)
{
	int temp = a;
	a = b;
	b = temp;
}
int FindParticipate(float a[], int n, int left, int right)
{
	float pivot = a[(right + left) / 2];
	int i = left - 1;
	int j = right + 1;
	while (i < j)
	{
		do {
			i++;
		} while (a[i] < pivot);
		do {
			j--;
		} while (a[j] > pivot);
		if (i < j)
			Swap(a[i], a[j]);
	}
	return j;
}

void DoQuickSortDescending(float a[], int n, int left, int right)
{
	if (left < right)
	{
		int par = FindParticipate(a, n, left, right);
		DoQuickSortDescending(a, n, left, par);
		DoQuickSortDescending(a, n, par + 1, right);
	}
}
void CreateNewArr(float a[][MAXC], int m, int n, float b[], int& nB)
{
	nB = 0;
	for (int i = 0; i < n; i++)
		b[nB++] = a[0][i];
	for (int i = 1; i < m; i++)
		b[nB++] = a[i][n - 1];
	for (int i = n - 2; i >= 0; i--)
		b[nB++] = a[m - 1][i];
	for (int i = m - 2; i > 0; i--)
		b[nB++] = a[i][0];
}

void SapXepBien(float a[][MAXC], int m, int n)
{
	float borderMatrix[MAXR * 4 - 4];
	int nB = 0;
	CreateNewArr(a, m, n, borderMatrix, nB);
	DoQuickSortDescending(borderMatrix, nB, 0, nB - 1);
	int i = 0;
	for (int j = 0; j < n; j++)
		a[0][j] = borderMatrix[i++];
	for (int j = 1; j < m; j++)
		a[j][n - 1] = borderMatrix[i++];
	for (int j = n - 2; j >= 0; j--)
		a[m - 1][j] = borderMatrix[i++];
	for (int j = m - 2; j > 0; j--)
		a[j][0] = borderMatrix[i++];

}