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
bool ktCotGiam(int[][MAXC], int, int);
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

bool ktCotGiam(float a[][MAXC], int m, int j)
{
	bool flag = true;
	for (int i = 0; i < m - 1; i++)
		if (a[i][j] < a[i+1][j])
			flag = false;
	return flag;
}

void LietKe(float a[][MAXC], int m, int n)
{
	bool flag = false;
	for (int j = 0; j < n; j++) {
		if (ktCotGiam(a, m, j) == true)
		{
			cout << "Cot thu " << j << " giam dan" << endl;
			flag = true;
		}
	}
	if (flag == false)
		cout << "Khong co cot nao!" << endl;
}
