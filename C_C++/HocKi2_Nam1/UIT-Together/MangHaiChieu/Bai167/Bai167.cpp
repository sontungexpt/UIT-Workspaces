#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
#include <math.h>

using namespace std;

#define MAXR 500
#define MAXC 500

void Nhap(string, float[][500], int&, int&);
void Xuat(float[][500], int, int);
void XuatMaTranCon(float[][500], int, int);
string GetFileLink(string);
int ktCon(float[][500], int, int, int, int);
void ConDau(float[][500], int, int, int&, int&);

int main()
{
	int row = 0;
	int col = 0;
	float a[MAXR][MAXC];
	Nhap(GetFileLink("int"), a, row, col);
	cout << "Ma tran: \n";
	Xuat(a, row, col);
	int vtd = 0;
	int vtc = 0;
	ConDau(a, row, col, vtd, vtc);
	cout << "\nMa tran 3x3 toan duong dau tien trong ma tran:  \n";
	XuatMaTranCon(a, vtd, vtc);
	return 1;
}

void Nhap(string filename, float a[][500], int& m, int& n)
{
	ifstream fi(filename);
	fi >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			fi >> a[i][j];
}

void Xuat(float a[][500], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(11) << a[i][j];
		cout << endl;
	}
}
void XuatMaTranCon(float a[][500], int m, int n)
{
	if ((m == n) && (m = -1))
		return;
	for (int i = m; i <= n; i++)
	{
		for (int j = m; j <= n; j++)
			cout << setw(11) << a[i][j];
		cout << endl;
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

int ktCon(float a[][500], int m, int n, int vtd, int vtc)
{
	int flag = 1;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (a[vtd + i][vtc + j] <= 0)
				flag = 0;
	return flag;
}

void ConDau(float a[][500], int m, int n, int& vtd, int& vtc)
{
	for (vtd = 0; vtc <= m - 3; vtd++)
		for (vtc = 0; vtc <= n - 3; vtc++)
			if (ktCon(a, m, n, vtd, vtc) == 1)
				return;
	vtd = vtc = -1;

}
