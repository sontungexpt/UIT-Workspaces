#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

#define MAX 100000

void Nhap(string, float[], int&);
void HoanVi(float&, float&);
void SapTang(float[], int);
void Xuat(float[], int);
string GetFileLink(string);

int main()
{
	int n;
	float a[MAX];
	Nhap(GetFileLink("float"), a, n);
	SapTang(a, n);
	cout << "Sau khi sap xep: " << endl;
	Xuat(a, n);
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

void HoanVi(float& x, float& y)
{
	float temp = x;
	x = y;
	y = temp;
}

void SapTang(float a[], int n)
{
	for (int i = 0; i <= n - 2; i++)
		for (int j = i + 1; j <= n - 1; j++)
			if (a[i] > a[j])
				HoanVi(a[i], a[j]);
}

void Xuat(float a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << setw(11) << a[i];
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