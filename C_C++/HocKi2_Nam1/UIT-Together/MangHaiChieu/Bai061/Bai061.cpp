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
bool ktHoanThien(int);
int DemHoanThien(int[][MAXC], int, int);
void Xuat(int[][MAXC], int, int);

int main()
{
	int m;
	int n;
	int a[MAXR][MAXC];
	NhapMaTran(GetFileLink("int"), a, m, n);
	Xuat(a, m, n);
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

bool ktHoanThien(int n)
{
	int t = 0;
	for (int i = 1; i < n; i++)
		if (n % i == 0)
			t += i;
	if (t == n) return true;
	return false;
}

int DemHoanThien(int a[][MAXC], int n, int i)
{
	int dem = 0;
	for (int j = 0; j < n; j++)
		if (ktHoanThien(a[i][j]) == true)
			dem++;
	return dem;
}

void Xuat(int a[][MAXC], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		cout << "So luong so hoan thien o dong " << i << " la: ";
		cout << setw(8) << DemHoanThien(a, n, i);
		cout << endl;
	}
}