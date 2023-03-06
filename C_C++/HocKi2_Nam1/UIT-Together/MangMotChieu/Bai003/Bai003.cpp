#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

#define MAX 100000

void Nhap(string, int[], int&);
void Xuat(int[], int);
string GetFileLink(string);

int main()
{
	int n;
	int a[MAX];
	Nhap(GetFileLink("int"), a, n);
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