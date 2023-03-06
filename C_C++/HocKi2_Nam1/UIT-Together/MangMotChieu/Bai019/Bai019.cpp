#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;

#define MAX 100000

void NhapTuFile(string, float[], int&);
string GetFileLink(string);
void LietKe(float[], int);
float NhoNhat(float[], int);

int main()
{
	float a[MAX];
	int n;
	NhapTuFile(GetFileLink("float"), a, n);
	LietKe(a, n);
	return 0;
}

void NhapTuFile(string filename, float a[], int& n)
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
void Nhap(string filename, float a[], int& n)
{
	ifstream fi(filename);
	fi >> n;
	for (int i = 0; i < n; i++)
		fi >> a[i];
}
float NhoNhat(float a[], int n)
{
	int lc = 0;
	for (int i = 0; i <= n - 1; i++)
		if (a[i] < a[lc])
			lc = i;
	return a[lc];
}
void LietKe(float a[], int n)
{
	float lc = NhoNhat(a, n);
	for (int i = 0; i <= n - 1; i++)
		if (a[i] == lc)
			cout << i << " ";
}