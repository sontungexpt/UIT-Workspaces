
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;

#define MAX 100000

void DichPhai(float[], int);
string GetFileLink(string);
void Nhap(float[], int&, string);
void Xuat(float[], int);

int main()
{
	float a[MAX];
	int n = 0;
	Nhap(a, n, GetFileLink("float"));
	DichPhai(a, n);
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

void DichPhai(float a[], int n)
{
	float temp = a[n - 1];
	for (int i = n - 1; i >= 1; i--)
		a[i] = a[i - 1];
	a[0] = temp;
}

void Xuat(float a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << setw(11) << a[i];
}