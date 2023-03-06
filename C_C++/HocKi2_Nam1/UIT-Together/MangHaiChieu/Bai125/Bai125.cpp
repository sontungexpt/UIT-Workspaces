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
void Swap(int&, int&);
int FindParticipate(int[][MAXC], int, int, int, int, int);
void DoQuickSort(int[][MAXC], int, int, int, int, int);
void SapXepCot(int[][MAXC], int, int, int&);

int main()
{
	int k = 0;
	int l = 0;
	int a[MAXR][MAXC];
	int vtCot;
	Nhap(GetFileLink("int"), a, k, l);
	SapXepCot(a, k, l, vtCot);
	cout << "Ma tran sau khi sap xep cot " << vtCot << " la: \n";
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
void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
int FindParticipate(int a[][MAXC], int m, int n, int bottom, int top, int vtCot)
{
	int pivot = a[(top + bottom) / 2][vtCot];
	int i = bottom - 1;
	int j = top + 1;
	while (i < j)
	{
		do {
			i++;
		} while (a[i][vtCot] < pivot);
		do {
			j--;
		} while (a[j][vtCot] > pivot);
		if (i < j)
			Swap(a[i][vtCot], a[j][vtCot]);
	}
	return j;
}

void DoQuickSort(int a[][MAXC], int m, int n, int bottom, int top, int vtCot)
{
	if (bottom < top)
	{
		int par = FindParticipate(a, m, n, bottom, top, vtCot);
		DoQuickSort(a, m, n, bottom, par, vtCot);
		DoQuickSort(a, m, n, par + 1, top, vtCot);
	}
}

void SapXepCot(int a[][MAXC], int m, int n, int& vtCot)
{
	cout << "Nhap vi tri cot can sap xep: ";
	cin >> vtCot;
	DoQuickSort(a, m, n, 0, m - 1, vtCot);
}