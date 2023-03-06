#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;

#define MAX 100000

void Nhap(string, float[], int&);
void Xuat(float[], int);
int ViTriDau(float[], int);		//Duong dau tien
int TimViTri(float[], int);		//Cua duong nho nhat
string GetFileLink(string);

int main()
{
	string filename = GetFileLink("float");
	int n;
	float a[MAX];

	Nhap(filename, a, n);
	Xuat(a, n);
	int kq = TimViTri(a, n);
	cout << "\nVi tri gia tri duong nho nhat la: " << kq;

	return 0;
}

void Nhap(string filename, float a[], int& n)
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
	for (int i = 0; i <= n - 1; i++)
		cout << a[i] << setw(11);
}

int ViTriDau(float a[], int n)
{
	for (int i = 0; i < n; i++)
		if (a[i] > 0)
			return i;
	return -1;
}

int TimViTri(float a[], int n)
{
	int lc = ViTriDau(a, n);

	if (lc == -1)
		return -1;

	for (int i = 0; i < n; i++)
		if (a[i] > 0 && a[i] < a[lc])
			lc = i;
	return lc;
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