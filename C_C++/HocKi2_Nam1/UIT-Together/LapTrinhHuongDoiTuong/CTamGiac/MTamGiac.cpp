#include "CTamGiac.h"

int main()
{
	CTamGiac A;
	cout << "Nhap diem A:\n";
	//A.Input();
	cin >> A;
	cout << A;
	//A.Print();
	CTamGiac B;
	cout << "Nhap diem A:\n";
	//A.Input();
	cin >> B;
	cout << B;
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