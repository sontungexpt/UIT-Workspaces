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
void Nhap(string, int[][MAXC], int&, int&);
void Xuat(int[][MAXC], int, int);

int DemChinhPhuongBien(int[][MAXC], int, int);
bool ktChinhPhuong(int);

string GetFileLink(string);

int main()
{
	int a[MAXR][MAXC];
	int m;
	int n;
	Nhap(GetFileLink("int"), a, m, n);
	Xuat(a, m, n);
	cout << "so chinh phuong bien: " << DemChinhPhuongBien(a, m, n);

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
			cout << setw(8) << setprecision(3) << a[i][j];
		cout << endl;
	}
}

int DemChinhPhuongBien(int a[][MAXC], int m, int n)
{
	int dem = 0;
	int dd = 0;
	int cd = 0;
	int dc = m - 1;
	int cc = n - 1;
	for (int j = 0; j < n; j++)
	{
		if (ktChinhPhuong(a[dd][j]))
			dem++;
		if (ktChinhPhuong(a[dc][j]))
			dem++;
	}

	for (int i = 0; i < m; i++)
	{
		if (ktChinhPhuong(a[i][cd]))
			dem++;
		if (ktChinhPhuong(a[i][cc]))
			dem++;
	}
	return dem;
}

bool ktChinhPhuong(int k)
{
	for (int i = 1; i * i <= k; i++)
		if (i % i == k)
			return true;
	return false;
}