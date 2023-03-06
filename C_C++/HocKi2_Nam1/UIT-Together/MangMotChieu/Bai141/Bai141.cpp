#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;

#define MAX 100000

void NhapTuFile(string, int[], int&);
string GetFileLink(string);
bool ktHoanThien(int);
void HoanThienGiam(int[], int);
void HoanVi(int&, int&);
void Xuat(int a[], int n);

int main()
{
	int a[MAX];
	int n;
	NhapTuFile(GetFileLink("int"), a, n);
	HoanThienGiam(a, n);
	Xuat(a, n);
	return 0;
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
bool ktHoanThien(int n)
{
	int s = 0;
	for (int i = 1; i <= n - 1; i++)
		if (n % i == 0)
			s += i;
	if (s == n)
		return true;
	return false;
}
void HoanThienGiam(int a[], int n)
{
	for (int i = 0; i <= n - 2; i++)
		for (int j = i + 1; j <= n - 1; j++)
			if (ktHoanThien(a[i]) &&
				ktHoanThien(a[j]) && a[i] < a[j])
				HoanVi(a[i], a[j]);
}
void HoanVi(int& m, int& n)
{
	int j = m;
	m = n;
	n = j;
}
void Xuat(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}