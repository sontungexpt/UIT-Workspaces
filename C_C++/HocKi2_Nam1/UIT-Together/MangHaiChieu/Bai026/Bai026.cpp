#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <iomanip>
using namespace std;

#define MAXR 500
#define MAXC 500

string GetFileLink(string);
void NhapMaTran(string, int[][MAXC], int&, int&);
bool ktChinhPhuong(int);
int TongChinhPhuong(int[][MAXC], int, int);

int main()
{
	int m;
	int n;
	int a[MAXR][MAXC];
	NhapMaTran(GetFileLink("int"), a, m, n);
	int kq = TongChinhPhuong(a, m, n);
	cout << "Tong cac so chinh phuong nam tren cot co chi so le la: " << kq << endl;
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

void NhapMaTran(string filename, int a[][MAXC], int& m, int& n)
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

bool ktChinhPhuong(int n)
{
	bool flag = false;
	if (n == 0) return true;
	for (int i = 1; i <= n; i++)
		if (i * i == n)
			flag = true;
	return flag;
}

int TongChinhPhuong(int a[][MAXC], int m, int n)
{
	int s = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (ktChinhPhuong(a[i][j]) == true && j % 2 != 0)
				s += a[i][j];
	return s;
}