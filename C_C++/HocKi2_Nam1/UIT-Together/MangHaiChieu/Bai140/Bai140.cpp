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

void BienDoi(float[][MAXC], int, int);


string GetFileLink(string);

int main()
{
	float a[MAXR][MAXC];
	int m;
	int n;
	Nhap(GetFileLink("float"), a, m, n);
	Xuat(a, m, n);
	cout << "ma tran xoan oc: \n";
	BienDoi(a, m, n);
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

void BienDoi(float a[][MAXC], int m, int n) // ham nay em xem mang lam chu em k biet lam a
{
	float b[MAXR][MAXC];
	float x = 1;
	int h1 = 0;
	int h2 = n - 1;
	int c1 = 0;
	int c2 = n - 1;
	while (h1 <= h2 && c1 <= 2)
	{
		for (int i = c1; i <= c2; i++)
		{
			b[h1][i] = x;
			x++;
		}
		++h1;
		for (int i = h1; i <= h2; i++)
		{
			b[i][c2] = x;
			++x;
		}
		--c2;
		if (c1 <= c2)
		{
			for (int i = h1; i <= h2; i++)
			{
				b[i][c2] = x;
				++x;
			}
			--h2;
		}
		if (h1 <= h2)
		{
			for (int i = h2; i >= h1; i--)
			{
				b[i][c1] = x;
				++x;
			}
			++c1;

		}

	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j <= m; j++)
			cout << a[i][j] << " ";
		cout << "\n";
	}

}