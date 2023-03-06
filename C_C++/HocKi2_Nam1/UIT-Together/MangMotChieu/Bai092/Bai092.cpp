#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;

#define MAX 100000

void NhapTuFile(string, int[], int&);
string GetFileLink(string);
int ChuSoDau(int);
int TimGiaTri(int[], int);

int main()
{
	int a[MAX];
	int n;
	NhapTuFile(GetFileLink("int"), a, n);
	cout << TimGiaTri(a, n);
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
	{
		fi >> a[i];
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
int ChuSoDau(int n)
{
	int t = abs(n);
	while (t >= 10)
		t /= 10;
	return t;
}
int TimGiaTri(int a[], int n)
{
	for (int i = 0; i <= n - 1; i++)
		if (ChuSoDau(a[i]) % 2 == 1)
			return a[i];
	return -1;
}