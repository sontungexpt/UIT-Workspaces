#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;

#define MAX 100000

string GetFileLink(string);
void LietKe(float[], int);
void Nhap(float[], int&, string);

int main()
{
	float a[MAX];
	int n = 0;
	Nhap(a, n, GetFileLink("float"));
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

void Nhap(float a[], int& n, string filename)
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

void LietKe(float a[], int n)
{
	if (n == 1)
		return;
	if (a[0] < a[1] || a[0] > a[1])
		cout << setw(11) << a[0];;
	for (int i = 1; i <= n - 2; i++)
	{
		if ((a[i] < a[i - 1] && a[i] < a[i + 1]) || (a[i] < a[i - 1] && a[i] < a[i + 1]))
			cout << setw(11) << a[i];
		if (a[n - 1] < a[n - 2] || a[n - 1] > a[n - 2])
			cout << setw(11) << a[n - 1];
	}
}