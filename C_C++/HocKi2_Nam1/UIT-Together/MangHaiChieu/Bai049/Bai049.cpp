#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

#define MAXR 500
#define MAXC 500

string GetFileLink(string);
void NhapMaTran(string, int[][MAXC], int&, int&);
bool kt5m(int);
int Tong5m(int[][MAXC], int, int);

int main()
{
	int m;
	int n;
	int a[MAXR][MAXC];
	NhapMaTran(GetFileLink("int"), a, m, n);
	int kq = Tong5m(a, m, n);
	cout << "Tong cac so nguyen co dang 5^m nam tren bien ma tran la: " << kq << endl;
	return 0;
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

void NhapMaTran(string filename, int a[][MAXC], int& m, int& n)
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

bool kt5m(int n)
{
	bool flag = true;
	int dem = 0;
	for (int t = abs(n); t > 1; t /= 5)
	{
		dem++;
		if (t % 5 != 0)
			flag = false;
	}
	return flag;
}

int Tong5m(int a[][MAXC], int m, int n)
{
	int s = 0;
	for (int i = 0; i < m; i++)
	{
		if (kt5m(a[i][0]) == true)
			s += a[i][0];
		if (kt5m(a[i][n - 1]))
			s += a[i][n - 1];
	}
	for (int j = 1; j < n - 1; j++)
	{
		if (kt5m(a[0][j]) == true)
			s += a[0][j];
		if (kt5m(a[m - 1][j]) == true)
			s += a[m - 1][j];
	}
	return s;
}
