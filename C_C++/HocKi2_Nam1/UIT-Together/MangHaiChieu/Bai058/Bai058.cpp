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
int DemDang2m(int[][500], int, int);
bool ktDang2m(int);
int main()
{
	int row = 0;
	int col = 0;
	int a[MAXR][MAXC];
	Nhap(GetFileLink("int"), a, row, col);
	cout << "Ma tran: \n";
	Xuat(a, row, col);
	int kq = DemDang2m(a, row, col);
	cout << "\nSo Phan tu co dang 2^m trong ma tran: " << kq;
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

int DemDang2m(int a[][500], int m, int n)
{
	int dem = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (ktDang2m(a[i][j]) == true)
				dem++;
	return dem;

}

bool ktDang2m(int n)
{
	int flag = true;
	int t = n;
	while (t != 0)
	{
		if (t % 2 != 0)
			flag = false;
		t = t / 2;
	}
	return flag;
}