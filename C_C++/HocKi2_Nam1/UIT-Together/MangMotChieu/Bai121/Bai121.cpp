#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
#include <math.h>

using namespace std;

#define MAX 100

string GetFileLink(string);
void Nhap(string, int[], int&);
bool KtHoanThien(int);
bool KtTinhChat(int[], int);

int main()
{
	int n;
	int a[MAX];
	Nhap(GetFileLink("int"), a, n);
	if (KtTinhChat(a, n) == true)
		cout << "Mang ko co ton tai so hoan thien lon hon 256";
	else
		cout << "Mang co ton tai so hoan thien lon hon 256";
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

bool KtHoanThien(int n)
{
	int sum = 0;
	for (int i = 1; i <= n / 2; i++)
		if (n % i == 0)
			sum += i;
	if (sum == n)
		return true;
	return false;
}
bool KtTinhChat(int a[], int n)
{
	for (int i = 0; i < n; i++)
		if (a[i] > 0 && KtHoanThien(a[i]) == true)
			return 0;
	return 1;
}



