#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
#include <math.h>

using namespace std;

#define MAXR 500
#define MAXC 500

void Nhap(string, int[][500], int&, int&);
void Xuat(int[][500], int, int);
string GetFileLink(string);
int ktToanChan(int[][500], int, int, int);



int main()
{
	int row = 0;
	int col = 0;
	int a[MAXR][MAXC];
	int c;

	Nhap(GetFileLink("int"), a, row, col);
	cout << "Ma tran: \n";
	Xuat(a, row, col);
	cout << "\nNhap cot: ";
	cin >> c;
	if (ktToanChan(a, row, col, c) == 1)
		cout << "\nCot toan gia tri chan";
	else
		cout << "\nCot khong toan gia tri chan";
	return 1;
}

void Nhap(string filename, int a[][500], int& m, int& n)
{
	ifstream fi(filename);
	fi >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			fi >> a[i][j];
}

void Xuat(int a[][500], int m, int n)
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

int ktToanChan(int a[][500], int m, int n, int c)
{
	int flag = 1;
	for (int i = 0; i < m; i++)
		if (a[i][c] % 2 != 0)
			flag = 0;
	return flag;

}