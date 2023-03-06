#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
#include<direct.h>

using namespace std;

#define MAX 100000


struct fraction
{
	int numerator;
	int denominator;
};
typedef struct fraction FRACTION;

//initalize function
void Input(FRACTION&);
void Input(string, FRACTION[], int&);
void Print(FRACTION);
void Print(FRACTION[], int);
void Print(string, FRACTION[], int);
string GetFileLink(string);
string GetFileLink(string, int);
void MergeSort(FRACTION[], int, int);
void Merge(FRACTION[], int, int, int);
int Compare(FRACTION, FRACTION);
void Print(string, string, FRACTION[], int);

int main()
{
	FRACTION a[MAX];
	int n;
	//for (int i = 1; i <= 13; i++)
	//{
		//string fileLink = GetFileLink("phanso", i);
	string fileLink = GetFileLink("phanso");
		Input(fileLink, a, n);
		MergeSort(a, 0,n-1);
		//cout << "File " << i << endl;
		Print(a, n);
		//Print(fileLink, "MergeSort", a, n);
	//}
	return 0;
}

//function
string GetFileLink(string dataTypeOfFile)
{
	string folderName = dataTypeOfFile;
	folderName[0] = toupper(folderName[0]);
	folderName[4] = toupper(folderName[4]);
	folderName += "Data";
	string fileLink = "../" + folderName + "/Input/" + dataTypeOfFile + "data";
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

string GetFileLink(string dataTypeOfFile, int fileIndex)
{
	string folderName = dataTypeOfFile;
	folderName[0] = toupper(folderName[0]);
	folderName[4] = toupper(folderName[4]);
	folderName += "Data";
	string fileLink = "../" + folderName + "/Input/" + dataTypeOfFile + "data";
	if (fileIndex < 10)
		fileLink += '0';
	fileLink += to_string(fileIndex);
	string fileLinkInp = fileLink;
	fileLinkInp += ".inp";
	return fileLinkInp;
}

void Input(FRACTION& frac)
{
	cout << "Nhap tu: ";
	cin >> frac.numerator;
	cout << "Nhap mau: ";
	cin >> frac.denominator;
}
void Input(string filename, FRACTION a[], int& n)
{
	ifstream fi(filename);
	if (fi.fail() == true)
	{
		cout << "Khong mo duoc file";
		exit(0);
	}
	fi >> n;
	for (int i = 0; i < n; i++)
		fi >> a[i].numerator >> a[i].denominator;
}

void Print(FRACTION frac)
{
	if (frac.numerator * frac.denominator >= 0)
		cout << abs(frac.numerator) << "/" << abs(frac.denominator);
	else
		cout << -abs(frac.numerator) << "/" << abs(frac.denominator);
}

void Print(FRACTION a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		Print(a[i]);
		cout << endl;
	}
}

void Print(string fileInName, string typeOfSort, FRACTION a[], int n)
{
	string fileOutName = fileInName;
	string inputFolderName = "Input";
	int indexFolderName = fileOutName.find(inputFolderName);
	int indexInsert = indexFolderName + inputFolderName.length() + 1;
	fileOutName.insert(indexInsert, typeOfSort + "/");
	fileOutName.replace(indexFolderName, inputFolderName.length(), "Output");
	string extension = "inp";
	int indexExtension = fileOutName.find(extension);
	fileOutName.replace(indexExtension, extension.length(), "out");
	ofstream fileOut(fileOutName);
	if (fileOut.fail() == true)
	{
		cout << "Khong mo duoc file";
		exit(0);
	}
	for (int i = 0; i < n; i++)
		fileOut << setw(8) << a[i].numerator << setw(8) << a[i].denominator << endl;
}

int Compare(FRACTION P, FRACTION Q)
{
	float a = (float)P.numerator / P.denominator;
	float b = (float)Q.numerator / Q.denominator;

	if (a > b)
		return 1;
	else if (a < b)
		return -1;
	return 0;
}

void Merge(FRACTION a[], int left, int mid, int right)
{
	FRACTION* temp = new FRACTION[right - left + 1];
	int m = 0;
	int i = left;
	int j = mid + 1;
	while (!(i > mid && j > right))
	{
		if ((i <= mid && j <= right && Compare(a[i], a[j]) == -1 ) || j > right)
			temp[m++] = a[i++];
		else
			temp[m++] = a[j++];
	}
	for (int i = 0; i < m; i++)
		a[left + i] = temp[i];
}

void MergeSort(FRACTION a[], int left, int right)
{
	if (left < right)
	{
		int mid = (right + left) / 2;
		MergeSort(a, left, mid);
		MergeSort(a, mid + 1, left);
		Merge(a, left, mid, right);
	}
}
