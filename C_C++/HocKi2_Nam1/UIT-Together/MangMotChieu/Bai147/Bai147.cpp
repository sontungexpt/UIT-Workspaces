#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
#include <math.h>

using namespace std;

#define MAX 1000

string GetFileLink(string);
void Nhap(string, int[], int&);
void Xuat(int[], int);
void TronGiam(int[], int, int[], int, int[], int&);
void SapTang(int[], int);
void HoanVi(int&, int&);

int main()
{
	int n1;
	int a1[MAX];
	int n2;
	int a2[MAX];
	int newN;
	int newArr[MAX];
	cout << "Chon file de nhap mang dau tien\n";
	Nhap(GetFileLink("int"), a1, n1);
	cout << "Chon file de nhap mang thu hai\n";
	Nhap(GetFileLink("int"), a2, n2);
	TronGiam(a1, n1, a2, n2, newArr, newN);
	Xuat(newArr, newN);
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

void HoanVi(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void SapTang(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
				HoanVi(a[i], a[j]);
}

void TronGiam(int a[], int nA, int b[], int nB, int out[], int& n3)
{
	int i = 0;
	int j = 0;
	n3 = 0;
	while (!(i >= nA && j >= nB))
	{
		if ((i < nA && j<nB && a[i]>b[j]) || (j >= nB))
			out[n3++] = a[i++];
		else out[n3++] = b[j++];
	}
}


