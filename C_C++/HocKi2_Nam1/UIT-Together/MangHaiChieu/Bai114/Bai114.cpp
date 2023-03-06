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
void Nhap(string, int[][MAXC], int&, int&);
void Xuat(int[][MAXC], int, int);

int ktDong(int[][MAXC], int, int, int);
void LietKe(int[][MAXC], int, int);

string GetFileLink(string);

int main()
{
	int a[MAXR][MAXC];
	int m;
	int n;
	Nhap(GetFileLink("int"), a, m, n);
	Xuat(a, m, n);
	cout << "liet ke cac dong chua toan so chan" << endl;
	LietKe(a, m, n);


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
	fi >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			fi >> a[i][j];
}

void Xuat(int a[][MAXC], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(8) << setprecision(3) << a[i][j];
		cout << endl;
	}
}

int ktDong(int a[][MAXC], int m, int n)
{
	int flag;
	for (int i = 0; i < m; i++)
	{
		flag = 1;
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] % 2 == 1)
			{
				flag = 0;
				break;
			}
		}
	}
	return flag;
}

void LietKe(int a[][MAXC], int m, int n)
{
	for (int i = 0; i < m; i++)
		if (ktDong(a, m, n) == 1)
			for (int j = 0; j < n; j++)
				cout << i << endl;
}