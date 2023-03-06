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
bool KtCucTieu(float[][MAXC], int, int, int, int);
double TongCucTieu(float[][MAXC], int, int);

int main()
{
	int k = 0;
	int l = 0;
	float a[MAXR][MAXC];
	Nhap(GetFileLink("float"), a, k, l);
	cout << "Tong cuc tieu la: " << TongCucTieu(a, k, l);
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

bool KtCucTieu(float a[][MAXC], int m, int n, int vtHang, int vtCot)
{
	for (int i = vtHang - 1; i <= vtHang + 1; i++)
	{
		if (i == -1 || i == m)
			continue;
		for (int j = vtCot - 1; j <= vtCot + 1; j++)
		{
			if (j == -1 || j == n)
				continue;
			if (i == vtHang && j == vtCot)
				continue;
			if (a[i][j] <= a[vtHang][vtCot])
				return 0;
		}
	}
	return 1;
}

double TongCucTieu(float a[][MAXC], int m, int n)
{
	double sum = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (KtCucTieu(a, m, n, i, j) == true)
				sum += a[i][j];
	return sum;
}


