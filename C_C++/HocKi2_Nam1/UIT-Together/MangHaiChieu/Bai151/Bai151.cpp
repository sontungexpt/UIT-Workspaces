#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
#include <math.h>

using namespace std;

#define MAXR 500
#define MAXC 500

void Nhap(string, float[][500], int&, int&);
void Xuat(float[][500], int, int);
string GetFileLink(string);
float NhoNhatDong(float[][500], int, int, int);
void ThemCot(float[][500], int, int&);

int main()
{
	int row = 0;
	int col = 0;
	float a[MAXR][MAXC];
	Nhap(GetFileLink("int"), a, row, col);
	cout << "Ma tran: \n";
	Xuat(a, row, col);
	ThemCot(a, row, col);
	cout << "\nMa Tran sau khi them cot  : \n";
	Xuat(a, row, col);
	return 1;
}

void Nhap(string filename, float a[][500], int& m, int& n)
{
	ifstream fi(filename);
	fi >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			fi >> a[i][j];
}

void Xuat(float a[][500], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(11) << a[i][j];
		cout << endl;
	}
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

float NhoNhatDong(float a[][500], int m, int n, int d)
{
	float lc = a[d][0];
	for (int j = 1; j < n; j++)
		if (a[d][j] < lc)
			lc = a[d][j];
	return lc;
}

void ThemCot(float a[][500], int m, int& n)
{
	for (int i = 0; i < m; i++)
		a[i][n] = NhoNhatDong(a, m, n, i);
	n++;

}


