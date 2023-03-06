#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
#include <math.h>

using namespace std;

#define MAXR 500
#define MAXC 500

void Nhap(string, float[][MAXC], int&, int&);
void Xuat(float[][MAXC], int, int);
float TichDuong(float[][MAXC], int, int);
int DemDuong(float[][MAXC], int, int);
float TbnDuong(float[][MAXC], int, int);
string GetFileLink(string);

int main()
{
	string filename = GetFileLink("float");
	int row = 0;
	int col = 0;
	float a[MAXR][MAXC];

	Nhap(filename, a, row, col);
	Xuat(a, row, col);

	float kq = TbnDuong(a, row, col);
	cout << "\nTrung binh nhan cac so duong trong ma tran la: " << kq;

	return 0;
}

void Nhap(string filename, float a[][MAXC], int& m, int& n)
{
	ifstream fi(filename);
	fi >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			fi >> a[i][j];
}

void Xuat(float a[][MAXC], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(8) << a[i][j];
		cout << endl;
	}
}

float TichDuong(float a[][MAXC], int m, int n)
{
	float t = 1;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] > 0)
			{
				t = t * a[i][j];
			}

	return t;
}

int DemDuong(float a[][MAXC], int m, int n)
{
	int dem = 0;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] > 0)
				dem++;

	return dem;
}

float TbnDuong(float a[][MAXC], int m, int n)
{
	float tich = TichDuong(a, m, n);
	int soluong = DemDuong(a, m, n);

	return pow(tich, (float)1 / soluong);
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