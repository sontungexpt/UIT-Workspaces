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
int TanSoXuatHien(int[], int, float);
bool LietKeDuyNhat(int[], int, int[], int);

int main()
{
	int n1;
	int a1[MAX];
	int n2;
	int a2[MAX];
	cout << "Chon file de nhap mang dau tien\n";
	Nhap(GetFileLink("int"), a1, n1);
	cout << "Chon file de nhap mang thu hai\n";
	Nhap(GetFileLink("int"), a2, n2);
	cout << "\nCac gia tri chi xuat hien mot trong hai mang la: ";
	if (LietKeDuyNhat(a1, n1, a2, n2) == false && LietKeDuyNhat(a2, n2, a1, n1) == false)
		cout << "Khong co gia tri khac nhau nao\n";
	else
	{
		LietKeDuyNhat(a1, n1, a2, n2);
		LietKeDuyNhat(a2, n2, a1, n1);
	}

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

int TanSoXuatHien(int a[], int n, int x)
{
	int count = 0;
	for (int i = 0; i < n; i++)
		if (a[i] == x)
			count++;
	return count;
}
bool LietKeDuyNhat(int aa1[], int nn1, int aa2[], int nn2)
{
	bool flag = 0;
	for (int i = 0; i < nn1; i++)
		if (TanSoXuatHien(aa2, nn2, aa1[i]) == 0)
		{
			cout << aa1[i] << setw(11);
			flag = 1;
		}
	return flag;
}

