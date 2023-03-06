#include "CDiem.h"


int main()
{
	CDiem A;
	cout << "Nhap diem A:\n";
	cin >> A;
	cout << "A" << A;
	CDiem B;
	cout << "Nhap diem A:\n";
	cin >> B;
	cout << "A" << B;

	if (A == B)
		cout << "\nA bang B";
	else
		cout << "\nA khac B";
	if (A > B)
		cout << "\nA > B";
	else if (A < B)
		cout << "\nA < B";
	return 0;
}