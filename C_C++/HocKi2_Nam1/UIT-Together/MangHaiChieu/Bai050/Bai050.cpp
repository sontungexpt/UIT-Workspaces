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
void NhapTuFile(string, float[][MAXC], int&, int&);
float TongCuaDai(float[][MAXC], int, int);
int ktCucDai(float[][MAXC], int, int, int, int);

int main()
{
	float a[MAXR][MAXC];
	int m;
	int n;
	NhapTuFile(GetFileLink("float"), a, m, n);
	float kq = TongCuaDai(a, m, n);
	cout << "Tong cac cuc dai cua ma tran la: " << kq;
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

void NhapTuFile(string filename, float a[][MAXC], int& m, int& n)
{
	ifstream fi(filename);
	if (fi.fail() == true)
		cout << "Khong mo duoc file";
	fi >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			fi >> a[i][j];
}

int ktCucDai(float a[][MAXC], int m, int n, int d, int c)
{
	int flag = 1;
	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
			if (d + i >= 0 && c + j >= 0 && d + i < m && c + j < n && !(i == 0 && j == 0))
				if (a[d][c] <= a[d + i][c + j])
					flag = 0;
	return flag;
}

float TongCuaDai(float a[][MAXC], int m, int n)
{
	float s = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (ktCucDai(a, m, n, i, j) == 1)
				s = s + a[i][j];
	return s;
}
