#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;

#define MAX 100000

void NhapGiam(string, float[], int&);
void Xuat(float[], int);
string GetFileLink(string);

int main()
{
	string filename = GetFileLink("float");
	int n;
	float a[MAX];

	NhapGiam(filename, a, n);
	Xuat(a, n);

	return 0;
}

void NhapGiam(string filename, float a[], int& n)
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
		float x;
		fi >> x;

		int j;
		for (j = i - 1; j >= 0 && a[j] < x; j--)	//(!) j phai de o ngoai thi a[j + 1] = x moi chay duoc
			a[j + 1] = a[j];
		a[j + 1] = x;
	}
}

void Xuat(float a[], int n)
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