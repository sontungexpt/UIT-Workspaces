#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;

#define MAX 100000

int ktBang(int[], int);
string GetFileLink(string);
void Nhap(int[], int&, string);

int main()
{
	int a[MAX];
	int n = 0;
	Nhap(a, n, GetFileLink("int"));
	if (ktBang(a, n) == 1)
		cout << "\nCac phan tu trong mang bang nhau";
	else cout << "\nCac phan tu trong mang khong bang nhau";
	return 0;
}

void Nhap(int a[], int& n, string filename)
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

int ktBang(int a[], int n)
{
	int flag = 1;
	for (int i = 0; i < n; i++)
		if (a[i] != a[0])
			flag = 0;
	return flag;
}