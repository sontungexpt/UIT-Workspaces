#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;

#define MAX 100000

string GetFileLink(string);
void ThemBaoToan(float[], int&, float);
void Nhap(float[], int&, string);
void Xuat(float[], int);
void SapTang(float[], int);

int main()
{
	float a[MAX];
	int n = 0;
	Nhap(a, n, GetFileLink("float"));
	cout << "\nMang truoc khi sap: ";
	Xuat(a, n);
	SapTang(a, n);
	ThemBaoToan(a, n, 5.5);
	cout << "\nMang sau khi sap: ";
	Xuat(a, n);
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

void ThemBaoToan(float a[], int& n, float x)
{
	int i = 0;
	for (i = n - 1; i >= 0 && a[i] > x; i--)
		a[i + 1] = a[i];
	a[i + 1] = x;
	n++;
}

void Xuat(float a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << setw(11) << a[i];
}

void SapTang(float a[], int n)
{
	for (int i = 0; i <= n - 2; i++)
		for (int j = i + 1; j <= n - 1; j++)
			if (a[j] < a[i])
				swap(a[i], a[j]);
}