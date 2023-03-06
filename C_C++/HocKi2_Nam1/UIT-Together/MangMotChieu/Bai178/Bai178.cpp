#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;

#define MAX 100000

string GetFileLink(string);
void NhapTuFile(string, float[], int&);
int ktCon(float[], int, int, int);
float TongCon(float[], int, int, int);
void LietKe(float[], int);

int main()
{
	float a[MAX];
	int n;
	NhapTuFile(GetFileLink("float"), a, n);
	LietKe(a, n);
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
		fi >> a[i];
}

int ktCon(float a[], int n, int vt, int l)
{
	int flag = 1;
	for (int i = 0; i <= l - 2; i++)
		if (a[vt + i] > a[vt + i + 1])
			flag = 0;
	return flag;
}

float TongCon(float a[], int n, int vt, int l)
{
	float s = 0;
	for (int i = 0; i < l; i++)
		s = s + a[vt + i];
	return s;
}

void LietKe(float a[], int n)
{
	for (int l = 1; l <= n; l++)
	{
		for (int vt = 0; vt <= n - l; vt++)
			if (ktCon(a, n, vt, l) == 1)
			{
				for (int i = 0; i < l; i++)
					cout << a[vt + i] << setw(11);
				cout << " co tong la: " << TongCon(a, n, vt, l) << endl;
			}
	}
}