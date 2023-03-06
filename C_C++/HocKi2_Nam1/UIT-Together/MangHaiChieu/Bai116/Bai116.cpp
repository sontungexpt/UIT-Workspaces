#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
#include <math.h>

using namespace std;

#define MAXR 500
#define MAXC 500

void Nhap(string, float[][MAXC], int&, int&);
void Xuat(float[][MAXC], int, int);
int ktDong(float[][MAXC], int, int, int);
void LietKe(float[][MAXC], int, int);
string GetFileLink(string);

int main()
{
	string filename = GetFileLink("float");
	int row = 0;
	int col = 0;
	float a[MAXR][MAXC];

	Nhap(filename, a, row, col);
	Xuat(a, row, col);

	cout << "\nCac dong giam dan trong ma tran la:\n";
	LietKe(a, row, col);

	return 0;
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
			cout << setw(8) << a[i][j];
		cout << endl;
	}
}

int ktDong(float a[][MAXC], int m, int n, int d)
{
	int flag = 1;
	int i = d;

	for (int j = 0; j < n - 1; j++)
		if (a[i][j] < a[i][j + 1])
			flag = 0;

	return flag;
}

void LietKe(float a[][MAXC], int m, int n)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (ktDong(a, m, n, i) == 1)
			{
				cout << setw(8) << i;
				break;
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