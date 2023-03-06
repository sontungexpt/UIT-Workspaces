#include <iostream>
#include <fstream>
#include<iomanip>
#include <string>
using namespace std;

int Nhap(int[], int&, string);
int Xuat(int[], int, string);
void InterchangeSort(int [], int);


int main()
{
	int b[100000];
	int k;

	for (int i = 1; i <= 13; i++)
	{
		string filename = "intdata";
		if (i < 10)
			filename += '0';
		filename += to_string(i);

		string filenameinp = filename;
		filenameinp += ".inp";
		if (Nhap(b, k, filenameinp) == 1)
		{
			InterchangeSort(b, k);
			string filenameout = filename;
			filenameout += ".out";
			Xuat(b, k, filenameout);

			cout << "\n" << filenameinp;
			cout << "\n" << filenameout;
		}
		else
			cout << "\n Khong mo duoc file " << filename << "\n";
	}
	cout << "\n\n\n";
	return 1;
}

int Nhap(int a[], int& n, string filename)
{
	ifstream fi(filename);
	if (fi.fail())
		return 0;
	fi >> n;
	for (int i = 0; i < n; i++)
		fi >> a[i];
	return 1;
}

int Xuat(int a[], int n, string filename)
{
	ofstream fo(filename);
	if (fo.fail() == true)
		return 0;
	fo << setw(5) << n << endl;
	for (int i = 0; i < n; i++)
		fo << setw(5) << a[i];
	return 1;
}


//#include <iostream>
//#include <fstream>
//#include <string>
//#include <iomanip>
//#include <cctype>
//#include <math.h>
//#include <algorithm>
//
//using namespace std;
//
//#define MAX 100000
//
//string GetFileLink(string);
//void Nhap(string, int[], int&);
//void Xuat(int [], int );

//
//int main()
//{
//	int b[100000];
//	int k;
//
//	for (int i = 1; i <= 13; i++)
//	{
//		InterchangeSort(b, k);
//		string filename = "intdata";
//		if (i < 10)
//			filename += '0';
//		filename += to_string(i);
//
//		string filenameinp = filename;
//		filenameinp += ".inp";
//		if (Nhap(filenameinp,b,k) == 1)
//		{
//
//			string filenameout = filename;
//			filenameout += ".out";
//			Xuat(filenameout,b,k);
//
//			cout << "\n" << filenameinp;
//			cout << "\n" << filenameout;
//		}
//		else
//			cout << "\n Khong mo duoc file " << filename << "\n";
//	}
//	cout << "\n\n\n";
//	return 1;
//}
//
////int main()
////{
////	int n;
////	int a[MAX];
////	//Nhap(GetFileLink("int"), a, n);
////	//InterchangeSort(a, n);
////	Xuat(a, n);
////	return 0;
////}
//
//
//string GetFileLink(string dataTypeOfFile)
//{
//	//lấy tên thư mục
//	string folderName = dataTypeOfFile;
//	folderName[0] = toupper(folderName[0]);
//	folderName += "Data";
//	//lấy đường dẫn tới file data.inp
//	string fileLink = "../" + folderName + "/" + dataTypeOfFile + "data";
//	int fileIndex;
//	cout << "Nhap so thu tu cua file can lay gia tri: ";
//	cin >> fileIndex;
//	if (fileIndex < 10)
//		fileLink += '0';
//	fileLink += to_string(fileIndex);
//	string fileLinkInp = fileLink;
//	fileLinkInp += ".inp";
//	return fileLinkInp;
//}
//
//void Nhap(string filename, int a[], int& n)
//{
//	ifstream fi(filename);
//	if (fi.fail() == true)
//	{
//		cout << "Khong mo duoc file";
//		exit(0);
//	}
//	fi >> n;
//	for (int i = 0; i < n; i++)
//		fi >> a[i];
//}
//
//void Xuat(int a[], int n)
//{
//	for (int i = 0; i < n; i++)
//		cout << setw(8) << a[i];
//}
//
void InterchangeSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n; j++)
			if (a[i] > a[j])
				swap(a[i], a[j]);
}