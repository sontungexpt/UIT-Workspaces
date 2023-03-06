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
string GetFileLink(string);
void Xuat(int[][MAXC], int, int);
void Nhap(string, int[][MAXC], int&, int&);
bool KtDang2m(int );
void LietKe(int[][MAXC], int, int);

int main()
{
	int k = 0;
	int l = 0;
	int a[MAXR][MAXC];
	Nhap(GetFileLink("int"), a, k, l);
	LietKe(a, k, l);
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

void Nhap(string filename, int a[][MAXC], int& m, int& n)
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

void Xuat(int a[][MAXC], int m, int n)
{
	cout << "Ma tran la:\n";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(8) << a[i][j];
		cout << endl;
	}
}

bool KtDang2m(int n)
{
	if (n < 1)
		return 0;
	int temp = n;
	bool flag = true;
	for (; temp > 1;)
	{
		int du = temp % 2;
		if (du != 0)
			flag = false;
		temp /= 2;
	}
	return flag;
}

void LietKe(int a[][MAXC], int m, int n)
{
	cout << "Cac so toan chu so chan la: ";
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (KtDang2m(a[i][j]) == true)
				cout << setw(8) << a[i][j];
}