#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
#include <math.h>

using namespace std;

#define MAX 100000

string GetFileLink(string);
void Nhap(string, float[], int&);
void LietKe(float[], int);

int main()
{
	int n;
	float a[MAX];
	Nhap(GetFileLink("float"), a, n);
	LietKe(a, n);
	return 0;
}

//function
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
	if (fi.fail() == true)
	{
		cout << "Khong mo duoc file";
	}
	fi >> n;
	for (int i = 0; i < n; i++)
		fi >> a[i];
}

void LietKe(float a[], int n)
{
	cout << "\nCac so co am trong mang la: ";
	for (int i = 0; i < n; i++)
		if (a[i] < 0)
			cout << a[i] << setw(11);
}


