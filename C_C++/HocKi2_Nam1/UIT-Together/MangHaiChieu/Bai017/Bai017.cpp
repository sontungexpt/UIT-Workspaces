#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
#include <math.h>

using namespace std;

#define MAXR 500
#define MAXC 500

void NhapTuFile(string, int[][MAXC], int&, int&);
string GetFileLink(string);
void Xuat(int[][MAXC], int m, int n);
void LietKe(int[][MAXC], int, int);
bool check(int k);

int main()
{
	int m = 0;
	int n = 0;
	int a[MAXR][MAXC];
	NhapTuFile(GetFileLink("int"), a, m, n);
	LietKe(a, m, n);
}

void NhapTuFile(string filename, int a[][MAXC], int& m, int& n)
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
void Xuat(int a[][MAXC], int m, int n)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cout << setw(8) << a[i][j];
}
bool check(int k)
{
	int sum = 0;
	for (int i = 1; i <= k / 2; i++) {
		if (k % i == 0)
			sum += i;
	}
	if (sum == k) return true;
	return false;
}
void LietKe(int a[][500], int m, int n)
{
	int p;
	cout << "Nhap so dong muon check: ";
	cin >> p;
	cout << "So hoan thien tren dong " << p << " la: ";
	for (int j = 0; j < n; j++)
	{
		if (check(a[p][j]) == true && a[p][j] > 0)
		{
			cout << a[p][j];
		}
	}
}

