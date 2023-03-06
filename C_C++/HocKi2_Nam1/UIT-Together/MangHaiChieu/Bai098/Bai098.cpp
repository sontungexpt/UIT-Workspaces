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
void Nhap(string, float[][MAXC], int&, int&);
void Xuat(float[][MAXC], int, int);

int DemYenNgua(float[][MAXC], int, int);

bool TimPhanTuLonNhatDong(float[][MAXC], int, int, int, int);

bool TimPhanTuNhoNhatCot(float[][MAXC], int, int, int, int);


string GetFileLink(string);

int main()
{
	float a[MAXR][MAXC];
	int m;
	int n;
	Nhap(GetFileLink("float"), a, m, n);
	Xuat(a, m, n);
	cout << "so yen ngua : " << DemYenNgua(a, m, n);
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
			cout << setw(8) << setprecision(3) << a[i][j];
		cout << endl;
	}
}

bool TimPhanTuLonNhatDong(float a[][MAXC], int m, int n, int i, int j)
{
	float x = a[i][j];
	for (int k = 0; k < n; k++)
		if (a[i][k] > x)
			return false;
	return true;
}

bool TimPhanTuNhoNhatCot(float a[][MAXC], int m, int n, int i, int j)
{
	float x = a[i][j];
	for (int k = 0; k < m; k++)
		if (a[k][j] < x)
			return false;
	return true;
}

int DemYenNgua(float a[][MAXC], int m, int n)
{
	int dem = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (TimPhanTuLonNhatDong(a, m, n, i, j) && TimPhanTuNhoNhatCot(a, m, n, i, j))
				dem++;
	return dem;
}