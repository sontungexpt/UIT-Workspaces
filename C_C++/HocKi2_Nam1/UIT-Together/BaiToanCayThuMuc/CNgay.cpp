#include "CNgay.h"
#include<iostream>
using namespace std;

void CNgay::Nhap()
{
	cout << "Nhap ngay tao lap: ";
	cin >> Ngay;
	cout << "Nhap thang tao lap: ";
	cin >> Thang;
	cout << "Nhap nam tao lap: ";
	cin >> Nam;
}

void CNgay::Xuat()
{
	cout << Ngay << "/" << Thang << "/" << Nam;
}
