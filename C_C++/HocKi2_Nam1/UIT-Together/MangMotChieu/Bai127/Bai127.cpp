#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;
#define MAX 100000

void Nhap(string, int[], int&);
void Xuat(int[], int);
int ktCSC(int[], int);
string GetFileLink(string);

int main()
{
	string filename = GetFileLink("int");
	int n;
	int a[MAX];

	Nhap(filename, a, n);
	Xuat(a, n);
	if (ktCSC(a, n) == 1)
		cout << "\nMang: Lap thanh cap so cong";
	else
		cout << "\nMang: Khong lap thanh cap so cong";

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

int ktCSC(int a[], int n)
{
	if (n <= 1)
		return 0;

	int flag = 1;

	for (int i = 0; i <= n - 2; i++)
		if ((a[i] - a[i + 1]) != (a[0] - a[1]))
			flag = 0;
	return flag;
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