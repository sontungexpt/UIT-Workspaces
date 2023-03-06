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

float TichCot(float[][MAXC], int, int, int);

string GetFileLink(string);

int main()
{
	float a[MAXR][MAXC];
	int m;
	int n;
	int c;
	Nhap(GetFileLink("float"), a, m, n);
	Xuat(a, m, n);
	cout << "nhap cot muon tim tich theo yeu cau: ";
	cin >> c;
	cout << "tich gia tri tu -1 -> 0: " << TichCot(a, m, n, c);

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

float TichCot(float a[][MAXC], int m, int n, int c)
{
	float t = 1;
	for (int i = 0; i < m; i++)
		if (-1 < a[i][c] && a[i][c] < 0)
			t = t * a[i][c];
	return t;
}

