#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;

#define MAX 100000

string GetFileLink(string);
void Nhap(float[], int&, string);
void Xuat(float[], int);
int ktCon(float[], int, float[], int);

int main()
{
	float a[MAX];
	int n = 0;
	float b[MAX];
	int m = 0;
	Nhap(a, n, GetFileLink("float"));
	cout << "\nMang A: ";
	Xuat(a, n);
	Nhap(b, m, GetFileLink("float"));
	cout << "\nMang B: ";
	Xuat(b, m);
	if (ktCon(a, n, b, m) == 0)
		cout << "\nMang A khong la mang con cua mang B";
	else
		cout << "\nMang A la mang con cua mang B";

	return 0;
}

string GetFileLink(string floatdata)
{
	string folderName = floatdata;
	folderName[0] = toupper(folderName[0]);
	folderName += "Data";

	string fileLink = "../" + folderName + "/" + floatdata + "data";
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

void Nhap(float a[], int& n, string filename)
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

void Xuat(float a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << setw(11) << a[i];
}

int ktCon(float a[], int n, float b[], int m)
{
	if (n > m)
		return 0;
	int flag = 0;
	for (int vt = 0; vt <= m - n; vt++)
	{
		int co = 1;
		for (int i = 0; i < n; i++)
			if (a[i] != b[vt + i])
				co = 0;
		if (co == 1)
			flag = 1;
	}
	return flag;
}