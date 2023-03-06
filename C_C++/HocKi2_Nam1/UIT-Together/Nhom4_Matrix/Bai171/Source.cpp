#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
#include <math.h>

using namespace std;

#define MAXR 350
#define MAXC 350

//initalize function
string GetFileLink(string);
void Xuat(float[][MAXC], int, int);
void Nhap(string, float[][MAXC], int&, int&);
int DemCon(float[][MAXC], int, int, float[][MAXC], int, int);

int main()
{
	int k = 0;
	int l = 0;
	int h = 0;
	int z = 0;
	float a[MAXR][MAXC];
	float b[MAXR][MAXC];
	cout << "Chon file de nhap ma tran 1\n";
	Nhap(GetFileLink("float"), a, k, l);
	cout << "Chon file de nhap ma tran 2\n";
	Nhap(GetFileLink("float"), b, h, z);
	cout << "So lan dem duoc duoc ma tran 1 trong ma tran 2 la: " << DemCon(a, k, l, b, h, z);
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

void Xuat(float a[][MAXC], int m, int n)
{
	cout << "Ma tran la:\n";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(8) << a[i][j];
		cout << endl;
	}
}

int DemCon(float a[][MAXC], int m, int n, float b[][MAXC], int u, int h)
{
	if (m > u || n > h)
		return 0;
	int count = 0;
	int flag = 0;
	for(int i=0;i<=u-m;i++)
		for (int j = 0; j <= h - n; j++)
		{
			int flag = 1;
			for (int d = 0; d < m; d++)
				for (int c = 0; c < n; c++)
					if (b[d + i][c + j] != a[d][c])
						flag = 0;
			if (flag == 1)
				count++;
		}
	return count;
}