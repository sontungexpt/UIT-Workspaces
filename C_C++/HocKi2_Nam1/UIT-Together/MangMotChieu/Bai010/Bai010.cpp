#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
#include <math.h>

using namespace std;

#define MAX 100000

string GetFileLink(string);
void Nhap(string, int[], int&);
void LietKe(int[], int);
bool ToanLe(int);

int main()
{
	int n;
	int a[MAX];
	Nhap(GetFileLink("int"), a, n);
	LietKe(a, n);
	return 0;
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

void LietKe(int a[], int n)
{
	cout << "\n Cac so co toan chu so le: ";
	for (int i = 0; i < n; i++)
		if (ToanLe(a[i]) == true)
			cout << a[i] << setw(11);
}

bool ToanLe(int n)
{
	int dvi = 0;
	int temp = abs(n);
	for (; temp > 0;)
	{
		dvi = temp % 10;
		if (dvi % 2 == 0)
			return false;
		temp /= 10;
	}
	return true;
}