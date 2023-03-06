#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
#include <math.h>

using namespace std;

#define MAXR 500
#define MAXC 500

//initalize function
string GetFileLink(string);
void Xuat(int[][MAXC], int, int);
void Nhap(string, int[][MAXC], int&, int&);
int ChuSoDau(int);
int DemChanTrongCot(int[][MAXC], int, int, int&);

int main()
{
	int k = 0;
	int l = 0;
	int a[MAXR][MAXC];
	int vtCot = 0;
	Nhap(GetFileLink("int"), a, k, l);
	int result = DemChanTrongCot(a, k, l, vtCot);
	cout << "So chu so co chu so dau tien la chan o cot "<<vtCot<<": " << result;
	return 0;
}

//function
string GetFileLink(string dataTypeOfFile)
{
	string folderName = dataTypeOfFile;
	folderName[0] = toupper(folderName[0]);
	folderName += "MatranData";
	string fileLink = "../" + folderName + "/" + dataTypeOfFile + "matrandata";
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

void Nhap(string filename, int a[][MAXC], int& m, int& n)
{
	ifstream fi(filename);
	if (fi.fail() == true)
	{
		cout << "Khong mo duoc file";
		exit(0);
	}
	fi >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			fi >> a[i][j];
}

void Xuat(int a[][MAXC], int m, int n)
{
	cout << "Ma tran la:\n";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(8) << a[i][j];
		cout << endl;
	}
}

int ChuSoDau(int n)
{
	int dt = abs(n);
	for (; dt >= 10;)
		dt /= 10;
	return dt;
}

int DemChanTrongCot(int a[][MAXC], int m, int n, int &vtCot )
{
	cout << "Nhap cot can dem: ";
	cin >> vtCot;
	int count = 0;
	for (int i = 0; i < m; i++)
		if (ChuSoDau(a[i][vtCot]) % 2 == 0)
			count++;
	return count;

}