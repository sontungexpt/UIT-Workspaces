#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
#include <math.h>

using namespace std;

#define MAX 10000

string GetFileLink(string);
void Nhap(string, int[], int&);
void Xuat(int[], int);
void XoaViTri(int[], int&, int);
bool KtChinhPhuong(int);
void XoaChinhPhuong(int[], int);

int main()
{
	int n;
	int a[MAX];
	Nhap(GetFileLink("int"), a, n);
	XoaChinhPhuong(a, n);
	Xuat(a, n);
	return 0;
}

string GetFileLink(string dataTypeOfFile)
{
	string folderName = dataTypeOfFile;
	folderName[0] = toupper(folderName[0]);
	folderName += "Data";
	string fileLink = "../" + folderName + "/" + dataTypeOfFile + "data";
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

void Nhap(string filename, int a[], int& n)
{
	ifstream fi(filename);
	if (fi.fail() == true)
	{
		cout << "Khong mo duoc file";
		exit(0);
	}
	fi >> n;
	for (int i = 0; i < n; i++)
		fi >> a[i];
}

void Xuat(int a[], int nn)
{
	for (int i = 0; i < nn; i++)
		cout << setw(11) << a[i];
}

void XoaViTri(int a[], int& n, int viTriXoa)
{
	for (int i = viTriXoa; i < n - 1; i++)
		a[i] = a[i + 1];
	n--;
}

bool KtChinhPhuong(int n)
{
	if (n < 1)
		return 0;
	for (int i = 1; i * i <= n; i++)
		if (i * i == n)
			return 1;
	return 0;
}

void XoaChinhPhuong(int a[], int n)
{
	for (int i = 0; i < n; i++)
		if (KtChinhPhuong(a[i]) == true)
			XoaViTri(a, n, i);
}