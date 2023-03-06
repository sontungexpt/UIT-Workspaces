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
int DemChanDong(int[][MAXC], int, int, int);
int DemChanNhieuNhat(int[][MAXC], int, int);
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

int DemChanDong(int a[][MAXC], int m, int n, int d)
{
	int dem = 0;
	for (int j = 0; j < n; j++)
		if (a[d][j] % 2 == 0)
			dem++;
	return dem;
}

int DemChanNhieuNhat(int a[][MAXC], int m, int n)
{
	int lc = DemChanDong(a, m, n, 0);
	for (int i = 0; i < m; i++)
		if (DemChanDong(a, m, n, i) > lc)
			lc = DemChanDong(a, m, n, i);
	return lc;
}

void LietKe(int a[][MAXC], int m, int n)
{
	int kq = DemChanNhieuNhat(a, m, n);
	cout << "Cac dong co nhieu so chan nhat la: " << endl;
	for (int i = 0; i < m; i++)
		if (DemChanDong(a, m, n, i) == kq)
			cout << "Dong " << i + 1 << " voi " << kq << " so chan." << endl;
}