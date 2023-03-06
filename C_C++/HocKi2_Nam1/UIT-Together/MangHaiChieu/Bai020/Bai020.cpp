#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
#include <math.h>

using namespace std;

#define MAXR 500
#define MAXC 500

void Nhap(string, int[][MAXC], int&, int&);
void Xuat(int[][MAXC], int, int);
bool ktDang5m(int);
void LietKe(int[][MAXC], int, int, int);
string GetFileLink(string);

int main()
{
	string filename = GetFileLink("int");
	int row = 0;
	int col = 0;
	int a[MAXR][MAXC];

	Nhap(filename, a, row, col);
	Xuat(a, row, col);

	int k;
	cout << "Nhap cot muon kiem tra: ";
	cin >> k;
	LietKe(a, row, col, k);

	return 0;
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
			cout << setw(8) << a[i][j];
		cout << endl;
	}
}

bool ktDang5m(int k)
{
	if (k < 1)
		return false;

	bool flag = true;
	for (int t = k; t > 1; t = t / 5)
		if (t % 5 != 0)
			flag = false;
	return flag;
}

void LietKe(int a[][MAXC], int m, int n, int k)
{
	cout << "\n\nCac gia tri co dang 5^m la:\n";
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			if (ktDang5m(a[i][j]) && j == k)
				cout << setw(8) << a[i][j];
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