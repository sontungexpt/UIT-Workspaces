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
void Nhap(string, float[][500], int&, int&);
int DemDuongDong(float[][500], int, int, int);

int main()
{
	float d;
	cout << "Hay nhap dong muon chon: ";
	cin >> d;
	int row = 0;
	int col = 0;
	float a[MAXR][MAXC];
	Nhap(GetFileLink("float"), a, row, col);
	int kq = DemDuongDong(a, row, col, d);
	cout << "So luong so duong tren dong la: " << kq << endl;
}

void Nhap(string filename, float a[][500], int& m, int& n)
{
	ifstream fi(filename);
	fi >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			fi >> a[i][j];
}

int DemDuongDong(float a[][500], int m, int n, int d)
{
	int dem = 0;
	for (int j = 0; j < n; j++)
		if (a[d][j] > 0)
			dem += 1;
	return dem;
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