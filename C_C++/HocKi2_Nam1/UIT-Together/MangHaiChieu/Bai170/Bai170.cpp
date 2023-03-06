#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
#include <math.h>

using namespace std;

#define MAXR 100
#define MAXC 100

string GetFileLink(string);
void NhapTuFile(string, float[][MAXC], int&, int&);
int ktCon(float[][MAXC], int, int, float[][MAXC], int, int);

int main()
{
	float a[MAXR][MAXC];
	int m;
	int n;
	float b[MAXR][MAXC];
	int k;
	int l;
	cout << "Nhap 2 mang: " << endl;
	NhapTuFile(GetFileLink("float"), a, m, n);
	NhapTuFile(GetFileLink("float"), b, k, l);
	int kq = ktCon(a, m, n, b, k, l);
	if (kq == 1)
		cout << "A la mang con cua B";
	else
		cout << "A khong la mang con cua B";
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

int ktCon(float a[][MAXC], int m, int n, float b[][MAXC], int k, int l)
{
	if (m > k || l > n)
		return 0;
	int flag = 0;
	for (int d = 0; d <= k - m; d++)
		for (int c = 0; c <= l - m; c++)
		{
			int co = 1;
			for (int i = 0; i < m; i++)
				for (int j = 0; j < n; j++)
					if (a[i][j] != b[d + i][c + j])
						co = 0;
			if (co == 1)
				flag = 1;
		}
	return flag;
}
