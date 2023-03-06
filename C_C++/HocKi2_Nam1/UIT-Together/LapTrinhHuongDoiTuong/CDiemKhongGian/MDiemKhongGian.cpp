#include "CDiemKhongGian.h"

int main()
{
	CDiemKhongGian A;
	cout << "Nhap diem A:\n";
	//A.Input();
	cin >> A;
	cout << "A" << A;
	//A.Print();
	cout << "Nhap diem A:\n";
	//A.Input();
	CDiemKhongGian B;
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