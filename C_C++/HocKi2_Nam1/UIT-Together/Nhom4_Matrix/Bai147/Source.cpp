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
bool KiemTraCotAm(float[][MAXC], int, int, int);
void XoaCot(float[][MAXC], int, int &, int);
void XoaCotAm(float[][MAXC], int, int&);


int main()
{
	int k = 0;
	int l = 0;
	float a[MAXR][MAXC];
	Nhap(GetFileLink("float"), a, k, l);
	Xuat(a, k, l);
	XoaCotAm(a, k, l);
	cout << "Ma tran sau khi xoa cac cot toan am la:\n";
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

bool KiemTraCotAm(float a[][MAXC], int m, int n, int vtCot)
{
	for (int i = 0; i < m; i++)
		if (a[i][vtCot] > 0)
			return false;
	return true;
}

void XoaCot(float a[][MAXC], int m, int &n, int vtXoa)
{
	for (int i = 0; i < m; i++)
		for (int j = vtXoa; j < n - 1; j++)
			a[i][j] = a[i][j + 1];
	n--;
}

void XoaCotAm(float a[][MAXC], int m, int &n)
{
	for (int i = 0; i < n; i++)
		if (KiemTraCotAm(a, m, n, i) == true)
			XoaCot(a, m, n, i);
}