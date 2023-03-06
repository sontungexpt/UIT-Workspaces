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
bool KtDong(float[][MAXC], int, int , int);
void LietKe(float[][MAXC], int, int);

int main()
{
	int k = 0;
	int l = 0;
	float a[MAXR][MAXC];
	Nhap(GetFileLink("float"), a, k, l);
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

bool KtDong(float a[][MAXC], int m, int n, int vtDong)
{
	for (int i = 0; i < n; i++)
		if (a[vtDong][i] < 0)
			return true;
	return false;
}


void LietKe(float a[][MAXC], int m, int n )
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