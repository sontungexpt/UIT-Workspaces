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
int TongCot(int[][MAXC], int, int);
void Xuat(int[][MAXC], int, int);

int main()
{
	int m;
	int n;
	int a[MAXR][MAXC];
	NhapMaTran(GetFileLink("int"), a, m, n);
	Xuat(a, m, n);
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

int TongCot(int a[][MAXC], int m, int j)
{
	int s = 0;
	int flag = 0;
	for (int i = 0; i < m; i++)
		if (ktChinhPhuong(a[j][i]) == true)
		{
			s += a[j][i];
			flag = 1;
		}
	if (flag == 1)
		return s;
	return -1;
}

void Xuat(int a[][MAXC], int m, int n)
{
	for (int i = 0; i < n; i++)
		if (TongCot(a, m, i) != -1)
		{
			cout << "Tong cac so chinh phuong o cot " << i << " la: ";
			cout << setw(8) << TongCot(a, m, i);
			cout << endl;
		}
		else
			continue;
}