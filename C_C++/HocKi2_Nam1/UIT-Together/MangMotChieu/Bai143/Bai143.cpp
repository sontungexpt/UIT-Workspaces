#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;

#define MAX 100000

string GetFileLink(string);
void SapTang(float[], int);
int ktHoanVi(float[], int, float[], int);
void Nhap(float[], int&, string);

int main()
{
	float a[MAX];
	int n = 0;
	float b[MAX];
	int m = 0;

	Nhap(a, n, GetFileLink("float"));
	Nhap(b, n, GetFileLink("float"));
	if (ktHoanVi(a, n, b, m) == 1)
		cout << "Mang a va mang b la 2 mang hoan vi";
	else
		cout << "Mang a va mang b khong la 2 mang hoan vi";


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

void SapTang(float a[], int n)
{
	for (int i = 0; i <= n - 2; i++)
		for (int j = i + 1; j <= n - 1; j++)
			if (a[j] < a[i])
				swap(a[i], a[j]);
}

int ktHoanVi(float a[], int n, float b[], int m)
{
	if (m != n)
		return 0;
	SapTang(a, n);
	SapTang(b, m);
	int flag = 1;
	for (int i = 0; i < n; i++)
		if (a[i] != b[i])
			flag = 0;
	return flag;
}