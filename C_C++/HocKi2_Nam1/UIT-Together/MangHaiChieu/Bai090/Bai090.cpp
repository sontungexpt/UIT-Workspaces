#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

#define MAXR 500
#define MAXC 500

string GetFileLink(string);
void NhapMaTran(string, float[][MAXC], int&, int&);
float TongDong(float[][MAXC], int, int);
float TongLonNhat(float[][MAXC], int, int);
void LietKe(float[][MAXC], int, int);

int main()
{
	int m;
	int n;
	float a[MAXR][MAXC];
	NhapMaTran(GetFileLink("float"), a, m, n);
	LietKe(a, m, n);
	return 0;
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

void NhapMaTran(string filename, float a[][MAXC], int& m, int& n)
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


float TongDong(float a[][MAXC], int n, int i)
{
	float s = 0;
	for (int j = 0; j < n; j++)
		s += a[i][j];
	return s;
}

float TongLonNhat(float a[][MAXC], int m, int n)
{
	float lc = TongDong(a, n, 0);
	for (int i = 1; i < m; i++)
	{
		float temp = TongDong(a, n, i);
		if (lc < temp)
			lc = temp;
	}
	return lc;
}

void LietKe(float a[][MAXC], int m, int n)
{
	float t = TongLonNhat(a, m, n);
	for (int i = 0; i < m; i++) {
		float temp = TongDong(a, n, i);
		if (temp == t)
			cout << "Dong thu " << i << " co tong lon nhat va tong do la: " << t << endl;
	}
}
