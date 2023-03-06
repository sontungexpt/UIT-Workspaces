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
void NhapTuFile(string, float[][MAXC], int&, int&);
int DemAmTrenCot(float[][MAXC], int, int, int);

int main()
{
	float a[MAXR][MAXC];
	int m;
	int n;
	NhapTuFile(GetFileLink("float"), a, m, n);
	for (int j = 0; j < n; j++)
		cout << "Cot " << j + 1 << " co " << DemAmTrenCot(a, m, n, j) << " gia tri am" << endl;
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

void NhapTuFile(string filename, float a[][MAXC], int& m, int& n)
{
	ifstream fi(filename);
	if (fi.fail() == true)
		cout << "Khong mo duoc file";
	fi >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			fi >> a[i][j];
}

int DemAmTrenCot(float a[][MAXC], int m, int n, int c)
{
	int dem = 0;
	for (int i = 0; i < m; i++)
		if (a[i][c] < 0)
			dem++;
	return dem;
}
