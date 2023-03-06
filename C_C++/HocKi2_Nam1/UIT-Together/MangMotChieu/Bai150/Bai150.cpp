#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;

#define MAX 100000

void Nhap(string, int[], int&);
void Xuat(int[], int);
void HoanVi(int&, int&);
void MotVeDau(int[], int);
string GetFileLink(string);

int main()
{
	string filename = GetFileLink("int");
	int n, k;
	int a[MAX], b[MAX];

	Nhap(filename, a, n);
	Xuat(a, n);
	MotVeDau(a, n);
	cout << "\n\nMang moi co so 1 ve dau la:\n";
	Xuat(a, n);

	return 0;
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

void Xuat(int a[], int n)
{
	for (int i = 0; i <= n - 1; i++)
		cout << a[i] << setw(11);
}

void HoanVi(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void MotVeDau(int a[], int n)
{
	int vt = 0;

	for (int i = 0; i < n; i++)
		if (a[i] == 1)
		{
			HoanVi(a[i], a[vt]);
			vt++;
		}
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