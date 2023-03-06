#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <fstream>
#include <cctype>
using namespace std;

#define MAX 100000

void Nhap(string, float[], int&);
string GetFileName(string);
float KiemTra(float, float, float);
void LietKe(float[], int);

int main()
{
	int n;
	float a[MAX];
	Nhap(GetFileName("float"), a, n);
	cout << "Cac tap hop thoa man dieu kien la: " << endl;
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

float KiemTra(float a, float b, float c)
{
	if (a != b && a != c && b != c && a == b + c) return 1;
	return 0;
}

void LietKe(float a[], int n)
{
	{
		for (int i = 0; i <= n - 1; i++)
			for (int j = 0; j <= n - 1; j++)
				for (int k = 0; k <= n - 1; k++)
					if (KiemTra(a[i], a[j], a[k]) == 1)
					{
						cout << "( " << a[i] << ", " << a[j];
						cout << ", " << a[k] << " )" << endl;

					}
	}
}

string GetFileName(string dataTypeOfFile)
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
