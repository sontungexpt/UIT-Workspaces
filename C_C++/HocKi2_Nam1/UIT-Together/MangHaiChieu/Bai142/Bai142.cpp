#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
#include <math.h>

using namespace std;

#define MAXR 500
#define MAXC 500

void Nhap(string, int[][MAXC], int&, int&);
void Xuat(int[][MAXC], int, int);
bool ktDang2m(int);
int TongCot(int[][MAXC], int, int, int);
string GetFileLink(string);

int main()
{
	string filename = GetFileLink("int");
	int row = 0;
	int col = 0;
	int a[MAXR][MAXC];

	Nhap(filename, a, row, col);
	Xuat(a, row, col);

	int k;
	cout << "Nhap cot muon kiem tra: ";
	cin >> k;

	int kq = TongCot(a, row, col, k);
	cout << "\n\nTong cac gia tri co dang 2^m tren cot " << k << " la: " << kq;

	return 0;
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
			cout << setw(8) << a[i][j];
		cout << endl;
	}
}

bool ktDang2m(int k)
{
	if (k < 1)
		return false;

	bool flag = true;
	for (int t = k; t > 1; t = t / 2)
		if (t % 2 != 0)
			flag = false;
	return flag;
}

int TongCot(int a[][MAXC], int m, int n, int c)
{
	int s = 0;
	int j = c;

	for (int i = 0; i < m; i++)
	{
		if (ktDang2m(a[i][j]))
			s += a[i][j];
	}

	return s;
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