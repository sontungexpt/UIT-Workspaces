#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;

#define MAX 10000

string GetFileLink(string);
void NhapTuFile(string, int[], int&);
void HoanVi(int&, int&);
void SapTang(int[], int);
void Tron(int[], int, int[], int, int[], int&);
void Xuat(int[], int);

int main()
{
	int a[MAX];
	int n;
	int b[MAX];
	int m;
	NhapTuFile(GetFileLink("int"), a, n);
	NhapTuFile(GetFileLink("int"), b, m);
	int c[MAX];
	int p;
	Tron(a, n, b, m, c, p);
	Xuat(c, p);
	return 1;
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

void NhapTuFile(string filename, int a[], int& n)
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

void HoanVi(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void SapTang(int a[], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
				HoanVi(a[i], a[j]);

}

void Tron(int a[], int n, int b[], int m, int c[], int& p)
{
	int i = 0;
	int j = 0;
	p = 0;
	SapTang(a, n);
	SapTang(b, m);
	while (!(i >= n && j >= m))
	{
		if ((i < n && j < m && a[i] < b[j]) || (j >= m))
			c[p++] = a[i++];
		else
			c[p++] = b[j++];
	}
}

void Xuat(int c[], int p)
{
	cout << "Mang sau khi tron la: ";
	for (int i = 0; i < p; i++)
		cout << setw(11) << c[i];
}