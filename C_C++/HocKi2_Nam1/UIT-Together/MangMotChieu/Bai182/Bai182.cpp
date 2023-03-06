#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;

#define MAX 100000

void Nhap(string, float[], int&);
void Xuat(float[], int);
int ktCon(float[], int, int, int);
float LonNhat(float[], int);
void LietKe(float[], int);
string GetFileLink(string);

int main()
{
	string filename = GetFileLink("float");
	int n;
	float a[MAX];

	Nhap(filename, a, n);
	Xuat(a, n);

	cout << "\n\nCac mang con tang co chua gia tri lon nhat la:\n";
	LietKe(a, n);

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

int ktCon(float a[], int n, int vt, int l)
{
	int flag = 1;

	for (int i = 0; i <= l - 2; i++)
		if (a[vt + i] > a[vt + i + 1])
			flag = 0;
	return flag;
}

float LonNhat(float a[], int n)
{
	float lc = a[0];

	for (int i = 0; i < n; i++)
		if (a[i] > lc)
			lc = a[i];
	return lc;
}

void LietKe(float a[], int n)
{
	float ln = LonNhat(a, n);

	for (int l = 1; l <= n; l++)
	{
		for (int vt = 0; vt <= n - l; vt++)
		{
			if (ktCon(a, n, vt, l) && a[vt + l - 1] == ln)
			{
				for (int i = 0; i <= l - 1; i++)
					cout << setw(11) << a[vt + i];
				cout << endl;
			}
		}
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