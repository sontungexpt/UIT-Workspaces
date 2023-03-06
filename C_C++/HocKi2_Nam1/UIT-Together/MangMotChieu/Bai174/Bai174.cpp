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
void XuatCon(int[], int, int&);

int main()
{
	int n;
	int l;
	int a[MAX];
	Nhap(GetFileLink("int"), a, n);
	XuatCon(a, n, l);
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

void XuatCon(int a[], int nn, int& doDaiCon)
{
	cout << "Nhap do dai chuoi con: ";
	cin >> doDaiCon;
	for (int i = 0; i <= nn - doDaiCon; i++)
	{
		for (int j = i; j < i + doDaiCon; j++)
			cout << setw(11) << a[j];
		cout << endl;
	}
}
