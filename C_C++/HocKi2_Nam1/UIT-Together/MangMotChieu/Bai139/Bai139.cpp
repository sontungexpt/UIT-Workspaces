#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
#include <math.h>

using namespace std;

#define MAX 100000

string GetFileLink(string);
void Nhap(string, int[], int&);
void HoanVi(int&, int&);
void ViTriLeTang(int[], int);
void Xuat(int[], int);
int main()
{
	int n;
	int a[MAX];
	Nhap(GetFileLink("int"), a, n);
	ViTriLeTang(a, n);
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

void HoanVi(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void ViTriLeTang(int a[], int nn)
{
	for (int i = 1; i < nn - 2; i += 2)
		for (int j = i + 2; j < nn; j += 2)
			if (a[i] > a[j])
				HoanVi(a[i], a[j]);

}
