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

void TimConLonNhat(float[][MAXC], int, int, int&, int&, int&, int&);

string GetFileLink(string);

int main()
{
	float a[MAXR][MAXC];
	int m;
	int n;
	int c;
	Nhap(GetFileLink("float"), a, m, n);
	Xuat(a, m, n);

	cout << "xap xep guong theo chieu doc: " << endl;
	Xuat(a, m, n);
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

void TimConLonNhat(float a[][MAXC], int m, int n, int&, int&, int&, int&)
{

}

float tong(float a[][MAXC], int i, int n)
{
	float s = 0;
	for (int j = 0; j < n; j++)
		s = s + a[i][j];
	return s;
}
float tonglonnhat(float a[][MAXC], int m, int n)
{
	int i, d;
	float max = tong(a, 0, n);
	for (i = 0; i < m; i++)
	{
		float t = tong(a, i, n);
		if (max < t)
		{
			max = t;
			d = i;
		}
	}
	return d;
}