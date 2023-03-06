#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;

#define MAX 100000

string GetFileLink(string);
void NhapTuFile(string, int[], int&);
int ktTonTai(int[], int);

int main()
{
	int a[MAX];
	int n;
	NhapTuFile(GetFileLink("int"), a, n);
	int kq = ktTonTai(a, n);
	if (kq == 0)
		cout << "Mang khong ton tai 2 so 0 lien tiep";
	else
		cout << "Mang ton tai 2 so 0 lien tiep";
	return 1;
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
		fi >> a[i];
}

int ktTonTai(int a[], int n)
{
	int flag = 0;
	for (int i = 0; i < n - 1; i++)
		if (a[i] == 0 && a[i + 1] == 0)
			flag = 1;
	return flag;
}