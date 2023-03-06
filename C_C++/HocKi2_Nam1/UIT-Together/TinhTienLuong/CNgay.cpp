#include "CNgay.h"

CNgay::CNgay()
{
	ng = 1;
	th = 1;
	nm = 1;
}

void CNgay::Nhap()
{
	cout << "Nhap ngay: ";
	cin >> ng;
	cout << "Nhap thang: ";
	cin >> th;
	cout << "Nhap nam: ";
	cin >> nm;
}

void CNgay::Xuat()
{
	cout << "Ngay: " << ng << endl;
	cout << "Thang: " << th << endl;
	cout << "Nam: " << nm;
}