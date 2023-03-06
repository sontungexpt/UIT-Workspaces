#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;

#define MAX 100000

void Nhap(string, int[], int&);
void Xuat(int[], int);
void LietKe(int[], int);
string GetFileLink(string);

int main()
{
	string filename = GetFileLink("int");
	int n;
	int a[MAX];

	Nhap(filename, a, n);
	Xuat(a, n);
	LietKe(a, n);

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

void LietKe(int a[], int n)
{
	cout << "\nCac gia tri thoa man yeu cau:";
	if (n <= 1)
		return;

	if (a[0] % 2 == 0 && a[1] % 2 == 0)
		cout << setw(6) << setprecision(3) << a[0];

	for (int i = 1; i <= n - 2; i++)
		if (a[i] % 2 == 0)
			if (a[i - 1] % 2 == 0 || a[i + 1] % 2 == 0)
				cout << setw(6) << setprecision(3) << a[i];

	if (a[n - 1] % 2 == 0 && a[n - 2] % 2 == 0)
		cout << setw(6) << setprecision(3) << a[n - 1];
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