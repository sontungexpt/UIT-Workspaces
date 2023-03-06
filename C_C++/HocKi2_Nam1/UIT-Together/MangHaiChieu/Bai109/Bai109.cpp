#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
#include <math.h>

using namespace std;

#define MAXR 500
#define MAXC 500

string GetFileLink(string);
void NhapTuFile(string, int[][MAXC], int&, int&);
int ktDongChan(int[][MAXC], int, int, int);
void LietKe(int[][MAXC], int, int);

int main()
{
	int a[MAXR][MAXC];
	int m;
	int n;
	NhapTuFile(GetFileLink("int"), a, m, n);
	LietKe(a, m, n);
	return 1;
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

void NhapTuFile(string filename, int a[][MAXC], int& m, int& n)
{
	ifstream fi(filename);
	if (fi.fail() == true)
		cout << "Khong mo duoc file";
	fi >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			fi >> a[i][j];
}

int ktDongChan(int a[][MAXC], int m, int n, int d)
{
	for (int j = 0; j < n; j++)
		if (a[d][j] % 2 == 0)
			return 1;
	return 2;
}

void LietKe(int a[][MAXC], int m, int n)
{
	cout << "Cac dong toan chan cua ma tran la: " << endl;
	for (int i = 0; i < m; i++)
		if (ktDongChan(a, m, n, i) == 1)
			cout << "Dong " << i + 1 << " chua so chan." << endl;
}